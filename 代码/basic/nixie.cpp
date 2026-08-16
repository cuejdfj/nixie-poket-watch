#include "nixie.h"//自己写的头文件用""包裹，软件带的用<>包裹

  byte nixie_control[5] = {
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
};//声明并赋值5组二进制数字

//==========初始化函数定义===========
void initNixie(){
  pinMode(DATA_PIN,OUTPUT);
  pinMode(CLOCK_PIN,OUTPUT);
  pinMode(LATCH_PIN,OUTPUT);

  int i = 4;//每次循环后减去1，刚好循环5次，把5组二进制数字依次发给移位寄存链
    digitalWrite(LATCH_PIN,LOW);
    while(i>=0){
      shiftOut(DATA_PIN,CLOCK_PIN,LSBFIRST,nixie_control[i]);//默认先发从上往下数最后一组二进制数字
      i-=1;
    }
    digitalWrite(LATCH_PIN,HIGH);
}

//==========氖管控制===========
  void teammate_on(int num){
    if(num>=5 && num<=9){
    nixie_control[4] |= 0b00000001<<(12-num);
    }

    if(num<5 && num>0){
      nixie_control[3] |= 0b00000001<<(4-num);
    }
  }

  void teammate_off(int num){
    if(num>=5 && num<=9){
    nixie_control[4] &= ~(0b00000001<<(12-num));
    }

    if(num<5 && num>0){
      nixie_control[3] &= ~(0b00000001<<(4-num));
    }
  }

//=========辉光管QS16-1B控制=============
void qs16_1B_on(int num){
  if(num == 1 || num == 2 || num == 5 || num == 0){
    if(num == 1){
    nixie_control[3] |= 0b00000001<<7;
    }
    if(num == 2){
    nixie_control[3] |= 0b00000001<<6;
    }
    if(num == 5){
    nixie_control[3] |= 0b00000001<<5;
    }
    if(num == 0){
    nixie_control[3] |= 0b00000001<<4;
    }
  }

    if(num == 9 || num == 8 || num == 7 || num == 6){
    nixie_control[2] |= 0b00000001<<(9-num);
    }
    if(num == 4 || num == 3){
    nixie_control[2] |= 0b00000001<<(8-num);
    }
  }

void qs16_1B_off(int num){
  if(num == 1 || num == 2 || num == 5 || num == 0){
    if(num == 1){
    nixie_control[3] &= ~(0b00000001<<7);
    }
    if(num == 2){
    nixie_control[3] &= ~(0b00000001<<6);
    }
    if(num == 5){
    nixie_control[3] &= ~(0b00000001<<5);
    }
    if(num == 0){
    nixie_control[3] &= ~(0b00000001<<4);
    }
  }
    if(num == 9 || num == 8 || num == 7 || num == 6){
    nixie_control[2] &= ~(0b00000001<<(9-num));
    }
    if(num == 4 || num == 3){
    nixie_control[2] &= ~(0b00000001<<(8-num));
    }
  }

//============辉光管QS16-1A控制==============
  void qs16_1A_on(int num){
    if(num == 5){
    nixie_control[2] |= 0b00000001<<7;
    }
    if(num == 0){
    nixie_control[2] |= 0b00000001<<6;
    }

    if(num<=9 && num>=6){
    nixie_control[1] |= 0b00000001<<(9-num);
    }
    if(num<=4 && num>=1){
    nixie_control[1] |= 0b00000001<<(8-num);
    }
  }

  void qs16_1A_off(int num){
    if(num == 5){
    nixie_control[2] &= ~(0b00000001<<7);
    }
    if(num == 0){
    nixie_control[2] &= ~(0b00000001<<6);
    }

    if(num<=9 && num>=6){
    nixie_control[1] &= ~(0b00000001<<(9-num));
    }
    if(num<=4 && num>=1){
    nixie_control[1] &= ~(0b00000001<<(8-num));
    }
  }

//=============辉光管IN19-A控制===============
  void in19_A_on(int num){
    if(num<=7 && num>=0){
    nixie_control[0] |= 0b00000001<<num;
    }
  }

  void in19_A_off(int num){
    if(num<=7 && num>=0){
    nixie_control[0] &= ~(0b00000001<<num);
    }
  }

//========刷新函数定义==========
  void refreshAll(){
    int i = 4;
    digitalWrite(LATCH_PIN,LOW);
    while(i>=0){
      shiftOut(DATA_PIN,CLOCK_PIN,LSBFIRST,nixie_control[i]);
      i-=1;
    }
    digitalWrite(LATCH_PIN,HIGH);
  }






















