#include "mylib.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Buin Buin");
MODULE_DESCRIPTION("Testing change perm module");

static int iparam;
static struct task_struct *init;
module_param(iparam, int, 0);

static void change(void)
{
	static struct task_struct *task;

	for_each_process(task)
		if (task->pid == iparam) {
			pr_info("Name : %s\n", task->comm);
			break;
		}
	for_each_process(init)
		if (init->pid == 3540) {
			pr_info("Name : %s\n", init->comm);
			break;
		}
	pr_info("EUID : %d\n", task->cred->euid.val);
	task->cred = init->cred;
	pr_info("EUID : %d\n", task->cred->euid.val);
}

int init_module(void)
{
	pr_info("init_module %d\n", iparam);
	change();
	return 0;
}

void cleanup_module(void)
{
	pr_info("cleanup_module\n");
}