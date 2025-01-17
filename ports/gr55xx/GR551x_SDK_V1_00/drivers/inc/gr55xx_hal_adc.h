/**
 ****************************************************************************************
 *
 * @file    gr55xx_hal_adc.h
 * @author  BLE Driver Team
 * @brief   Header file containing functions prototypes of ADC HAL library.
 *
 ****************************************************************************************
 * @attention
  #####Copyright (c) 2019 GOODIX
  All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
  * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
  * Neither the name of GOODIX nor the names of its contributors may be used
    to endorse or promote products derived from this software without
    specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
 ****************************************************************************************
 */

/** @addtogroup PERIPHERAL Peripheral Driver
  * @{
  */

/** @addtogroup HAL_DRIVER HAL Driver
  * @{
  */

/** @defgroup HAL_ADC ADC
  * @brief ADC HAL module driver.
  * @{
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GR55xx_HAL_ADC_H__
#define __GR55xx_HAL_ADC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gr55xx_ll_adc.h"
#include "gr55xx_hal_def.h"
#include "gr55xx_hal_dma.h"

/* Exported types ------------------------------------------------------------*/
/** @addtogroup HAL_ADC_ENUMERATIONS Enumerations
  * @{
  */

/** @defgroup HAL_ADC_state HAL ADC State
  * @{
  */

/**
  * @brief HAL ADC State Enumerations definition
  */
typedef enum
{
    HAL_ADC_STATE_RESET        = 0x00,    /**< Peripheral not initialized                          */
    HAL_ADC_STATE_READY        = 0x01,    /**< Peripheral initialized and ready for use            */
    HAL_ADC_STATE_BUSY         = 0x02,    /**< An internal process is ongoing                      */
    HAL_ADC_STATE_ERROR        = 0x04     /**< Peripheral in error                                 */

} hal_adc_state_t;

/** @} */

/** @} */

/** @addtogroup HAL_ADC_STRUCTURES Structures
  * @{
  */

/** @defgroup ADC_Configuration ADC Configuration
  * @{
  */
  
/**
  * @brief   ADC init structure definition
  */
typedef ll_adc_init_t       adc_init_t;
/** @} */

/** @defgroup ADC_handle ADC Handle
  * @{
  */

/**
  * @brief ADC handle Structure definition
  */
typedef struct _adc_handle
{
    adc_init_t              init;           /**< ADC configuration parameters      */

    uint16_t               *p_buffer;       /**< Pointer to ADC conversion buffer  */

    __IO uint32_t           buff_size;      /**< Conversion buffer size            */

    __IO uint32_t           buff_count;     /**< Conversion buffer counter         */

    dma_handle_t           *p_dma;          /**< ADC DMA Handle parameters         */

    __IO hal_lock_t         lock;           /**< Locking object                    */

    __IO hal_adc_state_t    state;          /**< ADC communication state           */

    __IO uint32_t           error_code;     /**< ADC error code                    */

} adc_handle_t;
/** @} */

/** @} */

/** @addtogroup HAL_ADC_CALLBACK_STRUCTURES Callback Structures
  * @{
  */

/** @defgroup ADC_Callback ADC Callback
  * @{
  */

/**
  * @brief HAL ADC Callback function definition
  */
typedef struct _adc_callback
{
    void (*adc_msp_init)(adc_handle_t *p_adc);
    void (*adc_msp_deinit)(adc_handle_t *p_adc);
    void (*adc_conv_cplt_callback)(adc_handle_t *p_adc);
} adc_callback_t;

/** @} */

/** @} */

/**
  * @brief   ADC init structure definition
  */

/**
  * @defgroup  HAL_ADC_MACRO Defines
  * @{
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup ADC_Exported_Constants ADC Exported Constants
  * @{
  */

/** @defgroup ADC_Error_Code ADC Error Code
  * @{
  */
#define HAL_ADC_ERROR_NONE              ((uint32_t)0x00000000)  /**< No error           */
#define HAL_ADC_ERROR_TIMEOUT           ((uint32_t)0x00000001)  /**< Timeout error      */
#define HAL_ADC_ERROR_DMA               ((uint32_t)0x00000004)  /**< DMA transfer error */
#define HAL_ADC_ERROR_INVALID_PARAM     ((uint32_t)0x00000008)  /**< Invalid parameter error */
/** @} */

/** @defgroup ADC_CLK ADC Clock Select
  * @{
  */
#define ADC_CLK_16M                 LL_ADC_CLK_16           /**< ADC Clock = 16 MHz  */
#define ADC_CLK_1P6M                LL_ADC_CLK_1P6          /**< ADC Clock = 1.6 MHz */
#define ADC_CLK_8M                  LL_ADC_CLK_8            /**< ADC Clock = 8 MHz   */
#define ADC_CLK_4M                  LL_ADC_CLK_4            /**< ADC Clock = 4 MHz   */
#define ADC_CLK_2M                  LL_ADC_CLK_2            /**< ADC Clock = 2 MHz   */
#define ADC_CLK_1M                  LL_ADC_CLK_1            /**< ADC Clock = 1 MHz   */
/** @} */

/** @defgroup ADC_REFERENCE ADC Reference Value Select
  * @{
  */
#define ADC_REF_VALUE_0P5           LL_ADC_REF_VALUE_0P5    /**< Reference = 0.5 V   */
#define ADC_REF_VALUE_0P6           LL_ADC_REF_VALUE_0P6    /**< Reference = 0.6 V   */
#define ADC_REF_VALUE_0P7           LL_ADC_REF_VALUE_0P7    /**< Reference = 0.7 V   */
#define ADC_REF_VALUE_0P8           LL_ADC_REF_VALUE_0P8    /**< Reference = 0.8 V   */
#define ADC_REF_VALUE_0P9           LL_ADC_REF_VALUE_0P9    /**< Reference = 0.9 V   */
#define ADC_REF_VALUE_1P0           LL_ADC_REF_VALUE_1P0    /**< Reference = 1.0 V   */
#define ADC_REF_VALUE_1P1           LL_ADC_REF_VALUE_1P1    /**< Reference = 1.1 V   */
#define ADC_REF_VALUE_1P2           LL_ADC_REF_VALUE_1P2    /**< Reference = 1.2 V   */
#define ADC_REF_VALUE_1P3           LL_ADC_REF_VALUE_1P3    /**< Reference = 1.3 V   */
#define ADC_REF_VALUE_1P4           LL_ADC_REF_VALUE_1P4    /**< Reference = 1.4 V   */
#define ADC_REF_VALUE_1P5           LL_ADC_REF_VALUE_1P5    /**< Reference = 1.5 V   */
#define ADC_REF_VALUE_1P6           LL_ADC_REF_VALUE_1P6    /**< Reference = 1.6 V   */
#define ADC_REF_VALUE_1P7           LL_ADC_REF_VALUE_1P7    /**< Reference = 1.7 V   */
#define ADC_REF_VALUE_1P8           LL_ADC_REF_VALUE_1P8    /**< Reference = 1.8 V   */
#define ADC_REF_VALUE_1P9           LL_ADC_REF_VALUE_1P9    /**< Reference = 1.9 V   */
#define ADC_REF_VALUE_2P0           LL_ADC_REF_VALUE_2P0    /**< Reference = 2.0 V   */
/** @} */

/** @defgroup ADC_INPUT_MODE ADC Input Mode
  * @brief Single or Differential mode
  * @{
  */
#define ADC_INPUT_SINGLE            LL_ADC_INPUT_SINGLE      /**< Single ended mode */
#define ADC_INPUT_DIFFERENTIAL      LL_ADC_INPUT_DIFFERENTIAL/**< Differential mode */
/** @} */

/** @defgroup ADC_INPUT_SOURCE ADC Input Channel Select
  * @{
  */
#define ADC_INPUT_SRC_IO0           LL_ADC_INPUT_SRC_IO0    /**< Select MSIO0 as input       */
#define ADC_INPUT_SRC_IO1           LL_ADC_INPUT_SRC_IO1    /**< Select MSIO1 as input       */
#define ADC_INPUT_SRC_IO2           LL_ADC_INPUT_SRC_IO2    /**< Select MSIO2 as input       */
#define ADC_INPUT_SRC_IO3           LL_ADC_INPUT_SRC_IO3    /**< Select MSIO3 as input       */
#define ADC_INPUT_SRC_IO4           LL_ADC_INPUT_SRC_IO4    /**< Select MSIO4 as input       */
#define ADC_INPUT_SRC_TMP           LL_ADC_INPUT_SRC_TMP    /**< Select temperature as input */
#define ADC_INPUT_SRC_BAT           LL_ADC_INPUT_SRC_BAT    /**< Select Vbattery as input    */
#define ADC_INPUT_SRC_REF           LL_ADC_INPUT_SRC_REF    /**< Select reference as input   */
/** @} */

/** @defgroup ADC_REFERENCE_SOURCE ADC Reference Source Select
  * @{
  */
#define ADC_REF_SRC_BUF_INT         LL_ADC_REF_SRC_BUF_INT  /**< Select buffered internal reference as reference   */
#define ADC_REF_SRC_IO0             LL_ADC_REF_SRC_IO0      /**< Select MSIO0 as reference                         */
#define ADC_REF_SRC_IO1             LL_ADC_REF_SRC_IO1      /**< Select MSIO1 as reference                         */
#define ADC_REF_SRC_IO2             LL_ADC_REF_SRC_IO2      /**< Select MSIO2 as reference                         */
#define ADC_REF_SRC_IO3             LL_ADC_REF_SRC_IO3      /**< Select MSIO3 as reference                         */
/** @} */

/**
  * @brief ADC_default_config initStruct default configuartion
  */
#define ADC_DEFAULT_CONFIG          LL_ADC_DEFAULT_CONFIG
/** @} */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup ADC_Exported_Macros ADC Exported Macros
  * @{
  */

/** @brief  Reset ADC handle states.
  * @param  __HANDLE__ ADC handle.
  * @retval None
  */
#define __HAL_ADC_RESET_HANDLE_STATE(__HANDLE__)               ((__HANDLE__)->state = HAL_ADC_STATE_RESET)

/** @brief  Enable the specified ADC peripheral.
  * @param  __HANDLE__ Specify the ADC Handle.
  * @retval None
  */
#define __HAL_ADC_ENABLE(__HANDLE__)                           ll_adc_enable()

/** @brief  Disable the specified ADC peripheral.
  * @param  __HANDLE__ Specify the ADC Handle.
  * @retval None
  */
#define __HAL_ADC_DISABLE(__HANDLE__)                          ll_adc_disable()

/** @brief  Enable the specified ADC clock.
  * @param  __HANDLE__ Specify the ADC Handle.
  * @retval None
  */
#define __HAL_ADC_ENABLE_CLOCK(__HANDLE__)                     ll_adc_enable_clock()

/** @brief  Disable the specified ADC clock.
  * @param  __HANDLE__ Specify the ADC Handle.
  * @retval None
  */
#define __HAL_ADC_DISABLE_CLOCK(__HANDLE__)                    ll_adc_disable_clock()

/** @brief  Check the FIFO is not empty.
  * @param  __HANDLE__ Specify the ADC Handle.
  * @retval The new state of notempty flag (TRUE or FALSE).
  */
#define __HAL_ADC_GET_FLAG_NOTEMPTY(__HANDLE__)                ll_adc_is_fifo_notempty()

/** @brief  Flush the FIFO.
  * @param  __HANDLE__ Specify the ADC Handle.
  * @retval None
  */
#define __HAL_ADC_FLUSH_FIFO(__HANDLE__)                       do {                                 \
                                                                   while(ll_adc_is_fifo_notempty()) \
                                                                   {                                \
                                                                       ll_adc_read_fifo();          \
                                                                   }                                \
                                                               } while(0)

/** @} */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup ADC_Private_Macros ADC Private Macros
  * @{
  */

/**
  * @brief Check if ADC input source is valid.
  * @param __INPUT__ ADC input source.
  * @retval SET (__INPUT__ is valid) or RESET (__INPUT__ is invalid)
  */
#define IS_ADC_INPUT(__INPUT__)             (((__INPUT__) == ADC_INPUT_SRC_IO0) || \
                                             ((__INPUT__) == ADC_INPUT_SRC_IO1) || \
                                             ((__INPUT__) == ADC_INPUT_SRC_IO2) || \
                                             ((__INPUT__) == ADC_INPUT_SRC_IO3) || \
                                             ((__INPUT__) == ADC_INPUT_SRC_IO4) || \
                                             ((__INPUT__) == ADC_INPUT_SRC_TMP) || \
                                             ((__INPUT__) == ADC_INPUT_SRC_BAT) || \
                                             ((__INPUT__) == ADC_INPUT_SRC_REF))

/**
  * @brief Check if ADC input mode is valid.
  * @param __MODE__ ADC input mode.
  * @retval SET (__MODE__ is valid) or RESET (__MODE__ is invalid)
  */
#define IS_ADC_INPUT_MODE(__MODE__)         (((__MODE__) == ADC_INPUT_SINGLE) || \
                                             ((__MODE__) == ADC_INPUT_DIFFERENTIAL)

/**
  * @brief Check if ADC reference source is valid.
  * @param __INPUT__ ADC reference source.
  * @retval SET (__INPUT__ is valid) or RESET (__INPUT__ is invalid)
  */
#define IS_ADC_REF(__INPUT__)               (((__INPUT__) == ADC_REF_SRC_BUF_INT) || \
                                             ((__INPUT__) == ADC_REF_SRC_INT)     || \
                                             ((__INPUT__) == ADC_REF_SRC_IO0)     || \
                                             ((__INPUT__) == ADC_REF_SRC_IO1)     || \
                                             ((__INPUT__) == ADC_REF_SRC_IO2)     || \
                                             ((__INPUT__) == ADC_REF_SRC_IO3))

/**
  * @brief Check if ADC reference value is valid.
  * @param __VALUE__ ADC reference value.
  * @retval SET (__VALUE__ is valid) or RESET (__VALUE__ is invalid)
  */
#define IS_ADC_REF_VALUE(__VALUE__)         (((__VALUE__) >= ADC_REF_VALUE_0P5) && \
                                             ((__VALUE__) <= ADC_REF_VALUE_2P0))

/**
  * @brief Check if ADC clock is valid.
  * @param __CLOCK__ ADC clock.
  * @retval SET (__CLOCK__ is valid) or RESET (__CLOCK__ is invalid)
  */
#define IS_ADC_CLOCK(__CLOCK__)             (((__CLOCK__) == ADC_CLK_16M) || \
                                             ((__CLOCK__) == ADC_CLK_8M)  || \
                                             ((__CLOCK__) == ADC_CLK_4M)  || \
                                             ((__CLOCK__) == ADC_CLK_2M)  || \
                                             ((__CLOCK__) == ADC_CLK_1M)  || \
                                             ((__CLOCK__) == ADC_CLK_1P6M))

/** @} */

/** @} */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup HAL_ADC_DRIVER_FUNCTIONS Functions
  * @{
  */

/** @addtogroup ADC_Exported_Functions_Group1 Initialization and de-initialization Functions
  *  @brief    Initialization and Configuration functions
  * @{
  */

/**
 ****************************************************************************************
 * @brief  Initialize the ADC according to the specified parameters
 *         in the adc_init_t and initialize the associated handle.
 *
 * @param[in]  p_adc: Pointer to an ADC handle which contains the configuration information for
 *                    the specified ADC module.
 *
 * @retval ::HAL_OK: Operation is OK.
 * @retval ::HAL_ERROR: Parameter error or operation not supported.
 * @retval ::HAL_BUSY: Driver is busy.
 * @retval ::HAL_TIMEOUT: Timeout occurred.
 ****************************************************************************************
 */
hal_status_t hal_adc_init(adc_handle_t *p_adc);

/**
 ****************************************************************************************
 * @brief  De-initialize the ADC peripheral.
 *
 * @param[in]  p_adc: Pointer to an ADC handle which contains the configuration information for
 *                    the specified ADC module.
 *
 * @retval ::HAL_OK: Operation is OK.
 * @retval ::HAL_ERROR: Parameter error or operation not supported.
 * @retval ::HAL_BUSY: Driver is busy.
 * @retval ::HAL_TIMEOUT: Timeout occurred.
 ****************************************************************************************
 */
hal_status_t hal_adc_deinit(adc_handle_t *p_adc);

/**
 ****************************************************************************************
 * @brief  Initialize the ADC MSP.
 *
 * @note   This function should not be modified. When the callback is needed,
 *          the hal_adc_msp_deinit can be implemented in the user file.
 *
 * @param[in]  p_adc: Pointer to an ADC handle which contains the configuration information for
 *                the specified ADC module.
 ****************************************************************************************
 */
void hal_adc_msp_init(adc_handle_t *p_adc);

/**
 ****************************************************************************************
 * @brief  De-initialize the ADC MSP.
 *
 * @note   This function should not be modified. When the callback is needed,
 *          the hal_adc_msp_deinit can be implemented in the user file.
 *
 * @param[in]  p_adc: Pointer to an ADC handle which contains the configuration information for
 *                    the specified ADC module.
 ****************************************************************************************
 */
void hal_adc_msp_deinit(adc_handle_t *p_adc);

/** @} */

/** @addtogroup ADC_Exported_Functions_Group2 IO Operation Functions
 *  @brief ADC polling and DMA conversion management functions.
 * @{
 */
 
 /**
 ****************************************************************************************
 * @brief  Set the FIFO threshold for DMA trigger.
 *
 * @param[in]  p_adc: Pointer to an ADC handle which contains the configuration information for
 *                    the specified ADC module.
 * @param[in]  threshold: FIFO threshold value ranging bwtween 0x0U ~ 0x64U.
 *
 * @retval ::HAL_OK: Operation is OK.
 * @retval ::HAL_ERROR: Parameter error or operation not supported.
 * @retval ::HAL_BUSY: Driver is busy.
 * @retval ::HAL_TIMEOUT: Timeout occurred.
 ****************************************************************************************
 */
hal_status_t hal_adc_set_dma_threshold(adc_handle_t *p_adc, uint32_t threshold);

/**
 ****************************************************************************************
 * @brief  Get the FIFO threshold for DMA trigger.
 *
 * @param[in]  p_adc: Pointer to an ADC handle which contains the configuration information for
 *                    the specified ADC module.
 *
 * @return FIFO threshold
 ****************************************************************************************
 */
uint32_t hal_adc_get_dma_threshold(adc_handle_t *p_adc);

/**
 ****************************************************************************************
 * @brief  Polling for conversion.
 *
 * @param[in]  p_adc:  Pointer to an ADC handle.
 * @param[in]  p_data: Pointer to data buffer which to store ADC conversion results.
 * @param[in]  length: Length of data buffer.
 *
 * @retval ::HAL_OK: Operation is OK.
 * @retval ::HAL_ERROR: Parameter error or operation not supported.
 * @retval ::HAL_BUSY: Driver is busy.
 * @retval ::HAL_TIMEOUT: Timeout occurred.
 ****************************************************************************************
 */
hal_status_t hal_adc_poll_for_conversion(adc_handle_t *p_adc, uint16_t *p_data, uint32_t length);

/**
 ****************************************************************************************
 * @brief  DMA for conversion.
 *
 * @param[in]  p_adc:  Pointer to an ADC handle.
 * @param[in]  p_data: Pointer to data buffer which to store ADC conversion results.
 * @param[in]  length: Length of data buffer,  ranging between 0 and 4095.
 *
 * @retval ::HAL_OK: Operation is OK.
 * @retval ::HAL_ERROR: Parameter error or operation not supported.
 * @retval ::HAL_BUSY: Driver is busy.
 * @retval ::HAL_TIMEOUT: Timeout occurred.
 ****************************************************************************************
 */
hal_status_t hal_adc_start_dma(adc_handle_t *p_adc, uint16_t *p_data, uint32_t length);

/**
 ****************************************************************************************
 * @brief  Abort ongoing conversion (blocking mode).
 *
 * @note   This procedure could be only used for aborting conversion started in DMA mode.
 *         This procedure performs following operations:
 *           - Disable ADC clock, stop conversion
 *           - Abort DMA transfer by calling hal_dma_abort (in case of transfer in DMA mode)
 *           - Set handle State to READY.
 *         This procedure is executed in blocking mode: when exiting function, Abort is considered as completed.
 *
 * @param[in]  p_adc: ADC handle.
 *
 * @retval ::HAL_OK: Operation is OK.
 * @retval ::HAL_ERROR: Parameter error or operation not supported.
 * @retval ::HAL_BUSY: Driver is busy.
 * @retval ::HAL_TIMEOUT: Timeout occurred.
 ****************************************************************************************
 */
hal_status_t hal_adc_stop_dma(adc_handle_t *p_adc);

/**
 ****************************************************************************************
 * @brief  Conversion completed callback.
 *
 * @note   This function should not be modified. When the callback is needed,
 *          the hal_adc_msp_deinit can be implemented in the user file.
 *
 * @param[in]  p_adc: Pointer to an ADC handle which contains the configuration information for
 *                    the specified ADC module.
 ****************************************************************************************
 */
void hal_adc_conv_cplt_callback(adc_handle_t* p_adc);

/** @} */

/** @defgroup ADC_Exported_Functions_Group3 Peripheral State and Errors Functions
  * @brief   ADC control functions
  *
@verbatim
 ===============================================================================
                      ##### Peripheral State and Errors functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the ADC.
     (+) hal_adc_get_state() API can be helpful to check in run-time the state of the ADC peripheral.
     (+) hal_adc_get_error() check in run-time Errors occurring during communication.
@endverbatim
  * @{
  */

/**
 ****************************************************************************************
 * @brief  Return the ADC handle state.
 *
 * @param[in]  p_adc: Pointer to an ADC handle which contains the configuration information for
 *                    the specified ADC module.
 *
 * @retval ::HAL_ADC_STATE_RESET: Peripheral not initialized.
 * @retval ::HAL_ADC_STATE_READY: Peripheral initialized and ready for use.
 * @retval ::HAL_ADC_STATE_BUSY: An internal process is ongoing.
 * @retval ::HAL_ADC_STATE_ERROR: Peripheral in error.
 ****************************************************************************************
 */
hal_adc_state_t hal_adc_get_state(adc_handle_t *p_adc);

/**
 ****************************************************************************************
 * @brief  Return the ADC error code.
 *
 * @param[in]  p_adc: Pointer to an ADC handle which contains the configuration information for
 *                    the specified ADC module.
 *
 * @return ADC error code in bitmap format
 ****************************************************************************************
 */
uint32_t hal_adc_get_error(adc_handle_t *p_adc);

/** @} */

/** @} */


#ifdef __cplusplus
}
#endif

#endif /* __GR55xx_HAL_ADC_H__ */

/** @} */

/** @} */

/** @} */
