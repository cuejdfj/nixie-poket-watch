#include "BadUSB.h"

  int script = 1;
  int last_script = 0;

  void script_select_mode(){
    if (key_switch){
     key_switch = false;
     script +=1;
    }

    if(script > 9){
      script = 1;
    }

    if(last_script != script){
     teammate_off_all();
     refreshAll();
     teammate_on(script);
     refreshAll();
     last_script = script;
    }
  }

  void script_run_mode(){
    if(key_ok){
      key_ok = false;

      if(USBStatus.isActive()){//检测是否和电脑握手成功
        switch(script){
          case 1 ://预留脚本操作

            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press('r');
            Keyboard.releaseAll();
            delay(150);
            Keyboard.println("cmd");
            delay(300);
            Keyboard.println("echo 你好来自辉光管BadUSB");
            Keyboard.println("pause");

          break;

          case 2 :

          break;

          case 3 :

          break;

          case 4 :

          break;

          case 5 :

          break;

          case 6 :

          break;

          case 7 :

          break;

          case 8 :

          break;
  
          case 9 :

          break;
        }
      }
    }
  }