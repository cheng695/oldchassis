#include "SerialCallback.hpp"

extern float tick_last;
extern float tick_now;
extern Clicker::DR16 dr16;
extern uint8_t RX_Data[1+sizeof(float)];
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    if(huart->Instance == USART3)
	{
        tick_last = tick_now;
		dr16.DR16DataUpdata(pData);
		HAL_UARTEx_ReceiveToIdle_IT(&huart3,pData,sizeof(pData));
	}
    else if(huart->Instance == USART1)
    {
        HAL_UARTEx_ReceiveToIdle_DMA(&huart1, RX_Data, sizeof(RX_Data));
        Communication_CtoA_Receive();
    }
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
    if(HAL_UART_GetError(huart) & HAL_UART_ERROR_ORE)
    {     
        if(huart->Instance == USART3)
        __HAL_UART_CLEAR_OREFLAG(&huart3);
        if(huart->Instance == USART1)
        __HAL_UART_CLEAR_OREFLAG(&huart1);
    }
}

extern "C" void RxEventCallback()
{
    Communication_CtoA_Tansmit();
	HAL_UARTEx_ReceiveToIdle_IT(&huart3,pData,sizeof(pData));
    HAL_UARTEx_ReceiveToIdle_DMA(&huart1, RX_Data, sizeof(RX_Data));
    Communication_CtoA_Receive();
}
