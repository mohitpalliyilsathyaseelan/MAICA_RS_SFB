/*
 * app.c — Application state machine and module implementation
 */
#include "app.h"

/* Global application data */
static APP_DATA appData;

/**
 * Button_Callback (ISR callback)
 * Called on falling edge of PB03 (EIC interrupt)
 * Toggles LED via GPIO module
 *
 * Note: This will be connected to EIC_PIN_3 once EIC is configured via MCC.
 * The callback must be registered in APP_Initialize().
 */
static void Button_Callback(uintptr_t context)
{
    (void)context;  /* Suppress unused parameter warning */
    
    /* Toggle LED on button press */
    GPIO_LED_Toggle();
}

void APP_Initialize(void)
{
    /* Initialize GPIO module */
    GPIO_Initialize();
    
    /* 
     * Register EIC callback for PB03 falling edge
     * 
     * NOTE: EIC peripheral must be configured in MCC first.
     * Once configured, plib_eic.h will be added to definitions.h,
     * and EIC_PIN_3 will be defined for PB03.
     * 
     * Uncomment the following lines once EIC is added via MCC:
     * 
     * EIC_CallbackRegister(EIC_PIN_3, Button_Callback, 0);
     * EIC_InterruptEnable(EIC_PIN_3);
     */
    
    /* Set initial state */
    appData.state = APP_STATE_IDLE;
}

void APP_Tasks(void)
{
    switch (appData.state)
    {
        case APP_STATE_INIT:
            APP_Initialize();
            appData.state = APP_STATE_IDLE;
            break;

        case APP_STATE_IDLE:
            /* Interrupt-driven; nothing to poll in idle state */
            break;

        case APP_STATE_SERVICE_TASKS:
            /* Call module task functions */
            GPIO_Tasks();
            appData.state = APP_STATE_IDLE;
            break;

        default:
            break;
    }
}
