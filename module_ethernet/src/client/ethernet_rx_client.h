/**
 * Module:  module_ethernet
 * Version: 1v4
 * Build:   d3c5347cdae4e3489ef0484a98cf3e6824343bb6
 * File:    ethernet_rx_client.h
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
 /*************************************************************************
 *
 * Ethernet MAC Layer Implementation
 * IEEE 802.3 MAC Client Interface (Receive)
 *
 *
 *************************************************************************
 *
 * This implement Ethernet frame receiving client interface.
 *
 *************************************************************************/
 
#ifndef _ETHERNET_RX_CLIENT_H_
#define _ETHERNET_RX_CLIENT_H_ 1
#include <xccompat.h>

/** This function receives a complete frame (i.e. src/dest MAC address,
 *  type & payload),  excluding pre-amble, SoF & CRC32 from the ethernet
 *  server.
 *
 *  This function is selectable i.e. it can be used as a case in a select e.g.
 *
 *  \verbatim
 *      select {
 *         ...
 *         case mac_rx(...):
 *            break;
 *          ...
 *        }
 *  \endverbatim
 *
 *  \param c_mac      A chanend connected to the ethernet server
 *  \param buffer     The buffer to fill with the incoming packet
 *  \param src_port   A reference parameter to be filled with the ethernet
 *                   port the packet came from.        
 *  \param len        A reference parameter to be filled with the length of 
 *                   the received packet in bytes. 
 *
 **/
#ifdef __XC__
#pragma select handler
#endif
void mac_rx(chanend c_mac, 
            unsigned char buffer[], 
            REFERENCE_PARAM(unsigned int, len),
            REFERENCE_PARAM(unsigned int, src_port));

/** This function receives a complete frame (i.e. src/dest MAC address,
 *  type & payload),  excluding pre-amble, SoF & CRC32. It also timestamps
 *  the arrival of the frame.
 *
 *  This function is selectable.
 *
 *  \param c_mac      A chanend connected to the ethernet server
 *  \param buffer     The buffer to fill with the incoming packet
 *  \param time       A reference parameter to be filled with the timestamp of 
 *                   the packet
 *  \param len        A reference parameter to be filled with the length of 
 *                   the received packet in bytes. 
 *  \param src_port   A reference parameter to be filled with the ethernet
 *                   port the packet came from.        
 *
 **/
#ifdef __XC__
#pragma select handler
#endif
void mac_rx_timed(chanend c_mac, 
                 unsigned char buffer[], 
                 REFERENCE_PARAM(unsigned int, len),
                 REFERENCE_PARAM(unsigned int, time),
                 REFERENCE_PARAM(unsigned int, src_port));



/** This function receives a complete frame (i.e. src/dest MAC address,
 *  type & payload),  excluding pre-amble, SoF & CRC32 from the ethernet
 *  server. In addition it will only fill the given buffer up to a specified
 *  length.
 *
 *  This function is selectable i.e. it can be used as a case in a select.
 *
 *  \param c_mac      A chanend connected to the ethernet server
 *  \param buffer     The buffer to fill with the incoming packet
 *  \param src_port   A reference parameter to be filled with the ethernet
 *                   port the packet came from.        
 *  \param len        A reference parameter to be filled with the length of 
 *                   the received packet in bytes. 
 *  \param n          The maximum number of bytes to fill the supplied buffer 
 *                   with.
 *
 **/
#ifdef __XC__
#pragma select handler
#endif
void safe_mac_rx(chanend c_mac, 
                unsigned char buffer[], 
                REFERENCE_PARAM(unsigned int, len),
                REFERENCE_PARAM(unsigned int, src_port),
                int n);

/** This function receives a complete frame (i.e. src/dest MAC address,
 *  type & payload),  excluding pre-amble, SoF & CRC32. It also timestamp 
 *  the arrival of the frame.  In addition it will only fill the given 
 *  buffer up to a specified length.
 *
 *  This function is selectable.
 *
 *  \param c_mac      A chanend connected to the ethernet server
 *  \param buffer     The buffer to fill with the incoming packet
 *  \param time       A reference parameter to be filled with the timestamp of 
 *                   the packet
 *  \param len        A reference parameter to be filled with the length of 
 *                   the received packet in bytes. 
 *  \param src_port   A reference parameter to be filled with the ethernet
 *                   port the packet came from.        
 *  \param n          The maximum number of bytes to fill the supplied buffer 
 *                   with.
 *
 **/
#ifdef __XC__
#pragma select handler
#endif
void safe_mac_rx_timed(chanend c_mac, 
                      unsigned char buffer[], 
                      REFERENCE_PARAM(unsigned int, len),
                      REFERENCE_PARAM(unsigned int, time),
                      REFERENCE_PARAM(unsigned int, src_port),
                      int n);

/** Setup whether a link should drop packets or block if the link is not ready
 *
 *  \param c_mac_svr          chanend of receive server.
 *  \param x                boolean value as to whether packets should 
 *                          be dropped at mac layer.
 * 
 *  NOTE: setting no dropped packets does not mean no packets will be 
 *  dropped. If packets are not dropped at the mac layer, it will block the
 *  mii fifo. The Mii fifo could possibly overflow and frames for other 
 *  links could be dropped.
 **/
void mac_set_drop_packets(chanend c_mac_svr, int x);


/** Setup the size of the buffer queue within the mac attached to this link.
 *  \param c_mac_svr  chanend connected to the mac
 *  \param x        the required size of the queue
 **/
void mac_set_queue_size(chanend c_mac_svr, int x);

/** Setup the custom filter up on a link.
 *
 *  \param c_mac_svr   chanend of receive server.
 *  \param x         filter value
 * 
 *  For each packet, the filter value is &-ed against the result of 
 *  the mac_custom_filter function. If the result is non-zero
 *  then the packet is transmitted down the link.
 **/
void mac_set_custom_filter(chanend c_mac_svr, int x);

#ifdef __XC__
#pragma select handler
#endif
void mac_rx_offset2(chanend c_mac, 
                   unsigned char buffer[], 
                    REFERENCE_PARAM(unsigned int, len),
                   REFERENCE_PARAM(unsigned int, src_port));


#endif
