#include "MyMain.h"
extern uint8_t Scan;
int value;
uint8_t command[1]={0};
uint8_t CanSend;
void UserMain(void)
{
	if(Scan==1)
	{
		CanSend=command[0];
		if(CanSend==0x31)
		{
			GetAndPrintADCValue();
		}
		Scan=0;
	}

}
void HAL_UART_RxCpltCallback (UART_HandleTypeDef * huart) 
{
	if(huart->Instance == UART5)
	{
		HAL_UART_Receive_DMA(&huart5,command,1);
	}
}
void GetAndPrintADCValue(void)
{
		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1,10);
		value=HAL_ADC_GetValue(&hadc1);
		printf("%d\r\n",value+1000);
	CanSend=0;
	command[0]=0;
}