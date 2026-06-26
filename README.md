# L298N函式庫
我們旨在於創建簡單的、好記的、強大的API，讓使用者能夠輕鬆地控制L298N電機驅動器。

## 版本 V2.1.0
 - 更新更新了資料夾結構以及新增了一些檔案以符合arduino函式庫的規範。
 - 暫時刪除了非常規函式(`PwmPwm`後綴等)的支持。

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