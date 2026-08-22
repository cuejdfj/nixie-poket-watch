#include "time.h"
RTC_DS3231 rtc;

  int time_state = HOUR;//当前时分显示状态
  int date_state = MONTH;//当前月日显示状态

  unsigned long  time_last_sign = 0;//时分显示过去时间戳
  unsigned long  date_last_sign = 0;//月日显示过去时间戳
  const unsigned long stoptime = 500;//时间间隔

  int display = TIME;

  int month;
  int day;
  int hour;
  int minute;
  int week;

  int lasthour = -1;
  int lastminute = -1;
  int lastmonth = -1;
  int lastday = -1;
  int lastweek = -1;

//===============刷新时间数据函数定义==================
  void displaytime(){
    DateTime currenttime = rtc.now();//DateTime是数据类型，currenttime是声明的变量名,.now()是一个自动抓时间数据的函数，相当于把时间数据赋值给一个叫currenttime的变量中
    month = currenttime.month();
    day = currenttime.day();
    hour = currenttime.hour();
    minute = currenttime.minute();
    week = currenttime.dayOfTheWeek();
  }

//==============时分功能函数定义=============
  void time_mode(){
    unsigned long current_sign = millis();//刷新当前时间戳

    if((current_sign - time_last_sign) >= stoptime){
      time_last_sign = current_sign;
      displaytime();//刷新时间数据

      if(time_state == HOUR){

        if(lasthour != hour){//检测上一刻小时是否与当前小时相等，如果不相等就熄灭错误数字校准为正确小时
         qs16_1A_off(lasthour / 10);
         qs16_1B_off(lasthour % 10);
         refreshAll();

         qs16_1A_on(hour / 10);
         qs16_1B_on(hour % 10);
         refreshAll();
         lasthour = hour;
        }
      
       time_state = MINUTE;
      }

      else if(time_state == MINUTE){

        if(lastminute != minute){//检测上一刻分钟是否与当前分钟相等，如果不相等就熄灭错误数字校准为正确分钟
         qs16_1A_off(minute / 10);
         qs16_1B_off(minute % 10);
         refreshAll();

         qs16_1A_on(minute / 10);
         qs16_1B_on(minute % 10);
         refreshAll();
         lastminute = minute;
        }

       time_state = HOUR;
      }
    }
  }
 
//===================月日功能函数定义=========================
  void date_mode(){
    unsigned long current_sign = millis();//刷新当前时间戳

    if((current_sign - date_last_sign) >= stoptime){
      date_last_sign = current_sign;
      displaytime();//刷新时间数据

      if(date_state == MONTH){

        if(lastmonth != month){//检测上一刻月份是否与当前月份相等，如果不相等就熄灭错误数字校准为正确月份
         qs16_1A_off(month / 10);
         qs16_1B_off(month % 10);
         refreshAll();

         qs16_1A_on(month / 10);
         qs16_1B_on(month % 10);
         refreshAll();
         lastmonth = month;
        }
      
       date_state = DAY;
      }

      else if(date_state == DAY){

        if(lastday != day){//检测上一刻日期是否与当前日期相等，如果不相等就熄灭错误数字校准为正确日期
         qs16_1A_off(day / 10);
         qs16_1B_off(day % 10);
         refreshAll();

         qs16_1A_on(day / 10);
         qs16_1B_on(day % 10);
         refreshAll();
         lastday = day;
        }

       date_state = MONTH;
      }
    }
  }

//========================星期函数定义===========================
  void week_mode(){
    if(week != lastweek){
      teammate_off_all();
      refreshAll();
      lastweek = week;

      for(int i = week;i != 0;i-=1){
        teammate_on(i);
      }
      refreshAll();
    }
  }

//==================总的时间功能函数定义=====================
  void clock_mode(){
    if(key_switch){
      key_switch = false;

      if(display == TIME){
        display = DATE;
      }
      else{
        display = TIME;
      }
    }

    if(display == TIME){
      time_mode();
    }

    if(display == DATE){
      date_mode();
    }
  }
 
 
 
 
  

























