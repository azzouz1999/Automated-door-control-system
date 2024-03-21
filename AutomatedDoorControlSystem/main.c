/*
 * main.c
 *
 *  Created on: Mar 18, 2024
 *      Author: ali_a
 */
#include <util/delay.h>
#include"STD_types.h"
#include"BIT_math.h"


#include"SERVO_interface.h"
#include"KPD_interface.h"
#include"LCD_interface.h"

#include"DIO_interface.h"
#include"PWM_interface.h"

int main()
{

	const u8 password[]="12345";
	u8 user_pass[5];
	u8 key=11;
	u8 counter=3;
	u8 kpd_counter=0;
	u8 check=0;

	const char text1[]="welcome";
	const char text2[]="Enter pass:";
	const char text3[]="wrong pass";
	const char text4[]="correct password";


	/*initializations*/
	LCD_voidInit();
	KPD_init();
	SERVO_voidInit();
	/*led*/
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN7,DIO_PIN_OUTPUT);
	/*buzzer*/
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN6,DIO_PIN_OUTPUT);

	/*welcome*/
	LCD_voidClearScreen();
	LCD_voidWriteString(text1);

	while(1)
	{
		_delay_ms(1000);
		LCD_voidClearScreen();
		/*please enter password:*/
		LCD_voidWriteString(text2);

		/*keypad enter password*/
		while(kpd_counter<5)
		{
			key=KPD_GetPressedKey();
			if(key>= '0' && key<='9')
			{
				user_pass[kpd_counter]=key;
				LCD_voidWriteChar('*');
				kpd_counter++;
			}

		}
		kpd_counter=0;

		/*check the password*/
		for(u8 i=0;i<5;i++)
		{
			if(user_pass[i]==password[i])
			{
				check++;
			}
		}

		/*correct pass*/
		if(check == 5)
		{
			LCD_voidClearScreen();
			LCD_voidWriteString(text4);
			SERVO_voidStart(180);
			break;
		}
		/*wrong pass*/
		else if(check < 4)
		{
			LCD_voidClearScreen();
			LCD_voidWriteString(text3);
			/*number of entries*/
			counter--;
			check=0;

		}
		/*if number of entries is 0 break and halt*/
		if(counter<=0)
		{
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,DIO_PIN_OUTPUT);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN6,DIO_PIN_OUTPUT);
			break;
		}

	}

}
