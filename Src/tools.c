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

void fill_string_with_space(uint8_t* str, uint8_t size)
{
  for (uint8_t i = 0; i < size; i++)
    str[i] = ' ';
}
