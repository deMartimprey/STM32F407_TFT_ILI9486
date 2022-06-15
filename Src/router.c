#include "router.h"

// Add a pointer of another router in a router for making subrouters
uint8_t add_elem_router(router* my_router, router* router_to_add)
{
  // If we ecced the size of pointer tab we don't add the router otherwise it will probably cause memory probleme
  if (my_router->size >= MAX_NB_ROUTER)
    return 1;
  my_router->sub_menus[0] = 0; // pointer null, router only display other router
  my_router->sub_routers[my_router->size] = router_to_add;
  my_router->size += 1;
  return 0;
}

// Add a pointer of another menu in a router for making submenus
uint8_t add_menu_router(router* my_router, menu* menu_to_add)
{
  // If we ecced the size of pointer tab we don't add the router otherwise it will probably cause memory probleme
  if (my_router->size >= MAX_NB_ROUTER)
    return 1;
  my_router->sub_routers[0] = 0; // pointer null, router only display menu
  my_router->sub_menus[my_router->size] = menu_to_add;
  my_router->size += 1;
  return 0;
}

void into_router(router *my_router)
{
  if (my_router->sub_routers[0] != 0)
    {
      if (my_router->pos_router <= MAX_NB_ROUTER && my_router->sub_routers[my_router->pos_router] != NULL)
	{
	  cur_router = my_router->sub_routers[my_router->pos_router];
	}
    }
  else if (my_router->sub_menus[0] != 0)
    {
      if (my_router->pos_router <= NB_LINE_ROUTER && my_router->sub_menus[my_router->pos_router] != NULL)
	{
	  cur_menu = my_router->sub_menus[my_router->pos_router];
	}
    }
}

// Scroll one elem to the bottom, if already at the bottom go back to the first element
void router_down(router *my_router)
{
  if (my_router->pos_router == 0)
    {
      my_router->pos_router = my_router->size - 1;
      my_router->first_elem_pos = my_router->size - 1;
      my_router->arrow_pos = 0;
    }
  else
    {
      my_router->pos_router -= 1;

      if (my_router->arrow_pos > 0)
	my_router->arrow_pos -= 1;
      else if (my_router->first_elem_pos > 0)
	my_router->first_elem_pos -= 1;
    }
}

// Scroll one elem to the top, if already at the top to go directly to the last element
void router_up(router *my_router)
{
  if (my_router->pos_router >= my_router->size - 1)
    {
      my_router->arrow_pos = 0;
      my_router->first_elem_pos = 0;
      my_router->pos_router = 0;
      return;
    }
  else
    {
      my_router->pos_router += 1;
      if (my_router->arrow_pos < NB_LINE_ROUTER - 1)
	my_router->arrow_pos += 1;
      else
	my_router->first_elem_pos += 1;
    }
}

static void fill_one_line_router(uint8_t* str, router* my_router)
{
  my_strncpy(str + 1, (*my_router->name)[*p_current_lang], my_strlen((*my_router->name)[*p_current_lang]));
}

static void fill_one_line_menu_from_router(uint8_t* str, menu* my_menu)
{
  my_strncpy(str + 1, (*my_menu->name)[*p_current_lang], my_strlen((*my_menu->name)[*p_current_lang]));
}

void display_router(router* my_router, uint16_t x_pos, uint8_t y_pos)
{
  if (cur_menu != 0)
    {
      display_menu(cur_menu, x_pos, y_pos);
      return;
    }
  uint8_t str[SIZE_NAME_ROUTER] = {0, };

  x_font_pos = x_pos;
  y_font_pos = y_pos;
  if (my_router == NULL)
    return;
  fill_string_with_space(str, SIZE_NAME_ROUTER - 1);
  my_strncpy((uint8_t*)str, (uint8_t*)my_router->name[*p_current_lang], my_strlen((uint8_t*)my_router->name[*p_current_lang]));
  print_str_10x16(str, BLACK, 0x9DDF);
  y_font_pos -= 18;
  for (uint8_t i = 0; i < NB_LINE_ROUTER; i++) // For the number of router elem we want to display
    {
      x_font_pos = x_pos;
      if (my_router->sub_routers[0] != 0)
	{
	  if (i + my_router->first_elem_pos < my_router->size && my_router->sub_routers[my_router->first_elem_pos + i] != NULL) // If the elem we display + the offset the first elem we display doesn't exed the size of the router elem tab, check if the pointeur is not null
	    {
	      fill_string_with_space(str, SIZE_NAME_ROUTER - 1);
	      fill_one_line_router(str, my_router->sub_routers[my_router->first_elem_pos + i]);
	      if (i == my_router->arrow_pos) // If this is the element seleted we display it with highlight with different backcolor
		{
		  str[0] = '>';
		  print_str_10x16(str, BLACK, YELLOW);
		}
	      else // If it is not the select elem print it with normal backcolor
		print_str_10x16(str, BLACK, WHITE);
	      /* add_line_number(str, i + my_router->pos_router); */
	    }
	  else // Print space at the end
	    {
	      fill_string_with_space(str, SIZE_NAME_ROUTER - 1);
	      print_str_10x16(str, BLACK, WHITE);
	    }
	}
      else if (my_router->sub_menus[0] != 0)
	{
	  if (i + my_router->first_elem_pos < my_router->size && my_router->sub_menus[my_router->first_elem_pos + i] != NULL) // If the elem we display + the offset the first elem we display doesn't exed the size of the router elem tab, check if the pointeur is not null

	    {
	      fill_string_with_space(str, SIZE_NAME_ROUTER - 1);
	      fill_one_line_menu_from_router(str, my_router->sub_menus[my_router->first_elem_pos + i]);
	      if (i == my_router->arrow_pos) // If this is the element seleted we display it with highlight with different backcolor
		{
		  str[0] = '>';
		  print_str_10x16(str, BLACK, YELLOW);
		}
	      else // If it is not the select elem print it with normal backcolor
		print_str_10x16(str, BLACK, WHITE);
	      /* add_line_number(str, i + my_router->pos_router); */
	    }
	  else // Print space at the end
	    {
	      fill_string_with_space(str, SIZE_NAME_ROUTER - 1);
	      print_str_10x16(str, BLACK, WHITE);
	    }
	}
      y_font_pos -= 18;
   }
}
