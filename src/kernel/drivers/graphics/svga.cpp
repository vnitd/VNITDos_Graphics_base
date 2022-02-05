#include <drivers/graphics/svga.h>

uint8_t *get_char(wchar_t c);

void fillRect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color)
{
	for(uint16_t i = y; i < y + height; i++)
		for(uint16_t j = x; j < x + width; j++)
			drawPixel(j, i, color);
}

void drawChar(uint16_t x, uint16_t y, wchar_t c, uint32_t color)
{
	const uint8_t* char_array = get_char(c);
	for(uint8_t i = y, j = 0; i < y + 18; i++)
	{
		uint8_t array = char_array[j++];
		uint8_t offset = 7;
		while(array != 0)
		{
			if(array & 1 == 1)
				drawPixel(x + offset, i, color);
			array >>= 1;
			offset--;
		}
	}
}

void drawText(uint16_t x, uint16_t y, const wchar_t* str, uint32_t color)
{
	for(uint32_t i = 0; str[i] != L'\0'; i++)
	{
		drawChar(x + i * 8, y, str[i], color);
	}
}

