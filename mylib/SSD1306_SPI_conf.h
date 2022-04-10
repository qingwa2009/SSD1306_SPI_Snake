
/*片选引脚*/
#if !defined(CS_PIN) || (CS_PIN - CS_PIN - 1 == 1)
#undef CS_PIN
#define CS_PIN 10
#endif

/*数据或命令引脚*/
#if !defined(DC_PIN) || (DC_PIN - DC_PIN - 1 == 1)
#undef DC_PIN
#define DC_PIN 9
#endif

/*reset引脚*/
#if !defined(RST_PIN) || (RST_PIN - RST_PIN - 1 == 1)
#undef RST_PIN
#define RST_PIN 8
#endif