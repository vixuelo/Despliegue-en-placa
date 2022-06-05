#include "leon3_uart.h"

#define LEON3_UART_TFF (0x200) //Transmision
#define LEON3_UART_TFE (0x4) //F
struct UART_regs
{
	volatile uint32_t Data;
	volatile uint32_t Status;
	volatile uint32_t Ctrl;
	volatile uint32_t Scaler;

};
struct UART_regs * const pLEON3_UART_REGS = (struct UART_regs *) 0x80000100;

#define leon3_UART_TF_IS_FULL() (pLEON3_UART_REGS->Status & LEON3_UART_TFF)

int8_t leon3_putchar(char c)
{
	uint32_t write_timeout = 0;

	while (leon3_UART_TF_IS_FULL() && (write_timeout < 0xAAAAA))
		write_timeout++; //Si transmision esta llena

	if (write_timeout < 0xAAAAA)
		pLEON3_UART_REGS->Data = (uint32_t) c; //Escribimos

	return (write_timeout == 0xAAAAA);
}

int8_t leon3_uart_tx_fifo_is_empty()
{
	if (pLEON3_UART_REGS->Status & LEON3_UART_TFE) //Si al hacer el and devuelve 1
		return (int8_t) 1;
	else
		return (int8_t) 0;

//Mejora:Está bien, pero no lo más sencillo es
//return (LEON3_UART_TFE & pLEON3_UART_REGS->Status);
//Basta con que sea !=0

}
