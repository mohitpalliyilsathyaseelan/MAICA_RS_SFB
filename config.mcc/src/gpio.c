/*
 * gpio.c — GPIO module source; PB02 (LED) PLIB wrappers
 */
#include "gpio.h"

/* Module-private state */
static bool s_initialized = false;

void GPIO_Initialize(void)
{
    /* Drive PB02 HIGH (LED off at startup) using MCC-generated macro */
    GPIO_PB02_Set();
    s_initialized = true;
}

void GPIO_LED_Off(void)
{
    /* PB02 active-low: drive HIGH to turn LED OFF */
    GPIO_PB02_Set();
}

void GPIO_LED_On(void)
{
    /* PB02 active-low: drive LOW to turn LED ON */
    GPIO_PB02_Clear();
}

void GPIO_LED_Toggle(void)
{
    /* Toggle PB02 state */
    GPIO_PB02_Toggle();
}

void GPIO_Tasks(void)
{
    if (!s_initialized) { return; }
    /* Idle stub — no polling required for static GPIO */
}
