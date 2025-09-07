#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

uint16_t led_state  =0;
void GPIO_Configure_C2()
{
	GPIO_InitTypeDef GPIO_Init_Structure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_Init_Structure.GPIO_Pin   = GPIO_Pin_5 | GPIO_Pin_6;
	GPIO_Init_Structure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Init_Structure);
	
	GPIO_Init_Structure.GPIO_Pin = GPIO_Pin_6;
	GPIO_Init_Structure.GPIO_Mode  = GPIO_Mode_IPU;
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
				if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6) == 0)
        {
            delay(20);  
            if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6) == 0) 
            {
                led_state = !led_state;   
                GPIO_WriteBit(GPIOA, GPIO_Pin_5, (BitAction) led_state);

                while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6) == 0);
            }
        }
	}
}

