/*
 * gpio.h — GPIO module for LED control via PORT PLIB
 * Target: PIC32CM6408PL10048 / PIC32CM PL10 Curiosity Nano
 */
#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <stdbool.h>
#include "config/default/definitions.h"    /* MCC PLIB APIs */

#ifdef __cplusplus
extern "C" {
#endif

/* ---- Public API ---- */

/**
 * GPIO_Initialize
 * Initializes GPIO; drives PB02 (LED) HIGH (LED off at startup)
 */
void GPIO_Initialize(void);

/**
 * GPIO_LED_Off
 * Turns LED off by driving PB02 HIGH (active-low logic)
 */
void GPIO_LED_Off(void);

/**
 * GPIO_LED_On
 * Turns LED on by driving PB02 LOW (active-low logic)
 */
void GPIO_LED_On(void);

/**
 * GPIO_LED_Toggle
 * Toggles LED state (ON ↔ OFF)
 */
void GPIO_LED_Toggle(void);

/**
 * GPIO_Tasks
 * Idle stub for super-loop integration; call from APP_STATE_SERVICE_TASKS
 */
void GPIO_Tasks(void);

#ifdef __cplusplus
}
#endif
#endif /* GPIO_H */
