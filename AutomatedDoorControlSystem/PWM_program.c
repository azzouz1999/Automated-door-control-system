/*
 * PWM_program.c
 *
 *  Created on: Mar 17, 2024
 *      Author: ali_a
 */
#include "BIT_math.h"
#include "STD_types.h"

#include "PWM_config.h"
#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_register.h"

void PWM_voidInitChannel_0(void)
{
	/*set mode*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

	/*non inverting*/
	CLEAR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);

	/**/

}
void PWM_voidGenerate_PWM_Channel_0(u8 copy_u8DutyCycle)
{
	if(copy_u8DutyCycle<=100)
	{
		OCR0 = (((u16)copy_u8DutyCycle*256)/100)-1;

		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);


	}
	else
	{
		/*report an error*/
	}
}
void PWM_voidInitChannel_1A(void)
{
	/*fast PWM mode 14*/
	CLEAR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);


	/*non inverting*/
	SET_BIT(TCCR1A,COM1A1);
	CLEAR_BIT(TCCR1A,COM1A0);

}
void PWM_voidStop_PWM_Channel_1A(void)
{
	/*prescaler 64*/
	CLEAR_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);
}
void PWM_voidGenerate_PWM_Channel_1A(u32 copy_u32Frequency_hz,f32 copy_f32DutyCycle)
{
	if(100>=copy_f32DutyCycle)
	{
		/*tick time 4us and 64 prescaler*/
		ICR1 = ((1000000UL/copy_u32Frequency_hz)/4)-1;
		OCR1A = ((copy_f32DutyCycle*(ICR1 +1))/100)-1;
		/*prescaler 64*/
		SET_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
	}
}
