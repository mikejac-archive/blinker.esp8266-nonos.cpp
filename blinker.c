/* 
 * The MIT License (MIT)
 * 
 * ESP8266 Non-OS Firmware
 * Copyright (c) 2015 Michael Jacobsen (github.com/mikejac)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include "blinker.h"
#include <github.com/mikejac/esp-open-rtos.gpio.esp8266-nonos.cpp/gpio/gpio.h>

/******************************************************************************************************************
 * public functions
 *
 */

/**
 * 
 * @param b
 * @param pin
 * @return 
 */
int ICACHE_FLASH_ATTR Blinker_Initialize(BLINKER* b, int pin)
{
    b->m_Pin     = pin;
    b->m_OffTime = 0;
    b->m_OnTime  = 0;
    
    countdown_ms(&b->m_Timer, 0);       // disable the timer
    
    gpio_enable(pin, GPIO_OUTPUT);

    return 0;
}
/**
 * 
 * @param b
 * @return 
 */
int ICACHE_FLASH_ATTR Blinker_Run(BLINKER* b)
{
    if(enabled(&b->m_Timer)) {
        if(expired(&b->m_Timer)) {
            if(b->m_Value == true) {
                Blinker_Enable_off(b);
            }
            else {
                Blinker_Enable_on(b);
            }
        }
    }
    
    return 0;
}
/**
 * 
 * @param b
 * @param off_ms
 * @param on_ms
 * @return 
 */
int ICACHE_FLASH_ATTR Blinker_Set(BLINKER* b, unsigned long off_ms, unsigned long on_ms)
{
    if(enabled(&b->m_Timer) && (b->m_OffTime != off_ms || b->m_OnTime != on_ms)) {
        if(b->m_Value == true) {
            countdown_ms(&b->m_Timer, on_ms);
        }
        else {
            countdown_ms(&b->m_Timer, off_ms);
        }        
    }
    
    b->m_OffTime = off_ms;
    b->m_OnTime  = on_ms;
    
    return 0;
}
/**
 * 
 * @param b
 * @return 
 */
int ICACHE_FLASH_ATTR Blinker_Enable_on(BLINKER* b)
{
    countdown_ms(&b->m_Timer, b->m_OnTime);
    b->m_Value = true;
    
    gpio_write(b->m_Pin, true);
    
    return 0;
}
/**
 * 
 * @param b
 * @return 
 */
int ICACHE_FLASH_ATTR Blinker_Enable_off(BLINKER* b)
{
    countdown_ms(&b->m_Timer, b->m_OffTime);
    b->m_Value = false;
    
    gpio_write(b->m_Pin, false);
    
    return 0;
}
/**
 * 
 * @param b
 * @return 
 */
int ICACHE_FLASH_ATTR Blinker_Disable_on(BLINKER* b)
{
    countdown_ms(&b->m_Timer, 0);
    b->m_Value = true;
    
    gpio_write(b->m_Pin, true);
    
    return 0;
}
/**
 * 
 * @param b
 * @return 
 */
int ICACHE_FLASH_ATTR Blinker_Disable_off(BLINKER* b)
{
    countdown_ms(&b->m_Timer, 0);
    b->m_Value = false;
    
    gpio_write(b->m_Pin, false);
    
    return 0;
}
