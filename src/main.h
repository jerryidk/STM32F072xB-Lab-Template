#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#include "stm32f072xb.h"

/*
 ADDTIONAL HEADER FILE GOES HERE ....
*/

#define REDLED (6)
#define BLUELED (7)
#define ORANGELED (8)
#define GREENLED (9)
 

extern volatile uint32_t tick;

/**
 * Basic support.
*/
void HSI48_EN(void)
{
  // Flash configuration
  FLASH->ACR |= (FLASH_ACR_LATENCY | FLASH_ACR_PRFTBE);	
  RCC->CR2 |= RCC_CR2_HSI48ON; // hsi48 on
  // See if HSI is ready to be selected 
  while((RCC->CR2 & RCC_CR2_HSI48RDY) != RCC_CR2_HSI48RDY);
  /* Select HSI48 as system clock source */
  RCC->CFGR |= RCC_CFGR_SW_HSI48;
  /* Wait for HSI48 clock to be selected as system clock */
  while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI48);  

}

void DELAY(int t)
{
  uint32_t start = tick;
  while (tick - start < t);
}

#endif
