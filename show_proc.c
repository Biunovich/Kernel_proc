#include "mylib.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Buin Buin");
MODULE_DESCRIPTION("Testing show proc module");

static void show_proc(void)
{
	struct task_struct *task;

	for_each_process(task)
		pr_info("name: %s pid %d\n", task->comm, task->pid);
}

int init_module(void)
{
	pr_info("init_module\n");
	show_proc();
}

void cleanup_module(void)
{
	pr_info("cleanup_module\n");
}