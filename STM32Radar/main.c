#include "RURS.h"
#include "UART.h"
#include "motorsL298N.h"
#include "wrapperFSM.h"

int main(void)
{
	InitializeUART();
	InitializeRURS();
	InitializeMotors();
	
	RURS_TurnOn();
	
	RURS_ResetPosition();
	
	while(1)
	{
		FSM_HandleCurrent();
	}
}

void UART_HandleReceived(uint16_t data)
{
	FSM_MakeTransition((InputSignal)data);
}
