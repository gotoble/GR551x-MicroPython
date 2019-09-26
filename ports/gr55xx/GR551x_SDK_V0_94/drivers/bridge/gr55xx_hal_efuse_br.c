/**
  ****************************************************************************************
  * @file    gr55xx_hal_efuse_br.c
  * @author  BLE Driver Team
  * @brief   EFUSE HAL module driver.
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

#include "gr55xx_hal.h"

#ifdef HAL_EFUSE_MODULE_ENABLED

/* Private variables ---------------------------------------------------------*/

static hal_efuse_callback_t *p_efuse_callback = NULL;

/* Private function prototypes -----------------------------------------------*/

hal_status_t hal_efuse_init_ext(efuse_handle_t *p_efuse)
{
    return hal_efuse_init(p_efuse);
}

hal_status_t hal_efuse_deinit_ext(efuse_handle_t *p_efuse)
{
    return hal_efuse_deinit(p_efuse);
}

void hal_efuse_msp_init(efuse_handle_t *p_efuse)
{
    if (NULL != p_efuse_callback && NULL != p_efuse_callback->efuse_msp_init)
    {
        p_efuse_callback->efuse_msp_init(p_efuse);
    }
}

void hal_efuse_msp_deinit(efuse_handle_t *p_efuse)
{
    if (NULL != p_efuse_callback && NULL != p_efuse_callback->efuse_msp_deinit)
    {
        p_efuse_callback->efuse_msp_deinit(p_efuse);
    }
}

void hal_efuse_register_callback(hal_efuse_callback_t *hal_efuse_callback)
{
    p_efuse_callback = hal_efuse_callback;
}

#endif /* HAL_EFUSE_MODULE_ENABLED */
