# SSD1306_SPI_Snake
arduino uno(atmega328) SSD1306 SPI 贪吃蛇

SSD1306接线：

D0<---> 13  (SCK)

D1<---> 11 (MOSI)

RES<--->8

CS <--->10

DC <--->9


(RES, CS, DC)可以在Makefile里修改，也可以在执行make时传入-Dxxx对应参数。

按键接线：拉低触发按键事件

右<--->A0

上<--->A1

左<--->A2

下<--->A3


地图及格子大小也可以在Makefile配置。

编译相关：

cmd输入make 编译

cmd输入make upload 上传

Makefile需要将ARDUINO_PATH改到自己的arduino路径，新版的好像都没有mksketch，我用的proteus自带的编译。

上传相关：

Makefile需要将AVRDUE_CONF改到自己的路径

串口及波特率也可以在Makefile里面修改




