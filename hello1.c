///
 /// hello.c
 ///
 ///  Created on: Jul 16, 2015
 ///      Author: visteon
///

#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/moduleparam.h>

#define AUTHOR "Emil Velikov <asdasd@abv.org>"
#define DESC "Hello driver"


static int __init init_hello(void)
{
    printk(KERN_INFO "Hello World\n");
    return 0;
}

static void __exit cleanup_hello(void)
{
    printk(KERN_INFO "Bye, Bye");
}

module_init(init_hello);
module_exit(cleanup_hello);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESC);
