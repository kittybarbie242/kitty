#include "stm32f10x.h"
#include "stm32f10x_gpio.h"


void GPIO_Configure_C2()
{
	GPIO_InitTypeDef GPIO_Init_Structure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_Init_Structure.GPIO_Pin   = GPIO_Pin_5 | GPIO_Pin_6;
	GPIO_Init_Structure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Init_Structure);
	
}
void delay(int time)
{
	for(int i = 0; i < time; i++)
	{
		for(int j = 0; j < 0x2AFF; j++);
	}
}
int main()
{
	GPIO_Configure_C2();
	while(1)
	{
				GPIO_SetBits(GPIOA, GPIO_Pin_5);
        GPIO_ResetBits(GPIOA, GPIO_Pin_6);
        delay(1000);
        GPIO_SetBits(GPIOA, GPIO_Pin_6);
        GPIO_ResetBits(GPIOA, GPIO_Pin_5);
        delay(1000);
	}
}

