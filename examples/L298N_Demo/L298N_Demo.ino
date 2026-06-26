#include <Arduino.h>
#include "L298N.h"	// 包含L298N函式庫

MOTOR* motor=NULL; // 宣告一個指向馬達物件的指標，初始值為NULL

void setup() {
  motor = motorCreatePwm(2, 3, 4); // 建立一個帶有PWM控制的馬達物件，腳位為2、3和4
  motorInit(motor); // 初始化馬達物件
}

void loop() {
  motorSet(motor, CW); // 設定馬達正轉
  motorSetPwm(motor, 255); // 設定馬達全速
  delay(2000); // 等待2秒
  motorSet(motor, CCW); // 設定馬達反轉
  motorSetPwm(motor, 128); // 設定馬達半速
  delay(2000); // 等待2秒
  motorSet(motor, STOP); // 停止馬達
  delay(2000); // 等待2秒
}