/**
 * Module:  module_dsc_display
 * Version: 1v0module_dsc_display3
 * Build:
 * File:    shared_io_motor.h
 * Author: 	Srikanth
 *
 * The copyrights, all other intellectual and industrial 
 * property rights are retained by XMOS and/or its licensors. 
 * Terms and conditions covering the use of this code can
 * be found in the Xmos End User License Agreement.
 *
 * Copyright XMOS Ltd 2011
 *
 * In the case where this code is a modification of existing code
 * under a separate license, the separate license terms are shown
 * below. The modifications to the code are still covered by the 
 * copyright notice above.
 *
 **/                                   
#ifndef SHARED_IO_MOTOR_H_
#define SHARED_IO_MOTOR_H_

	#include <xccompat.h>

	// Individual command interfaces
	#define ETH_RST_HI 		0
	#define ETH_RST_LO		1

	#define CAN_TERM_HI		1
	#define CAN_TERM_LO		2
	#define CAN_RST_HI		4
	#define CAN_RST_LO		8

	#define CMD_GET_VALS	1
	#define CMD_GET_IQ		2
	#define CMD_SET_SPEED	3
    #define CMD_DIR         4
	#define CMD_GET_IQ2		5
	#define CMD_SET_SPEED2	6
	#define CMD_DIR2        7

	#ifdef __XC__
		typedef struct lcd_interface_t
		{
			//clock clk_lcd_1;
			//clock clk_lcd_2;

			out port p_lcd_sclk; // buffered port:8
			out port p_lcd_mosi; // buffered port:8
			out port p_lcd_cs_n;
			out port p_core1_shared;
		} lcd_interface_t;

		void display_shared_io_motor( chanend c_lcd, chanend c_lcd2, REFERENCE_PARAM(lcd_interface_t, p), in port btns[]);
	#endif

#endif /* SHARED_IO_MOTOR_H_ */
