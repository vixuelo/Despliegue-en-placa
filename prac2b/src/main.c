#include "../include/leon3_uart.h"
#include "../include/leon3_bprint.h"
int main() {
	//main del pryecto prac2
	leon3_putchar('p');
	leon3_putchar('2');
	leon3_putchar('\n');
	int i = 0;
	char aux = '0';
	for (i = 0; i < 10; i++) {
		leon3_putchar(aux);
		aux++;
	}
	leon3_putchar('\n');
	while (!leon3_uart_tx_fifo_is_empty())
		;
	//main del proyecto prac2b
	char * pchar = "cadena\n";
	uint8_t a=43,b=34,c=12;
	leon3_print_string(pchar);
	leon3_print_uint8(a);
	leon3_putchar('\n');
	leon3_print_uint8(b);
	leon3_putchar('\n');
	leon3_print_uint8(c);
	leon3_putchar('\n');

	while (!leon3_uart_tx_fifo_is_empty())
		;
	return 0;
}

