#pragma once
#ifndef __MMER__
#define __MMER__
// 起始地址
#define ADDRESS 0x1000000
//内存参数设定.
#define MEM_BLOCK_SIZE			32  	  						//内存块大小为32字节
#define MEM_MAX_SIZE			1024//2*1024*1024  						//最大管理内存 2MB
#define MEM_ALLOC_TABLE_SIZE	(MEM_MAX_SIZE/MEM_BLOCK_SIZE) 	//内存表大小
#define u32 unsigned short
#define u8  unsigned char
//内存管理控制器
typedef struct _m_malloc_dev
{
    void (*init)();		    //初始化
    int (*perused)();		//内存使用率
    u8*  membase;				//内存池 
    u32* memmap; 				//内存管理状态表
    bool memrdy; 				//内存管理是否就绪
};
void mem_init();
int mem_perused();
void* mymalloc(int size);
void myfree(void* ptr);
void* myrealloc(void* ptr, int size);
#endif