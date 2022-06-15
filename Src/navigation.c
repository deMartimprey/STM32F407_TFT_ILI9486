#include "navigation.h"

void nav_up()
{
  if (cur_menu != NULL)
    {
      menu_up(cur_menu);
    }
  else if (cur_router != NULL)
    {
      router_up(cur_router);
    }
}

void nav_down()
{
  if (cur_menu != NULL)
    {
      menu_down(cur_menu);
    }
  else if (cur_router != NULL)
    {
      router_down(cur_router);
    }
}

void nav_right()
{
  if (cur_menu != NULL)
    {
      menu_var_up(cur_menu);
    }
}

void nav_left()
{
  if (cur_menu != NULL)
    {
      menu_var_down(cur_menu);
    }
}

void nav_valid()
{
  if (cur_menu != 0);
  else
    into_router(cur_router);
}

void nav_back()
{
  if (cur_menu != 0)
    cur_menu = 0;
  else
    cur_router = cur_router->up_router;
}

