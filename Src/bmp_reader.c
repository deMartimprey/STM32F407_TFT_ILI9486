/**
 * @file bmp_reader.c
 * @brief Lib for bmp
 * @author de Martimprey Edmond
 * @version 0.1
 * @date 28 june 2022
 *
 * To read headers and display bmp
 *
 */

#include "bmp_reader.h"

/**
  * @fn uint8_t fill_file_header(BMPFileHeader* header, const uint8_t* f)
  * @brief  Fill file header of a bmp pic
  * @note   None
  * @param  header Pointeur to the allocated header to fill
  * @param  f bmp pic
  * @retval 0
  */
uint8_t fill_file_header(BMPFileHeader* header, const uint8_t* f)
{
  header->file_type = f[MAGIC_NUMBER_OFFSET + 1] << 8 | f[MAGIC_NUMBER_OFFSET];
  header->file_size = f[SIZE_OFFSET + 3] << 24 | f[SIZE_OFFSET + 2] << 16 | f[SIZE_OFFSET + 1] << 8 | f[SIZE_OFFSET];
  header->reserved1 = f[RESERVED1_OFFSET + 1] << 8 | f[RESERVED1_OFFSET];
  header->reserved2 = f[RESERVED2_OFFSET + 1] << 8 | f[RESERVED2_OFFSET];
  header->offset_data = f[PIC_OFFSET + 1] << 8 | f[PIC_OFFSET];
  return 0;
}

/**
  * @fn uint8_t fill_info_header(BMPInfoHeader* header, const uint8_t* f)
  * @brief  Fill file header of a bmp pic
  * @note   None
  * @param  header Pointeur to the allocated header to fill
  * @param  f bmp pic
  * @retval 0
  */
uint8_t fill_info_header(BMPInfoHeader* header, const uint8_t* f)
{
  header->size = f[SIZE_BITMAP_INFO_OFFSET + 3] << 24 | f[SIZE_BITMAP_INFO_OFFSET + 2] << 16 | f[SIZE_BITMAP_INFO_OFFSET + 1] << 8 | f[SIZE_BITMAP_INFO_OFFSET];

  header->width = f[PIXEL_X_OFFSET + 3] << 24 | f[PIXEL_X_OFFSET + 2] << 16 | f[PIXEL_X_OFFSET + 1] << 8 | f[PIXEL_X_OFFSET];

  header->height = f[PIXEL_Y_OFFSET + 3] << 24 | f[PIXEL_Y_OFFSET + 2] << 16 | f[PIXEL_Y_OFFSET + 1] << 8 | f[PIXEL_Y_OFFSET];

  header->planes = f[PLANE_OFFSET + 1] << 8 | f[PLANE_OFFSET];

  header->bit_count = f[BIT_COUNT_OFFSET + 1] << 8 | f[BIT_COUNT_OFFSET];

  header->compression = f[COMPRESSION_OFFSET + 3] << 24 | f[COMPRESSION_OFFSET + 2] << 16 | f[COMPRESSION_OFFSET + 1] << 8 | f[COMPRESSION_OFFSET];

  header->size_image = f[SIZE_PIC_OFFSET + 3] << 24 | f[SIZE_PIC_OFFSET + 2] << 16 | f[SIZE_PIC_OFFSET + 1] << 8 | f[SIZE_PIC_OFFSET];

  header->x_pixels_per_meter = f[PPI_X_OFFSET + 3] << 24 | f[PPI_X_OFFSET + 2] << 16 | f[PPI_X_OFFSET + 1] << 8 | f[PPI_X_OFFSET];

  header->y_pixels_per_meter = f[PPI_Y_OFFSET + 3] << 24 | f[PPI_Y_OFFSET + 2] << 16 | f[PPI_Y_OFFSET + 1] << 8 | f[PPI_Y_OFFSET];

  header->colors_used = f[COLORS_USED_OFFSET + 3] << 24 | f[COLORS_USED_OFFSET + 2] << 16 | f[COLORS_USED_OFFSET + 1] << 8 | f[COLORS_USED_OFFSET];

  header->colors_important = f[COLORS_IMPORTANT_OFFSET + 3] << 24 | f[COLORS_IMPORTANT_OFFSET + 2] << 16 | f[COLORS_IMPORTANT_OFFSET + 1] << 8 | f[COLORS_IMPORTANT_OFFSET];
  return 0;
}

/**
  * @fn uint8_t fill_color_header(BMPInfoHeader* header, const uint8_t* f)
  * @brief  Fill color header of a bmp pic
  * @note   None
  * @param  header Pointeur to the allocated header to fill
  * @param  f bmp pic
  * @retval 0
  */
uint8_t fill_color_header(BMPInfoHeader* header, const uint8_t* f)
{
  return 0;
}

/**
  * @fn uint16_t find_one_pixel_bmp(BMPFileHeader* Fileheader, BMPInfoHeader* Infoheader, const uint8_t* f, uint16_t x_pos, uint16_t y_pos)
  * @brief  find and return the color on a pixel in a bmp depending location x and y
  * @note   None
  * @param  FileHeader Pointeur to the file header info
  * @param  Infoheader Pointeur to the info header info
  * @param  f bmp pic
  * @param  x X axis of the pixel to find
  * @param  y Y axis of the pixel to find
  * @param  f bmp pic
  * @retval None
  */
uint16_t find_one_pixel_bmp(BMPFileHeader* Fileheader, BMPInfoHeader* Infoheader, const uint8_t* f, uint16_t x_pos, uint16_t y_pos)
{
  const uint8_t* ptr_pic;

  ptr_pic = f + Fileheader->offset_data;
  const uint8_t* horizontal_line = (ptr_pic + y_pos * Infoheader->width * 2);
  uint16_t* place_pixel = (uint16_t*)(horizontal_line + x_pos * 2);
  return *place_pixel;
}

/**
  * @fn uint8_t display_bmp(BMPFileHeader* Fileheader, BMPInfoHeader* Infoheader, const uint8_t* f, uint16_t x_pos, uint16_t y_pos)
  * @brief  find and return the color on a pixel in a bmp depending location x and y
  * @note   None
  * @param  FileHeader Pointeur to the file header info
  * @param  Infoheader Pointeur to the info header info
  * @param  f bmp pic
  * @param  x X axis of the pixel to find
  * @param  y Y axis of the pixel to find
  * @retval None
  */
uint8_t display_bmp(BMPFileHeader* Fileheader, BMPInfoHeader* Infoheader, const uint8_t* f, uint16_t x_pos, uint16_t y_pos)
{
  uint8_t x_size = Infoheader->width;
  uint8_t y_size = Infoheader->height;
  uint16_t pixel;

  for (uint16_t y = 0; y < y_size; y++)
    {
      for (uint16_t x = 0; x < x_size; x++)
	{
	  pixel = find_one_pixel_bmp(Fileheader, Infoheader, f, x, y);
	  write_one_pixel(x_pos + x, y_pos + y, pixel);
	}
    }
  return 0;
}

/**
  * @fn uint8_t display_bmp_from_window(bmp* bmp, uint16_t x_pos, uint16_t y_pos)

  * @brief  Display bmp from bmp structure and the offset
  * @note   None
  * @param  bmp Pointeur to the bmp structure that contain all the necessary information
  * @param  x_pos X axis of bmp offset
  * @param  y_pos Y axis of bmp offset
  * @retval None
  */
uint8_t display_bmp_from_window(bmp* bmp, uint16_t x_pos, uint16_t y_pos)
{
  BMPFileHeader h = {0, };
  BMPInfoHeader hi = {0, };

  fill_file_header(&h, bmp->file);
  fill_info_header(&hi, bmp->file);

  return display_bmp(&h, &hi, bmp->file, x_pos + bmp->x_pos, y_pos + bmp->y_pos);
}

/**
  * @fn uint8_t update_bmp_from_window(bmp* bmp, uint16_t x_pos, uint16_t y_pos)

  * @brief  Display bmp from bmp structure and the offset only if update element is 1
  * @note   None
  * @param  bmp Pointeur to the bmp structure that contain all the necessary information
  * @param  x_pos X axis of bmp offset
  * @param  y_pos Y axis of bmp offset
  * @retval None
  */
uint8_t update_bmp_from_window(bmp* bmp, uint16_t x_pos, uint16_t y_pos)
{
  BMPFileHeader h = {0, };
  BMPInfoHeader hi = {0, };

  if (bmp->update == 1)
    {
      fill_file_header(&h, bmp->file);
      fill_info_header(&hi, bmp->file);

      return display_bmp(&h, &hi, bmp->file, x_pos + bmp->x_pos, y_pos + bmp->y_pos);
    }
  return 0;
}
