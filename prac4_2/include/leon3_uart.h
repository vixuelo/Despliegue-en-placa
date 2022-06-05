#ifndef LEON3_UART_H
#define LEON3_UART_H

#include "leon3_types.h"

int8_t leon3_putchar(char c);
int8_t leon3_uart_tx_fifo_is_empty();

#endif
