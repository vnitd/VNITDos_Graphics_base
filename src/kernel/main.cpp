#include <stdint.h>
#include <drivers/graphics/vbe.h>

extern "C" void kernel_main(void)
{
	vbe_initialize();

	// drawPixel(10, 10, 0x00ff00ff);
	
	while(1);
}