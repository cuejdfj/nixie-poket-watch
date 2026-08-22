#ifndef TIME_H//如果宏TIME_H没有被定义，就执行下一段（防止头文件被重复引用）
#define TIME_H//定义一个宏TIME_H

#include <Wire.h>//I2C通讯库
#include "nixie.h"
#include <RTClib.h>//封装了DS3231的操作
#include <Arduino.h>//引入Arduino核心库
#include "key.h"
extern RTC_DS3231 rtc;

#define HOUR   0
#define MINUTE 1
#define MONTH  2
#define DAY    3

#define TIME 0//显示时分状态
#define DATE 1//显示月日状态

void clock_mode();//总的时间功能

void time_mode();//时分函数
void date_mode();//月日函数
void week_mode();//星期函数
void displaytime();//刷新时间数据函数

#endif