#include "../include/leon3_uart.h"
#include "../include/leon3_bprint.h"
#include "../include/leon3_hw_irqs.h"
#include "../include/leon3_ev_handling.h"
uint8_t irq_counter=0;
char RxChars[8];
/*Esta función se utilizará como manejador de la interrupción que genera la recepción de un dato por el puerto serie. La función almacena en RxChars los primeros 8 carateres que se reciben, reenviando, además el sucesor por el mismo canal Tx*/
void uart_rx_irq_handler(void){
char aux;
aux=leon3_getchar();
if(irq_counter<7){
RxChars[irq_counter]=aux;
aux++;
leon3_putchar(aux);
}
irq_counter++;
}
int main(){
uint8_t i;
//Instalar como manejador del trap 0x83 la rutina
// que habilita las interrupciones
leon3_set_trap_handler(0x83,leon3_trap_handler_enable_irqs);
//Instalar el manejador del trap que 0x83 la rutina
// que deshabilita las interrupciones
leon3_set_trap_handler(0x84,leon3_trap_handler_disable_irqs);
//Llamada alsistema para deshabilitar las interrupciones
leon3_sys_call_disable_irqs();
 //COMPLETAR instalando como manejador de la interrupción de
//nivel 2 la rutina uart_rx_irq_handler siguiendo el mismo
//patrón de la prac3a
leon3_sparc_irqhandler_entry(12);
uart_rx_irq_handler();
//FIN COMPLETAR
//Habilito loop-back
leon3_uart_ctrl_config_rxtx_loop(1);
//Habilito interrupción de recepción por la UART
leon3_uart_ctrl_rx_irq_enable();
//Habilito la recepción por la UART
leon3_uart_ctrl_rx_enable();
//COMPLETARhabilitando las interrupciones y
//desenmascarando la interrupción de nivel 2
leon3_sys_call_enable_irqs();
leon3_unmask_irq(2);
//FIN COMPLETAR
leon3_putchar('A');
//Sondeo si los 8 caracteres se han recibido
while(irq_counter < 7);
//Tras recibir los 8 caracteres, configuro la UART
//sin loop-back
leon3_uart_ctrl_config_rxtx_loop(0);
 //Envío de nuevo los 8 caracteres que se recibieron,
//pero sin loop-back, por lo que aparecerán por pantalla
for(i=0;i<8;i++)
leon3_putchar(RxChars[i]);
leon3_putchar('\n');
//Espero a que todos los caracteres se hayan enviado.
while(!leon3_uart_tx_fifo_is_empty());
return 0;
}
