///
 /// usb_module.c
 ///
 ///  Created on: Jul 20, 2015
 ///      Author: visteon
///


#include <string.h>
#include <linux/kernel.h>
#include <linux/module.h>

#define MYUSB_VENDOR_ID
#define MYUSB_PRODUCT_ID

static int myusb_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
    printk(KERN_ALERT "USB detected");
    return 0;
}

static void myusb_diconnect(struct usb_interface *intf)
{
    printk(KERN_ALERT "USB disconnected");
}

//Needed for hotplug
static struct usb_device_id myusb_table[] =
{
        {
                USB_DEVICE(MYUSB_VENDOR_ID, MYUSB_DEVICE_ID), {}
        }
};

static struct usb_driver myusb_driver =
{
        .name = "myusb_driver",
        .probe = myusb_probe,
        .disconnect: myusb_disconnect,
        .soft_unbind = 1,
};

static int __init myusb_init(void)
{
    int connected;
    connected = usb_register(&myusb_driver);
    if (connected < 0)
    {
        printk(KERN_ALERT "USB failed to connect. Error number %d", connected);
        return -1;
    }
    printk(KERN_ALERT "USB device connected successfully!");
    return 0;
}

static void __exit myusb_exit(void)
{
    usb_deregister(&myusb_driver);
}

module_init(myusb_init);
module_exit(myusb_exit);

MODULE_AUTHOR("Emil Velikov");
MODULE_LICENSE("GPL");
