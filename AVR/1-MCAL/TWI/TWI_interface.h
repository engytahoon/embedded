#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_


void TWI_voidInitMaster(void);

void TWI_voidInitSlave(u8 Copy_u8Address);

Error_Status TWI_errSendStartCondition(void);

Error_Status TWI_errSendRepeatedStart(void);

Error_Status TWI_errSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

Error_Status TWI_errSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

Error_Status TWI_errMstrWriteDataByte(u8 Copy_u8Byte);

Error_Status TWI_errMstrReceiveDataByte(u8* Copy_pu8Byte);

void TWI_voidSendStopCondition(void);






#endif /* TWI_INTERFACE_H_ */
