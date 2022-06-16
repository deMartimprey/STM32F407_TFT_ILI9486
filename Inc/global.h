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
} menu;


extern var* var0;
extern var* var1;
extern var* var2;
extern var* var3;
extern var* var4;

extern var* current_lang; // current lang will be modified to parameter
extern int32_t* p_current_lang;

#define SIZE_NAME_ROUTER 20
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
};

extern router* cur_router; // Position in menu and submenu sytem
extern menu* cur_menu; // Position in menu and submenu sytem

// Strings const static so its stay on the rom and don't go in the ram

const static uint8_t s_router_1[NB_LANG][SIZE_NAME_VAR] =
{
 "Sous menu 1",
 "Sub menu 1"
};

const static uint8_t s_router_2[NB_LANG][SIZE_NAME_VAR] =
{
 "Sous menu 2",
 "Sub menu 2"
};

const static uint8_t s_router_3[NB_LANG][SIZE_NAME_VAR] =
{
 "Sous menu 3",
 "Sub menu 3"
};

const static uint8_t s_router_4[NB_LANG][SIZE_NAME_VAR] =
{
 "Sous menu 4",
 "Sub menu 4"
};

const static uint8_t s_router_5[NB_LANG][SIZE_NAME_VAR] =
{
 "Sous menu 5",
 "Sub menu 5"
};

const static uint8_t s_router_6[NB_LANG][SIZE_NAME_VAR] =
{
 "Sous menu 6",
 "Sub menu 6"
};

const static uint8_t s_router_7[NB_LANG][SIZE_NAME_VAR] =
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

#ifdef __cplusplus
}
#endif

#endif /* __GLOBAL_H */
