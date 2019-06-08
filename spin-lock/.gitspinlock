#include <linux/module.h>

spinlock_t test_lock;

static int __init test_init(void)
{
  spin_lock_init(&test_lock);
  printk(KERN_INFO "spin lock initialization\n");

  spin_lock(&test_lock);
  printk(KERN_INFO "lock spin lock\n");
  return 0;
}

static void __exit test_exit(void)
{
  spin_unlock(&test_lock);
  printk(KERN_INFO "unlock spin lock\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_AUTHOR("hana_shin");
MODULE_LICENSE("GPL v2");
