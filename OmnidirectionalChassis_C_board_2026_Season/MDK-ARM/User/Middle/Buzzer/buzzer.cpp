#include "buzzer.hpp"
void B_star()
{
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 125);
    delay_ms(150);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
    delay_ms(150);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 125);
    delay_ms(400);    
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);

    delay_ms(200);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 125);
    delay_ms(50);    
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
    delay_ms(50); 
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 125);
    delay_ms(50);    
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);

}

void B_stop()
{
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 125);
    delay_ms(400);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
    delay_ms(150);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 125);
    delay_ms(150);    
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);

    delay_ms(200);
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 125);
    delay_ms(50);    
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
    delay_ms(50); 
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 125);
    delay_ms(50);    
    __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, 0);
}

void delay_ms(uint32_t ms) 
{
    uint32_t start = HAL_GetTick();
    while ((HAL_GetTick() - start) < ms) 
    {
        // µÈ´ý
    }
}
