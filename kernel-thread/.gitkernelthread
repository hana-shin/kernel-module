#include <linux/module.h>
#include <linux/kthread.h>

static char *name;
struct task_struct *t;
module_param(name, charp, S_IRUGO);

static int test_func(void *arg)
{
  printk(KERN_INFO "%s kthread started.PID is %d\n", t->comm, t->pid);

  while(!kthread_should_stop())
    schedule();
  return 0;
}

static int __init test_init(void)
{
  t = kthread_run(test_func, NULL, name);
  return 0;
}

static void __exit test_exit(void)
{
  kthread_stop(t);
  printk(KERN_INFO "%s kthread ended.\n", t->comm);
}

module_init(test_init);
module_exit(test_exit);

MODULE_AUTHOR("hana_shin");
MODULE_LICENSE("GPL v2");
