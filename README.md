# STM32F407_TFT_ILI9486
Driver for ILI9486 on a STM32F407

Simply change the pin in global.h and adapte TFT_Send_A_2Byte_To_TFT_DataPins_register

Compile with make

You can increase a bit the speed by reducing PLLM register in SystemClock_Config()

Current configuration can be wire on an F4 DISCOVERY :

CSX -> PE10 // CS ON MY SCREEN

DCX -> PE9 // RS ON MY SCREEN

WRX -> PE8 // WR ON MY SCREEN

RESX -> PE7 // RESET ON MY SCREEN

D0 -> P0A

D1 -> PA1

D2 -> PA2

D3 -> PA3

D4 -> PA4

D5 -> PA5

D6 -> PA6

D7 -> PA7

D8 -> PC0

D9 -> PC1

D10 -> PC2

D11 -> PC3

D12 -> PB4

D13 -> PB5

D14 -> PB6

D15 -> PB7