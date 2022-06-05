#include "../include/leon3_uart.h"
int main() {
	leon3_putchar('p');
	leon3_putchar('2');
	leon3_putchar('\n');
	while (!leon3_uart_tx_fifo_is_empty())
		;
	return 0;
}
