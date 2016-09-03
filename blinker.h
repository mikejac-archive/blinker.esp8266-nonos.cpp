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

#ifndef BLINKER_H
#define	BLINKER_H

#include <github.com/mikejac/timer.esp8266-nonos.cpp/timer.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct {
    int             m_Pin;
    unsigned long   m_OffTime;
    unsigned long   m_OnTime;
    Timer           m_Timer;
    bool            m_Value;
} BLINKER;

/******************************************************************************************************************
 * prototypes
 *
 */

/**
 * 
 * @param b
 * @param pin
 * @return 
 */
int Blinker_Initialize(BLINKER* b, int pin);
/**
 * 
 * @param b
 * @return 
 */
int Blinker_Run(BLINKER* b);
/**
 * 
 * @param b
 * @param off_ms
 * @param on_ms
 * @return 
 */
int Blinker_Set(BLINKER* b, unsigned long off_ms, unsigned long on_ms);
/**
 * 
 * @param b
 * @return 
 */
int Blinker_Enable_on(BLINKER* b);
/**
 * 
 * @param b
 * @return 
 */
int Blinker_Enable_off(BLINKER* b);
/**
 * 
 * @param b
 * @return 
 */
int Blinker_Disable_on(BLINKER* b);
/**
 * 
 * @param b
 * @return 
 */
int Blinker_Disable_off(BLINKER* b);

#ifdef	__cplusplus
}
#endif

#endif	/* BLINKER_H */

