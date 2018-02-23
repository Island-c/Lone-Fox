/*
malloc分配堆内存的实现猜想，
来自 ： http://blog.csdn.net/shanghairuoxiao/article/details/70337890
按照自己的想法，修改了85-92行。不知道是不是对的....。

*/

#define malloc_addr 0x00000
#define malloc_size 0x22222

#ifndef NULL
#define NULL 0
#endif

void* managed_memory_start = NULL;  //堆区的起始地址
void* managed_memory_end = NULL;    //堆取的终止地址
int is_initialized = 0;

/*
* 内存控制块，通过内存控制块将堆区的内存用双向链表连接起来管理
*/
typedef struct
{
	unsigned int is_available; //是否被占用
	unsigned int current_block_size; //这个块中可用的量。
	unsigned int prev_block_size; //到下一个块的距离？
}mem_control_block;


void malloc_init(void)
{
	mem_control_block* tmp = NULL;
	managed_memory_start = (void*)malloc_addr;
	managed_memory_end = (void*)(malloc_addr + malloc_size);

	tmp = (mem_control_block*)managed_memory_start;
	tmp->is_available = 1;
	tmp->current_block_size = (managed_memory_end - managed_memory_start) - sizeof(mem_control_block);
	tmp->prev_block_size = 0;
	is_initialized = 1;
}

void* malloc(size_t size)
{
	//初始化，最开始链表只有一个节点
	if (!is_initialized)
	{
		malloc_init();
	}

	//保存内存地址游标
	void* current_location = NULL;
	//保存当前内存控制块的位置
	mem_control_block* current_location_mcb = NULL;
	//如果块太大，取下所需大小，剩余放回链表
	mem_control_block* leave_location_mcb = NULL;
	//定义一个用于返回的指针，返回的地址是控制块加上前面结构体的大小
	void* memory_location = NULL;

	//把游标指向堆的首地址
	current_location = managed_memory_start;

	while (current_location <= managed_memory_end)
	{
		current_location_mcb = (mem_control_block*)current_location;
		//判断该节点是否被空闲
		if (current_location_mcb->is_available)
		{
			//判断该空闲块大于需要，但是剩下的空间又不足以维持一个空闲块，就把整个块都分配了，为了维持链表的连续性
			//实际上也浪费不了多少内存，因为一个struct结构体很小
			if (current_location_mcb->current_block_size < size + 2 * sizeof(mem_control_block)) //如果剩余空间只能放得下需要的内存和一个多一点的内存控制块，就把剩下的内存全占了吧。
			{
				current_location_mcb->is_available = 0;
				break;
			}
			else //如果空闲块大于需要的，就把剩余的块放入leave_location_mcb节点了
			{
				unsigned int process_blocksize;

				//另当前块为被使用状态
				current_location_mcb->is_available = 0;
				process_blocksize = current_location_mcb->current_block_size; //总共的可用的空间（除去了第一个控制块结构体）

				current_location_mcb->current_block_size = size + sizeof(mem_control_block); //实际使用了的空间
				//leave_location_mcb = (mem_control_block*)(current_location + process_blocksize);
				leave_location_mcb =current_location_mcb+current_location_mcb->current_block_size; //原来块的起始地址加上占用了的空间就是剩余块的起始地址。
				leave_location_mcb->is_available = 1;
				//当前块大小减去需要的内存减去一个控制块结构体就是剩余的大小
				leave_location_mcb->current_block_size = process_blocksize - sizeof(mem_control_block) - size;//剩余可用空间
				//leaveo块的前一个块的大小就是要分配的大小
			//	leave_location_mcb->prev_block_size = size + sizeof(mem_control_block);
			}
		}
		//如果该块不空闲，则指针游标指向下一块的首地址
	//	current_location += current_location_mcb->current_block_size;
	}

	//如果空闲链表中已经没有合适的块就扩大堆区的范围
	if (!memory_location)
	{
		//申请取扩大堆取的内存
		if (sbrk(size + sizeof(mem_control_block)) != -1)
			return NULL;

		//如果空闲链表中没有合适的块，那么必然是遍历了整个链表，此时的current_location_mcb指向原来空闲链表的最后一个块
		//将该块的大小保存下来，就是马上要分配块的前一个块的大小了
		unsigned int prev_size = current_location_mcb->current_block_size;

		//之前的循环会使得current_location指向最后一个块末尾的下一个地址
		current_location_mcb = (mem_control_block*)current_location;
		current_location_mcb->current_block_size = size + sizeof(mem_control_block);
		current_location_mcb->prev_block_size = prev_size;
	}

	memory_location = current_location + sizeof(mem_control_block);
	return memory_location;
}