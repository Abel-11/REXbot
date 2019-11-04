/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F45K22
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_AN0 aliases
#define channel_AN0_TRIS                 TRISAbits.TRISA0
#define channel_AN0_LAT                  LATAbits.LATA0
#define channel_AN0_PORT                 PORTAbits.RA0
#define channel_AN0_ANS                  ANSELAbits.ANSA0
#define channel_AN0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_AN0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_AN0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_AN0_GetValue()           PORTAbits.RA0
#define channel_AN0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_AN0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_AN0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define channel_AN0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set channel_AN1 aliases
#define channel_AN1_TRIS                 TRISAbits.TRISA1
#define channel_AN1_LAT                  LATAbits.LATA1
#define channel_AN1_PORT                 PORTAbits.RA1
#define channel_AN1_ANS                  ANSELAbits.ANSA1
#define channel_AN1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define channel_AN1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define channel_AN1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define channel_AN1_GetValue()           PORTAbits.RA1
#define channel_AN1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define channel_AN1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define channel_AN1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define channel_AN1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set channel_AN2 aliases
#define channel_AN2_TRIS                 TRISAbits.TRISA2
#define channel_AN2_LAT                  LATAbits.LATA2
#define channel_AN2_PORT                 PORTAbits.RA2
#define channel_AN2_ANS                  ANSELAbits.ANSA2
#define channel_AN2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define channel_AN2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define channel_AN2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define channel_AN2_GetValue()           PORTAbits.RA2
#define channel_AN2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define channel_AN2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define channel_AN2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define channel_AN2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set channel_AN4 aliases
#define channel_AN4_TRIS                 TRISAbits.TRISA5
#define channel_AN4_LAT                  LATAbits.LATA5
#define channel_AN4_PORT                 PORTAbits.RA5
#define channel_AN4_ANS                  ANSELAbits.ANSA5
#define channel_AN4_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define channel_AN4_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define channel_AN4_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define channel_AN4_GetValue()           PORTAbits.RA5
#define channel_AN4_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define channel_AN4_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define channel_AN4_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define channel_AN4_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set channel_AN11 aliases
#define channel_AN11_TRIS                 TRISBbits.TRISB4
#define channel_AN11_LAT                  LATBbits.LATB4
#define channel_AN11_PORT                 PORTBbits.RB4
#define channel_AN11_WPU                  WPUBbits.WPUB4
#define channel_AN11_ANS                  ANSELBbits.ANSB4
#define channel_AN11_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define channel_AN11_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define channel_AN11_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define channel_AN11_GetValue()           PORTBbits.RB4
#define channel_AN11_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define channel_AN11_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define channel_AN11_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define channel_AN11_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define channel_AN11_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define channel_AN11_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set channel_AN13 aliases
#define channel_AN13_TRIS                 TRISBbits.TRISB5
#define channel_AN13_LAT                  LATBbits.LATB5
#define channel_AN13_PORT                 PORTBbits.RB5
#define channel_AN13_WPU                  WPUBbits.WPUB5
#define channel_AN13_ANS                  ANSELBbits.ANSB5
#define channel_AN13_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define channel_AN13_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define channel_AN13_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define channel_AN13_GetValue()           PORTBbits.RB5
#define channel_AN13_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define channel_AN13_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define channel_AN13_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define channel_AN13_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define channel_AN13_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define channel_AN13_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set IO_RC1 aliases
#define IO_RC1_TRIS                 TRISCbits.TRISC1
#define IO_RC1_LAT                  LATCbits.LATC1
#define IO_RC1_PORT                 PORTCbits.RC1
#define IO_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IO_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IO_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IO_RC1_GetValue()           PORTCbits.RC1
#define IO_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set IO_RC2 aliases
#define IO_RC2_TRIS                 TRISCbits.TRISC2
#define IO_RC2_LAT                  LATCbits.LATC2
#define IO_RC2_PORT                 PORTCbits.RC2
#define IO_RC2_ANS                  ANSELCbits.ANSC2
#define IO_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_RC2_GetValue()           PORTCbits.RC2
#define IO_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_RC2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define IO_RC2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set IO_RC3 aliases
#define IO_RC3_TRIS                 TRISCbits.TRISC3
#define IO_RC3_LAT                  LATCbits.LATC3
#define IO_RC3_PORT                 PORTCbits.RC3
#define IO_RC3_ANS                  ANSELCbits.ANSC3
#define IO_RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define IO_RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define IO_RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define IO_RC3_GetValue()           PORTCbits.RC3
#define IO_RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define IO_RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define IO_RC3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define IO_RC3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set IO_RC7 aliases
#define IO_RC7_TRIS                 TRISCbits.TRISC7
#define IO_RC7_LAT                  LATCbits.LATC7
#define IO_RC7_PORT                 PORTCbits.RC7
#define IO_RC7_ANS                  ANSELCbits.ANSC7
#define IO_RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define IO_RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define IO_RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define IO_RC7_GetValue()           PORTCbits.RC7
#define IO_RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define IO_RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define IO_RC7_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define IO_RC7_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set IO_RD0 aliases
#define IO_RD0_TRIS                 TRISDbits.TRISD0
#define IO_RD0_LAT                  LATDbits.LATD0
#define IO_RD0_PORT                 PORTDbits.RD0
#define IO_RD0_ANS                  ANSELDbits.ANSD0
#define IO_RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define IO_RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define IO_RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define IO_RD0_GetValue()           PORTDbits.RD0
#define IO_RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define IO_RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define IO_RD0_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define IO_RD0_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set RD1 procedures
#define RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RD1_GetValue()              PORTDbits.RD1
#define RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RD1_SetAnalogMode()         do { ANSELDbits.ANSD1 = 1; } while(0)
#define RD1_SetDigitalMode()        do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set IO_RD2 aliases
#define IO_RD2_TRIS                 TRISDbits.TRISD2
#define IO_RD2_LAT                  LATDbits.LATD2
#define IO_RD2_PORT                 PORTDbits.RD2
#define IO_RD2_ANS                  ANSELDbits.ANSD2
#define IO_RD2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define IO_RD2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define IO_RD2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define IO_RD2_GetValue()           PORTDbits.RD2
#define IO_RD2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define IO_RD2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define IO_RD2_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define IO_RD2_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set IO_RD4 aliases
#define IO_RD4_TRIS                 TRISDbits.TRISD4
#define IO_RD4_LAT                  LATDbits.LATD4
#define IO_RD4_PORT                 PORTDbits.RD4
#define IO_RD4_ANS                  ANSELDbits.ANSD4
#define IO_RD4_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define IO_RD4_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define IO_RD4_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define IO_RD4_GetValue()           PORTDbits.RD4
#define IO_RD4_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define IO_RD4_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define IO_RD4_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define IO_RD4_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set RE2 procedures
#define RE2_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define RE2_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define RE2_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define RE2_GetValue()              PORTEbits.RE2
#define RE2_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define RE2_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define RE2_SetAnalogMode()         do { ANSELEbits.ANSE2 = 1; } while(0)
#define RE2_SetDigitalMode()        do { ANSELEbits.ANSE2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/