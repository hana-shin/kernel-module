#include <linux/module.h>

static int sec = 1;
module_param(sec, int, S_IRUGO);
static struct timer_list test_timer;

static void test_func(int sec)
{
  printk(KERN_INFO "Timer expired\n");
  mod_timer(&test_timer, jiffies + sec * HZ);
}

static int __init test_init(void)
{
  init_timer(&test_timer);

  test_timer.data = sec;
  test_timer.function = (void *)&test_func;
  test_timer.expires = jiffies + sec * HZ;
  add_timer(&test_timer);

  printk(KERN_INFO "Hello. Time interval is %d second\n", sec);
  return 0;
}

static void __exit test_exit(void)
{
  printk(KERN_INFO "Bye\n");
  del_timer(&test_timer);
}

module_init(test_init);
module_exit(test_exit);

MODULE_AUTHOR("hana_shin");
MODULE_LICENSE("GPL v2");
