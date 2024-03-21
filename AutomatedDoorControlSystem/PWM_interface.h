/*
 * PWM_interface.h
 *
 *  Created on: Mar 17, 2024
 *      Author: ali_a
 */

#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

void PWM_voidInitChannel_0(void);
void PWM_voidGenerate_PWM_Channel_0(u8 copy_u8DutyCycle);

void PWM_voidInitChannel_1A(void);
void PWM_voidGenerate_PWM_Channel_1A(u32 copy_u32Frequency_hz,f32 copy_f32DutyCycle);
void PWM_voidStop_PWM_Channel_1A(void);
void PWM_voidInitChannel_1B(void);



#endif /* PWM_INTERFACE_H_ */
