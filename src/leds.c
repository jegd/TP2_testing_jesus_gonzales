/*
 * Copyright (c) 2023 Jesus Gonzales <jesus.e.1997.eg@gmail.com>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * @file   : leds.c
 * @date   : Mar 23, 2024
 * @author : Jesus Gonzales <jesus.e.1997.eg@gmail.com>
 * @version	v1.0.0
 */

/********************** inclusions *******************************************/
#include "leds.h"
/********************** macros and definitions *******************************/
#define BIT_HIGH 1
#define LED_OFFSET 1
#define ALL_LED_OFF 0x00
#define BYTE 8
/********************** internal data declaration ****************************/
/********************** internal functions declaration ***********************/
/********************** internal data definition *****************************/
static uint16_t *puntero;
/********************** external data definition *****************************/
/********************** internal functions definition ************************/
static uint16_t led_to_mask(int led){
    return BIT_HIGH<<(led-LED_OFFSET);
}
/********************** external functions definition ************************/
void leds_init(uint16_t * puerto){
    puntero=puerto;
    leds_turn_off_all(puntero);
}

void leds_turn_on(int led)
{
    *puntero|=led_to_mask(led);
}

void leds_turn_off(int led){
    *puntero&=~(led_to_mask(led));
}

void leds_turn_off_all(uint16_t * puerto){
    *puntero=ALL_LED_OFF;
}

bool leds_on_verify(int led){
    return led_to_mask(led)==(led_to_mask(led)&(*puntero));
}

void leds_turn_on_leds_off(uint16_t * puerto){
    static uint16_t led; 
    for(led=0;led<=sizeof(*puntero)*BYTE;led++){
        if(!leds_on_verify(led))
        leds_turn_on(led);
    }
}

void leds_turn_off_leds_on(uint16_t * puerto){
    static uint16_t led; 
    for(led=0;led<=sizeof(*puntero)*BYTE;led++){
        if(leds_on_verify(led))
        leds_turn_off(led);
    }
}
/********************** end of file ******************************************/