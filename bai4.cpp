#include "stm32f10x.h"

void GPIO_Config(void);
void TIM2_Config(void);

int main(void) {
    GPIO_Config();   // cau hình PA3 output
    TIM2_Config();   // cau hình Timer2

    while (1) {
    }
}

// ================= GPIO =================
void GPIO_Config(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef gpio;
    gpio.GPIO_Pin = GPIO_Pin_3;
    gpio.GPIO_Speed = GPIO_Speed_2MHz;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP;     // push-pull output
    GPIO_Init(GPIOA, &gpio);

    GPIO_ResetBits(GPIOA, GPIO_Pin_3);     // ban dau LED tat
}

// ================= TIMER =================
void TIM2_Config(void) {
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    TIM_TimeBaseInitTypeDef timer;
    timer.TIM_Period = 4999;               // ARR
    timer.TIM_Prescaler = 7199;            // PSC
    timer.TIM_ClockDivision = TIM_CKD_DIV1;
    timer.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &timer);

    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);   // enable update interrupt

    NVIC_InitTypeDef nvic;
    nvic.NVIC_IRQChannel = TIM2_IRQn;
    nvic.NVIC_IRQChannelPreemptionPriority = 0;
    nvic.NVIC_IRQChannelSubPriority = 0;
    nvic.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvic);

    TIM_Cmd(TIM2, ENABLE); 
}

// ================= ISR =================
void TIM2_IRQHandler(void) {
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

        // dao trang thái LED PA3
        GPIOA->ODR ^= GPIO_Pin_3;
    }
}