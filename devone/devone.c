#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/current.h>
#include <linux/uaccess.h>

MODULE_LICENSE("Dual BSD/GPL");

#define DRIVER_NAME "devone"

static unsigned int devone_major = 0;
module_param(devone_major, uint, 0);

static int devone_open(struct inode *inode, struct file *file)
{
    printk("%s: major %d minor %d (pid %d)\n", __func__,
            imajor(inode),
            iminor(inode),
            current->pid
          );
    inode->i_private = inode;
    file->private_data = file;


