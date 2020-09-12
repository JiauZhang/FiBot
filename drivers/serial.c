#include <wilinker/serial.h>

static struct serial_device *serial_devices;
static struct serial_device *serial_current;

static void serial_null(void)
{
}

#define serial_initfunc(name)   \
	void name(void)             \
		__attribute__((weak, alias("serial_null")));

serial_initfunc(stm32_serial_initialize);

void serial_register(struct serial_device *dev)
{
	dev->next = serial_devices;
	serial_devices = dev;
}

void serial_initialize(void)
{
	stm32_serial_initialize();
}

void serial_stdio_init(void)
{
	// stdio dev
}

int serial_init(void)
{
	// return get_current()->start();
	return 0;
}