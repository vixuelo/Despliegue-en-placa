#include "../include/leon3_uart.h"
//Estructura de datos que permite acceder a los registros de la //UART de LEON3
//! LEON3 UART A Transmit FIFO is FULL 0x4
#define LEON3_UART_TFF  0x200
//!  LEON3 UART A Transmit FIFO is EMPTY
#define LEON3_UART_TFE  0x04
//macro tf lleno

struct UART_regs { /** \brief UART  Data Register */
	volatile uint32_t Data; /* 0x80000100 *//** \brief UART  Status Register */
	volatile uint32_t Status; /* 0x80000104 *//** \brief UART  Control Register */
	volatile uint32_t Ctrl; /* 0x80000108 *//** \brief UART  Scaler Register */
	volatile uint32_t Scaler; /* 0x8000010C */
};
struct UART_regs * pLEON3_UART_REGS= (struct UART_regs *) 0x80000100;
#define leon3_UART_TF_IS_FULL() ((pLEON3_UART_REGS->Status & LEON3_UART_TFF))
//macro tf vacio
#define leon3_UART_TF_IS_EMPTY() ((pLEON3_UART_REGS->Status & LEON3_UART_TFE))





int8_t leon3_putchar(char c){

	uint32_t write_timeout = 0;

	while (leon3_UART_TF_IS_FULL()&&(write_timeout < 0xAAAAA)) {
		write_timeout++;
	}; //Espera mientras la cola de transmisión esté llena

	if (write_timeout < 0xAAAAA) { //COMPLETAR. Escribir el carácter en el registro Data
		pLEON3_UART_REGS->Data=(uint32_t)c;
	};
	return (write_timeout == 0xAAAAA);
};
int8_t leon3_uart_tx_fifo_is_empty() {
	if(leon3_UART_TF_IS_EMPTY()){
		return 1;
	}else{
		return 0;
	}
};
