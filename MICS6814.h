/*
 * MICS6814.h
 *
 *  Created on: Sep 28, 2020
 *      Author: Aniket Paluskar
 */

#ifndef APPLICATION_MICS6814_MICS6814_H_
#define APPLICATION_MICS6814_MICS6814_H_

#include <ti/drivers/ADC.h>

/*****************************MACROS*****************************/
#define MAX_CO_PPM          1000            //Maximum CO Detection Level
#define MAX_NH3_PPM         300             //Maximum NH3 Detection Level
#define MAX_NO2_PPM         10              //Maximum No2 detection Level
#define MAX_RED_OP_VOLTAGE  2.4             //Maximum Output Voltage from RED(CO) Sensor
#define MAX_NH3_OP_VOLTAGE  2.2             //Maximum Output Voltage from NH3 Sensor
#define MAX_OX_OP_VOLTAGE   1.7             //Maximum Output Voltage from OX Sensor


/*
 * Functions
 */
uint16_t getCO_MICS6814(ADC_Handle adc);
uint16_t getNH3_MICS6814(ADC_Handle adc);
uint16_t getNO2_MICS6814(ADC_Handle adc);


#endif /* APPLICATION_MICS6814_MICS6814_H_ */