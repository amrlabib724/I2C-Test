
/*==================******************************************================*
 *==================**   Author: Mohamed Samir Hashish      **================*
 *==================**               NTI                    **================*
 *==================******************************************================*/

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "util/delay.h"
//#include "avr/io.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/EXT_INT/EXTINT_Interface.h"
#include "../MCAL/UART/UART_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/TIMER0/TMR0_Interface.h"
#include "../HAL/KEYPAD/KPD_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../MCAL/TIMER1/TIMER1_int.h"
#include "../MCAL/I2C/TWI_int.h"
#include "../MCAL/I2C/TWI_private.h"
#include "../HAL/EEPROM/EXT_EEPROM_int.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include <util/delay.h>
#include"string.h"
#ifndef F_CPU
#define F_CPU 8000000UL
#endif




#define F_CPU 8000000UL
#include <util/delay.h>

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../MCAL/I2C/TWI_int.h"

int main(void)
{
	M_TWI_void_Init();
	LCD_voidInit();
	u8 i = 0;
	u8 ReceivedChar;
	u8 Message[20];
	M_TWI_u8_ReadByte(&ReceivedChar);
//	LCD_voidWriteString("Amr Labib ");
    LCD_voidWriteString(ReceivedChar);



	while(1)
	{
		i = 0;

		do {
			M_TWI_u8_ReadByte(&ReceivedChar);
			Message[i] = ReceivedChar;
//			LCD_voidWriteData(ReceivedChar);
			LCD_voidWriteString(ReceivedChar);
			i++;
			_delay_ms(100);

		} while (ReceivedChar != '\0' && i < sizeof(Message) - 1);

		Message[i] = '\0';
		_delay_ms(1000);
//		LCD_voidClear();
	}

	return 0;
}

