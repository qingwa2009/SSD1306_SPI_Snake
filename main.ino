#include <Arduino.h>
#include "mylib/MyPin.h"
#include "mylib/MySPI.h"
#include "mylib/SSD1306.h"
#include "mySnake.h"

/*
相应引脚拉低触发相应转向
PIN_TURN_RIGHT  A0
PIN_TURN_UP     A1
PIN_TURN_LEFT   A2
PIN_TURN_DOWN   A3
*/

void setup()
{
    initSPIMaster(MySPI_Fosc_1_2);
    initSSD1306();
    setScreenDir(2);
}

void drawSnakeTile(unsigned char x, unsigned char y, unsigned char t)
{
    enum Color r;
    switch (t)
    {
    case SNAKE_EMPTY:
        r = BLACK;
        break;
    case SNAKE_FOOD:
        r = WHITE;
        break;
    case SNAKE_WALL:
        r = WHITE;
        break;
    default:
        r = WHITE;
        break;
    }
    uint8_t gap = 1;

    fillRect(x * SNAKE_PIXEL_W, y * SNAKE_PIXEL_H, SNAKE_PIXEL_W - gap, SNAKE_PIXEL_H - gap, r);
}

uint8_t snakeScoreCharScale = 1;
uint8_t scoreStr[] = "Score:000";
void updateScoreStr(int score)
{
    if (score > 999)
        score = 999;
    scoreStr[6] = score / 100;
    score -= scoreStr[6] * 100;
    scoreStr[7] = score / 10;
    score -= scoreStr[7] * 10;
    scoreStr[8] = score;
    scoreStr[6] += 0x30;
    scoreStr[7] += 0x30;
    scoreStr[8] += 0x30;
}
void updateSnakeScore(int score)
{
    drawStr(SNAKE_PIXEL_W, SNAKE_PIXEL_H, scoreStr, sizeof(scoreStr) - 1, snakeScoreCharScale, INVERSE);
    updateScoreStr(score);
    // drawRect(SNAKE_PIXEL_W + snakeScoreCharScale * (FONT_W + 1) * 7, SNAKE_PIXEL_H, snakeScoreCharScale * (FONT_W + 1) * 3, snakeScoreCharScale * FONT_H, INVERSE);
}

void drawSnakeScore()
{
    drawStr(SNAKE_PIXEL_W, SNAKE_PIXEL_H, scoreStr, sizeof(scoreStr) - 1, snakeScoreCharScale, WHITE);
}

volatile bool stuck;
bool snakeTurnEnable;
ISR(PCINT1_vect)
{
    stuck = 0;
    if (!snakeTurnEnable)
        return;
    //snakeTurnEnable=0;

    uint8_t s = ~PINC;
    if (!(s & 0b00001111))
        return;

    if (s & _BV(PINC0))
    {
        snakeTurn(SNAKE_R);
    }
    else if (s & _BV(PINC1))
    {
        snakeTurn(SNAKE_U);
    }
    else if (s & _BV(PINC2))
    {
        snakeTurn(SNAKE_L);
    }
    else if (s & _BV(PINC3))
    {
        snakeTurn(SNAKE_D);
    }
}

void testSnake()
{
    pinMode(A0, INPUT_PULLUP);
    pinMode(A1, INPUT_PULLUP);
    pinMode(A2, INPUT_PULLUP);
    pinMode(A3, INPUT_PULLUP);

    PCICR = _BV(PCIE1); //打开引脚变化中断
    PCMSK1 = _BV(PCINT11) | _BV(PCINT10) | _BV(PCINT9) | _BV(PCINT8);
    /*每开一次换一个方向*/
    // static uint8_t dir = 2;
    // setScreenDir(dir++);

    stuck = 0;
    clearDisplay(0);
    snakeInit(SCREEN_W / SNAKE_PIXEL_W, SCREEN_H / SNAKE_PIXEL_H, drawSnakeTile, TCNT2, SCREEN_W < SCREEN_H);
    updateScoreStr(snakeScore);
    while (!snakeGameOver)
    {
        snakeTurnEnable = 0;
        snakeMove(drawSnakeTile, TCNT2, updateSnakeScore);
        snakeTurnEnable = 1;
        drawSnakeScore();
        display();
        delay(100);
    }

    stuck = 1;
    while (stuck)
    {
        uint8_t scale = 1;
        drawStr((SCREEN_W / 2 - (FONT_W + 1) * 5 * scale),
                (SCREEN_H - FONT_H * scale) / 2, (uint8_t *)"GAME OVER!", 10, scale, INVERSE);
        display();
        delay(100);
    }

    PCICR = 0; //关闭引脚变化中断
}

void loop()
{
    testSnake();
}