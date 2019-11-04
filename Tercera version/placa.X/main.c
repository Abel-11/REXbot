/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F45K22
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#define LED                             LATC7 
#define PWMA                            LATE2
#define AIN2                            LATC2
#define AIN1                            LATC3
#define STBY                            LATC1
#define BIN1                            LATD0
#define BIN2                            LATD2
#define PWMB                            LATD1

//#define KP      1
//#define KD      0
float KP = 0.8;
float KD = 10;
#define VELOCIDAD   750
#define VELOCIDAD_RECTA 1000
#define MAXIMO_REGISTRO_ANALOGICO       1023
#define MINIMO_REGISTRO_ANALOGICO       0
#define MUESTRAS_CALIBRACION            30000

void encender_motores();
void apagar_motores();
void mover_motor_A(signed int velocidad);
void mover_motor_B(signed int velocidad);
void parada();
void moverse(signed int velocidad_A, signed int velocidad_B);
void calibracion();
void lectura_precalibracion();
void leer_sensores();
float calculo_PID();

bit flag_recta;

int sensor[8];
int sensor_max[8];
int sensor_min[8];
int media_blanco[8];
/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    LED = 1;
  //  printf("comenzamos transmision");
    int velocidad_avance = VELOCIDAD;
    int velocidad_motor_A = 0, velocidad_motor_B = 0;
    char anterior = 1;
    char inicio;
    float correccion;
    int extra_arriba_A, extra_arriba_B,extra_abajo_B, extra_abajo_A;
    int correccion_entera;
    encender_motores();
    lectura_precalibracion();
    calibracion();
    LED = 0;
    while(PORTBbits.RB1);
    for(inicio = 0; inicio < 50; inicio++)
    {
        LED =~ LED;
        __delay_ms(100);
    }
    while (1)
    {
    /*    if(PORTBbits.RB2)
        {
            if(PORTBbits.RB1 == 0 && anterior)
            {
                anterior = 0;
                KD = KD+0.05;
            }else if(PORTBbits.RB1 == 1 && !anterior)
            {
                anterior = 1;
            }
        }else
        {
            if(PORTBbits.RB1 == 0 && anterior)
            {
                anterior = 0;
                KP = KP-0.05;
            }else if(PORTBbits.RB1 == 1 && !anterior)
            {
                anterior = 1;
            }
        }
        */
       
       while(!(TMR4_HasOverflowOccured()));
       
       correccion = calculo_PID();
       correccion_entera = (int)correccion;
       
       if(flag_recta)
           velocidad_avance = VELOCIDAD_RECTA;
       else
           velocidad_avance = VELOCIDAD;
       
       velocidad_motor_A = velocidad_avance - correccion_entera;
       velocidad_motor_B = velocidad_avance + correccion_entera;
        
       //printf("%f       %i   %i", correccion, velocidad_motor_A, velocidad_motor_B);
      //  printf("\r\n");
        
       if(velocidad_motor_A > 1023)
       {
           extra_abajo_B = velocidad_motor_A - 1023;
           velocidad_motor_B = velocidad_motor_B - extra_abajo_B;
       }else if(velocidad_motor_B > 1023)
       {
           extra_abajo_A = velocidad_motor_B - 1023;
           velocidad_motor_A = velocidad_motor_A - extra_abajo_A;
       }else if(velocidad_motor_A < 40)
       {
           extra_arriba_B = 40 - velocidad_motor_A;
           velocidad_motor_B = velocidad_motor_B + extra_arriba_B;
       }else if(velocidad_motor_B < 40)
       {
           extra_arriba_A = 40 - velocidad_motor_B;
           velocidad_motor_A = velocidad_motor_A + extra_arriba_A;
       }
     //  apagar_motores();
        moverse(velocidad_motor_A,velocidad_motor_B);
    //    printf("Velocidad_A: %i   velocidad_B: %i   error: %f \r\n",velocidad_motor_A,velocidad_motor_B, correccion);
     //   LED =~ LED;
      
    }
    
    
}

void encender_motores()
{
    STBY = 1;
}
void apagar_motores()
{
    STBY = 0;
}
void mover_motor_A(signed int velocidad)
{
    if (velocidad > 1023)
        velocidad = 1023;
    else if (velocidad < -1023)
        velocidad = -1023;
    
    if(velocidad >= 0)
    {
        AIN1 = 1;
        AIN2 = 0;
    }else
    {
        AIN1 = 0;
        AIN2 = 1;
        velocidad = velocidad * (-1);
    }


    PWM5_LoadDutyValue(velocidad);
}
void mover_motor_B(signed int velocidad)
{
    if (velocidad > 1023)
        velocidad = 1023;
    else if (velocidad < -1023)
        velocidad = -1023;
    
    if(velocidad >= 0)
    {
        BIN1 = 1;
        BIN2 = 0;
    }else
    {
        BIN1 = 0;
        BIN2 = 1;
        velocidad = velocidad * (-1);
    }

    PWM4_LoadDutyValue(velocidad);
}
void parada()
{
    AIN1 = 0;
    AIN2 = 0;

    PWM5_LoadDutyValue(0);
    
    BIN1 = 0;
    BIN2 = 0;

    PWM4_LoadDutyValue(0);
}
void moverse(signed int velocidad_A, signed int velocidad_B)
{
    mover_motor_A(velocidad_A);
    mover_motor_B(velocidad_B);
}
float calculo_PID()
{
    float correccion;
    static float last_error;
    float valor_proporcional, valor_diferencial;
    float error;
    char valores_digitales[8];
    char numero_sensor, valor_digital;
   
    leer_sensores();
  /*  for(numero_sensor = 0; numero_sensor < 8; numero_sensor++)
    {
        printf("%i   ", sensor[numero_sensor]);
       
    } printf("\r\n");*/
    
    error = -3 * sensor[0] - 2 * sensor[1] - sensor[2] + sensor[3] + 2 * sensor[4] + 3 * sensor[5];
    
    error = ((error - (-4200)) * (1000 - (-1000)) / (4200 - (-4200))) - 1000;
    
    valor_digital = 0;
    
    for(numero_sensor = 0; numero_sensor < 6; numero_sensor++)
    {
        if(sensor[numero_sensor] > media_blanco[numero_sensor])
            valores_digitales[numero_sensor] = 1;
        else
            valores_digitales[numero_sensor] = 0;
        valor_digital = valor_digital + valores_digitales[numero_sensor];
    }
    /* for(numero_sensor = 0; numero_sensor < 6; numero_sensor++)
    {
         printf("Digital:%i  Sensor:%i  blanco:%i\r\n ",valores_digitales[numero_sensor],sensor[numero_sensor], media_blanco[numero_sensor]);
    }printf("------------------------------");*/
    if((valor_digital == 0 || valor_digital == 6) && last_error < 0)
        error = -1000;
    else if((valor_digital == 0 || valor_digital == 6) && last_error > 0)
        error = 1000;
    if(valor_digital == 2 && valores_digitales[2] && valores_digitales[3])
        flag_recta = 1;
    else
        flag_recta = 0;
        
    
    valor_proporcional = ((float)error)*KP;
    valor_diferencial = (error - last_error) * KD;
    
    correccion = valor_proporcional + valor_diferencial;
    
   /* printf("error:%f      last error:%f   dig:%i", error, last_error  , valor_digital);
       printf("\r\n");*/
    last_error = error;
     
    
    return correccion;
}
void leer_sensores()
{
    int lectura_sin_calibrar[8];
    char numero_sensor;
    ADC_GetConversion(11);
    ADC_GetConversion(13);
    ADC_GetConversion(11);
    ADC_GetConversion(13);
  
    lectura_sin_calibrar[0] = ADC_GetConversion(11);
    lectura_sin_calibrar[1] = ADC_GetConversion(13);
    lectura_sin_calibrar[2] = ADC_GetConversion(4);
    lectura_sin_calibrar[3] = ADC_GetConversion(0);
    lectura_sin_calibrar[4] = ADC_GetConversion(1);
    lectura_sin_calibrar[5] = ADC_GetConversion(2);
  
    
   
  /*  for(numero_sensor = 0; numero_sensor < 6; numero_sensor++)
    {
        printf("%i   ", lectura_sin_calibrar[numero_sensor]);
       
    } printf("\r\n");*/
    
    for(numero_sensor = 0; numero_sensor < 6; numero_sensor++)
    {
        sensor[numero_sensor] = ((lectura_sin_calibrar[numero_sensor] - sensor_min[numero_sensor]) * (int)((1023) / (sensor_max[numero_sensor] - sensor_min[numero_sensor]))); 
        if(sensor[numero_sensor] < sensor_min[numero_sensor])
            sensor[numero_sensor] = sensor_min[numero_sensor];
        else if(sensor[numero_sensor] > sensor_max[numero_sensor])
            sensor[numero_sensor] = sensor_max[numero_sensor];
       /* printf("sensor:%i  lsin calibrar:%i  min:%i  max:%i",sensor[numero_sensor], lectura_sin_calibrar[numero_sensor], sensor_min[numero_sensor],sensor_max[numero_sensor]);
        printf("\r\n");*/
    }//printf("---------------------------------------------\r\n");
   /* for(numero_sensor = 0; numero_sensor < 6; numero_sensor++)
    {
        printf("%i   ", sensor[numero_sensor]);
       
    } printf("\r\n");*/
    

}

void calibracion()
{
    unsigned long int repeticiones_calibrado;
    char numero_sensor;
    int lectura_sin_calibrar[8];
    
    lectura_sin_calibrar[0] = ADC_GetConversion(11);
    lectura_sin_calibrar[1] = ADC_GetConversion(13);
    lectura_sin_calibrar[2] = ADC_GetConversion(4);
    lectura_sin_calibrar[3] = ADC_GetConversion(0);
    lectura_sin_calibrar[4] = ADC_GetConversion(1);
    lectura_sin_calibrar[5] = ADC_GetConversion(2);
    
    for(repeticiones_calibrado = 0; repeticiones_calibrado < MUESTRAS_CALIBRACION; repeticiones_calibrado++)
    {
        lectura_sin_calibrar[0] = ADC_GetConversion(11);
        lectura_sin_calibrar[1] = ADC_GetConversion(13);
        lectura_sin_calibrar[2] = ADC_GetConversion(4);
        lectura_sin_calibrar[3] = ADC_GetConversion(0);
        lectura_sin_calibrar[4] = ADC_GetConversion(1);
        lectura_sin_calibrar[5] = ADC_GetConversion(2);
        for(numero_sensor = 0; numero_sensor < 6; numero_sensor++)
        {
            if(lectura_sin_calibrar[numero_sensor] > sensor_max[numero_sensor])
                sensor_max[numero_sensor] = lectura_sin_calibrar[numero_sensor];
            else if(lectura_sin_calibrar[numero_sensor] < sensor_min[numero_sensor])
                sensor_min[numero_sensor] = lectura_sin_calibrar[numero_sensor];

        }
    }
  /*  for(numero_sensor = 0; numero_sensor < 6; numero_sensor++)
    {
        printf("%i   %i", sensor_min[numero_sensor],sensor_max[numero_sensor]);
        printf("\r\n");
    }*/
    for(numero_sensor = 0; numero_sensor < 6; numero_sensor++)
    {
        media_blanco[numero_sensor] = (sensor_min[numero_sensor] + sensor_max[numero_sensor]) / 2;
    }
}
void lectura_precalibracion()
{
 
    sensor_min[0] = sensor_max[0] = ADC_GetConversion(11);
    sensor_min[1] = sensor_max[1] = ADC_GetConversion(13);
    sensor_min[2] = sensor_max[2] = ADC_GetConversion(4);
    sensor_min[3] = sensor_max[3] = ADC_GetConversion(0);
    sensor_min[4] = sensor_max[4] = ADC_GetConversion(1);
    sensor_min[5] = sensor_max[5] = ADC_GetConversion(2);
   
}
/**
 End of File
*/