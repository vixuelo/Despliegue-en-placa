/*
 * leon3_timing_service_config.h
 *
 *  Created on: Apr 2, 2013
 *      Author: user
 */

#include "leon3_types.h"

#ifndef LEON3_TIMING_SERVICE_H
#define LEON3_TIMING_SERVICE_H


//TIMING SERVICE CONFIGURATION PARAMETERS

//TODO: definir macro
#define TIMING_SERVICE_TICKS_PER_SECOND 10



	/** \brief Init Timing Service
	 *
	 *  \param currentTime_in_Y2K set current time in Y2K
	 *
	 */


uint64_t get_tick_counter_from_reset(void);
uint8_t wait_until(uint64_t ticks_from_reset);
void init_timing_service(uint32_t currentTime_in_Y2K);






#endif /* LEON3_TIMING_SERVICE_CONFIG_H_ */
