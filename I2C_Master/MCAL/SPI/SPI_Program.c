
 /*****************************************************************************
 *==================******************************************================*
 *==================**   Author: Mohamed Samir Hashish      **================*
 *==================**               NTI                    **================*
 *==================******************************************================*/


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_Interface.h"
#include "SPI_Interface.h"
#include "SPI_config.h"
#include "SPI_Private.h"
/********************************************************************************************/
void SPI_voidInit(void)
{
#if   SPI_MODE   ==   SPI_MASTER_MODE
	//MASTER_MODE
	SET_BIT(SPCR_REG,SPCRMSTR);

	//Freq
	SET_BIT(SPCR_REG,SPCR_SPR0);
	SET_BIT(SPCR_REG,SPCR_SPR1);


	DIO_voidSetPinDirection(PORTB_ID,PIN4,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB_ID,PIN5,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB_ID,PIN6,PIN_INPUT);
	DIO_voidSetPinDirection(PORTB_ID,PIN7,PIN_OUTPUT);


#elif SPI_MODE   ==   SPI_SLAVE_MODE
     //SLAVE_MODE
	CLR_BIT(SPCR_REG,SPCR_MSTR);

	DIO_voidSetPinDirection(PORTB_ID,PIN4,PIN_INPUT);
	DIO_voidSetPinDirection(PORTB_ID,PIN5,PIN_INPUT);
	DIO_voidSetPinDirection(PORTB_ID,PIN6,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB_ID,PIN7,PIN_INPUT);

#endif
	/* to send from LSB first */
	SET_BIT(SPCR_REG,SPCR_DORD);
	/* to enable spi circuit */
	SET_BIT(SPCR_REG,SPCR_SPE);
}

/********************************************************************************************/
u8   SPI_voidTransiver(u8 Copy_u8Data)
{
	u8 data =0;
	SPDR_REG = Copy_u8Data;

	//while(GET_BIT(SPSR_REG,SPSR_SPIF) == 0);
	if(GET_BIT(SPSR_REG,SPSR_SPIF) == 1)
	{
		data=SPDR_REG;
	}
	return data;
}

void SPI_voidReceiveChar(u8 *Copy_u8Data)
{
	while(GET_BIT(SPSR_REG,SPSR_SPIF) == 0);
	//if(GET_BIT(SPSR_REG,SPSR_SPIF) == 1)
	{
		*Copy_u8Data=SPDR_REG;
	}

}
void SPI_VoidSendChar(u8 Copy_u8Data)
{
	//while(GET_BIT(SPSR_REG,SPSR_SPIF) == 0);
	SPDR_REG = Copy_u8Data;
}
