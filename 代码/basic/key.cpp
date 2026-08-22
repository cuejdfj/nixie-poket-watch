#include "key.h"
//对外事件（取消，切换，确定）
  bool key_cancel = false;
  bool key_switch = false;
  bool key_ok = false;

//声明一个结构体，用typedef使其别名为keystate，可用作数据类型
  typedef struct{
    byte pin;//引脚
    bool last_level;//引脚上一次的电平
    unsigned long press_time;//按压时间
  }keystate;

  keystate keys[3] = {//这个数组就是声明三个变量，存的东西分别是引脚，引脚上一次的电平，按压时间，一共存三份给取消，选择，确定用
    {KEY_CANCEL_PIN, true, 0},
    {KEY_SWITCH_PIN, true, 0},//三个大括号里的内部的内容是在分别给pin,last_level,press_time赋值
    {KEY_OK_PIN,     true, 0}
  };

  void initkey(void){
    for(byte i=0;i<3;i+=1){//给三个变量都初始化
      pinMode(keys[i].pin, INPUT_PULLUP);
      keys[i].last_level = true;
      keys[i].press_time = 0;
    }
  }

  void clear_key(void){//重置事件布尔值为false
    key_cancel = false;
    key_switch = false;
    key_ok = false;
  }

  void key_engine(void){
    unsigned long current_sign = millis();//更新当前时间戳

    for(int i = 0;i < 3;i += 1){//循环检测三个按钮的状态
      bool current_level = digitalRead(keys[i].pin);

      if(current_level != keys[i].last_level){//检测到电平变化就更新过去时间戳
        keys[i].press_time = current_sign;
      }

      if( (current_sign - keys[i].press_time) >= KEY_DEBOUNCE_MS ){//消抖逻辑
          
        if(current_level == true && keys[i].last_level == false){//检测上升沿，若有就更改指定事件的布尔值
          switch(i){
            case 0: key_cancel = true; break;
            case 1: key_switch = true; break;
            case 2: key_ok     = true; break;
          }
        }
        keys[i].last_level = current_level;
      }
    }
  }




































































