#ifndef _GPIO_EXTI_H
#define _GPIO_EXTI_H

#include "stm32f10x.h"                  // Device header
//GPIO输出有关按键的宏定义（对于引脚和寄存器端口,以及时钟进行重定义）

//按键KEY1
#define KEY1_INT_GPIO_PIN				GPIO_Pin_0
#define KEY1_INT_GPIO_PORT				GPIOA
#define KEY1_INT_GPIO_CLK				RCC_APB2Periph_GPIOA
#define	KEY1_INT_GPIO_Mode				GPIO_Mode_IN_FLOATING
//按键KEY2
#define KEY2_INT_GPIO_PIN				GPIO_Pin_13
#define KEY2_INT_GPIO_PORT				GPIOC
#define KEY2_INT_GPIO_CLK				RCC_APB2Periph_GPIOC
#define	KEY2_INT_GPIO_Mode				GPIO_Mode_IN_FLOATING

//定义KEY的中断时钟
#define KEY1_AFIO	RCC_APB2Periph_AFIO
#define KEY2_AFIO	RCC_APB2Periph_AFIO
//定义EXTI的配置宏
//KEY1的EXTI
#define	KEY1_EXTI_Line			EXTI_Line0
#define	KEY1_EXTI_Mode			EXTI_Mode_Interrupt
#define	KEY1_EXTI_Trigger		EXTI_Trigger_Rising
//KEY2的EXTI
#define	KEY2_EXTI_Line			EXTI_Line13
#define	KEY2_EXTI_Mode			EXTI_Mode_Interrupt
#define	KEY2_EXTI_Trigger		EXTI_Trigger_Falling

//配置NVIC的相关宏
//KEY1的NVIC
#define	NVIC_PriorityGroup_KEY1						NVIC_PriorityGroup_2
#define	NVIC_IRQChannel_KEY1						EXTI0_IRQn
#define	NVIC_IRQChannelPreemptionPriority_KEY1		1
#define	NVIC_IRQChannelSubPriority_KEY1				1
//KEY2的NVIC
#define	NVIC_PriorityGroup_KEY2						NVIC_PriorityGroup_2
#define	NVIC_IRQChannel_KEY2						EXTI15_10_IRQn
#define	NVIC_IRQChannelPreemptionPriority_KEY2		1
#define	NVIC_IRQChannelSubPriority_KEY2				2

//配置中断函数相对应的宏
#define	KEY1_IRQHandler			EXTI0_IRQHandler
#define	KEY2_IRQHandler			EXTI15_10_IRQHandler



//配置EXTI事件线
//KEY1事件线
#define EXTI_GPIO_LINE_KEY1			GPIO_PortSourceGPIOA
#define EXTI_Pin_LINE_KEY1			GPIO_PinSource0
//KEY1事件线
#define EXTI_GPIO_LINE_KEY2			GPIO_PortSourceGPIOC
#define EXTI_Pin_LINE_KEY2			GPIO_PinSource13
//声明按键函数
void EXTI_KEY_Config(void);


#endif /*_GPIO_EXTI_H*/
