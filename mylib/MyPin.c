
#include "MyPin.h"

// void createMyPin(uint8_t pin, MyPin *outMyPin)
// {
//     uint8_t p = digitalPinToPort(pin);
//     uint8_t b = digitalPinToBitMask(pin);

//     uint8_t t;
//     t = (uint8_t)(uint16_t)portModeRegister(p);
//     outMyPin->dirReg = t;
//     t = (uint8_t)(uint16_t)portOutputRegister(p);
//     outMyPin->outReg = t;
//     t = (uint8_t)(uint16_t)portInputRegister(p);
//     outMyPin->inReg = t;
//     outMyPin->port = b;
// }
