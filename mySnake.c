#include "mySnake.h"

static unsigned char SNAKE_MAP_W;
static unsigned char SNAKE_MAP_H;

static unsigned char snakeMap[SNAKE_MAP_MAX_W][SNAKE_MAP_MAX_H];
static unsigned char snakeHeadx;
static unsigned char snakeHeady;
static unsigned char snakeTailx;
static unsigned char snakeTaily;
static unsigned char snakeFoodx;
static unsigned char snakeFoody;
static unsigned char snakeSwapSceenWH;
unsigned char snakeGameOver;
unsigned int snakeScore;

inline void setSnakeMapTile(unsigned char x, unsigned char y, unsigned char v)
{
    if (snakeSwapSceenWH)
    {
        snakeMap[y][x] = v;
    }
    else
    {
        snakeMap[x][y] = v;
    }
}

inline unsigned char getSnakeMapTile(unsigned char x, unsigned char y)
{
    return snakeSwapSceenWH ? snakeMap[y][x] : snakeMap[x][y];
}

void setSnakeFood(unsigned char seed, EventDraw draw)
{
    unsigned char pseed = seed;
    unsigned char c = 2;
    while (seed)
    {
        for (unsigned char i = snakeFoodx; i < SNAKE_MAP_W; i++)
        {
            for (unsigned char j = snakeFoody; j < SNAKE_MAP_H; j++)
            {
                if (getSnakeMapTile(i, j) == SNAKE_EMPTY)
                    seed--;
                if (seed == 0)
                {
                    snakeFoodx = i;
                    snakeFoody = j;
                    setSnakeMapTile(i, j, SNAKE_FOOD);
                    draw(i, j, SNAKE_FOOD);
                    return;
                }
            }
        }
        snakeFoodx = 0;
        snakeFoody = 0;
        c--;
        if (c == 0 && pseed == seed)
        {
            //满屏
            snakeGameOver = 1;
        }
    }
}

void snakeInit(unsigned char snakemapw, unsigned char snakemaph, EventDraw draw, unsigned char foodSeed, unsigned char swapScrennWH)
{

    SNAKE_MAP_W = snakemapw;
    SNAKE_MAP_H = snakemaph;

    snakeSwapSceenWH = swapScrennWH;

    snakeGameOver = 0;
    snakeScore = 0;

    unsigned char *p;
    p = (unsigned char *)snakeMap;
    unsigned int n = sizeof(snakeMap);
    for (unsigned int i = 0; i < n; i++)
    {
        *(p++) = 0;
    }

    //墙壁
    for (unsigned char i = 0; i < SNAKE_MAP_W; i++)
    {
        setSnakeMapTile(i, 0, SNAKE_WALL);
        draw(i, 0, SNAKE_WALL);
        setSnakeMapTile(i, SNAKE_MAP_H - 1, SNAKE_WALL);
        draw(i, SNAKE_MAP_H - 1, SNAKE_WALL);
    }

    for (unsigned char j = 1; j < SNAKE_MAP_H - 1; j++)
    {
        setSnakeMapTile(0, j, SNAKE_WALL);
        draw(0, j, SNAKE_WALL);
        setSnakeMapTile(SNAKE_MAP_W - 1, j, SNAKE_WALL);
        draw(SNAKE_MAP_W - 1, j, SNAKE_WALL);
    }
    //蛇
    snakeHeadx = SNAKE_MAP_W / 2;
    snakeHeady = SNAKE_MAP_H / 2;

    setSnakeMapTile(snakeHeadx, snakeHeady, SNAKE_R);
    draw(snakeHeadx, snakeHeady, SNAKE_R);

    setSnakeMapTile(snakeHeadx - 1, snakeHeady, SNAKE_R);
    draw(snakeHeadx - 1, snakeHeady, SNAKE_R);

    snakeTailx = snakeHeadx - 2;
    snakeTaily = snakeHeady;
    setSnakeMapTile(snakeTailx, snakeTaily, SNAKE_R);
    draw(snakeTailx, snakeTaily, SNAKE_R);

    setSnakeFood(foodSeed, draw);
}

void snakeTilePosMoveNext(unsigned char tileDir, unsigned char *x, unsigned char *y)
{
    switch (tileDir)
    {
    case SNAKE_R:
        *x += 1;
        break;
    case SNAKE_U:
        *y -= 1;
        break;
    case SNAKE_L:
        *x -= 1;
        break;
    case SNAKE_D:
        *y += 1;
        break;
    default:
        break;
    }
}

void snakeMove(EventDraw draw, unsigned char foodSeed, EventUpdateScore updateScore)
{
    unsigned char head = getSnakeMapTile(snakeHeadx, snakeHeady);
    snakeTilePosMoveNext(head, &snakeHeadx, &snakeHeady);
    unsigned char tail;
    switch (getSnakeMapTile(snakeHeadx, snakeHeady))
    {
    case SNAKE_EMPTY:
        tail = getSnakeMapTile(snakeTailx, snakeTaily);
        setSnakeMapTile(snakeTailx, snakeTaily, SNAKE_EMPTY);
        draw(snakeTailx, snakeTaily, SNAKE_EMPTY);
        snakeTilePosMoveNext(tail, &snakeTailx, &snakeTaily);
        break;
    case SNAKE_FOOD:
        snakeScore++;
        setSnakeFood(foodSeed, draw);
        updateScore(snakeScore);
        break;
    case SNAKE_WALL:
    case SNAKE_R:
    case SNAKE_U:
    case SNAKE_L:
    case SNAKE_D:
        snakeGameOver = 1;
        return;
    default:
        break;
    }

    setSnakeMapTile(snakeHeadx, snakeHeady, head);
    draw(snakeHeadx, snakeHeady, head);
}

void snakeTurn(unsigned char dir)
{
    unsigned char head = getSnakeMapTile(snakeHeadx, snakeHeady);
    unsigned char offset = dir + 4 - head;
    if (!(offset & 1))
        return;
    setSnakeMapTile(snakeHeadx, snakeHeady, dir);
}
