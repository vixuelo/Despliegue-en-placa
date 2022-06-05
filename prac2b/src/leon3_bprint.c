
/*
 * leon3_bprint.c
 *
 *  Created on: 25/02/2022
 *      Author: atcsol
 */

#include "../include/leon3_bprint.h"
#include "../include/leon3_uart.h"
#define ZERO '0'
#define END_CHAR '\0'
//Recorre la cadena pasada por parametro hasta obtener el caracter final \0 definido como constante
//Finaliza cuando la fifo de transmision este vacia
int8_t leon3_print_string(char* str){
	int i=0;
    int8_t error=0;
	while(*str!='\0'&&(!error)){
		error=leon3_putchar(*str);
		str++;
	}

	while (!leon3_uart_tx_fifo_is_empty())
			;
	return error;
};
//Comprueba si hay ceros a la izquierda que quitar e imprime los digitos en caracteres gracias a su
//codigo ASCII sumando el codigo ASCII del numero 0 definido como una constante
//Finaliza cuando la fifo de transimision este vacia y devuelve un 0
int8_t leon3_print_uint8(uint8_t i){
	int8_t error=0;
	uint32_t aux;
	int8_t first_digit=0;
	aux=100;
	if(i==0){
		leon3_putchar(ZERO);
	}else{
		while(i &&(!error)){
			uint8_t digit;
			digit= i/aux;
			i-=aux*digit;
			aux=aux/10;
			if(first_digit||digit){
				error=leon3_putchar(ZERO+digit);
				first_digit=1;
			}
		}
	}

	// OK, pero es una solución demasiado particular, debes generalizarla. En la P3 hay que imprimir un uint32
	// Piensa en un bucle, los ceros a la izquierda no hay que imprimirlos

	while (!leon3_uart_tx_fifo_is_empty())
			;

	return error;
}
