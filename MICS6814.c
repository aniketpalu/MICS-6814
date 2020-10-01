/*
 * MICS6814.c
 *
 *  Created on: Sep 28, 2020
 *      Author: Aniket Paluskar
 */

#include "MICS6814.h"
#include "math.h"
#include <ti/drivers/ADC.h>

static float getResistance(ADC_Handle adcHandle);

/**********************************************************
 *  Declaration of local variables
 *  reading : Temporary output from MICS6814
 */
static uint16_t readings;



/**********************************************************
 * @fn               getCO_MICS6814(ADC_Handle adc)
 *
 * @brief            Calculates the CO in the air
 *
 * @param            ADC handle
 *
 * @returns          uint16_t value of CO in ppm units
 */
uint16_t getCO_MICS6814(ADC_Handle adc)
{
    float CODetection_Volts = 0.0, CODetection = 0.0;
    CODetection_Volts = getResistance(adc);
    CODetection = CODetection_Volts * (MAX_CO_PPM / MAX_RED_OP_VOLTAGE);
    return CODetection;
}


/**********************************************************
 * @fn               getNH3_MICS6814(ADC_Handle adc)
 *
 * @brief            Calculates the NH3 in the air
 *
 * @param            ADC handle
 *
 * @returns          uint16_t value of NH3 in ppm units
 */

uint16_t getNH3_MICS6814(ADC_Handle adc)
{
    float NH3Detection_Volts = 0.0, NH3Detection = 0.0;
    NH3Detection_Volts = getResistance(adc);
    NH3Detection = NH3Detection_Volts * (MAX_NH3_PPM / MAX_NH3_OP_VOLTAGE);
    return NH3Detection;
}


/**********************************************************
 * @fn               getNO2_MICS6814(ADC_Handle adc)
 *
 * @brief            Calculates the NO2 in the air
 *
 * @param            ADC handle
 *
 * @returns          uint16_t value of NO2 in ppm units
 */
uint16_t getNO2_MICS6814(ADC_Handle adc)
{
    float NO2Detection_Volts = 0.0, NO2Detection = 0.0;
    NO2Detection_Volts = getResistance(adc);
    NO2Detection = NO2Detection_Volts * (MAX_NO2_PPM / MAX_OX_OP_VOLTAGE);
    return  NO2Detection;
}

/**********************************************************
 * @fn               getResistance(ADC_Handle adc)
 *
 * @brief            Calculates the resistance of given Handle
 *
 * @param            ADC handle
 *
 * @returns          float value with unit Volts
 */
float getResistance(ADC_Handle adcHandle)
{
    uint32_t tempResistance=0;
    uint8_t count =0;
    int_fast16_t res;
    for(int i = 0;i < 100; i++)
    {
       res =  ADC_convert(adcHandle, &readings);
       if(res == ADC_STATUS_SUCCESS)
       {
          tempResistance = ADC_convertToMicroVolts(adcHandle, readings);
          tempResistance += tempResistance/pow(10,6);                      //Converting from MicroVolts to Volts
          count++;
       }
    }
    return count!=0 ? tempResistance/count: 0 ;
}
