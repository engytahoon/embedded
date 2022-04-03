#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_


#define START_ACK                0x08 // start has been sent
#define REP_START_ACK            0x10 // repeated start
#define SLAVE_ADD_AND_WR_ACK     0x18 // Master transmit ( slave address + Write request ) ACK
#define SLAVE_ADD_AND_RD_ACK     0x40 // Master transmit ( slave address + Read request ) ACK
#define MSTR_WR_BYTE_ACK         0x28 // Master transmit data ACK
#define MSTR_RD_BYTE_WITH_ACK    0x50 // Master received data with ACK
#define MSTR_RD_BYTE_WITH_NACK   0x58 // Master received data with not ACK
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 // means that slave address is received with read request
#define SLAVE_ADD_RCVD_WR_REQ    0x60 // means that slave address is received with write request
#define SLAVE_DATA_RECEIVED      0x80 // means that a byte is received
#define SLAVE_BYTE_TRANSMITTED   0xB8 // means that the written byte is transmitted



#endif /* TWI_PRIVATE_H_ */
