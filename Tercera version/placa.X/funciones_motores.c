/*
 * File:   funciones motores.c
 * Author: USER
 *
 * Created on October 25, 2019, 5:26 PM
 */


#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "funciones_motores.h"


//sentidos
#define AVANCE      1
#define RETROCESO   0

// Pines motores
#define PWMA                            LATE2
#define AIN2                            LATC2
#define AIN1                            LATC3
#define STBY                            LATC1
#define BIN1                            LATD0
#define BIN2                            LATD2
#define PWMB                            LATD1

//Motores
#define A   1
#define B   0



