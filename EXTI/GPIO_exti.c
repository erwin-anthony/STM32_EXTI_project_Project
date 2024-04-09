#include "GPIO_exti.h"

//初始化NVIC
//(只可以被exti.c文件调用。因为这是跟中断线对应的NVIC的中断路线配置)
//为了下面中断优先级的NVIC配置，建议函数EXTI_NVIC_Config（）放前面
static void EXTI_NVIC_Config(void){
	//声明结构体变量
	NVIC_InitTypeDef NVIC_InitStruct_EXTI_KEY1;
	NVIC_InitTypeDef NVIC_InitStruct_EXTI_KEY2;
	//配置中断优先级分组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_KEY1);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_KEY2);
	//配置NVIC寄存器
	//IRQ是中断源。Tip:后几位使用不同（EXTI9_5_IRQn或者EXTI15_10_IRQn）
	NVIC_InitStruct_EXTI_KEY1.NVIC_IRQChannel = NVIC_IRQChannel_KEY1;
	NVIC_InitStruct_EXTI_KEY2.NVIC_IRQChannel = NVIC_IRQChannel_KEY2;
	
	//抢占优先级（数字越小，优先级越高）
	NVIC_InitStruct_EXTI_KEY1.NVIC_IRQChannelPreemptionPriority = NVIC_IRQChannelPreemptionPriority_KEY1;
	NVIC_InitStruct_EXTI_KEY2.NVIC_IRQChannelPreemptionPriority = NVIC_IRQChannelPreemptionPriority_KEY2;
	
	//子优先级
	NVIC_InitStruct_EXTI_KEY1.NVIC_IRQChannelSubPriority = NVIC_IRQChannelSubPriority_KEY1;
	NVIC_InitStruct_EXTI_KEY2.NVIC_IRQChannelSubPriority = NVIC_IRQChannelSubPriority_KEY2;
	//NVIC使能
	NVIC_InitStruct_EXTI_KEY1.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct_EXTI_KEY2.NVIC_IRQChannelCmd = ENABLE;
	
	
	//使用库函数初始化NVIC结构体
	NVIC_Init(&NVIC_InitStruct_EXTI_KEY1);
	NVIC_Init(&NVIC_InitStruct_EXTI_KEY2);
	

}






//按键函数以及EXTI初始化编写
void EXTI_KEY_Config(void){
	
	//变量声明要放最前面
	//按键GPIO的结构体(每一个引脚都对应一个结构体)
	GPIO_InitTypeDef GPIO_InitStruct_EXTI_KEY1;
	GPIO_InitTypeDef GPIO_InitStruct_EXTI_KEY2;
	EXTI_InitTypeDef EXTI_InitStruct_EXTI_KEY1;
	EXTI_InitTypeDef EXTI_InitStruct_EXTI_KEY2;
	
	
	//配置中断优先级（要放在EXTI使能前面）
	EXTI_NVIC_Config();
	
	

	//时钟的使能
	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK,ENABLE);
	RCC_APB2PeriphClockCmd(KEY2_INT_GPIO_CLK,ENABLE);

	//对控制EXTI按键的引脚，引脚输出模式配置

	GPIO_InitStruct_EXTI_KEY1.GPIO_Pin = KEY1_INT_GPIO_PIN;
	GPIO_InitStruct_EXTI_KEY1.GPIO_Mode = KEY1_INT_GPIO_Mode;
	GPIO_InitStruct_EXTI_KEY2.GPIO_Pin = KEY2_INT_GPIO_PIN;
	GPIO_InitStruct_EXTI_KEY2.GPIO_Mode = KEY2_INT_GPIO_Mode;


	//调用库函数，初始化GPIO
	GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStruct_EXTI_KEY1);
	GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStruct_EXTI_KEY2);

	
	//初始化EXTI
	//打开EXTI时钟
	RCC_APB2PeriphClockCmd(KEY1_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(KEY2_AFIO,ENABLE);
	//EXTI输入线的选择
	GPIO_EXTILineConfig(EXTI_GPIO_LINE_KEY1, EXTI_Pin_LINE_KEY1);
	GPIO_EXTILineConfig(EXTI_GPIO_LINE_KEY2, EXTI_Pin_LINE_KEY2);
	
	
	//配置EXTI结构体
	//KEY1的EXTI结构体
	EXTI_InitStruct_EXTI_KEY1.EXTI_Line = KEY1_EXTI_Line;
	EXTI_InitStruct_EXTI_KEY1.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct_EXTI_KEY1.EXTI_Mode = KEY1_EXTI_Mode;
	EXTI_InitStruct_EXTI_KEY1.EXTI_Trigger = KEY1_EXTI_Trigger;
	//KEY2的EXTI结构体
	EXTI_InitStruct_EXTI_KEY2.EXTI_Line = KEY2_EXTI_Line;//每一条事件线，对应一个GPIO端口的引脚
	EXTI_InitStruct_EXTI_KEY2.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct_EXTI_KEY2.EXTI_Mode = KEY2_EXTI_Mode;
	EXTI_InitStruct_EXTI_KEY2.EXTI_Trigger = KEY2_EXTI_Trigger;
	
	//初始化EXTI结构体
	EXTI_Init(&EXTI_InitStruct_EXTI_KEY1);
	EXTI_Init(&EXTI_InitStruct_EXTI_KEY2);
	
	
}
