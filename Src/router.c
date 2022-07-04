/**
 * @file router.c
 * @brief Display routers.
 * @author de Martimprey Edmond
 * @version 0.1
 * @date 28 june 2022
 *
 * Router is a scrolable list cointaing other router as subrouter to navigate between them.
 *
 */

#include "router.h"

/**
  * @fnvoid init_router(router *r)
  * @brief  Reset struct elem of a router.
  * @note   Need to be executed on every router created, other function check null pointer to know if some element is present or not
  * @param  r : Pointeur to the allocated router struct
  * @retval 0
  */
void init_router(router *r)
{
    for (uint8_t i = 0; i < MAX_NB_ROUTER; i++)
    {
      r->sub_routers[i] = 0;
    }
    for (uint8_t i = 0; i < MAX_NB_ROUTER; i++)
    {
      r->sub_menus[i] = 0;
    }
}

/**
  * @fn uint8_t add_elem_router(router* my_router, router* router_to_add)
  * @brief  Add one router to the router to make subrouter
  * @note   When you display router you will only display router even if you have added menu previously
  * @param  my_router : Pointeur to the allocated router where to add router
  * @param  router_to_add : Pointeur to the router that is added to the list of subrouter
  * @retval 0 : OK 1 : Fail not enough space
  *
  * 
  *
  */
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

/**
  * @fn uint8_t add_elem_router(router* my_router, router* router_to_add)
  * @brief  Add one menu to the router
  * @note   When you display router you will only display menu even if you have added router previously
  * @param  my_router : Pointeur to the allocated router where to add menu
  * @param  menu_to_add : Pointeur to the router that is added to the list of submenu
  * @retval 0 : OK 1 : Fail not enough space
  *
  * 
  *
  */
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

/**
  * @fn void into_router(router *my_router)
  * @brief  When press valid into a menu, go into subrouter or menu
  * @note   If no menu or router added to this router it will do nothing
  * @param  my_router : Pointeur to the allocated router
  * @retval None
  *
  * 
  *
  */
void into_router(router *my_router)
{
  if (my_router->sub_routers[0] != 0)
    {
      if (my_router->pos_router <= MAX_NB_ROUTER && my_router->sub_routers[my_router->pos_router] != NULL)
	{
	  cur_router = my_router->sub_routers[my_router->pos_router];
	  cur_window->router = my_router->sub_routers[my_router->pos_router];
	  cur_window->update_router = 1;
	}
    }
  else if (my_router->sub_menus[0] != 0)
    {
      if (my_router->pos_router <= NB_LINE_ROUTER && my_router->sub_menus[my_router->pos_router] != NULL)
	{
	  cur_menu = my_router->sub_menus[my_router->pos_router];
	  cur_window->update_router = 1;
	}
    }
}

/**
  * @fn void back_router(router *my_router)
  * @brief  When press back into a router or menu, go into uprouter.
  * @note   If no up router just do nothing
  * @param  my_router : Pointeur to the allocated router
  * @retval None
  *
  * 
  *
  */
void back_router(router *my_router)
{
  if (my_router->up_router != 0)
    {
      cur_router = my_router->up_router;
      cur_window->router = cur_router;
    }
  else if (my_router->sub_menus[0] != 0)
    {
      if (my_router->pos_router <= NB_LINE_ROUTER && my_router->sub_menus[my_router->pos_router] != NULL)
	{
	  cur_menu = my_router->sub_menus[my_router->pos_router];
	}
    }
}

/**
  * @fn void router_down(router *my_router)
  * @brief  When press down into a router or menu, scroll one element down
  * @note   None
  * @param  my_router : Pointeur to the allocated router
  * @retval None
  *
  * Scroll one elem to the bottom, if already at the bottom go back to the first element
  *
  */
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
  cur_window->update_router = 1;
}

/**
  * @fn void router_up(router *my_router)
  * @brief  When press down into a router or menu, scroll one element up
  * @note   None
  * @param  my_router : Pointeur to the allocated router
  * @retval None
  *
  * Scroll one elem to the top, if already at the top to go directly to the last element
  *
  */
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
  cur_window->update_router = 1;
}

/**
  * @fn static void fill_one_line_router(uint8_t* str, router* my_router)
  * @brief  Generate one line of the router in str depending the subrouter give in parameter
  * @note   None
  * @param  str String to fill, need to be alocated
  * @param  my_router name of router is extract to generate the line
  * @retval None
  */
static void fill_one_line_router(uint8_t* str, router* my_router)
{
  my_strncpy(str + 1, (*my_router->name)[*p_current_lang], my_strlen((*my_router->name)[*p_current_lang]));
}

/**
  * @fn static void fill_one_line_menu_from_router(uint8_t* str, menu* my_menu)
  * @brief  Generate one line of the menu in str depending the submenu give in parameter
  * @note   None
  * @param  str String to fill, need to be alocated
  * @param  my_router menu of router is extract to generate the line
  * @retval None
  */
static void fill_one_line_menu_from_router(uint8_t* str, menu* my_menu)
{
  my_strncpy(str + 1, (*my_menu->name)[*p_current_lang], my_strlen((*my_menu->name)[*p_current_lang]));
}

/**
  * @fn void display_router(router* my_router, uint16_t x_pos, uint16_t y_pos)
  * @brief  display a router
  * @note   A router is a liste of subrouter, write by increasing X axis and decreasing Y axis, position is at to top left
  * @param  my_router Router to display
  * @param  x : X axis to start display, left of the router
  * @param  y : Y axis to start display, top of the router
  * @retval None
  */
void display_router(router* my_router, uint16_t x_pos, uint16_t y_pos)
{
  x_pos += my_router->router_x;
  y_pos += my_router->router_y;
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
  y_font_pos -= 16;
  if (cur_router == my_router)
    print_str_10x16(str, WHITE, RED);
  else
    print_str_10x16(str, WHITE, STRONG_FONT);
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
		  print_str_10x16(str, WHITE, MENU_HIGHLIGHT_FONT_COLOR);
		}
	      else // If it is not the select elem print it with normal backcolor
		print_str_10x16(str, STRONG_GRAY, (i % 2 ? MENU_PAIR_FONT_COLOR : MENU_UNPAIR_FONT_COLOR));
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
      else
	{
	  fill_string_with_space(str, SIZE_NAME_ROUTER - 1);
	  print_str_10x16(str, BLACK, WHITE);
	}
      y_font_pos -= 18;
   }
}

/**
  * @fn void display_router26(router* my_router, uint16_t x_pos, uint16_t y_pos)
  * @brief  display a router with 16x26 font
  * @note   A router is a liste of subrouter, write by increasing X axis and decreasing Y axis, position is at to top left
  * @param  my_router Router to display
  * @param  x : X axis to start display, left of the router
  * @param  y : Y axis to start display, top of the router
  * @retval None
  */
void display_router26(router* my_router, uint16_t x_pos, uint16_t y_pos)
{
  x_pos += my_router->router_x;
  y_pos += my_router->router_y;
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
  y_font_pos -= 26;
  if (cur_router == my_router)
    print_str_16x26(str, WHITE, RED);
  else
    print_str_16x26(str, WHITE, STRONG_FONT);
  y_font_pos -= 28;
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
		  print_str_16x26(str, WHITE, MENU_HIGHLIGHT_FONT_COLOR);
		}
	      else // If it is not the select elem print it with normal backcolor
		print_str_16x26(str, STRONG_GRAY, (i % 2 ? MENU_PAIR_FONT_COLOR : MENU_UNPAIR_FONT_COLOR));
	      /* add_line_number(str, i + my_router->pos_router); */
	    }
	  else // Print space at the end
	    {
	      fill_string_with_space(str, SIZE_NAME_ROUTER - 1);
	      print_str_16x26(str, BLACK, WHITE);
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
		  /* str[0] = '>'; */
		  print_str_16x26(str, BLACK, YELLOW);
		}
	      else // If it is not the select elem print it with normal backcolor
		print_str_16x26(str, BLACK, WHITE);
	      /* add_line_number(str, i + my_router->pos_router); */
	    }
	  else // Print space at the end
	    {
	      fill_string_with_space(str, SIZE_NAME_ROUTER - 1);
	      print_str_16x26(str, BLACK, WHITE);
	    }
	}
      else
	{
	  fill_string_with_space(str, SIZE_NAME_ROUTER - 1);
	  print_str_16x26(str, BLACK, WHITE);
	}
      y_font_pos -= 28;
   }
}
