/*reset引脚*/
#if !defined(RST_PIN) || (RST_PIN - RST_PIN - 1 == 1)
#undef RST_PIN
#define RST_PIN 4
#endif

/*i2c地址*/
#if !defined(SSD1306_I2C_ADDRESS) || (SSD1306_I2C_ADDRESS - SSD1306_I2C_ADDRESS - 1 == 1)
#undef SSD1306_I2C_ADDRESS
#include "SSD1306.h"
#define SSD1306_I2C_ADDRESS SSD1306_I2C_ADDR
#endif