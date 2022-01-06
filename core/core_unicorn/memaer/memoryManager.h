#pragma once
#ifndef __MMER__
#define __MMER__
// ��ʼ��ַ
#define ADDRESS 0x1000000
//�ڴ�����趨.
#define MEM_BLOCK_SIZE			32  	  						//�ڴ���СΪ32�ֽ�
#define MEM_MAX_SIZE			1024//2*1024*1024  						//�������ڴ� 2MB
#define MEM_ALLOC_TABLE_SIZE	(MEM_MAX_SIZE/MEM_BLOCK_SIZE) 	//�ڴ���С
#define u32 unsigned short
#define u8  unsigned char
//�ڴ���������
typedef struct _m_malloc_dev
{
    void (*init)();		    //��ʼ��
    int (*perused)();		//�ڴ�ʹ����
    u8*  membase;				//�ڴ�� 
    u32* memmap; 				//�ڴ����״̬��
    bool memrdy; 				//�ڴ�����Ƿ����
};
void mem_init();
int mem_perused();
void* mymalloc(int size);
void myfree(void* ptr);
void* myrealloc(void* ptr, int size);
#endif