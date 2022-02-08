#include <stdint.h>
#include <stdint.h>
#include <drivers/graphics/vbe.h>
#include <drivers/graphics/svga.h>

extern "C" void kernel_main(void)
{
	vbe_initialize();
	drawText(8, 18, L"Hệ điều hành: ", rgb(255, 255, 255));
	drawText(120, 18, L"VNITDos Base 0.1", rgb(0, 255, 0));
	
	while(1);
}