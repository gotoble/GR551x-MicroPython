/**
 ******************************************************************************
 *
 * @file platform_sdk.h
 *
 * @brief NVDS API
 *
 * Copyright(C) 2016-2018, Shenzhen Goodix  Technology Co., Ltd
 * All Rights Reserved
 *
 ******************************************************************************
 */
 
 
/**
 * @addtogroup SYSTEM
 * @{
 */
 /**
  @addtogroup platform sdk function
  @{
  @brief Definitions and prototypes for the Platform SDK
 */

#ifndef _PLATFORM_SDK_H
#define _PLATFORM_SDK_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
 
/**@addtogroup Platform SDK Enumerations
 * @{ */

/**@brief IO PINs for leakage protect. */
#define GPIO_PIN(x)                 ( 1<< (x) )
#define AON_IO_PIN(x)               ( 1<< (x) )
#define MSIO_PIN(x)                 ( 1<< (x) )

/**@brief system clock and run mode. */
typedef enum
{
   XIP_64M = 0,
   XIP_48M,   
   XIP_XO16M,  
   XIP_24M, 
   XIP_16M, 
   XIP_32M,
   MIRROR_64M,
   MIRROR_48M,    
   MIRROR_XO16M,
   MIRROR_24M, 
   MIRROR_16M, 
   MIRROR_32M,
} table_idx_t;

/**@brief sdk clock type. */
typedef enum
{
    RNG_OSC_CLK = 0,
    RTC_OSC_CLK,
    RNG_OSC_CLK2,
} sdk_clock_type_t;


/*
 ****************************************************************************************
 * @brief   IO leakage protect config table.
 * The three fields are defined in bitmap format, each bit is corresponding to each IO
 * The configuration rules are as below
 * 1. input to GR551x with on-board PU or PD resistors
 * 2. output from GR551x
 * IO setting must be set properly according to board configurations to avoid leackage
 * during sleep.
 ****************************************************************************************
 */
typedef struct
{
   uint32_t gpio;
   uint8_t  aon_gpio;
   uint8_t  msio;
} io_table_t;

/**@brief memory power setting mode. */
typedef enum
{
   MEM_POWER_FULL_MODE = 0,
   MEM_POWER_AUTO_MODE,    
} mem_power_t;

 /** @} */

/** @addtogroup PLATFORM_SDK Functions
 * @{ */

/*
 ****************************************************************************************
 * @brief   platform sdk init function
 * @retval :  void
 ****************************************************************************************
 */
void platform_sdk_init(void);

/*
 ****************************************************************************************
 * @brief  set the memory power state
 * @param[in] mem_pwr_mode : FULL POWER setting or AUTO POWER setting
 * @retval : void
 ****************************************************************************************
 */
void system_lp_mem_mode_set(mem_power_t mem_pwr_mode);

/*
 ****************************************************************************************
 * @brief  update the counter A and counter B
 * @param[in] counter_a :  Start Index Number
 * @param[in] counter_b   :  End Index Number
 * @retval :  void
 ****************************************************************************************
 */
void system_lp_counter_set(uint8_t cnt_a, uint8_t cnt_b);

/*
 ****************************************************************************************
 * @brief  Enabling patch function
 * @param[in] table_idx :  Start Index Number
 * @param[in] dur   :  duration setting
 * @param[in] ext   :  ext wakeup setting
 * @param[in] osc   :  pre-wakeup setting
 * @retval :  void
 ****************************************************************************************
 */
void system_lp_table_update_twval(table_idx_t table_idx, int16_t dur_offset, int16_t ext_offset, int16_t osc_offset);

/*
 ****************************************************************************************
 * @brief  Leakage Protection for User's IO 
 *         The leakage protection only acts on the outside without pull-up and pull-down,
 *         and only for input mode IO. By default, flash-related IO has been internally processed.
 *         For instance : 
 *         io_table_t io_table =
 *         {
 *             .gpio     = GPIO_PIN(0) | GPIO_PIN(1),
 *             .aon_gpio = AON_GPIO_PIN(0) | AON_GPIO_PIN(1),
 *             .msio     = MSIO_PIN(0) | MSIO_PIN(1),
 *         };
 * @param[in] p_io_table : the potiner of io setting table
 * @retval :  void
 ****************************************************************************************
 */
void system_io_leakage_protect(io_table_t *p_io_table);

/*
 ****************************************************************************************
 * @brief  platform low power clock init function
+ * @param[in] clock     :  Exteranl RTC setting or internal RNG/RNG2 setting
+ * @param[in] accuracy  :  Low speed clock accuracy.
+ * @param[in] xo_offset :  Clock calibration parameter.
 * @retval :  void
 ****************************************************************************************
 */
void platform_clock_init(sdk_clock_type_t clock, uint16_t accuracy, uint16_t xo_offset);

/*
 ****************************************************************************************
 * @brief  platform rc calibration function
 * @retval :  void
 ****************************************************************************************
 */
void platform_rc_calibration(void);

/*
 ****************************************************************************************
 * @brief  platform init function
 * @retval :  void
 ****************************************************************************************
 */
void platform_init(void);

/*
 ****************************************************************************************
 * @brief  pmu init function
 * @retval : void
 ****************************************************************************************
 */
void system_pmu_init(void);

/*
 ****************************************************************************************
 * @brief  pmu deinit function
 * @retval : void
 ****************************************************************************************
 */
void system_pmu_deinit(void);

/*
 ****************************************************************************************
 * @brief  warm boot process
 * @retval :  void
 ****************************************************************************************
 */
void warm_boot(void);

/*
 ****************************************************************************************
 * @brief  pmu calibration handler     
 * @param[in] p_arg : none args
 * @retval :  void
 ****************************************************************************************
 */
void pmu_calibration_handler(void* p_arg);


/** @} */

#endif

/** @} */
/** @} */

