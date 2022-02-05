#include <stdint.h>
#include <stdint.h>
#include <drivers/graphics/vbe.h>
#include <drivers/graphics/svga.h>

extern "C" void kernel_main(void)
{
	vbe_initialize();
	// for(uint8_t i = 0; i < 0x20; i++)
	// 	drawChar(i * 8, 0, i, rgb(255, 255, 255));
	// drawText(0, 18, L" !\"#$%&'()*+,-./0123456789:;<=>?", rgb(255, 255, 255));
	// drawText(0, 36, L"@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_", rgb(255, 255, 255));
	// drawText(0, 54, L"`abcdefghijklmnopqrstuvwxyz{|}~\x7f", rgb(255, 255, 255));
	drawText(10, 54, L"ÁÀẢÃẠ ĂẮẰẲẴẶ ÂẤẦẨẪẬ Đ ÉÈẺẼẸ ÊẾỀỂỄỆ ÍÌỈĨỊ ÓÒỎÕỌ ÔỐỒỔỖỘ ƠỚỜỞỠỢ ÚÙỦŨỤ ƯỨỪỬỮỰ ÝỲỶỸỴ", rgb(255, 255, 255));
	drawText(10, 90, L"áàảãạ ăắằẳẵặ âấầẩẫậ đ éèẻẽẹ êếềểễệ íìỉĩị óòỏõọ ôốồổỗộ ơớờởỡợ úùủũụ ưứừửữự ýỳỷỹỵ", rgb(255, 255, 255));
	
	while(1) {}
}