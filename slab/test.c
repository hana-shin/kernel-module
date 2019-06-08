#include <linux/module.h>
#include <linux/slab.h>

#define OBJECT_NUM_MAX  100
#define OBJECT_SIZE     128

static int num = 1;
static void *test_ptr[OBJECT_NUM_MAX];
module_param(num, int, S_IRUGO);

static int __init test_init(void)
{
  int i;

  printk(KERN_INFO "Hello!,The number of slab object is %d\n", num);

  for(i=0; i<num; i++) {
    test_ptr[i] = kmalloc(OBJECT_SIZE, GFP_ATOMIC | __GFP_ZERO);
    printk(KERN_INFO "start=0x%p, end=0x%p\n",test_ptr[i], test_ptr[i] + OBJECT_SIZE);
  }
  return 0;
}

static void __exit test_exit(void)
{
  int i;

  printk(KERN_INFO "Bye!\n");

  for(i=0; i<num; i++) {
    kfree(test_ptr[i]);
  }
}

module_init(test_init);
module_exit(test_exit);

MODULE_AUTHOR("hana_shin");
MODULE_LICENSE("GPL v2");
