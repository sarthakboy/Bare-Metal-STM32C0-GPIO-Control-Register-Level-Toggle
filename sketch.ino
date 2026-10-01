#include "stm32c0xx.h"
#include <stdbool.h>

bool previous_state = 1;
bool toggle = 0;
void delay(void){
  for(volatile int i = 0;i<200000;i++){}
}

int main(){
  RCC->IOPENR |= RCC_IOPENR_GPIOCEN;
  RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
  GPIOC->MODER &= ~(3UL<<(13*2));
  GPIOC->MODER &= ~(3UL<<(14*2));
  GPIOC->MODER |= (1UL<<(13*2));
  GPIOC->MODER |= (1UL<<(14*2));

  GPIOA->MODER &= ~(3UL<<(0*2));
  GPIOA->PUPDR &= ~(3UL<<(0*2));
  GPIOA->PUPDR |= (1UL<<(0*2));//PULLUP-ENABLE

  while(1){
    bool current_state = (GPIOA->IDR & (1UL << 0));  // Read only PA0

    
    if (previous_state == 1 && current_state ==0){
      toggle ^=1;
      delay();
    }
    
    

    if(toggle){
      GPIOC->ODR |= (1UL<<13);
      GPIOC->ODR &= ~(1UL<<14);
      delay();
    }
    else if (!toggle){
      GPIOC->ODR &= ~(1UL<<13);
      GPIOC->ODR |= (1UL<<14);
      delay();
    }

    previous_state = current_state;
  }
}