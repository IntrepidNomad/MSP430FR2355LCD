//*****************************************************************************
//
// HAL_MSP-EXP430FR2355_Sharp128x128.h - Prototypes for the Sharp128x128
//                  LCD display driver. There is no output from Sharp128x128 LCD
//
//                   MSP430FR2355                 LCD Sharp128x128
//                -----------------             -----------------
//               |     P4.5/UCB1CLK|---------> |SPI_CLK  EXT_MODE|--GND
//            /|\|                 |           |            	 |
//             | |    P4.6/UCB1SIMO|---------> |SPI_SI   EXTCOMIN|--GND
//             --|RST              |           |              	 |
//               |             P5.2|---------> |SPI_CS           |
//               |             	   |		   |         	     |
//               |             P3.6|---------> |DISP             |
//               |                 |		   |                 |
//               |             P1.5|-----*---> |VDD              |
//               |                 |      `--> |VDDA             |
//               |                 |            -----------------
//                -----------------
//*****************************************************************************

#include <stdint.h>
#ifndef __HAL_MSP_EXP430FR2355_SHARPLCD_H__
#define __HAL_MSP_EXP430FR2355_SHARPLCD_H__


//*****************************************************************************
//
// User Configuration for the LCD Driver
//
//*****************************************************************************

// Ports from MSP430 connected to LCD
#define LCD_SPI_SI_PORT                     GPIO_PORT_P4 //
#define LCD_SPI_CLK_PORT                    GPIO_PORT_P4 //
#define LCD_DISP_PORT                       GPIO_PORT_P3 //
#define LCD_POWER_PORT                      GPIO_PORT_P1 //
#define LCD_SPI_CS_PORT	                    GPIO_PORT_P5 //

// Pins from MSP430 connected to LCD
#define LCD_SPI_SI_PIN                      GPIO_PIN6
#define LCD_SPI_SI_PIN_FUNCTION             GPIO_PRIMARY_MODULE_FUNCTION
#define LCD_SPI_CLK_PIN                     GPIO_PIN5
#define LCD_SPI_CLK_PIN_FUNCTION            GPIO_PRIMARY_MODULE_FUNCTION
#define LCD_DISP_PIN                        GPIO_PIN6
#define LCD_POWER_PIN                       GPIO_PIN5
#define LCD_SPI_CS_PIN                      GPIO_PIN2

// Definition of USCI base address to be used for SPI communication
#define LCD_EUSCI_BASE		      EUSCI_B1_BASE


// Non-volatile Memory used to store DisplayBuffer
#define NON_VOLATILE_MEMORY_BUFFER


//*****************************************************************************
//
// Prototypes for the globals exported by this driver.
//
//*****************************************************************************
extern void HAL_LCD_initDisplay(void);
extern void HAL_LCD_writeCommandOrData(uint16_t command);
extern void HAL_LCD_clearCS(void);
extern void HAL_LCD_setCS(void);
extern void HAL_LCD_prepareMemoryWrite(void);
extern void HAL_LCD_finishMemoryWrite(void);
extern void HAL_LCD_waitUntilLcdWriteFinish(void);
extern void HAL_LCD_disableDisplay(void);
extern void HAL_LCD_enableDisplay(void);


#endif // __HAL_MSP_EXP430FR2355_SHARPLCD_H__
