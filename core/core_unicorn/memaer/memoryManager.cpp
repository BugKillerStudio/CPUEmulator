#include <iostream>
#include "memoryManager.h"
using namespace std;

//内存池(4字节对齐)
//#define base (u8*)ADDRESS
u8 base[MEM_MAX_SIZE];			                //内存池
//内存管理表
u32 memmapbase[MEM_ALLOC_TABLE_SIZE];			    //内存池MAP
//内存管理参数	   
const int memtblsize = MEM_ALLOC_TABLE_SIZE;		//内存表大小
const int memblksize = MEM_BLOCK_SIZE;			    //内存分块大小
const int memsize = MEM_MAX_SIZE;					//内存总大小

_m_malloc_dev malloc_dev = {
    mem_init,			//内存初始化
    mem_perused,		//内存使用率
    base,			    //内存池
    memmapbase,			//内存管理状态表
    false    			//内存管理未就绪
};

//复制内存
//*des:目的地址
//*src:源地址
//n:需要复制的内存长度(字节为单位)
void mymemcpy(void* des, void* src, int n)
{
    u8* xdes = (u8*)des;
    u8* xsrc = (u8*)src;
    while (n--)*xdes++ = *xsrc++;
}
//设置内存
//*s:内存首地址
//count:需要设置的内存大小(字节为单位)
void mymemset(void* s,u8 c,int count)
{
    u8* xs = (u8*)s;
    /*uc_mem_write(uc,(uint64_t)xs,"0", 1);*/
    while (count--)*xs++ = c;
}
//内存管理初始化  
void mem_init()
{
    mymemset(malloc_dev.memmap, 0,memtblsize * 4); //内存状态表数据清零  
    mymemset(malloc_dev.membase, 0,memsize);	    //内存池所有数据清零  
    malloc_dev.memrdy = true;						//内存管理初始化OK  
}
//获取内存使用率
//返回值:使用率(0~100)
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
//内存分配(内部调用)
//memx:所属内存块
//size:要分配的内存大小(字节)
//返回值:0XFFFFFFFF,代表错误;其他,内存偏移地址 
int mem_malloc(int size)
{
    int offset = 0; //内存偏移量
    int nmemb;	            //需要的内存块数  
    int cmemb = 0;          //连续空内存块数
    if (!malloc_dev.memrdy) malloc_dev.init();	//未初始化,先执行初始化 
    if (size == 0)  return 0XFFFFFFFF;				//不需要分配
    nmemb = size / memblksize;  					//获取需要分配的连续内存块数
    if (size % memblksize)  nmemb++;                //非整数块内存，内存块数加一
    for(offset = memtblsize - 1; offset >= 0; offset--)	//搜索整个内存控制区  
    {
        if (!malloc_dev.memmap[offset])cmemb++;	//连续空内存块数增加
        else cmemb = 0;							//非连续内存块清零
        if (cmemb == nmemb)						//找到了连续nmemb个空内存块
        {
            for (int i = 0; i < nmemb; i++)  				//标注内存块非空 
            {
                malloc_dev.memmap[offset + i] = nmemb;
            }
            return (offset * memblksize);			//返回偏移地址  
        }
    }
    return 0XFFFFFFFF;//未找到符合分配条件的内存块  
}
//释放内存(内部调用) 
//offset:内存地址偏移
//返回值:0.释放成功;1.未初始化;2.偏移量超区  
u8 mem_free(int offset)
{
    int i;
    if (!malloc_dev.memrdy)//未初始化,先执行初始化
    {
        malloc_dev.init();
        return 1;//未初始化  
    }
    if (offset < memsize)//偏移在内存池内. 
    {
        int index = offset / memblksize;		//偏移所在内存块号码  
        int nmemb = malloc_dev.memmap[index];	//内存块数量
        for (i = 0; i < nmemb; i++)  				//内存块清零
        {
            malloc_dev.memmap[index + i] = 0;
        }
        return 0;
    }
    else return 2;//偏移超区了.  
}
//分配内存(外部调用)
//size:内存大小(字节)
//返回值:分配到的内存首地址.
void* mymalloc(int size)
{
    int offset;//内存偏移量
    offset = mem_malloc(size);
    if (offset == 0XFFFFFFFF)   return NULL;
    else return (void*)((int)malloc_dev.membase+offset);
}
//释放内存(外部调用) 
//ptr:内存首地址 
void myfree(void* ptr)
{
    int offset;//内存偏移量
    if (ptr == NULL)    return;//地址为0.  
    offset = (int)ptr - (int)malloc_dev.membase;
    mem_free(offset);	//释放内存     
}
//重新分配内存(外部调用)
//*ptr:旧内存首地址
//size:要分配的内存大小(字节)
//返回值:新分配到的内存首地址.
void* myrealloc(void* ptr, int size)
{
    int offset;//内存偏移量
    offset = mem_malloc(size);
    if (offset == 0XFFFFFFFF)   return NULL;
    else
    {
        mymemcpy((void*)((int)malloc_dev.membase + offset), ptr, size);	//拷贝旧内存内容到新内存   
        myfree(ptr);  											  	//释放旧内存
        return (void*)((int)malloc_dev.membase + offset);  			//返回新内存首地址
    }
}
