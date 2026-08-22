#include "nixie.h"
#include "time.h"
#include "key.h"
#include "BadUSB.h"

#define MENU_ON  1
#define MENU_OFF 0

int step = 0;
int step_max = 7;

int menu_system = MENU_ON;

void setup() {
  menu_system = MENU_ON;
  step = 0;
  initNixie();
  refreshAll();
  initkey();

  in19_A_on(6);//手动刷新步数1对应辉光管
  refreshAll();
}

void loop() {
  key_engine();

  if(menu_system == MENU_ON){

    if(key_switch){
      key_switch = false;

      step+= 1;
      if(step > step_max){
        step = 0;
      }

      switch(step){
        case 0: 
        in19_A_off(7);//熄灭上一个
        in19_A_on(6);//对应μ，时间功能
        refreshAll();
        break;

        case 1:
        in19_A_off(6);
        in19_A_on(3);//对应℃，BadUSB功能
        refreshAll();
        break;

        case 2:
        in19_A_off(3);
        in19_A_on(0);
        refreshAll();
        break;

        case 3:
        in19_A_off(0);
        in19_A_on(1);
        refreshAll();
        break;

        case 4:
        in19_A_off(1);
        in19_A_on(2);
        refreshAll();
        break;

        case 5:
        in19_A_off(2);
        in19_A_on(4);
        refreshAll();
        break;

        case 6:
        in19_A_off(4);
        in19_A_on(5);
        refreshAll();
        break;

        case 7:
        in19_A_off(5);
        in19_A_on(7);
        refreshAll();
        break;
      }
    }

    if(key_ok){
      key_ok = false;
      menu_system = MENU_OFF;
    }
  }

  if(menu_system == MENU_OFF){

    switch(step){
      case 0:
      clock_mode();
      week_mode();
      break;

      case 1:
      script_select_mode();
      script_run_mode();
      break;

      case 2:
      
      break;

      case 3:
      
      break;

      case 4:
      
      break;

      case 5:
      
      break;

      case 6:
      
      break;

      case 7:
      
      break;
    }

    if(key_cancel){
      key_cancel = false;
      teammate_off_all();
      qs16_1B_off_all();
      qs16_1A_off_all();
      refreshAll();

      menu_system = MENU_ON;
    }
  }
}















































