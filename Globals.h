/* 
 * File:   Globals.h
 * Author: nchommanivong
 *
 * Created on February 13, 2020, 5:06 PM
 */

#ifndef GLOBALS_H
#define	GLOBALS_H

#define Now() TimerTick
#define TIME_OVER(target,time) ((uint16_t)((time) - (target)) < 0x8000U)
#define CYC_DELAY 1000u

extern uint16_t TimerTick;
extern ModbusFrame PendingFrame;

#endif	/* GLOBALS_H */

