#ifndef KEY_H
#define KEY_H

#include <Arduino.h>

//硬件引脚
#define KEY_CANCEL_PIN  A2
#define KEY_SWITCH_PIN  A3
#define KEY_OK_PIN      A4

#define KEY_DEBOUNCE_MS    20    //消抖时间

//事件标志，只维持一帧，用完要手动置false
extern bool key_cancel;
extern bool key_switch;
extern bool key_ok;

void initkey(void);//初始化按钮
void key_engine(void);//按钮驱动
void clear_key(void);//重置事件

#endif