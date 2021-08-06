/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-3-19   tyustli      first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "sensor.h"
#include "stm32l475e_iot01.h"
#include "stm32l475e_iot01_accelero.h"

/* defined the LED0 pin: PB14 */
#define LED0_PIN    GET_PIN(B, 14)

struct rt_i2c_bus_device* i2c_bus;
rt_int16_t pAccelData[3] = {0, 0, 0};
rt_int16_t iAccelValX = 0;    // Accelerometer value in X-axis
rt_int16_t iAccelValY = 0;    // Accelerometer value in Y-axis
rt_int16_t iAccelValZ = 0;    // Accelerometer value in Z-axis

/* Thread prototypes */
static void thread1_led_blink(void* param);
static void thread2_get_sensor_data(void* param);

int main(void)
{
    static rt_thread_t rt1 = RT_NULL;
    static rt_thread_t rt2 = RT_NULL;

    /* set LED0 pin mode to output */
    rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);

    /* Initialize sensor */
    BSP_ACCELERO_Init();
    BSP_ACCELERO_LowPower(0);

    /* Initialize and start thread 1 */
    rt1 = rt_thread_create("thread1", thread1_led_blink, RT_NULL, 128, 2, 10);
    rt_thread_startup(rt1);

    /* Initialize and start thread 2 */
    rt2 = rt_thread_create("thread2", thread2_get_sensor_data, RT_NULL, 128, 0, 100);
    rt_thread_startup(rt2);


    return RT_EOK;
}

/* Threads */
static void thread1_led_blink(void* param)
{
    while(1)
    {
        rt_pin_write(LED0_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED0_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }
}

static void thread2_get_sensor_data(void* param)
{
    while(1)
    {
        // Get sensor data
        BSP_ACCELERO_AccGetXYZ(pAccelData);

        // Fetch each axis data
        iAccelValX = pAccelData[0];
        iAccelValY = pAccelData[1];
        iAccelValZ = pAccelData[2];

        // Send sensor data to UART
        rt_kprintf("%d,%d,%d\r\n", iAccelValX, iAccelValY, iAccelValZ);

        rt_thread_mdelay(20);
    }
}
