/**************************************************************************//**
 * @file     system_gr55xx.h
 * @brief    CMSIS Cortex-M# Device Peripheral Access Layer Header File for
 *           Device GR55xx
 * @version  V1.00
 * @date     12. June 2018
 ******************************************************************************/
/*
 * Copyright (c) 2016-2018, Shenzhen Huiding Technology Co., Ltd
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __SYSTEM_GR55xx_H__
#define __SYSTEM_GR55xx_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define CLK_64M        64000000
#define CLK_48M        48000000
#define CLK_32M        32000000
#define CLK_24M        24000000
#define CLK_16M        16000000

typedef enum
{
    XO_S16M_CLK   = 2,
    CPLL_S16M_CLK = 4,
    CPLL_T24M_CLK = 3,
    CPLL_T32M_CLK = 5,
    CPLL_F48M_CLK = 1,
    CPLL_S64M_CLK = 0,
    CLK_TYPE_NUM  = 6,
} mcu_clock_type_t;


extern uint32_t SystemCoreClock;     /*!< System Clock Frequency (Core Clock) */

/** @brief Setup the microcontroller system.

    Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit(void);

/** \brief  Update SystemCoreClock variable.

    Updates the SystemCoreClock with current core Clock
    retrieved from cpu registers.
 */
extern void SystemCoreSetClock(mcu_clock_type_t clock);

/** \brief  Get SystemCoreClock variable.

    Get the SystemCoreClock with current core Clock
    retrieved from cpu registers.
 */
extern void SystemCoreGetClock(mcu_clock_type_t *clock);


extern void SystemCoreUpdateClock(void);


//extern void system_pmu_init(void);

//extern void system_pmu_deinit(void);

//extern void startClockCalibration(uint32_t lpcyclecounter);

//extern void platform_init(void);

//extern void warm_boot(void);

//extern void system_pmu_calibration_start(uint32_t interval);

#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_GR55xx_H__ */
