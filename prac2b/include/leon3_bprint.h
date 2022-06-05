/*
 * leon3_bprint.h
 *
 *  Created on: 25/02/2022
 *      Author: atcsol
 */
#include "leon3_types.h"
#ifndef LEON3_BPRINT_H_
#define LEON3_BPRINT_H_
//transmite  a  través  del  puerto  serie  la  cadena  de  caracteres
//pasada por parámetro.
int8_t leon3_print_string(char* str);  //ver **
//transmite a través del puerto serie el entero transformado en
//cadena de caracteres.
int8_t leon3_print_uint8(uint8_t i);     // ver ***
//calcula las potencias de 10
int potencia10(int i);


#endif /* LEON3_BPRINT_H_ */

