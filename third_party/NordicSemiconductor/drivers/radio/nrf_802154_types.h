/* Copyright (c) 2018, Nordic Semiconductor ASA
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this
 *      list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *
 *   3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *      contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef NRF_802154_TYPES_H__
#define NRF_802154_TYPES_H__

#include <stdint.h>

#include "hal/nrf_radio.h"

/**
 * @defgroup nrf_802154_types Types definitions used in the 802.15.4 driver.
 * @{
 * @ingroup nrf_802154
 * @brief Definitions of types used in the 802.15.4 driver.
 */

/**
 * @brief States of the driver.
 */
typedef uint8_t nrf_802154_state_t;

#define NRF_802154_STATE_INVALID              0x01 /**< Radio in an invalid state. */
#define NRF_802154_STATE_SLEEP                0x02 /**< Radio in Sleep state. */
#define NRF_802154_STATE_RECEIVE              0x03 /**< Radio in Receive state. */
#define NRF_802154_STATE_TRANSMIT             0x04 /**< Radio in Transmit state. */
#define NRF_802154_STATE_ENERGY_DETECTION     0x05 /**< Radio in Energy Detection state. */
#define NRF_802154_STATE_CCA                  0x06 /**< Radio in CCA state. */
#define NRF_802154_STATE_CONTINUOUS_CARRIER   0x07 /**< Radio in Continuous Carrier state. */

/**
 * @brief Errors reported during frame transmission.
 */
typedef uint8_t nrf_802154_tx_error_t;

#define NRF_802154_TX_ERROR_NONE              0x00 /**< There is no transmit error. */
#define NRF_802154_TX_ERROR_BUSY_CHANNEL      0x01 /**< CCA reported busy channel prior to transmission. */
#define NRF_802154_TX_ERROR_INVALID_ACK       0x02 /**< Received ACK frame is other than expected. */
#define NRF_802154_TX_ERROR_NO_MEM            0x03 /**< No receive buffer are available to receive an ACK. */
#define NRF_802154_TX_ERROR_TIMESLOT_ENDED    0x04 /**< Radio timeslot ended during transmission procedure. */
#define NRF_802154_TX_ERROR_NO_ACK            0x05 /**< ACK frame was not received during timeout period. */
#define NRF_802154_TX_ERROR_ABORTED           0x06 /**< Procedure was aborted by other driver operation with FORCE priority. */

/**
 * @brief Possible errors during frame reception.
 */
typedef uint8_t nrf_802154_rx_error_t;

#define NRF_802154_RX_ERROR_NONE              0x00 /**< There is no receive error */
#define NRF_802154_RX_ERROR_INVALID_FRAME     0x01 /**< Received a malformed frame */
#define NRF_802154_RX_ERROR_INVALID_FCS       0x02 /**< Received a frame with invalid checksum. */
#define NRF_802154_RX_ERROR_INVALID_DEST_ADDR 0x03 /**< Received a frame with mismatched destination address. */
#define NRF_802154_RX_ERROR_RUNTIME           0x04 /**< A runtime error occured (e.g. CPU was hold for too long.) */
#define NRF_802154_RX_ERROR_TIMESLOT_ENDED    0x05 /**< Radio timeslot ended during frame reception. */
#define NRF_802154_RX_ERROR_ABORTED           0x06 /**< Procedure was aborted by other driver operation with FORCE priority. */

/**
 * @brief Possible errors during energy detection.
 */
typedef uint8_t nrf_802154_ed_error_t;

#define NRF_802154_ED_ERROR_ABORTED           0x01 /**< Procedure was aborted by other driver operation with FORCE priority. */

/**
 * @brief Possible errors during CCA procedure.
 */
typedef uint8_t nrf_802154_cca_error_t;

#define NRF_802154_CCA_ERROR_ABORTED          0x01 /**< Procedure was aborted by other driver operation with FORCE priority. */

/**
 * @brief Termination level selected for particular request.
 *
 * Each request is able to terminate ongoing operation. This type selects which operation should be
 * aborted by given request.
 */
typedef uint8_t nrf_802154_term_t;

#define NRF_802154_TERM_NONE    0x00  /**< Request is skipped if another operation is ongoing. */
#define NRF_802154_TERM_802154  0x01  /**< Request terminates ongoing 802.15.4 operation. */

/**
 * @brief Structure for configuring CCA.
 */
typedef struct
{
    nrf_radio_cca_mode_t mode;           /**< CCA mode. */
    uint8_t              ed_threshold;   /**< CCA Energy Busy Threshold. Not used in NRF_RADIO_CCA_MODE_CARRIER. */
    uint8_t              corr_threshold; /**< CCA Correlator Busy Threshold. Not used in NRF_RADIO_CCA_MODE_ED. */
    uint8_t              corr_limit;     /**< Limit of occurrences above CCA Correlator Busy Threshold. Not used in NRF_RADIO_CCA_MODE_ED. */
} nrf_802154_cca_cfg_t;

/**
 *@}
 **/

#endif // NRF_802154_TYPES_H__
