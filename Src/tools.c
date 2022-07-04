/**
 * @file menu.c
 * @brief Various function.
 * @author de Martimprey Edmond
 * @version 0.1
 * @date 28 june 2022
 *
 * Various function non classable or copy of the stdlib
 *
 */

#include "tools.h"

uint16_t my_strlen(const uint8_t *s)
{
  uint16_t len = 0;

  if (s == 0)
    return 0;
  while (*s++ /* increment to next character every loop */ != '\0')
    {
      len++;
    }
  return len;
}

void			my_memcpy(void *dest, void *src, int size)
{
  char			*ptr_dest;
  char			*ptr_src;
  int			i;

  i = 0;
  ptr_dest = (char *)dest;
  ptr_src = (char *)src;
  while (i < size)
    {
      ptr_dest[i] = ptr_src[i];
      i += 1;
    }
}

uint8_t* my_strncpy(dst, src, n)
     uint8_t *dst;
     const uint8_t *src;
     register int n;
{
  if (n != 0) {
    register uint8_t *d = dst;
    register const uint8_t *s = src;

    do {
      if ((*d++ = *s++) == 0) {
	/* NUL pad the remaining n-1 bytes */
	while (--n != 0)
          *d++ = 0;
	break;
      }
    } while (--n != 0);
  }
  return (dst);
}

static void reverse(uint8_t * str)
{
  if (str)
    {
      uint8_t * end = str + my_strlen((uint8_t*)str) - 1;

      // swap the values in the two given variables
      // XXX: fails when a and b refer to same memory location
#   define XOR_SWAP(a,b) do			\
	{					\
	  a ^= b;				\
	  b ^= a;				\
	  a ^= b;				\
	} while (0)

      // walk inwards from both ends of the string,
	   // swapping until we get to the middle
	while (str < end)
	  {
	    XOR_SWAP(*str, *end);
	    str++;
	    end--;
	  }
#   undef XOR_SWAP
    }
}

static uint8_t* itoa(uint32_t num, uint8_t* str, uint16_t base)
{
    uint16_t i = 0;
    uint16_t isNegative = 0;

    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }

    // If number is negative, append '-'
    if (isNegative == 1)
        str[i++] = '-';
    str[i] = '\0'; // Append string terminator

        // Reverse the string
    reverse(str);

    return str;
}

void num32ToString(uint8_t* str, uint32_t nb)
{
  // clear the string with space
  for (int i = 0; i < 10; i++)
    str[i] = ' ';
  // convert nbStart into string to be able
  // to display it on LCD
  itoa(nb, (uint8_t *)str, 10);
  // if null value replace by a space
  for (int i = 0; i < 9; i++)
    if (str[i] == 0)
      str[i] = ' ';
}

//https://stackoverflow.com/questions/2442576/how-does-one-convert-16-bit-rgb565-to-24-bit-rgb888
uint32_t convert565_to_888(uint16_t color565)
{
  uint32_t R8, G8, B8 = 0;
  float R5, G6, B5 = 0;
  uint32_t RGB888 = 0;

  R5 = (float) ((color565 & 0b1111100000000000) >> 11);
  G6 = (float) ((color565 & 0b0000011111100000) >> 5);
  B5 = (float) ((color565 & 0b0000000000011111) >> 0);
  /* R8 = ( R5 * 527 + 23 ) >> 6; */
  /* G8 = ( G6 * 259 + 33 ) >> 6; */
  /* B8 = ( B5 * 527 + 23 ) >> 6; */
  R8 = (int) floor( R5 * 255.0 / 31.0 + 0.5);
  G8 = (int) floor( G6 * 255.0 / 63.0 + 0.5);
  B8 = (int) floor( R5 * 255.0 / 31.0 + 0.5);

  RGB888 |= R8 << 16;
  RGB888 |= G8 << 8;
  RGB888 |= B8 << 0;
}

//https://stackoverflow.com/questions/2442576/how-does-one-convert-16-bit-rgb565-to-24-bit-rgb888
uint16_t convert888_to_565(uint32_t color888)
{
  uint32_t R8, G8, B8 = 0;
  uint8_t R5, G6, B5 = 0;
  uint16_t RGB565 = 0;

  R8 = ((color888 & 0b00000000111111110000000000000000) >> 16);
  G8 = ((color888 & 0b00000000000000001111111100000000) >> 8);
  B8 = ((color888 & 0b00000000000000000000000011111111) >> 0);

  R5 = ( R8 * 249 + 1014 ) >> 11;
  G6 = ( G8 * 253 +  505 ) >> 10;
  B5 = ( B8 * 249 + 1014 ) >> 11;

  RGB565 |= R5 << 11;
  RGB565 |= G6 << 5;
  RGB565 |= B5 << 0;
}
