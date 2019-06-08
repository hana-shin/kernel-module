#include <linux/module.h>

static int cnt = 1;
module_param(cnt, int, S_IRUGO);

static int __init test_init(void)
{
  printk(KERN_INFO "Hello!,cnt=%d\n",cnt);
  return 0;
}

static void __exit test_exit(void)
{
  printk(KERN_INFO "Bye!\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_AUTHOR("hana_shin");
MODULE_LICENSE("GPL v2");
