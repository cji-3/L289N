//版本：V2.0.1

#ifndef _L298N_H_
#define _L298N_H_

#include<stdint.h>

#define _L298N_N_PWMPIN (0b10000000)

#ifdef __cplusplus
extern "C"{
#endif

//馬達物件[結構]
typedef struct{
	uint8_t pin1;
	uint8_t pin2;
	uint8_t pwmPin;
}MOTOR;

//方向模式[常數]
typedef enum{
	STOP,	/**< 停止 */
	CW,		/**< 順時針 */
	CCW		/**< 逆時針 */
}MOTOR_TURN_MOD;

/**
 * \brief 創建一個馬達
 *
 * 範例：`MOTOR* car=motorCreate(2,3);`
 *
 * \param pin1 連接至L298N的IN1/IN3之腳位
 * \param pin2 連接至L298N的IN2/IN4之腳位
 * \return MOTOR結構之指標
 */
MOTOR* motorCreate(uint8_t pin1,uint8_t pin2);

/**
 * \brief 創建一個可使用L298N的PWM波調速腳調速的馬達
 *
 * 範例：`MOTOR* car=motorCreatePwm(2,3,4);`
 *
 * \param pin1 連接至L298N的IN1/IN3之腳位
 * \param pin2 連接至L298N的IN2/IN4之腳位
 * \param pwmPin 連接至L298N的EN1/EN2之腳位(必須使用PWM腳)
 * \return MOTOR結構之指標
 */
MOTOR* motorCreatePwm(uint8_t pin1,uint8_t pin2,uint8_t pwmPin);

/**
 * \brief 初始化馬達並且預設不轉速度為0
 * \param MOTOR結構之指標
 */
void motorInit(MOTOR* motor);

/**
 * \brief 設定馬達之轉向
 *
 * \param motor MOTOR結構之指標
 * \param turnMod 馬達轉向模式
 *	STOP:停止
 *	CW:順時針
 *	CCW:逆時針
 */
void motorSet(MOTOR* motor,MOTOR_TURN_MOD turnMod);

/**
 * \brief 設定馬達之速度
 *
 * \param motor MOTOR結構之指標
 * \param pwm 轉速(PWM)
 */
void motorSetPwm(MOTOR* motor,uint16_t pwm);

#ifdef __cplusplus
}
#endif

#endif