#ifndef NIXIE_H//如果宏NIXIE_H没有被定义，就执行下一段（防止头文件被重复引用）
#define NIXIE_H//定义一个宏NIXIE_H

#include <Arduino.h>//引入Arduino核心库

#define DATA_PIN MOSI//定义主设备引脚为宏
#define CLOCK_PIN SCK//定义时钟线引脚为宏
#define LATCH_PIN A5//定义锁存引脚为宏

void initNixie();//自己弄一个初始化辉光管的函数
void in19_A_on(int num);//自己弄一个指定辉光管显示数字的函数
void qs16_1A_on(int num);
void qs16_1B_on(int num);
void teammate_on(int num);

void teammate_off(int num);
void qs16_1B_off(int num);
void qs16_1A_off(int num);
void in19_A_off(int num);

void refreshAll();




#endif//预处理阶段执行完毕