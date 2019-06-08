#include <linux/module.h>

static struct kobject *test_kobj;

static ssize_t test1_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
  return sprintf(buf, "%lu\n", get_seconds());
}

static ssize_t test2_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
  return sprintf(buf, "%lu\n", jiffies);
}

static struct kobj_attribute test1_attr = __ATTR(time, 0444, test1_show, NULL);
static struct kobj_attribute test2_attr = __ATTR(jiffies, 0444, test2_show, NULL);

static struct attribute *test_attrs[] = {
  &test1_attr.attr,
  &test2_attr.attr,
  NULL,
};

static struct attribute_group test_attr_group = {
  .name = "stat",
  .attrs = test_attrs,
};

static int test_init(void)
{
  int ret;

  printk(KERN_INFO "Hello\n");

  test_kobj = kobject_create_and_add("test", kernel_kobj);
  ret = sysfs_create_group(test_kobj, &test_attr_group);
  return ret;
}

static void test_exit(void)
{
  kobject_put(test_kobj);
  printk(KERN_INFO "Bye!\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_AUTHOR("hana_shin");
MODULE_LICENSE("GPL v2");
