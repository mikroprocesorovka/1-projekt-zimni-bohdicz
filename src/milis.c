#include "milis.h"

#if defined(STM8S208) || defined(STM8S103)
volatile uint16_t miliseconds=0; // global variable storing milis value

// return value of milisecond timestamp ("atomic" read)
uint16_t milis(void){
uint16_t tmp;
TIM4_ITConfig(TIM4_IT_UPDATE,DISABLE);
tmp = miliseconds;
TIM4_ITConfig(TIM4_IT_UPDATE,ENABLE);
return tmp;
}

// init TIM4 as source for milis interrupt (low priority)
void init_milis(void){
TIM4_TimeBaseInit(PRESCALER,PERIOD); // (16MHz / 128) / 125 = 1000Hz
TIM4_ClearFlag(TIM4_FLAG_UPDATE);
TIM4_ITConfig(TIM4_IT_UPDATE,ENABLE);
ITC_SetSoftwarePriority(ITC_IRQ_TIM4_OVF, ITC_PRIORITYLEVEL_1); // nízká priorita pøerušení
TIM4_Cmd(ENABLE);
enableInterrupts();
}

void delay_ms(uint16_t del){ 
uint16_t start_time;
if(del>DELAY_MS_MAX_VALUE){del=DELAY_MS_MAX_VALUE;} // ošetøení pøíliš velké hodnoty
start_time=milis();
while((milis()-start_time) < del){}
}

// milis interrupt routine
INTERRUPT TIM4_UPD_OVF_IRQHandler(){
TIM4_ClearFlag(TIM4_FLAG_UPDATE);
miliseconds++;
}

#else
#warning "millis not defined for this platform !"
#endif



