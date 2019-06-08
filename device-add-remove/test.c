#include <linux/module.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>

static struct file_operations test_dev_fops = {
    .owner = THIS_MODULE,
};

static struct miscdevice test_dev = {
    .name = "test_device",
    .minor = MISC_DYNAMIC_MINOR,
    .fops = &test_dev_fops,
};

static __init int test_init(void)
{
    printk(KERN_INFO "Device registered!\n");
    misc_register(&test_dev);
    return 0;
}

static __exit void test_exit(void)
{
    printk(KERN_INFO "Device unegistered!\n");
    misc_deregister(&test_dev);
}

module_init(test_init);
module_exit(test_exit);

MODULE_AUTHOR("hana_shin");
MODULE_LICENSE("GPL v2");
