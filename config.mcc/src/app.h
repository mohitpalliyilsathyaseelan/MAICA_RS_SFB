/*
 * app.h — Application state machine and module interface
 * Target: PIC32CM6408PL10048 / PIC32CM PL10 Curiosity Nano
 */
#ifndef APP_H
#define APP_H

#include <stdint.h>
#include <stdbool.h>
#include "config/default/definitions.h"
#include "gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ---- Application State Machine ---- */
typedef enum
{
    APP_STATE_INIT = 0,            /* Initialize modules */
    APP_STATE_IDLE,                /* Idle; interrupt-driven operation */
    APP_STATE_SERVICE_TASKS        /* Service module tasks */
} APP_STATES;

/* ---- Application Data Structure ---- */
typedef struct
{
    APP_STATES state;
} APP_DATA;

/* ---- Public API ---- */

/**
 * APP_Initialize
 * Initializes all application modules and sets up interrupt handlers
 */
void APP_Initialize(void);

/**
 * APP_Tasks
 * Main application task loop; call from main.c's while(1) loop
 */
void APP_Tasks(void);

#ifdef __cplusplus
}
#endif
#endif /* APP_H */
