
#include"STD_types.h"
#include"BIT_MATH.h"
#include"ERROR_STATUS.h"
#include"keybad_inter.h"
#include"DIO_interface.h"
#include<util/delay.h>

u8 arr_Keypad[4][4] =
{
		{'7','8','9','/'},
		{'4','5','6','x'},
		{'1','2','3','-'},
		{'*','0','=','+'},
};

void keypad_init( u8 PortID )
{
	DIO_enumSetPortDirection(PortID,0xf0);   // 4pin input -4pin output
	DIO_enumSetPortValue(PortID,0xff);       // port high
}
u8 Keypad_u8Keypress( u8 PortID)
{
	u8 col=0;
	u8 row=0;
	u8 Local_u8KeyResult=0;
	for(col=4;col<8;col++)
	{
		DIO_enumSetPinValue(PortID,col,DIO_U8_LOW);        //to create 0 in the pattern
		for (row=0;row<4;row++)                            // loop through rows to find which key is pressed
		{
			if(!(DIO_enumGetPinValue(PortID,row)))         // check rows how set zero /if( (DIO_enumGetPinValue(PortID,row)==0)
			{
				while(!DIO_enumGetPinValue(PortID,row));   // polling while pressing the button /while(DIO_enumGetPinValue(PortID,row)==0);
				Local_u8KeyResult = arr_Keypad[row][col-4];      // equaling the pattern to the value equavilant in the array(-4)

				_delay_ms(10); // to overcome any bouncing
			}
        }
		DIO_enumSetPinValue(PortID,col,DIO_U8_HIGH);
	}
	return Local_u8KeyResult;
}
