#ifndef MICS6814_h
#define MICS6814_h

typedef enum{
    CH_CO,
    CH_NO2,
    CH_NH3
}channel_t;

typedef enum{
    CO,
    NO2,
    NH3,
}gas_t;

int base_NH3, base_RED, base_OX;
int pin_CO, pin_NO2, pin_NH3;

int getResistance(channel_t channel);
void setup_base_values(int base_NH3,int base_RED, int base_OX);
void setup_pins(int pin_CO,int pin_NO2,int pin_NH3);


#endif
