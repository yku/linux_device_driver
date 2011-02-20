#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("Dual BSD/GPL");

/* This function is called when insmod executes*/
static int hello_init(void)
{
    printk(KERN_ALERT "driver loaded\n");

    return 0;
}

/* This function is called when rmmod executes*/
static void hello_exit(void)
{
    printk(KERN_ALERT "driver unloaded\n");
}

module_init(hello_init);
module_exit(hello_exit);
