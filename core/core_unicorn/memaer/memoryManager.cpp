#include <iostream>
#include "memoryManager.h"
using namespace std;

//�ڴ��(4�ֽڶ���)
//#define base (u8*)ADDRESS
u8 base[MEM_MAX_SIZE];			                //�ڴ��
//�ڴ�����
u32 memmapbase[MEM_ALLOC_TABLE_SIZE];			    //�ڴ��MAP
//�ڴ�������	   
const int memtblsize = MEM_ALLOC_TABLE_SIZE;		//�ڴ���С
const int memblksize = MEM_BLOCK_SIZE;			    //�ڴ�ֿ��С
const int memsize = MEM_MAX_SIZE;					//�ڴ��ܴ�С

_m_malloc_dev malloc_dev = {
    mem_init,			//�ڴ��ʼ��
    mem_perused,		//�ڴ�ʹ����
    base,			    //�ڴ��
    memmapbase,			//�ڴ����״̬��
    false    			//�ڴ����δ����
};

//�����ڴ�
//*des:Ŀ�ĵ�ַ
//*src:Դ��ַ
//n:��Ҫ���Ƶ��ڴ泤��(�ֽ�Ϊ��λ)
void mymemcpy(void* des, void* src, int n)
{
    u8* xdes = (u8*)des;
    u8* xsrc = (u8*)src;
    while (n--)*xdes++ = *xsrc++;
}
//�����ڴ�
//*s:�ڴ��׵�ַ
//count:��Ҫ���õ��ڴ��С(�ֽ�Ϊ��λ)
void mymemset(void* s,u8 c,int count)
{
    u8* xs = (u8*)s;
    /*uc_mem_write(uc,(uint64_t)xs,"0", 1);*/
    while (count--)*xs++ = c;
}
//�ڴ�����ʼ��  
void mem_init()
{
    mymemset(malloc_dev.memmap, 0,memtblsize * 4); //�ڴ�״̬����������  
    mymemset(malloc_dev.membase, 0,memsize);	    //�ڴ��������������  
    malloc_dev.memrdy = true;						//�ڴ�����ʼ��OK  
}
//��ȡ�ڴ�ʹ����
//����ֵ:ʹ����(0~100)
int mem_perused(void)
{
    int used = 0;
    for (int i = 0; i < MEM_ALLOC_TABLE_SIZE; i++)
    {
        if (malloc_dev.memmap[i])used++;
    }
    for (int i = 0; i < MEM_ALLOC_TABLE_SIZE; i++)
        cout << malloc_dev.memmap[i] << endl;
    for (int i = 0; i < MEM_MAX_SIZE; i++)
        cout << malloc_dev.membase[i];
    cout << endl;
    return (used * 100) / MEM_ALLOC_TABLE_SIZE;
}
//�ڴ����(�ڲ�����)
//memx:�����ڴ��
//size:Ҫ������ڴ��С(�ֽ�)
//����ֵ:0XFFFFFFFF,�������;����,�ڴ�ƫ�Ƶ�ַ 
int mem_malloc(int size)
{
    int offset = 0; //�ڴ�ƫ����
    int nmemb;	            //��Ҫ���ڴ����  
    int cmemb = 0;          //�������ڴ����
    if (!malloc_dev.memrdy) malloc_dev.init();	//δ��ʼ��,��ִ�г�ʼ�� 
    if (size == 0)  return 0XFFFFFFFF;				//����Ҫ����
    nmemb = size / memblksize;  					//��ȡ��Ҫ����������ڴ����
    if (size % memblksize)  nmemb++;                //���������ڴ棬�ڴ������һ
    for(offset = memtblsize - 1; offset >= 0; offset--)	//���������ڴ������  
    {
        if (!malloc_dev.memmap[offset])cmemb++;	//�������ڴ��������
        else cmemb = 0;							//�������ڴ������
        if (cmemb == nmemb)						//�ҵ�������nmemb�����ڴ��
        {
            for (int i = 0; i < nmemb; i++)  				//��ע�ڴ��ǿ� 
            {
                malloc_dev.memmap[offset + i] = nmemb;
            }
            return (offset * memblksize);			//����ƫ�Ƶ�ַ  
        }
    }
    return 0XFFFFFFFF;//δ�ҵ����Ϸ����������ڴ��  
}
//�ͷ��ڴ�(�ڲ�����) 
//offset:�ڴ��ַƫ��
//����ֵ:0.�ͷųɹ�;1.δ��ʼ��;2.ƫ��������  
u8 mem_free(int offset)
{
    int i;
    if (!malloc_dev.memrdy)//δ��ʼ��,��ִ�г�ʼ��
    {
        malloc_dev.init();
        return 1;//δ��ʼ��  
    }
    if (offset < memsize)//ƫ�����ڴ����. 
    {
        int index = offset / memblksize;		//ƫ�������ڴ�����  
        int nmemb = malloc_dev.memmap[index];	//�ڴ������
        for (i = 0; i < nmemb; i++)  				//�ڴ������
        {
            malloc_dev.memmap[index + i] = 0;
        }
        return 0;
    }
    else return 2;//ƫ�Ƴ�����.  
}
//�����ڴ�(�ⲿ����)
//size:�ڴ��С(�ֽ�)
//����ֵ:���䵽���ڴ��׵�ַ.
void* mymalloc(int size)
{
    int offset;//�ڴ�ƫ����
    offset = mem_malloc(size);
    if (offset == 0XFFFFFFFF)   return NULL;
    else return (void*)((int)malloc_dev.membase+offset);
}
//�ͷ��ڴ�(�ⲿ����) 
//ptr:�ڴ��׵�ַ 
void myfree(void* ptr)
{
    int offset;//�ڴ�ƫ����
    if (ptr == NULL)    return;//��ַΪ0.  
    offset = (int)ptr - (int)malloc_dev.membase;
    mem_free(offset);	//�ͷ��ڴ�     
}
//���·����ڴ�(�ⲿ����)
//*ptr:���ڴ��׵�ַ
//size:Ҫ������ڴ��С(�ֽ�)
//����ֵ:�·��䵽���ڴ��׵�ַ.
void* myrealloc(void* ptr, int size)
{
    int offset;//�ڴ�ƫ����
    offset = mem_malloc(size);
    if (offset == 0XFFFFFFFF)   return NULL;
    else
    {
        mymemcpy((void*)((int)malloc_dev.membase + offset), ptr, size);	//�������ڴ����ݵ����ڴ�   
        myfree(ptr);  											  	//�ͷž��ڴ�
        return (void*)((int)malloc_dev.membase + offset);  			//�������ڴ��׵�ַ
    }
}
