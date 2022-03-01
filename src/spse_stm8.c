#include "spse_stm8.h"  
#include "delay.h"

#ifdef STM8S208
void ADC2_Select_Channel(ADC2_Channel_TypeDef ADC2_Channel){
    uint8_t tmp = (ADC2->CSR) & (~ADC2_CSR_CH);
    tmp |= ADC2_Channel | ADC2_CSR_EOC;
    ADC2->CSR = tmp;
}

void ADC2_AlignConfig(ADC2_Align_TypeDef ADC2_Align){
	if(ADC2_Align){
		ADC2->CR2 |= (uint8_t)(ADC2_Align);
	}else{
		ADC2->CR2 &= (uint8_t)(~ADC2_CR2_ALIGN);
	}
}
#endif


#ifdef STM8S103
void ADC1_Select_Channel(ADC1_Channel_TypeDef ADC1_Channel){
    uint8_t tmp = (ADC1->CSR) & (~ADC1_CSR_CH);
    tmp |= ADC1_Channel | ADC1_CSR_EOC;
    ADC1->CSR = tmp;
}

void ADC1_AlignConfig(ADC1_Align_TypeDef ADC1_Align){
	if(ADC1_Align){
		ADC1->CR2 |= (uint8_t)(ADC1_Align);
	}else{
		ADC1->CR2 &= (uint8_t)(~ADC1_CR2_ALIGN);
	}
}
#endif