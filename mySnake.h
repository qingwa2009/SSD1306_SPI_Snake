#ifndef __MY_SNAKE_H
#define __MY_SNAKE_H

//每格宽
#if !defined(SNAKE_PIXEL_W) || (SNAKE_PIXEL_W - SNAKE_PIXEL_W - 1 == 1)
#undef SNAKE_PIXEL_W
#define SNAKE_PIXEL_W 10
#endif

//每格高
#if !defined(SNAKE_PIXEL_H) || (SNAKE_PIXEL_H - SNAKE_PIXEL_H - 1 == 1)
#undef SNAKE_PIXEL_H
#define SNAKE_PIXEL_H 10
#endif

/*屏幕最大的尺寸*/
#if !defined(SNAKE_SCREEN_W_PIXEL) || (SNAKE_SCREEN_W_PIXEL - SNAKE_SCREEN_W_PIXEL - 1 == 1)
#undef SNAKE_SCREEN_W_PIXEL
#define SNAKE_SCREEN_W_PIXEL 240
#endif

#if !defined(SNAKE_SCREEN_H_PIXEL) || (SNAKE_SCREEN_H_PIXEL - SNAKE_SCREEN_H_PIXEL - 1 == 1)
#undef SNAKE_SCREEN_H_PIXEL
#define SNAKE_SCREEN_H_PIXEL 320
#endif

#define SNAKE_MAP_MAX_H SNAKE_SCREEN_H_PIXEL / SNAKE_PIXEL_H
#define SNAKE_MAP_MAX_W SNAKE_SCREEN_W_PIXEL / SNAKE_PIXEL_W

//#define SNAKE_MAP_W 240/SNAKE_PIXEL_W
//#define SNAKE_MAP_H 320/SNAKE_PIXEL_H

#define SNAKE_EMPTY 0         //0000 0000: 空白
#define SNAKE_FOOD 0b00010000 //0001 0000: 食物
#define SNAKE_WALL 0b11111111 //1111 1111: 墙壁
#define SNAKE_R 0b00001000    //0000 1000: 蛇右
#define SNAKE_U 0b00001001    //0000 1001: 蛇上
#define SNAKE_L 0b00001010    //0000 1010: 蛇左
#define SNAKE_D 0b00001011    //0000 1011: 蛇下

typedef void (*EventDraw)(unsigned char x, unsigned char y, unsigned char t);
typedef void (*EventUpdateScore)(int score);

extern unsigned char snakeGameOver;
extern unsigned int snakeScore;

#ifdef __cplusplus
extern "C"
{
#endif
    void setSnakeMapTile(unsigned char x, unsigned char y, unsigned char v);
    unsigned char getSnakeMapTile(unsigned char x, unsigned char y);
    void setSnakeFood(unsigned char seed, EventDraw draw);
    void snakeInit(unsigned char snakemapw, unsigned char snakemaph, EventDraw draw, unsigned char foodSeed, unsigned char swapScrennWH);
    void snakeTilePosMoveNext(unsigned char tileDir, unsigned char *x, unsigned char *y);
    void snakeMove(EventDraw draw, unsigned char foodSeed, EventUpdateScore updateScore);
    void snakeTurn(unsigned char dir);

#ifdef __cplusplus
}
#endif

#endif