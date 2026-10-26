#include "buzzer.h"
#include "stm32f4xx.h"
#include "delay.h"


void buzzer_init(void){
	//enable GPIO B clock
	RCC->AHB1ENR |= (1 << 1);
	//configure PB3 as output
	GPIOB->MODER|=GPIO_MODER_MODE3_0;
	GPIOB->MODER&=~GPIO_MODER_MODE3_1;
	//configure PB3 as push-pull output
	GPIOB->OTYPER &= ~(0 << 3);
	//set to low as initial state
	GPIOB->ODR &= ~(0 << 3);

}

void buzzer_on(void){
	GPIOB->ODR ^= (1 << 3);
	GPIOB->ODR ^= (0 << 3);
}

void buzzer_off(void){
	GPIOB -> ODR &= ~(0 << 3);
}
