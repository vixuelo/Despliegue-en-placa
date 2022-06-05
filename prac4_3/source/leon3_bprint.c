#include "leon3_uart.h"
#include "leon3_bprint.h"

int8_t leon3_print_string(char *str)
{
	uint32_t i = 0;
	uint32_t write_timeout = 0;

	while (str[i] != '\0')
	{
		leon3_putchar(str[i]);
		i++;
	}
	return (leon3_uart_tx_fifo_is_empty()); // Esto no espera a que este vacia la fifo
/*
	//Mejora: while(*str!='\0'){
	//funciona, pero mejor si tratas errores
    	//int8_t error=0;
    	//while(str[i]!='\0'&&(!error)){

	while(*str!='\0'&&(!error)){
		error=leon3_putchar(*str);
		//error=leon3_putchar(str[i]);
		str++;
	}
	//Error: Debes añadir la espera a que la fifo de transmisión se vacie
	while(!leon3_uart_tx_fifo_is_empty())
	 ;

	 return error;
*/
}

int8_t leon3_print_uint8(uint8_t i)
{
	uint8_t aux;
	if (i < 10)
		leon3_putchar(i + '0');
	else if (i < 100)
	{
		leon3_putchar((i / 10) + '0');
		leon3_putchar((i % 10) + '0');
	}
	else
	{
		aux = i % 100;
		leon3_putchar((i / 100) + '0');
		leon3_putchar((aux / 10) +'0');
		leon3_putchar((aux % 10) + '0');
	}

	// Solución demasiado particular, debes generalizarla. En la P3 hay que imprimir un uint32
	// Piensa en un bucle, los ceros a la izquierda no hay que imprimirlos

	return (leon3_uart_tx_fifo_is_empty()); // lo mismo...
}
int8_t leon3_print_uint32(uint32_t i)
{
int8_t error=0;
uint32_t aux;
int8_t first_digit=0;

aux=1000000000;

if(i==0)
leon3_putchar('0');
else{
while(i && (!error)){
uint8_t digit;

digit=i/aux;

i -= aux*digit;

aux = aux/10;
if(first_digit || digit){
error = leon3_putchar('0' + digit);
first_digit = 1;
}
}
}
return error;
}
