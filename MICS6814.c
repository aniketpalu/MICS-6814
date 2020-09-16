include "MICS6814.h"

/**********************************************************
 *  Declaration of local variables
 *  pinCO : Pin used for detecting carbon dioxide
 *  pinNO2 : Pin used for Nitrogen Dioxide
 *  pinNH3 : Pin used for Ammonia
 *  base_CO : Base value of Carbon Monoxide from Application Level
 *  base_NO2 : Base Value of Nitrogen Dioxide from Application Level
 *  base NH3 : Base Value of Ammonia from Application level
 */


int pinCO, pinNO2, pinNH3;
int base_co, base_no2, base_nh3;







/**************************************************************
 * @fn      setup_base_values(int base_RED, int base_OX,int base_NH3);
 * 
 * @brief   Setting up the base values of Sensors to be used for 
 *          caliberation and interpretation
 * 
 * @param   Integer values of Average level  
 * 
 * @return  None 
 */
void setup_base_values(int base_RED, int base_OX,int base_NH3)
{
    base_co = base_RED;
    base_no2 = base_OX;
    base_nh3 = base_NH3;
}






/*****************************************************************
 * @fn      setup_pins(int pin_CO,int pin_NO2,int pin_NH3)
 * 
 * @brief   Setting up pin values for reading the data from
 * 
 * @param   Integer values of Pin Number
 * 
 * @returns None
 */
void setup_pins(int pin_CO,int pin_NO2,int pin_NH3)
{
    pinCO = pin_CO;
    pinNO2 = pin_NO2;
    pinNH3 = pin_NH3;
	pinMode(pinCO, INPUT);
	pinMode(pinNO2, INPUT);
	pinMode(pinNH3, INPUT);
}




/*****************************************************************
 * @fn      getResistance (channel_t channel)
 * 
 * @brief   Fetches the resistance Value
 * 
 * @param   channel_t type value(User Defined Datatype)
 * 
 * @returns Float value of resistance of demanded gas
 */


float  getResistance(channel_t channel)
{
	float tempResistance = 0 ;
	int counter = 0 ;

	switch (channel)
	{
	case CH_CO:
		for ( int i = 0 ; i < 100 ; i ++)
		{
			tempResistance +=analogRead(pinCO);
			counter++;
			delay(2);
		}
	case CH_NO2:
		for ( int i = 0 ; i < 100 ; i ++)
		{
			tempResistance +=analogRead(pinNO2);
			counter++;
			delay(2);
		}
	case CH_NH3:
		for ( int i = 0 ; i < 100 ; i ++)
		{
			tempResistance +=analogRead(pinNH3);
			counter++;
			delay ( 2 );
		}
	}

	return counter== 0 ? 0 :tempResistance / counter ;
}
