# L298N函式庫
我們旨在於創建簡單的、好記的、強大的API，讓使用者能夠輕鬆地控制L298N電機驅動器。

## 版本 V2.0.2
- 修復了`motorSetPwm`的嚴重bug。
- 新增說明文檔。
- 非常規函式(`PwmPwm`等)仍在測試，暫不建議使用。

## 安裝
在您的arduino專案資料夾中放入`L298N.c`和`L298N.h`兩個檔案，並在您的程式碼中包含`#include "L298N.h"`。

## 函式
所由函式皆以motor開頭。命名風格為大駝峰。

函式|參數|回傳|說明
---|---|---|---
Create |pin1,pin2 |回傳`MOTOR*` | 建立一個無法調速的馬達物件，pin1和pin2為控制馬達的兩個腳位
CreatePwm |pin1,pin2,pwmPin |回傳`MOTOR*` | 建立一個帶有PWM控制的馬達物件，pin1和pin2為控制馬達的兩個腳位，pwmPin為PWM控制腳位
Init |motor |無 | 初始化馬達物件，設定腳位為輸出
Set | motor,turn |無 | 設定馬達轉動方向，turn為CW表示正轉，CCW表示反轉，STOP表示停止
SetPwm | motor,speed |無 | 設定馬達轉速，speed為0-255的值，0表示停止，255表示全速

## 範例
```c
#include <Arduino.h>
#include "L298N.h"	// 包含L298N函式庫

MOTOR* motor=NULL; // 宣告一個指向馬達物件的指標，初始值為NULL

void setup() {
  motor = motorCreatePwm(2, 3, 4); // 建立一個帶有PWM控制的馬達物件，腳位為2、3和4
  Init(motor); // 初始化馬達物件
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
```