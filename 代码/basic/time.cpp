#include <time.h>

//=============这里统一设置时间，若电池断电了要手动校准================
  int year = 0;
  int month = 0;
  int day = 0;
  int hour = 0;
  int minute = 0;
  int second = 0;
  
//===============初始化函数定义=================
  void inittime(){
    if(!rtc.begin()){//芯片定义名.begin()函数是用于开始通讯，成功就返回true，失败就返回false，！是取反符号，目的是在芯片返回false的时候让if条件为真
    while(1){}//没找到就卡死
    }

    if(rtc.lostPower()){
    rtc.adjust(DateTime(year,month,day,hour,minute,second));//上电时读设置的日期和时间给芯片，DateTime()将字符串打包为时间对象，.adjust()将对象写入芯片
    }//掉电了就读前面设置的时间给芯片
  }

  DateTime currenttime = time.now();//DateTime是数据类型，currenttime是声明的变量名,time.now()是一个自动抓时间数据的函数，相当于把时间数据赋值给一个叫currenttime的变量中
 
//==============时分功能函数定义=============
  void time_mode(){
    qs16_1A_on(currenttime.hour() / 10);



  }
 
 
 
 
 
 
 
 
 
 
  Serial.print("年：");
  Serial.println(currenttime.year());
  Serial.print("月：");
  Serial.println(currenttime.month());
  Serial.print("日：");
  Serial.println(currenttime.day());
  Serial.print("星期：");
  Serial.println(currenttime.dayOfTheWeek());
  Serial.print("时：");
  Serial.println(currenttime.hour());//从一个DataTime类型的变量currenttime中读取指定的数据，这里读的是小时
  Serial.print("分：");
  Serial.println(currenttime.minute());//因为我们想打印的是一个函数的值，而不是一个变量，所以now.minute后必须跟()来表示他是个函数而不是变量
  Serial.print("秒：");
  Serial.println(currenttime.second());
  delay(1000);
}