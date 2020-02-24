/* 
 * File:   Modbus.h
 * Author: nchommanivong
 *
 * Created on 17 février 2020, 17:42
 */

#ifndef MODBUS_H
#define	MODBUS_H

#include "mcc_generated_files/mcc.h"

#define DEVIDE_ADDR             100u
#define FCN_SINGLE_READ         0x03
#define FCN_SINGLE_WRITE        0x06
#define FCN_MULTIPLE_WRITES     0x10
#define REG_LOGIC_COMMAND_DATA  0x2000
#define REG_REFERENCE_SPEED     0x2001
#define REG_LOGIC_STATUS_DATA   0x2100
#define REG_DRIVE_ERROR_CODE    0x2101
#define REG_FEEDBACK            0x2103


typedef struct{
    uint8_t NodeAddr;
    uint8_t Command;
    uint8_t * Data;
    uint8_t length;
    uint8_t FrameStatus;
    uint16_t t_TxEnd;
    uint16_t t_RxStart;
}ModbusFrame;

extern ModbusFrame PendingFrame;

void ModbusInitDevice(void);
void ModbusPrepareRegWr(ModbusFrame * Msg, uint8_t * Payload, uint8_t DeviceID, uint16_t RegisterAddr, uint16_t RegisterValue);
void ModbusSendMSG(ModbusFrame SendingMSG);
uint16_t ModbusCRC16Buffer(uint8_t * Data, uint8_t Size);
void UARTSendChar(uint8_t data);

#endif	/* MODBUS_H */

