/* keypad-keetronics-4949.c
 *
 * Driver for Keetronics Keypad 4949
 *
 * Author : Raghavendra Chandra Ganiga <ravi23ganiga@gmail.com>
 *		Santosh Ramroop Yadav <santosh.yadav@bitcommtechnologies.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/kernel.h>
#include <linux/i2c.h>


#define KEETRONICS4949_DRV_VERSION      "01.00"
#define KEETRONICS_KEY449			0

/* TODO check standard of device table and vendor name */
static struct i2c_device_id key4949_id[] = {
        { "keetronics4949", KEETRONICS_KEY449 },
        { }
};

MODULE_DEVICE_TABLE(i2c, key4949_id);

static int key4949_id(struct i2c_client *client,
                        const struct i2c_device_id *id)
{
	printk(KERN_ALERT, "Key probe called\r\n");
}

static struct i2c_driver key4949_driver = {
	.driver = {
		.name = "keetronics-key4949",
		.owner = THIS_MODULE,
},
	.probe = &key4949_probe,
	.id_table = key4949_id,
};

module_i2c_driver(key4949_driver);


MODULE_DESCRIPTION("Keetronics Key 4949 Driver");
MODULE_AUTHOR("Raghavendra Chandra Ganiga <ravi23ganiga@gmail.com>,"
                "Santosh Ramroop Yadav <santosh.yadav@bitcommtechnologies.com >");
MODULE_LICENSE("GPL v2");
MODULE_VERSION(KEETRONICS4949_DRV_VERSION);
