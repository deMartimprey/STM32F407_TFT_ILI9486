#ifndef __GLOBAL_H
#define __GLOBAL_H

#define BLUE_Pin GPIO_PIN_15
#define BLUE_GPIO_Port GPIOD

#define RED_Pin GPIO_PIN_14
#define RED_GPIO_Port GPIOD

#define ORANGE_Pin GPIO_PIN_13
#define ORANGE_GPIO_Port GPIOD

#define GREEN_Pin GPIO_PIN_12
#define GREEN_GPIO_Port GPIOD

#define TFT_CSX_Pin GPIO_PIN_10 // CS ON MY SCREEN
#define TFT_CSX_GPIO_Port GPIOE

#define TFT_DCX_Pin GPIO_PIN_9 // RS ON MY SCREEN
#define TFT_DCX_GPIO_Port GPIOE

#define TFT_WRX_Pin GPIO_PIN_8 // WR ON MY SCREEN
#define TFT_WRX_GPIO_Port GPIOE

#define TFT_RESX_Pin GPIO_PIN_7 // RESET ON MY SCREEN
#define TFT_RESX_GPIO_Port GPIOE

#define TFT_D0_Pin GPIO_PIN_0
#define TFT_D0_GPIO_Port GPIOA

#define TFT_D1_Pin GPIO_PIN_1
#define TFT_D1_GPIO_Port GPIOA

#define TFT_D2_Pin GPIO_PIN_2
#define TFT_D2_GPIO_Port GPIOA

#define TFT_D3_Pin GPIO_PIN_3
#define TFT_D3_GPIO_Port GPIOA

#define TFT_D4_Pin GPIO_PIN_4
#define TFT_D4_GPIO_Port GPIOA

#define TFT_D5_Pin GPIO_PIN_5
#define TFT_D5_GPIO_Port GPIOA

#define TFT_D6_Pin GPIO_PIN_6
#define TFT_D6_GPIO_Port GPIOA

#define TFT_D7_Pin GPIO_PIN_7
#define TFT_D7_GPIO_Port GPIOA

#define TFT_D8_Pin GPIO_PIN_0
#define TFT_D8_GPIO_Port GPIOC

#define TFT_D9_Pin GPIO_PIN_1
#define TFT_D9_GPIO_Port GPIOC

#define TFT_D10_Pin GPIO_PIN_2
#define TFT_D10_GPIO_Port GPIOC

#define TFT_D11_Pin GPIO_PIN_3
#define TFT_D11_GPIO_Port GPIOC

#define TFT_D12_Pin GPIO_PIN_4
#define TFT_D12_GPIO_Port GPIOB

#define TFT_D13_Pin GPIO_PIN_5
#define TFT_D13_GPIO_Port GPIOB

#define TFT_D14_Pin GPIO_PIN_6
#define TFT_D14_GPIO_Port GPIOB

#define TFT_D15_Pin GPIO_PIN_7
#define TFT_D15_GPIO_Port GPIOB

#define USE_5X7
#define USE_10X16
#define USE_16X26

#define X_SIZE	480
#define Y_SIZE	320

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define ORANGE  0xFCC0

#define NICE_GREEN 0xFCC0
#define STRONG_GRAY 0x630C

#define FONT_COLOR			0xBF1C
#define STRONG_FONT			0x3C72
#define FONT_TEXT			0xE7FF
#define MENU_PAIR_FONT_COLOR		0xE79E
#define MENU_UNPAIR_FONT_COLOR		0xF7DF
#define MENU_HIGHLIGHT_FONT_COLOR	0x3193
#define MENU_STRONG_COLOR		0x0398

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"

extern TIM_HandleTypeDef htim_timer;

#ifdef USE_5X7
extern uint16_t x_font_pos; // X position start for writing strings
extern uint16_t y_font_pos; // Y position start for writing strings
#endif /* USE_5X7 */

#ifdef USE_RAM_BUFFER
extern uint16_t buffer[X_SIZE][Y_SIZE]; // Not enough place
#endif /* USE_RAM_BUFFER */

#define NB_LANG 2 // Number of lang availble for menu
#define FR 0 // French by default, sorry
#define EN 1 // English

  // Define for VAR, struct that cointain all information for 1 parameter
#define NB_VAR		        40 // Nb of var allocated
#define SIZE_NAME_VAR	        20 // Max name size of a VAR
#define NB_NAME_VAR_MENU	5 // Max of String possible if parameter is display as stromg
#define SIZE_NAME_VAR_MENU	20 // Max if string size if parameter is display as soze
#define DIGIT_TYPE		0 // Pointer null to menu_var mean this var (parameter is display a number)
#define NAME_TYPE		1 // Value display as string

#define RECTANGLE	0
#define FRAME		1
#define DOT		2
#define CIRCLE		3

#define SIZE_TEXT 20

typedef struct draw draw;

struct draw
{
  uint8_t type;
  uint16_t x_pos;
  uint16_t y_pos;
  uint16_t x_size; // r in case of circle or dot
  uint16_t y_size; // use only rectangle or frame
  uint16_t thickness; // Frame only
  uint16_t color;
  uint8_t update;
};

typedef struct text text;

struct text
{
  uint8_t (*str)[NB_LANG][SIZE_TEXT];
  uint16_t text_x;
  uint16_t text_y;
  uint8_t update;
};

typedef struct
{
  uint16_t id; // Unique id of var(parameter) increment of 1 each time a new one is created
  uint8_t type; // 0 Digit ; 1 list of string
  int32_t min; // Min value
  int32_t max; // Max value
  int32_t value; // Current Value
#ifdef USE_EEPROM
  uint16_t eeprom_addr; // Address in the eeprom
  eeprom *link_eeprom; // Link to a struc of the eeprom it is register
#endif /* USE_EEPROM */
  const uint8_t (*name)[NB_LANG][SIZE_NAME_VAR]; // Name
  const uint8_t (*menu_var)[NB_LANG][NB_NAME_VAR_MENU][SIZE_NAME_VAR_MENU]; // List of string in case the paramaters is display as string, value 0 is menu_var[0], value 1 is menu_var[1] l...
  uint8_t update;
} var;

#define MAX_SIZE_MENU	        20 // Number of parameter max in one menu
#define SIZE_NAME_MENU		20 // Max size of a menu name
extern var vars[NB_VAR];

typedef struct router router;

// Menu contain list of vars that can change value
typedef struct
{
  const uint8_t (*name)[NB_LANG][SIZE_NAME_MENU]; // Name of the menu
  uint8_t pos_menu; // Current position in the menu
  uint8_t size; // Size of the menu
  uint8_t arrow_pos; // Position of highlight / selected paramter
  uint8_t first_elem_pos; // First parameter display, used for better scrolling experience
  router* up_router; // Router when press the back button, if null no router is up the current
  var* vars[MAX_SIZE_MENU]; // list of parameter
  uint16_t menu_x; // offset x
  uint16_t menu_y; // offset y
  uint8_t update;
} menu;

extern var* var0;
extern var* var1;
extern var* var2;
extern var* var3;
extern var* var4;

extern var* current_lang; // current lang will be modified to parameter
extern int32_t* p_current_lang;

#define SIZE_NAME_ROUTER 18
#define MAX_NB_ROUTER 20
#define NB_LINE_ROUTER 4


// A router is a menu that contain other router or menu
struct router
{
  const uint8_t (*name)[NB_LANG][SIZE_NAME_ROUTER]; // Name in menu
  uint8_t pos_router; // Actual position in the liste of router
  uint8_t size; // size for scrolling gestion and give a tab position when new submenu is added
  uint8_t arrow_pos; // position of arrow or highlight
  uint8_t first_elem_pos; // if there is scrolling beacuse it doesn't fit
  router* up_router; // Router when press the back button, if null no router is up the current
  router* sub_routers[MAX_NB_ROUTER]; // list of other router that make the liste to display, null if contains menus
  menu* sub_menus[MAX_NB_ROUTER]; // list of menu to display null, if containt routers
  uint16_t router_x; // offset x
  uint16_t router_y; // offset y
  uint8_t update;
};

typedef struct view view;

typedef struct window window;

#define MAX_WINDOW_PER_VIEW 5
#define MAX_NB_TEXT_PER_WINDOWS 5
#define MAX_NB_DRAW_PER_WINDOWS 5
#define MAX_NB_ROUTER_PER_WINDOWS 1

struct window
{
  uint16_t window_size_x;
  uint16_t window_size_y;
  uint16_t window_x;
  uint16_t window_y;
  window* window_up;
  window* window_down;
  window* window_right;
  window* window_left;
  window* window_back;
  router* router[MAX_NB_ROUTER_PER_WINDOWS];
  menu* menu;
  text *text[MAX_NB_TEXT_PER_WINDOWS];
  draw *draw[MAX_NB_DRAW_PER_WINDOWS];
  uint8_t update;
};

struct view
{
  window* windows[MAX_WINDOW_PER_VIEW];
  window* cur_window;
  uint16_t view_x;
  uint16_t view_y;
  uint8_t update;
  view* view_back;
};

extern router* cur_router; // Position in menu and submenu sytem
extern menu* cur_menu; // Position in menu and submenu sytem
extern view* cur_view;
extern window* cur_window;

extern uint8_t pressed_down;
extern uint8_t pressed_up;
extern uint8_t pressed_left;
extern uint8_t pressed_right;
extern uint8_t pressed_valid;
extern uint8_t pressed_back;

// Strings const static so its stay on the rom and don't go in the ram

const static uint8_t s_router_1[NB_LANG][SIZE_NAME_ROUTER] =
{
 "Sous menu 1",
 "Sub menu 1"
};

const static uint8_t s_router_2[NB_LANG][SIZE_NAME_ROUTER] =
{
 "Sous menu 2",
 "Sub menu 2"
};

const static uint8_t s_router_3[NB_LANG][SIZE_NAME_ROUTER] =
{
 "Sous menu 3",
 "Sub menu 3"
};

const static uint8_t s_router_4[NB_LANG][SIZE_NAME_ROUTER] =
{
 "Sous menu 4",
 "Sub menu 4"
};

const static uint8_t s_router_5[NB_LANG][SIZE_NAME_ROUTER] =
{
 "Sous menu 5",
 "Sub menu 5"
};

const static uint8_t s_router_6[NB_LANG][SIZE_NAME_ROUTER] =
{
 "Sous menu 6",
 "Sub menu 6"
};

const static uint8_t s_router_7[NB_LANG][SIZE_NAME_ROUTER] =
{
 "Sous menu 7",
 "Sub menu 7"
};

const static uint8_t s_menu1[NB_LANG][SIZE_NAME_VAR] =
{
  "MENU_1",
  "MENU_1"
};

const static uint8_t s_menu2[NB_LANG][SIZE_NAME_VAR] =
{
  "MENU_2",
  "MENU_2"
};

const static uint8_t s_lang[NB_LANG][SIZE_NAME_VAR] =
{
  "LANG",
  "LANG"
};

const static uint8_t s_var1[NB_LANG][SIZE_NAME_VAR] =
{
  "VAR1_FR",
  "VAR1_EN"
};

const static uint8_t s_var2[NB_LANG][SIZE_NAME_VAR] =
{
  "VAR2_FR",
  "VAR2_EN"
};

const static uint8_t s_var3[NB_LANG][SIZE_NAME_VAR] =
{
  "VAR3_FR",
  "VAR3_EN"
};

const static uint8_t s_var4[NB_LANG][SIZE_NAME_VAR] =
{
  "VAR4_FR",
  "VAR4_EN"
};

const static uint8_t t_1_w1_v1[NB_LANG][SIZE_TEXT] =
{
  "text1FR",
  "text1EN"
};

const static uint8_t t_2_w1_v1[NB_LANG][SIZE_TEXT] =
{
  "text2FR",
  "text2EN"
};

#ifdef __cplusplus
}
#endif

#endif /* __GLOBAL_H */
