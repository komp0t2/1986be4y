/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Generic application start

*/


/*********************************************************************
*
*       main()
*
*  Function description
*   Application entry point.
*/
#include "Library/MDR1986BE4.h"
int main(void)
{
	MDR_RST_CLK->PER2_CLOCK |= RST_CLK_PER2_CLOCK_PCLK_EN_PORTB;
	MDR_PORTB->OE |= 0x1<<2;
	MDR_PORTB->FUNC &= ~(0x3<<2);
	MDR_PORTB->ANALOG |= 0x1<<2;
	MDR_PORTB->PULL &= ~(0x3 << (PORT_PULL_PULL_UP_Pos + 2));
	MDR_PORTB->PULL &= ~(0x3 << (PORT_PULL_PULL_DOWN_Pos + 2));
	MDR_PORTB->PD &= ~(0x1 << (PORT_PD_PD_Pos + 2));
	MDR_PORTB->PWR &= ~(0x3 << PORT_PWR_PWR2_Pos);
	MDR_PORTB->PWR |= (0x1 << PORT_PWR_PWR2_Pos);
	MDR_PORTB->GFEN &= ~(0x1 << (PORT_GFEN_GFEN_Pos + 2));
	while (1)
	{
		MDR_PORTB->RXTX |= (0x1 << 2);
		for(uint32_t i = 0;i < 400000;i++)asm("NOP");
		MDR_PORTB->RXTX &= ~(0x1 << 2);
		for(uint32_t i = 0;i < 400000;i++)asm("NOP");
	}
}

/*************************** End of file ****************************/