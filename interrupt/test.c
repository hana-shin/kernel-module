#include <linux/module.h>
#include <linux/interrupt.h>

#define TEST_IRQ    17
static int irq_counter=0;
static int test_dev_id;

static irqreturn_t test_interrupt(int irq, void *dev_id)
{
  printk(KERN_INFO "Interrupt Counter=%d\n",++irq_counter);
  return IRQ_HANDLED;
}

static int __init test_init(void)
{
  if(request_irq(TEST_IRQ, test_interrupt, IRQF_SHARED, "test_interrupt", &test_dev_id))
    return -1;
  printk(KERN_INFO "Loading Interrupt Handler\n");
  return 0;
}

static void __exit test_exit(void)
{
  synchronize_irq(TEST_IRQ);
  free_irq(TEST_IRQ, &test_dev_id);
  printk(KERN_INFO "Unloading Interrupt handler\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_AUTHOR("hana_shin");
MODULE_LICENSE("GPL v2");
