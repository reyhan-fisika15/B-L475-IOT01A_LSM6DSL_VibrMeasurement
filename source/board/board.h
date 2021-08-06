/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 *2019-3-19     tyustli      first version
 */

#ifndef __BOARD_H__
#define __BOARD_H__

#include <rtthread.h>
#include <stm32l4xx.h>
#include "drv_common.h"
#include "drv_gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

#define STM32_FLASH_START_ADRESS       ((uint32_t)0x08000000)
#define STM32_FLASH_SIZE               (1024 * 1024)
#define STM32_FLASH_END_ADDRESS        ((uint32_t)(STM32_FLASH_START_ADRESS + STM32_FLASH_SIZE))

#define STM32_SRAM1_SIZE               (96)
#define STM32_SRAM1_START              (0x20000000)
#define STM32_SRAM1_END                (STM32_SRAM1_START + STM32_SRAM1_SIZE * 1024)

#define HEAP_BEGIN                     STM32_SRAM1_START
#define HEAP_END                       STM32_SRAM1_END

#define BSP_USING_I2C1                         /* Use I2C1 Bus */
#define BSP_I2C1_SCL_PIN    GET_PIN(B, 10)      /* SCL -> PB10 */
#define BSP_I2C1_SDA_PIN    GET_PIN(B, 11)      /* SDA -> PB11 */

void SystemClock_Config(void);

#ifdef __cplusplus
}
#endif

#endif

