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
