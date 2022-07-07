#ifndef __BMP_READER_H
#define __BMP_READER_H

#include "stm32f4xx_hal.h"
#include "ili9486.h"
#include "tools.h"

#define MAGIC_NUMBER_OFFSET	0x00
#define SIZE_OFFSET		0x02
#define RESERVED1_OFFSET	0x06
#define RESERVED2_OFFSET	0x08
#define PIC_OFFSET		0x0A
#define SIZE_BITMAP_INFO_OFFSET	0x0E
#define PIXEL_X_OFFSET		0x12
#define PIXEL_Y_OFFSET		0x16
#define PLANE_OFFSET		0x1A
#define BIT_COUNT_OFFSET	0x1C
#define COMPRESSION_OFFSET	0x1E
#define SIZE_PIC_OFFSET		0x22
#define PPI_X_OFFSET		0x26
#define PPI_Y_OFFSET		0x2A
#define COLORS_USED_OFFSET	0x2E
#define COLORS_IMPORTANT_OFFSET	0x32

void Error_Handler(void);

typedef struct {
  uint16_t file_type;	            // File type always BM which is 0x4D42
  uint32_t file_size;               // Size of the file (in bytes)
  uint16_t reserved1;               // Reserved, always 0
  uint16_t reserved2;               // Reserved, always 0
  uint32_t offset_data;             // Start position of pixel data (bytes from the beginning of the file)
} BMPFileHeader;

typedef struct {
  uint32_t size;                      // Size of this header (in bytes)
  int32_t width;                      // width of bitmap in pixels
  int32_t height;                     // width of bitmap in pixels
  //       (if positive, bottom-up, with origin in lower left corner)
  //       (if negative, top-down, with origin in upper left corner)
  uint16_t planes;                    // No. of planes for the target device, this is always 1
  uint16_t bit_count;                 // No. of bits per pixel
  uint32_t compression;               // 0 or 3 - uncompressed. THIS PROGRAM CONSIDERS ONLY UNCOMPRESSED BMP images
  uint32_t size_image;                // 0 - for uncompressed images
  int32_t x_pixels_per_meter;
  int32_t y_pixels_per_meter;
  uint32_t colors_used;               // No. color indexes in the color table. Use 0 for the max number of colors allowed by bit_count
  uint32_t colors_important;          // No. of colors used for displaying the bitmap. If 0 all colors are required
} BMPInfoHeader;

typedef struct {
  uint32_t red_mask;         // Bit mask for the red channel
  uint32_t green_mask;       // Bit mask for the green channel
  uint32_t blue_mask;        // Bit mask for the blue channel
  uint32_t alpha_mask;       // Bit mask for the alpha channel
  uint32_t color_space_type; // Default "sRGB" (0x73524742)
  uint32_t unused[16];       // Unused data for sRGB color space
} BMPColorHeader;

uint8_t fill_file_header(BMPFileHeader* header, const uint8_t* f);
uint8_t fill_info_header(BMPInfoHeader* header, const uint8_t* f);
uint8_t fill_color_header(BMPInfoHeader* header, const uint8_t* f);
uint8_t display_bmp(BMPFileHeader* Fileheader, BMPInfoHeader* Infoheader, const uint8_t* f, uint16_t x_pos, uint16_t y_pos);
uint16_t find_one_pixel_bmp(BMPFileHeader* Fileheader, BMPInfoHeader* Infoheader, const uint8_t* f, uint16_t x_pos, uint16_t y_pos);
uint8_t display_bmp_from_window(bmp* bmp, uint16_t x_pos, uint16_t y_pos);
uint8_t update_bmp_from_window(bmp* bmp, uint16_t x_pos, uint16_t y_pos);

#endif /* __BMP_READER_H */
