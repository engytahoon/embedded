#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LEM_IR.h"

void main(void)
{
	LEMIR_voidInit();
	while(1)
	{
		IR_voidSetCallBack(LEMIR_voidApp);
	}
}
