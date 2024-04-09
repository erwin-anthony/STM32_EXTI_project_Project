#include "stm32f10x.h"                  // Device header
#include "bsp_led.h"
#include "GPIO_exti.h"

int main(void){
	
	
	
	//调用LED函数
	LED_GPIO_Config();
	
	//调用中断函数
	EXTI_KEY_Config();
	
	
	
	
	while(1){
	
	
	}


}
