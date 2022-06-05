#include "../include/leon3_uart.h"
#include "../include/leon3_bprint.h"
#include "../include/leon3_hw_irqs.h"
#include "../include/leon3_ev_handling.h"
void device_hw_irq_level_1_handler(void){
leon3_print_string("Device HWIRQ user handler \n");
}
int main() {
		//Instalar como manejador del trap 0x83 la rutina
	// que habilita las interrupciones
	leon3_set_trap_handler(0x83,leon3_trap_handler_enable_irqs);
	//Instalar el manejador del trap que 0x83 la rutina
	// que deshabilita las interrupciones
	leon3_set_trap_handler(0x84,leon3_trap_handler_disable_irqs);
	//Llamada al sistema para deshabilitar las interrupciones
	leon3_sys_call_disable_irqs();
	//COMPLETAR///

	///Enmascarar todas las interrupciones
	leon3_mask_all_irqs();
	//Instalar la función device_hw_irq_level_1_handlercomo
	leon3_sparc_irqhandler_entry(0x11);
	device_hw_irq_level_1_handler();
	// manejador de usuario de la interrupción de nivel 1
	//Desenmascarar la interrupción de nivel 1
	leon3_unmask_irq(1);
//Llamada al sistema para habilitar las interrupciones
	leon3_sys_call_enable_irqs();
	//Fuerza la interrupción
	leon3_force_irq(1);
	//FIN COMPLETAR
	return 0;}
