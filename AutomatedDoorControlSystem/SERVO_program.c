/*
 * SERVO_program.c
 *
 *  Created on: Mar 18, 2024
 *      Author: ali_a
 */

#include"BIT_math.h"
#include"STD_types.h"

#include"SERVO_interface.h"


#include"DIO_interface.h"
#include"PWM_interface.h"


void SERVO_voidInit(void)
{
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
}

void SERVO_voidStart(u8 copy_u8Angle)
{
	f32 prv_f32DutyCycle=0;
	prv_f32DutyCycle=((f32)copy_u8Angle*0.027777)+5;
	PWM_voidInitChannel_1A();
	PWM_voidGenerate_PWM_Channel_1A(50,prv_f32DutyCycle);


}
void SERVO_voidOff(void)
{
	PWM_voidStop_PWM_Channel_1A();
}
