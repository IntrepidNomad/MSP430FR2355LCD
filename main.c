

/* --COPYRIGHT--,BSD
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/

#include "inc/hw_memmap.h"
#include "grlib.h"
#include "Sharp128x128.h"
#include "HAL_MSP_EXP430FR2355_Sharp128x128.h"
#include "images.h"
#include "driverlib.h"
#include "stdint.h"
#include <msp430.h> 

void init_CS(void);
void boardInit();
void timerInit();
void Delay(void);

tContext g_sContext;
tRectangle g_sRect;
tRectangle myRectangle1 = { 5, 15, 65, 45};
tRectangle myRectangle2 = { 10, 40, 90, 90};
tRectangle myRectangle3 = { 0, 0, 95, 95};
uint8_t g_delayCounter = 0;

void main(void)
{

    boardInit();
    init_CS();
    timerInit();


    // Set up the LCD
    HAL_LCD_initDisplay();

    /*
     * Disable the GPIO power-on default high-impedance mode to activate
     * previously configured port settings
     */



    __enable_interrupt();

    GrContextInit(&g_sContext, &g_sharp128x128LCD);
    GrContextForegroundSet(&g_sContext, ClrBlack);
    GrContextBackgroundSet(&g_sContext, ClrWhite);
    GrContextFontSet(&g_sContext, &g_sFontFixed6x8);
    GrClearDisplay(&g_sContext);
    GrFlush(&g_sContext);

    // Intro Screen
    GrStringDrawCentered(&g_sContext,
                         "How to use",
                         AUTO_STRING_LENGTH,
                         48,
                         15,
                         TRANSPARENT_TEXT);
    GrStringDrawCentered(&g_sContext,
                         "the MSP430",
                         AUTO_STRING_LENGTH,
                         48,
                         35,
                         TRANSPARENT_TEXT);
    GrStringDraw(&g_sContext,
                 "Graphics Library",
                 AUTO_STRING_LENGTH,
                 1,
                 51,
                 TRANSPARENT_TEXT);
    GrStringDrawCentered(&g_sContext,
                         "Primitives",
                         AUTO_STRING_LENGTH,
                         48,
                         75,
                         TRANSPARENT_TEXT);

    GrFlush(&g_sContext);
    Delay();
    GrClearDisplay(&g_sContext);

    // Draw pixels and lines on the display
    GrStringDrawCentered(&g_sContext,
                         "Draw Pixels",
                         AUTO_STRING_LENGTH,
                         48,
                         5,
                         TRANSPARENT_TEXT);
    GrStringDrawCentered(&g_sContext,
                         "& Lines",
                         AUTO_STRING_LENGTH,
                         48,
                         15,
                         TRANSPARENT_TEXT);
    GrPixelDraw(&g_sContext, 30, 30);
    GrPixelDraw(&g_sContext, 30, 32);
    GrPixelDraw(&g_sContext, 32, 32);
    GrPixelDraw(&g_sContext, 32, 30);
    GrLineDraw(&g_sContext, 35, 35, 90, 90);
    GrLineDraw(&g_sContext, 5, 80, 80, 20);
    GrLineDraw(&g_sContext,
               0,
               GrContextDpyHeightGet(&g_sContext) - 1,
               GrContextDpyWidthGet(&g_sContext) - 1,
               GrContextDpyHeightGet(&g_sContext) - 1);
    GrFlush(&g_sContext);
    Delay();
    GrClearDisplay(&g_sContext);

    // Draw circles on the display_
    GrStringDraw(&g_sContext,
                 "Draw Circles",
                 AUTO_STRING_LENGTH,
                 10,
                 5,
                 TRANSPARENT_TEXT);
    GrCircleDraw(&g_sContext,
                 30,
                 70,
                 20);
    GrCircleFill(&g_sContext,
                 60,
                 50,
                 30);
    GrFlush(&g_sContext);
    Delay();
    GrClearDisplay(&g_sContext);

    // Draw rectangles on the display
    GrStringDrawCentered(&g_sContext,
                         "Draw Rectangles",
                         AUTO_STRING_LENGTH,
                         48,
                         5,
                         TRANSPARENT_TEXT);
    GrRectDraw(&g_sContext, &myRectangle1);
    GrRectFill(&g_sContext, &myRectangle2);
    // Text below won't be visible on screen due to transparency
    // (foreground colors match)
    GrStringDrawCentered(&g_sContext,
                         "Normal Text",
                         AUTO_STRING_LENGTH,
                         50,
                         50,
                         TRANSPARENT_TEXT);
    // Text below draws foreground and background for opacity
    GrStringDrawCentered(&g_sContext,
                         "Opaque Text",
                         AUTO_STRING_LENGTH,
                         50,
                         65,
                         OPAQUE_TEXT);
    GrContextForegroundSet(&g_sContext, ClrWhite);
    GrContextBackgroundSet(&g_sContext, ClrBlack);
    GrStringDrawCentered(&g_sContext,
                         "Invert Text",
                         AUTO_STRING_LENGTH,
                         50,
                         80,
                         TRANSPARENT_TEXT);
    GrFlush(&g_sContext);
    Delay();

    // Invert the foreground and background colors
    GrContextForegroundSet(&g_sContext, ClrBlack);
    GrContextBackgroundSet(&g_sContext, ClrWhite);
    GrRectFill(&g_sContext, &myRectangle3);
    GrContextForegroundSet(&g_sContext, ClrWhite);
    GrContextBackgroundSet(&g_sContext, ClrBlack);
    GrStringDrawCentered(&g_sContext,
                         "Invert Colors",
                         AUTO_STRING_LENGTH,
                         48,
                         5,
                         TRANSPARENT_TEXT);
    GrRectDraw(&g_sContext, &myRectangle1);
    GrRectFill(&g_sContext, &myRectangle2);
    // Text below won't be visible on screen due to
    // transparency (foreground colors match)
    GrStringDrawCentered(&g_sContext,
                         "Normal Text",
                         AUTO_STRING_LENGTH,
                         50,
                         50,
                         TRANSPARENT_TEXT);
    // Text below draws foreground and background for opacity
    GrStringDrawCentered(&g_sContext,
                         "Opaque Text",
                         AUTO_STRING_LENGTH,
                         50,
                         65,
                         OPAQUE_TEXT);
    // Text below draws with inverted foreground color to become visible
    GrContextForegroundSet(&g_sContext, ClrBlack);
    GrContextBackgroundSet(&g_sContext, ClrWhite);
    GrStringDrawCentered(&g_sContext,
                         "Invert Text",
                         AUTO_STRING_LENGTH,
                         50,
                         80,
                         TRANSPARENT_TEXT);
    GrFlush(&g_sContext);
    Delay();
    GrContextForegroundSet(&g_sContext, ClrBlack);
    GrContextBackgroundSet(&g_sContext, ClrWhite);
    GrClearDisplay(&g_sContext);

    // Draw Images on the display
    GrImageDraw(&g_sContext, &LPRocket_96x37_1BPP_UNCOMP, 3, 28);
    GrFlush(&g_sContext);
    Delay();
    GrClearDisplay(&g_sContext);
    GrImageDraw(&g_sContext, &TI_Logo_69x64_1BPP_UNCOMP, 15, 15);
    GrFlush(&g_sContext);

    __bis_SR_register(LPM0_bits+GIE);


}

void init_CS(void) {
    // Configure two FRAM waitstate as required by the device datasheet for MCLK
    // operation at 24MHz(beyond 8MHz) _before_ configuring the clock system.
    FRCTL0 = FRCTLPW | NWAITS_2 ;

    P2SEL1 |= BIT6 | BIT7;                       // P2.6~P2.7: crystal pins
    do
    {
        CSCTL7 &= ~(XT1OFFG | DCOFFG);           // Clear XT1 and DCO fault flag
        SFRIFG1 &= ~OFIFG;
    } while (SFRIFG1 & OFIFG);                   // Test oscillator fault flag

    __bis_SR_register(SCG0);                     // disable FLL
    CSCTL3 |= SELREF__XT1CLK;                    // Set XT1 as FLL reference source
    CSCTL0 = 0;                                  // clear DCO and MOD registers
    CSCTL1 = DCORSEL_7;                         // Set DCO = 24MHz
    CSCTL2 = FLLD_0 + 731;                       // DCOCLKDIV = 24MHz
    __delay_cycles(3);
    __bic_SR_register(SCG0);                     // enable FLL
    while(CSCTL7 & (FLLUNLOCK0 | FLLUNLOCK1));   // FLL locked

    CSCTL4 = SELMS__DCOCLKDIV | SELA__XT1CLK;   // set XT1 (~32768Hz) as ACLK source, ACLK = 32768Hz
                                                 // default DCOCLKDIV as MCLK and SMCLK source

    P3DIR |= BIT4;
    P3SEL0 |= BIT4;
    P3SEL1 &= ~BIT4;
}

void boardInit()
{

        GPIO_setAsOutputPin(GPIO_PORT_PA, GPIO_PIN_ALL16);
        GPIO_setAsOutputPin(GPIO_PORT_PB, GPIO_PIN_ALL16);
        GPIO_setAsOutputPin(GPIO_PORT_PC, GPIO_PIN_ALL16);
        GPIO_setAsOutputPin(GPIO_PORT_PD, GPIO_PIN_ALL16);
        GPIO_setAsOutputPin(GPIO_PORT_PE, GPIO_PIN_ALL16);

        GPIO_setOutputLowOnPin(GPIO_PORT_PA, GPIO_PIN_ALL16);
        GPIO_setOutputLowOnPin(GPIO_PORT_PB, GPIO_PIN_ALL16);
        GPIO_setOutputLowOnPin(GPIO_PORT_PC, GPIO_PIN_ALL16);
        GPIO_setOutputLowOnPin(GPIO_PORT_PD, GPIO_PIN_ALL16);
        GPIO_setOutputLowOnPin(GPIO_PORT_PE, GPIO_PIN_ALL16);

    PMM_unlockLPM5();
}

void timerInit()
{
    Timer_B_initUpModeParam param = {0};
    param.clockSource = TIMER_B_CLOCKSOURCE_SMCLK;
    param.clockSourceDivider = TIMER_B_CLOCKSOURCE_DIVIDER_64;
    param.timerPeriod = 65535-1;
    param.timerInterruptEnable_TBIE = TIMER_B_TBIE_INTERRUPT_ENABLE;
    param.captureCompareInterruptEnable_CCR0_CCIE =
            TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE;
    param.timerClear = TIMER_B_SKIP_CLEAR;
    param.startTimer = false;
    Timer_B_initUpMode(TIMER_B1_BASE, &param);

    Timer_B_initCompareModeParam initComp1Param = {0};
    initComp1Param.compareRegister = TIMER_B_CAPTURECOMPARE_REGISTER_1;
    initComp1Param.compareInterruptEnable =
            TIMER_B_CAPTURECOMPARE_INTERRUPT_DISABLE;
    initComp1Param.compareOutputMode = TIMER_B_OUTPUTMODE_OUTBITVALUE;
    initComp1Param.compareValue = 62500;
    Timer_B_initCompareMode(TIMER_B1_BASE, &initComp1Param);

    Timer_B_startCounter(TIMER_B1_BASE,
            TIMER_B_UP_MODE
                        );
}


void Delay(void)
{
    //Reset delayCounter
    g_delayCounter=0;

    Timer_B_enableCaptureCompareInterrupt(TIMER_B1_BASE,
            TIMER_B_CAPTURECOMPARE_REGISTER_1);

    Timer_B_clear(TIMER_B1_BASE);

    // Enter Low Power Mode 0 with Global Interrupts Enabled
    __bis_SR_register(LPM0_bits+GIE);

    Timer_B_disableCaptureCompareInterrupt(TIMER_B1_BASE,
                TIMER_B_CAPTURECOMPARE_REGISTER_1);

}

//------------------------------------------------------------------------------
// Timer1 B0 Interrupt Service Routine
//------------------------------------------------------------------------------
#pragma vector=TIMER1_B0_VECTOR
__interrupt void TIMER1_B0_ISR (void)
{

    Sharp128x128_SendToggleVCOMCommand();

    // Add Offset to TBCCR0
    Timer_B_setCompareValue(TIMER_B1_BASE,
                          TIMER_B_CAPTURECOMPARE_REGISTER_0,
                          Timer_B_getCaptureCompareCount(
                                  TIMER_B1_BASE,
                                  TIMER_B_CAPTURECOMPARE_REGISTER_0)+(65535-1));

    Timer_B_clearCaptureCompareInterrupt(TIMER_B1_BASE,
            TIMER_B_CAPTURECOMPARE_REGISTER_0);

    Timer_B_clearTimerInterrupt(TIMER_B1_BASE);


}

//------------------------------------------------------------------------------
// Timer1 B1 Interrupt Service Routine. This ISR id use to generate delay on
// LCD before changing screen content. The ISR is triggered every 500 msec.
//------------------------------------------------------------------------------
#pragma vector=TIMER1_B1_VECTOR
__interrupt void TIMER1_B1_ISR (void)
{

    g_delayCounter++;

    // Add Offset to TBCCR0
    Timer_B_setCompareValue(TIMER_B1_BASE,
                            TIMER_B_CAPTURECOMPARE_REGISTER_1,
                            Timer_B_getCaptureCompareCount(
                            TIMER_B1_BASE,
                            TIMER_B_CAPTURECOMPARE_REGISTER_1)+(62500));

    // If 5 seconds have elapsed, exit LPM0 mode
    if(g_delayCounter==10){
        __bic_SR_register_on_exit(LPM0_bits);
    }

    Timer_B_clearCaptureCompareInterrupt(TIMER_B1_BASE,
                TIMER_B_CAPTURECOMPARE_REGISTER_1);

    Timer_B_clearTimerInterrupt(TIMER_B1_BASE);

}




