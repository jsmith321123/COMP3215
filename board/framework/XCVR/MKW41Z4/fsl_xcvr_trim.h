/*
* Copyright 2016-2017 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef _FSL_XCVR_TRIM_H_
/* Clang-format off. */
#define _FSL_XCVR_TRIM_H_
/* Clang-format on. */

//#include "fsl_common.h"
#include "fsl_device_registers.h"
#include "fsl_xcvr.h"

/*!
* @addtogroup xcvr
* @{
*/

/*! @file*/

/************************************************************************************
*************************************************************************************
* Public constant definitions
*************************************************************************************
************************************************************************************/

/************************************************************************************
*************************************************************************************
* Public type definitions
*************************************************************************************
************************************************************************************/

/* \brief  The enumerations used to define the I & Q channel selections. */
typedef enum
{
    I_CHANNEL = 0,
    Q_CHANNEL = 1,
    NUM_I_Q_CHAN = 2
} IQ_t;

typedef enum /* Enumeration of ADC_GAIN_CAL 2 */
{
    NOMINAL2 = 0,
    BBF_NEG = 1,
    BBF_POS = 2,
    TZA_STEP_N0 = 3,
    TZA_STEP_N1 = 4,
    TZA_STEP_N2 = 5,
    TZA_STEP_N3 = 6,
    TZA_STEP_N4 = 7,
    TZA_STEP_N5 = 8,
    TZA_STEP_N6 = 9,
    TZA_STEP_N7 = 10,
    TZA_STEP_N8 = 11,
    TZA_STEP_N9 = 12,
    TZA_STEP_N10 = 13,
    TZA_STEP_P0 = 14,
    TZA_STEP_P1 = 15,
    TZA_STEP_P2 = 16,
    TZA_STEP_P3 = 17,
    TZA_STEP_P4 = 18,
    TZA_STEP_P5 = 19,
    TZA_STEP_P6 = 20,
    TZA_STEP_P7 = 21,
    TZA_STEP_P8 = 22,
    TZA_STEP_P9 = 23,
    TZA_STEP_P10 = 24,

    NUM_SWEEP_STEP_ENTRIES2 = 25 /* Including the baseline entry #0. */
} DAC_SWEEP_STEP2_t;

/* \brief  Defines an entry in an array of structs to describe TZA DCOC STEP and TZA_DCOC_STEP_RECIPROCAL. */
typedef struct
{
    uint16_t dcoc_step; 
    uint16_t dcoc_step_rcp; 
} TZAdcocstep_t;

typedef struct
{
    int8_t step_value; /* The offset from nominal DAC value (see sweep_step_values[]) */
    int16_t internal_measurement; /* The value (average code) measured from DMA samples. */
//    uint8_t valid; /* Set to TRUE (non zero) when a value is written to this table entry. */
} GAIN_CALC_TBL_ENTRY2_T;

/*******************************************************************************
* Definitions
******************************************************************************/
void rx_dc_sample_average(int16_t * i_avg, int16_t * q_avg);
void rx_dc_sample_average_long(int16_t * i_avg, int16_t * q_avg);
uint8_t rx_bba_dcoc_dac_trim_shortIQ(void);
void XcvrCalDelay(uint32_t time);
void rx_dc_est_average(int16_t * i_avg, int16_t * q_avg, uint16_t SampleNumber);
uint8_t rx_bba_dcoc_dac_trim_DCest(void);
void DCOC_DAC_INIT_Cal(uint8_t standalone_operation);




/* @} */

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* _FSL_XCVR_TRIM_H_ */

