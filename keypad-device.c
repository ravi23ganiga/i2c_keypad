#include <linux/init.h>
#include <linux/module.h>
#include <linux/i2c.h>

static const struct i2c_board_info key4949_devs = {
	I2C_BOARD_INFO("keetronics-key4949", 0x60),
	//.platform_data = &wm8996_pdata,
	/* TODO find interrupt number */
	.irq = 2,
}

static int __init
hello_init(void)
{
	struct i2c_client *client;

#if 0
	/* TODO Find adapter number */
	i2c_register_board_info(1, key4949_devs, ARRAY_SIZE(key4949_devs));
#else
	/* TODO Find adapter number */
	client = i2c_new_device (i2c_get_adapter(2), &key4949_devs);
	if(client ==  NULL)
		return -ENODEV;
#endif
}

static void __exit
hello_exit(void)
{
}


module_init(key_init);
module_exit(key_exit);

MODULE_DESCRIPTION("Keetronics Key 4949 Device");
MODULE_AUTHOR("Raghavendra Chandra Ganiga <ravi23ganiga@gmail.com>,"
                "Santosh Ramroop Yadav <santosh.yadav@bitcommtechnologies.com >");
MODULE_LICENSE("GPL v2");
MODULE_VERSION("0.8");
