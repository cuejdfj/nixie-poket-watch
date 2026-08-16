#ifndef TIME_H//如果宏TIME_H没有被定义，就执行下一段（防止头文件被重复引用）
#define TIME_H//定义一个宏TIME_H

#include <Wire.h>//I2C通讯库
#include "nixie.h"
#include <RTClib.h>//封装了DS3231的操作
#include <Arduino.h>//引入Arduino核心库
RTC_DS3231 rtc

void time_mode();
void date_mode();
void inittime();//初始化函数
