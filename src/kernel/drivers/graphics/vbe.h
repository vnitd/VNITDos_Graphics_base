#ifndef _DRIVERS_GRAPHICS_VBE_H
#define _DRIVERS_GRAPHICS_VBE_H

#include <stdint.h>

typedef struct vbe_info_structure
{
	uint8_t vbe_signature[4];
	uint16_t vbe_version;
	uint32_t oem_string_pointer;
	uint32_t capabilities;
	uint32_t video_mode_pointer;
	uint16_t total_memory;
	uint16_t oem_software_version;
	uint32_t oem_vendor_name_pointer;
	uint32_t oem_product_name_pointer;
	uint32_t oem_product_rev_pointer;
	uint8_t reseved[222];
	uint8_t oem_data[256];
}__attribute__((packed)) vbe_info;

typedef struct vbe_mode_info_structure
{
	// Mandatory info for all VBE revisions
	uint16_t attributes;		// deprecated, only bit 7 should be of interest to you, and it indicates the mode supports a linear frame buffer.
	uint8_t window_a;			// deprecated
	uint8_t window_b;			// deprecated
	uint16_t granularity;		// deprecated; used while calculating bank numbers
	uint16_t window_size;
	uint16_t segment_a;
	uint16_t segment_b;
	uint32_t win_func_ptr;		// deprecated; used to switch banks from protected mode without returning to real mode
	uint16_t pitch;			// number of bytes per horizontal line

	// Mandatory info for VBE 1.2 and above
	uint16_t width;			// width in pixels
	uint16_t height;			// height in pixels
	uint8_t w_char;			// unused...
	uint8_t y_char;			// ...
	uint8_t planes;
	uint8_t bpp;			// bits per pixel in this mode
	uint8_t banks;			// deprecated; total number of banks in this mode
	uint8_t memory_model;
	uint8_t bank_size;		// deprecated; size of a bank, almost always 64 KB but may be 16 KB...
	uint8_t image_pages;
	uint8_t reserved0;
 
	// Direct color fields (required for direct/6 and YUV/7 memory models)
	uint8_t red_mask;
	uint8_t red_position;
	uint8_t green_mask;
	uint8_t green_position;
	uint8_t blue_mask;
	uint8_t blue_position;
	uint8_t reserved_mask;
	uint8_t reserved_position;
	uint8_t direct_color_attributes;
	
	// Mandatory info for VBE 2.0 and above
	uint32_t framebuffer;		// physical address of the linear frame buffer; write here to draw to the screen
	uint32_t off_screen_mem_off;
	uint16_t off_screen_mem_size;	// size of memory in the framebuffer but not being displayed on the screen

	// Mandatory info for VBE 3.0 and above
	uint16_t linear_bytes_per_scan_line;
	uint8_t bank_number_of_image_pages;
	uint8_t linear_numberofimage_pages;
	uint8_t linear_red_mask_size;
	uint8_t linear_red_field_position;
	uint8_t linear_green_mask_size;
	uint8_t linear_greenfield_position;
	uint8_t linear_blue_mask_size;
	uint8_t linear_blue_field_position;
	uint8_t linear_reserved_mask_size;
	uint8_t linear_res_field_position;
	uint32_t max_pixel_clock;

	uint8_t reserved1[190];
} __attribute__((packed)) vbe_mode_info;

extern vbe_info *info;
extern vbe_mode_info *mode_info;

void vbe_initialize();
void drawPixel(uint16_t x, uint16_t y, uint32_t color);
uint32_t rgb(uint8_t r, uint8_t g, uint8_t b);

#endif // _DRIVERS_GRAPHICS_VBE_H
