/**
 * Module:  app_dsc_demo
 * Version: 1v0alpha1
 * Build:   60a90cca6296c0154ccc44e1375cc3966292f74e
 * File:    inner_loop.h
 *
 * The copyrights, all other intellectual and industrial 
 * property rights are retained by XMOS and/or its licensors. 
 * Terms and conditions covering the use of this code can
 * be found in the Xmos End User License Agreement.
 *
 * Copyright XMOS Ltd 2010
 *
 * In the case where this code is a modification of existing code
 * under a separate license, the separate license terms are shown
 * below. The modifications to the code are still covered by the 
 * copyright notice above.
 *
 **/                                   
#ifndef _INNER_LOOP_H_
#define _INNER_LOOP_H_

/* run the motor inner loop */
void run_motor ( chanend c_pwm, chanend c_hall, chanend c_adc, chanend c_control, chanend ?c_logging );

#endif /* _INNER_LOOP_H_ */
