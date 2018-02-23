/*
malloc������ڴ��ʵ�ֲ��룬
���� �� http://blog.csdn.net/shanghairuoxiao/article/details/70337890
�����Լ����뷨���޸���85-92�С���֪���ǲ��ǶԵ�....��

*/

#define malloc_addr 0x00000
#define malloc_size 0x22222

#ifndef NULL
#define NULL 0
#endif

void* managed_memory_start = NULL;  //��������ʼ��ַ
void* managed_memory_end = NULL;    //��ȡ����ֹ��ַ
int is_initialized = 0;

/*
* �ڴ���ƿ飬ͨ���ڴ���ƿ齫�������ڴ���˫������������������
*/
typedef struct
{
	unsigned int is_available; //�Ƿ�ռ��
	unsigned int current_block_size; //������п��õ�����
	unsigned int prev_block_size; //����һ����ľ��룿
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
	//��ʼ�����ʼ����ֻ��һ���ڵ�
	if (!is_initialized)
	{
		malloc_init();
	}

	//�����ڴ��ַ�α�
	void* current_location = NULL;
	//���浱ǰ�ڴ���ƿ��λ��
	mem_control_block* current_location_mcb = NULL;
	//�����̫��ȡ�������С��ʣ��Ż�����
	mem_control_block* leave_location_mcb = NULL;
	//����һ�����ڷ��ص�ָ�룬���صĵ�ַ�ǿ��ƿ����ǰ��ṹ��Ĵ�С
	void* memory_location = NULL;

	//���α�ָ��ѵ��׵�ַ
	current_location = managed_memory_start;

	while (current_location <= managed_memory_end)
	{
		current_location_mcb = (mem_control_block*)current_location;
		//�жϸýڵ��Ƿ񱻿���
		if (current_location_mcb->is_available)
		{
			//�жϸÿ��п������Ҫ������ʣ�µĿռ��ֲ�����ά��һ�����п飬�Ͱ������鶼�����ˣ�Ϊ��ά�������������
			//ʵ����Ҳ�˷Ѳ��˶����ڴ棬��Ϊһ��struct�ṹ���С
			if (current_location_mcb->current_block_size < size + 2 * sizeof(mem_control_block)) //���ʣ��ռ�ֻ�ܷŵ�����Ҫ���ڴ��һ����һ����ڴ���ƿ飬�Ͱ�ʣ�µ��ڴ�ȫռ�˰ɡ�
			{
				current_location_mcb->is_available = 0;
				break;
			}
			else //������п������Ҫ�ģ��Ͱ�ʣ��Ŀ����leave_location_mcb�ڵ���
			{
				unsigned int process_blocksize;

				//��ǰ��Ϊ��ʹ��״̬
				current_location_mcb->is_available = 0;
				process_blocksize = current_location_mcb->current_block_size; //�ܹ��Ŀ��õĿռ䣨��ȥ�˵�һ�����ƿ�ṹ�壩

				current_location_mcb->current_block_size = size + sizeof(mem_control_block); //ʵ��ʹ���˵Ŀռ�
				//leave_location_mcb = (mem_control_block*)(current_location + process_blocksize);
				leave_location_mcb =current_location_mcb+current_location_mcb->current_block_size; //ԭ�������ʼ��ַ����ռ���˵Ŀռ����ʣ������ʼ��ַ��
				leave_location_mcb->is_available = 1;
				//��ǰ���С��ȥ��Ҫ���ڴ��ȥһ�����ƿ�ṹ�����ʣ��Ĵ�С
				leave_location_mcb->current_block_size = process_blocksize - sizeof(mem_control_block) - size;//ʣ����ÿռ�
				//leaveo���ǰһ����Ĵ�С����Ҫ����Ĵ�С
			//	leave_location_mcb->prev_block_size = size + sizeof(mem_control_block);
			}
		}
		//����ÿ鲻���У���ָ���α�ָ����һ����׵�ַ
	//	current_location += current_location_mcb->current_block_size;
	}

	//��������������Ѿ�û�к��ʵĿ����������ķ�Χ
	if (!memory_location)
	{
		//����ȡ�����ȡ���ڴ�
		if (sbrk(size + sizeof(mem_control_block)) != -1)
			return NULL;

		//�������������û�к��ʵĿ飬��ô��Ȼ�Ǳ���������������ʱ��current_location_mcbָ��ԭ��������������һ����
		//���ÿ�Ĵ�С������������������Ҫ������ǰһ����Ĵ�С��
		unsigned int prev_size = current_location_mcb->current_block_size;

		//֮ǰ��ѭ����ʹ��current_locationָ�����һ����ĩβ����һ����ַ
		current_location_mcb = (mem_control_block*)current_location;
		current_location_mcb->current_block_size = size + sizeof(mem_control_block);
		current_location_mcb->prev_block_size = prev_size;
	}

	memory_location = current_location + sizeof(mem_control_block);
	return memory_location;
}