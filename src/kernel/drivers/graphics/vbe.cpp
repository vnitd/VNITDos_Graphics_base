#include <drivers/graphics/vbe.h>

vbe_info *info;
vbe_mode_info *mode_info;
uint32_t* framebuffer;
uint16_t width, height;
uint8_t red_pos, green_pos, blue_pos;

void vbe_initialize()
{
	info = (vbe_info*) 0x8400;
	mode_info = (vbe_mode_info*) 0x8600;
	width = mode_info->width;
	height = mode_info->height;
	framebuffer = (uint32_t*)mode_info->framebuffer;
	red_pos = mode_info->red_position;
	blue_pos = mode_info->blue_position;
	green_pos = mode_info->green_position;
}

void drawPixel(uint16_t x, uint16_t y, uint32_t color)
{
	framebuffer[y * width + x] = color;
}

uint32_t rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return (r << red_pos) | (g << green_pos) | (b << blue_pos);
}
