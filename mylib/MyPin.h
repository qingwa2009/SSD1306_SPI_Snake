#ifndef __MYMYPIN_H
#define __MYMYPIN_H
#include <Arduino.h>
/*D----------------------------------------------*/
#define MYPIN_0_WRITE_MODE (DDRD |= _BV(DDD0))
#define MYPIN_1_WRITE_MODE (DDRD |= _BV(DDD1))
#define MYPIN_2_WRITE_MODE (DDRD |= _BV(DDD2))
#define MYPIN_3_WRITE_MODE (DDRD |= _BV(DDD3))
#define MYPIN_4_WRITE_MODE (DDRD |= _BV(DDD4))
#define MYPIN_5_WRITE_MODE (DDRD |= _BV(DDD5))
#define MYPIN_6_WRITE_MODE (DDRD |= _BV(DDD6))
#define MYPIN_7_WRITE_MODE (DDRD |= _BV(DDD7))

#define MYPIN_0_WRITE_HIGH (PORTD |= _BV(PORTD0))
#define MYPIN_1_WRITE_HIGH (PORTD |= _BV(PORTD1))
#define MYPIN_2_WRITE_HIGH (PORTD |= _BV(PORTD2))
#define MYPIN_3_WRITE_HIGH (PORTD |= _BV(PORTD3))
#define MYPIN_4_WRITE_HIGH (PORTD |= _BV(PORTD4))
#define MYPIN_5_WRITE_HIGH (PORTD |= _BV(PORTD5))
#define MYPIN_6_WRITE_HIGH (PORTD |= _BV(PORTD6))
#define MYPIN_7_WRITE_HIGH (PORTD |= _BV(PORTD7))

#define MYPIN_0_WRITE_LOW (PORTD &= ~(_BV(PORTD0)))
#define MYPIN_1_WRITE_LOW (PORTD &= ~(_BV(PORTD1)))
#define MYPIN_2_WRITE_LOW (PORTD &= ~(_BV(PORTD2)))
#define MYPIN_3_WRITE_LOW (PORTD &= ~(_BV(PORTD3)))
#define MYPIN_4_WRITE_LOW (PORTD &= ~(_BV(PORTD4)))
#define MYPIN_5_WRITE_LOW (PORTD &= ~(_BV(PORTD5)))
#define MYPIN_6_WRITE_LOW (PORTD &= ~(_BV(PORTD6)))
#define MYPIN_7_WRITE_LOW (PORTD &= ~(_BV(PORTD7)))

#define MYPIN_0_READ_MODE (DDRD &= ~(_BV(DDD0)))
#define MYPIN_1_READ_MODE (DDRD &= ~(_BV(DDD1)))
#define MYPIN_2_READ_MODE (DDRD &= ~(_BV(DDD2)))
#define MYPIN_3_READ_MODE (DDRD &= ~(_BV(DDD3)))
#define MYPIN_4_READ_MODE (DDRD &= ~(_BV(DDD4)))
#define MYPIN_5_READ_MODE (DDRD &= ~(_BV(DDD5)))
#define MYPIN_6_READ_MODE (DDRD &= ~(_BV(DDD6)))
#define MYPIN_7_READ_MODE (DDRD &= ~(_BV(DDD7)))

#define MYPIN_0_READ_HIGH (PIND & (_BV(PIND0)))
#define MYPIN_1_READ_HIGH (PIND & (_BV(PIND1)))
#define MYPIN_2_READ_HIGH (PIND & (_BV(PIND2)))
#define MYPIN_3_READ_HIGH (PIND & (_BV(PIND3)))
#define MYPIN_4_READ_HIGH (PIND & (_BV(PIND4)))
#define MYPIN_5_READ_HIGH (PIND & (_BV(PIND5)))
#define MYPIN_6_READ_HIGH (PIND & (_BV(PIND6)))
#define MYPIN_7_READ_HIGH (PIND & (_BV(PIND7)))

#define MYPIN_0_WRITE_TOGGLE (PIND |= (_BV(PIND0)))
#define MYPIN_1_WRITE_TOGGLE (PIND |= (_BV(PIND1)))
#define MYPIN_2_WRITE_TOGGLE (PIND |= (_BV(PIND2)))
#define MYPIN_3_WRITE_TOGGLE (PIND |= (_BV(PIND3)))
#define MYPIN_4_WRITE_TOGGLE (PIND |= (_BV(PIND4)))
#define MYPIN_5_WRITE_TOGGLE (PIND |= (_BV(PIND5)))
#define MYPIN_6_WRITE_TOGGLE (PIND |= (_BV(PIND6)))
#define MYPIN_7_WRITE_TOGGLE (PIND |= (_BV(PIND7)))

/*B----------------------------------------------*/
#define MYPIN_8_WRITE_MODE (DDRB |= _BV(DDB0))
#define MYPIN_9_WRITE_MODE (DDRB |= _BV(DDB1))
#define MYPIN_10_WRITE_MODE (DDRB |= _BV(DDB2))
#define MYPIN_11_WRITE_MODE (DDRB |= _BV(DDB3))
#define MYPIN_12_WRITE_MODE (DDRB |= _BV(DDB4))
#define MYPIN_13_WRITE_MODE (DDRB |= _BV(DDB5))

#define MYPIN_8_WRITE_HIGH (PORTB |= _BV(PORTB0))
#define MYPIN_9_WRITE_HIGH (PORTB |= _BV(PORTB1))
#define MYPIN_10_WRITE_HIGH (PORTB |= _BV(PORTB2))
#define MYPIN_11_WRITE_HIGH (PORTB |= _BV(PORTB3))
#define MYPIN_12_WRITE_HIGH (PORTB |= _BV(PORTB4))
#define MYPIN_13_WRITE_HIGH (PORTB |= _BV(PORTB5))

#define MYPIN_8_WRITE_LOW (PORTB &= ~(_BV(PORTB0)))
#define MYPIN_9_WRITE_LOW (PORTB &= ~(_BV(PORTB1)))
#define MYPIN_10_WRITE_LOW (PORTB &= ~(_BV(PORTB2)))
#define MYPIN_11_WRITE_LOW (PORTB &= ~(_BV(PORTB3)))
#define MYPIN_12_WRITE_LOW (PORTB &= ~(_BV(PORTB4)))
#define MYPIN_13_WRITE_LOW (PORTB &= ~(_BV(PORTB5)))

#define MYPIN_8_READ_MODE (DDRB &= ~(_BV(DDB0)))
#define MYPIN_9_READ_MODE (DDRB &= ~(_BV(DDB1)))
#define MYPIN_10_READ_MODE (DDRB &= ~(_BV(DDB2)))
#define MYPIN_11_READ_MODE (DDRB &= ~(_BV(DDB3)))
#define MYPIN_12_READ_MODE (DDRB &= ~(_BV(DDB4)))
#define MYPIN_13_READ_MODE (DDRB &= ~(_BV(DDB5)))

#define MYPIN_8_READ_HIGH (PINB & (_BV(PINB0)))
#define MYPIN_9_READ_HIGH (PINB & (_BV(PINB1)))
#define MYPIN_10_READ_HIGH (PINB & (_BV(PINB2)))
#define MYPIN_11_READ_HIGH (PINB & (_BV(PINB3)))
#define MYPIN_12_READ_HIGH (PINB & (_BV(PINB4)))
#define MYPIN_13_READ_HIGH (PINB & (_BV(PINB5)))

#define MYPIN_8_WRITE_TOGGLE (PINB |= (_BV(PINB0)))
#define MYPIN_9_WRITE_TOGGLE (PINB |= (_BV(PINB1)))
#define MYPIN_10_WRITE_TOGGLE (PINB |= (_BV(PINB2)))
#define MYPIN_11_WRITE_TOGGLE (PINB |= (_BV(PINB3)))
#define MYPIN_12_WRITE_TOGGLE (PINB |= (_BV(PINB4)))
#define MYPIN_13_WRITE_TOGGLE (PINB |= (_BV(PINB5)))

/*C----------------------------------------------*/
#define MYPIN_A0_WRITE_MODE (DDRC |= _BV(DDC0))
#define MYPIN_A1_WRITE_MODE (DDRC |= _BV(DDC1))
#define MYPIN_A2_WRITE_MODE (DDRC |= _BV(DDC2))
#define MYPIN_A3_WRITE_MODE (DDRC |= _BV(DDC3))
#define MYPIN_A4_WRITE_MODE (DDRC |= _BV(DDC4))
#define MYPIN_A5_WRITE_MODE (DDRC |= _BV(DDC5))

#define MYPIN_A0_WRITE_HIGH (PORTC |= _BV(PORTC0))
#define MYPIN_A1_WRITE_HIGH (PORTC |= _BV(PORTC1))
#define MYPIN_A2_WRITE_HIGH (PORTC |= _BV(PORTC2))
#define MYPIN_A3_WRITE_HIGH (PORTC |= _BV(PORTC3))
#define MYPIN_A4_WRITE_HIGH (PORTC |= _BV(PORTC4))
#define MYPIN_A5_WRITE_HIGH (PORTC |= _BV(PORTC5))

#define MYPIN_A0_WRITE_LOW (PORTC &= ~(_BV(PORTC0)))
#define MYPIN_A1_WRITE_LOW (PORTC &= ~(_BV(PORTC1)))
#define MYPIN_A2_WRITE_LOW (PORTC &= ~(_BV(PORTC2)))
#define MYPIN_A3_WRITE_LOW (PORTC &= ~(_BV(PORTC3)))
#define MYPIN_A4_WRITE_LOW (PORTC &= ~(_BV(PORTC4)))
#define MYPIN_A5_WRITE_LOW (PORTC &= ~(_BV(PORTC5)))

#define MYPIN_A0_READ_MODE (DDRC &= ~(_BV(DDC0)))
#define MYPIN_A1_READ_MODE (DDRC &= ~(_BV(DDC1)))
#define MYPIN_A2_READ_MODE (DDRC &= ~(_BV(DDC2)))
#define MYPIN_A3_READ_MODE (DDRC &= ~(_BV(DDC3)))
#define MYPIN_A4_READ_MODE (DDRC &= ~(_BV(DDC4)))
#define MYPIN_A5_READ_MODE (DDRC &= ~(_BV(DDC5)))

#define MYPIN_A0_READ_HIGH (PINC & (_BV(PINC0)))
#define MYPIN_A1_READ_HIGH (PINC & (_BV(PINC1)))
#define MYPIN_A2_READ_HIGH (PINC & (_BV(PINC2)))
#define MYPIN_A3_READ_HIGH (PINC & (_BV(PINC3)))
#define MYPIN_A4_READ_HIGH (PINC & (_BV(PINC4)))
#define MYPIN_A5_READ_HIGH (PINC & (_BV(PINC5)))

#define MYPIN_A0_WRITE_TOGGLE (PINC |= (_BV(PINC0)))
#define MYPIN_A1_WRITE_TOGGLE (PINC |= (_BV(PINC1)))
#define MYPIN_A2_WRITE_TOGGLE (PINC |= (_BV(PINC2)))
#define MYPIN_A3_WRITE_TOGGLE (PINC |= (_BV(PINC3)))
#define MYPIN_A4_WRITE_TOGGLE (PINC |= (_BV(PINC4)))
#define MYPIN_A5_WRITE_TOGGLE (PINC |= (_BV(PINC5)))
/*一级--------------------------------------------*/
#define MYPIN_WRITE_MODE(x) MYPIN_##x##_WRITE_MODE
#define MYPIN_WRITE_HIGH(x) MYPIN_##x##_WRITE_HIGH
#define MYPIN_WRITE_LOW(x) MYPIN_##x##_WRITE_LOW
#define MYPIN_READ_MODE(x) MYPIN_##x##_READ_MODE
#define MYPIN_READ_HIGH(x) MYPIN_##x##_READ_HIGH
#define MYPIN_WRITE_TOGGLE(x) MYPIN_##x##_WRITE_TOGGLE

/*二级--------------------------------------------*/
#define MYPIN_WRITE_MODE_(x) MYPIN_WRITE_MODE(x)
#define MYPIN_WRITE_HIGH_(x) MYPIN_WRITE_HIGH(x)
#define MYPIN_WRITE_LOW_(x) MYPIN_WRITE_LOW(x)
#define MYPIN_READ_MODE_(x) MYPIN_READ_MODE(x)
#define MYPIN_READ_HIGH_(x) MYPIN_READ_HIGH(x)
#define MYPIN_WRITE_TOGGLE_(x) MYPIN_WRITE_TOGGLE(x)

// #define MYPIN_READ_MODE(mypin) ((*(volatile uint8_t *)(uint16_t)mypin.dirReg) &= ~(mypin.port))
// #define MYPIN_WRITE_MODE(mypin) ((*(volatile uint8_t *)(uint16_t)mypin.dirReg) |= (mypin.port))
// #define MYPIN_WRITE_HIGH(mypin) ((*(volatile uint8_t *)(uint16_t)mypin.outReg) |= (mypin.port))
// #define MYPIN_WRITE_LOW(mypin) ((*(volatile uint8_t *)(uint16_t)mypin.outReg) &= ~(mypin.port))
// #define MYPIN_READ(mypin) ((*(volatile uint8_t *)(uint16_t)mypin.inReg) & mypin.port)

// typedef struct
// {
//     uint8_t port;
//     uint8_t dirReg;
//     uint8_t outReg;
//     uint8_t inReg;
// } MyPin;

// #ifdef __cplusplus
// extern "C"
// {
// #endif
//     void createMyPin(uint8_t pin, MyPin *outMyPin);
// #ifdef __cplusplus
// }
// #endif

#endif