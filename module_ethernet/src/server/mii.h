/**
 * Module:  module_ethernet
 * Version: 1v4
 * Build:   d3c5347cdae4e3489ef0484a98cf3e6824343bb6
 * File:    mii.h
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
#ifndef __mii_h__
#define __mii_h__
#include <xs1.h>
#include <xccompat.h>
#include "ethernet_conf.h"

#ifndef MAX_ETHERNET_PACKET_SIZE
#define MAX_ETHERNET_PACKET_SIZE (1518)
#endif

#ifndef NUM_MII_RX_BUF 
#define NUM_MII_RX_BUF 5
#endif

#ifndef NUM_MII_TX_BUF 
#define NUM_MII_TX_BUF 5
#endif

#ifndef MAC_REQUIRED_WORDS_TO_FILTER
#define MAC_REQUIRED_WORDS_TO_FILTER (4)
#endif

#include "mii_queue.h"



#ifdef __XC__
/** Structure containing resources required for the MII ethernet interface.
 *
 *  This structure contains resources required to make up an MII interface. 
 *  It consists of 7 ports and 2 clock blocks.
 *
 *  The clock blocks can be any available clock blocks and will be clocked of 
 *  incoming rx/tx clock pins.
 *
 *  \sa ethernet_server()
 **/
typedef struct mii_interface_t {
  clock clk_mii_rx;            /**< MII RX Clock Block **/
  clock clk_mii_tx;            /**< MII TX Clock Block **/

  in port p_mii_rxclk;         /**< MII RX clock wire */
  in port p_mii_rxer;          /**< MII RX error wire */
  in buffered port:32 p_mii_rxd; /**< MII RX data wire */
  in port p_mii_rxdv;          /**< MII RX data valid wire */


  in port p_mii_txclk;       /**< MII TX clock wire */
  out port p_mii_txen;       /**< MII TX enable wire */
  out buffered port:32 p_mii_txd; /**< MII TX data wire */
} mii_interface_t;

void mii_init(REFERENCE_PARAM(mii_interface_t, m));
#endif


typedef struct mii_packet_t {
  int length;
  int complete;
  int timestamp;
  unsigned int data[(MAX_ETHERNET_PACKET_SIZE+3)/4];
  int filter_result;
  int src_port;
  int timestamp_id; 
  int free_pool;
} mii_packet_t;

#ifdef __XC__
void mii_rx_pins(mii_queue_t &free_queue,
                 mii_packet_t buf[],
                 in port p_mii_rxdv,
                 in buffered port:32 p_mii_rxd,
                 int ifnum,
                 streaming chanend c);
#else
void mii_rx_pins(mii_queue_t *free_queue,
                 mii_packet_t buf[],
                 port p_mii_rxdv,
                 port p_mii_rxd,
                 int ifnum,
                 chanend c);
#endif

#ifdef __XC__
void mii_tx_pins(mii_packet_t buf[],
                 mii_queue_t &in_queue,
                 mii_queue_t &free_queue,
                 mii_queue_t &ts_queue,
                 out buffered port:32 p_mii_txd,
                 int ifnum);
#else
void mii_tx_pins(mii_packet_t buf[],
                 mii_queue_t *in_queue,
                 mii_queue_t *free_queue,
                 mii_queue_t *ts_queue,
                 port p_mii_txd,
                 int ifnum);
#endif



#endif
