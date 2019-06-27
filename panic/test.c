#include <linux/module.h>

int func2(int y, int z)
{
  printk(KERN_INFO "y=%d, z=%d\n", y,z);
  panic("panic for test\n");
  return 0;
}

int func1(int x)
{
  printk(KERN_INFO "x=%d\n", x);
  func2(x+100, x+200);
  return 0;
}

static int __init test_init(void)
{
  printk(KERN_INFO "Hello!\n");
  func1(100);
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
