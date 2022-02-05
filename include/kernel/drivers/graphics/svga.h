#ifndef _DRIVERS_GRAPHICS_SVGA_H
#define _DRIVERS_GRAPHICS_SVGA_H

#include <drivers/graphics/vbe.h>

void drawChar(uint16_t x, uint16_t y, wchar_t c, uint32_t color);
void drawText(uint16_t x, uint16_t y, const wchar_t* str, uint32_t color);
void fillRect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color);

#endif // _DRIVERS_GRAPHICS_SVGA_H
