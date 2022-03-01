#ifndef _MILIS_H_
#define _MILIS_H_ 1

//#include "stm8s.h"
#include "stm8s_conf.h"
// configure PRESCALER and PERIOD according to your clock, to setup 1ms time base
#if F_CPU==16000000
// varianta pro 16MHz
#define PRESCALER TIM4_PRESCALER_128
#define PERIOD (125-1)
#elif F_CPU==2000000
// varianta pro 2MHz
#define PRESCALER TIM4_PRESCALER_16
#define PERIOD (125-1)
#else
#warning "milis timer parameters not defined for this clock !"
#endif

#define DELAY_MS_MAX_VALUE 32000 // te� p�esn� nev�m jak� je strop kter� je�t� zvl�dne p�ete�en� ... ale to je jedno, nikdo rozumn� nezvol� delay_ms na v�c jak sekundu...

uint16_t milis(void);
void init_milis(void);
void delay_ms(uint16_t del);


#endif