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

