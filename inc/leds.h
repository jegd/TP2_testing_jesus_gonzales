/*
 * Copyright (c) 2024 Jesus Gonzales <jesus.e.1997.eg@gmail.com>.
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
 * @file   : leds.h
 * @date   : Mar 23, 2024
 * @author : Jesus Gonzales <jesus.e.1997.eg@gmail.com>
 * @version	v1.0.0
 */
#ifndef INC_LEDS_H_
#define INC_LEDS_H_

/********************** inclusions *******************************************/
#include <stdint.h>
/********************** cabecera c++ *******************************************/

#ifdef __cplusplus
extern "C" {
#endif
/********************** macros and definitions *******************************/
/********************** internal data declaration ****************************/
/********************** internal functions declaration ***********************/
/********************** internal data definition *****************************/
/********************** external data definition *****************************/
/********************** internal functions definition ************************/
/********************** external functions definition ************************/
/**
 * @brief   Inicializa las GPIO
 *
 * @param puerto Dirección del puerto que se usará
 */
void leds_init(uint16_t * puerto);
/**
 * @brief   Función para prender un led
 *
 * @param led Número del led a prender
 */
void leds_turn_on(int led);
/**
 * @brief   Función para apagar un led
 *
 * @param led Número del led a apagar
 */
void leds_turn_off(int led);
/**
 * @brief   Apaga todos los leds
 *
 * @param puerto Dirección del puerto que se usará
 */
void leds_turn_off_all(uint16_t * puerto);
/**
 * @brief   Verifica si el led está encendido
 *
 * @param led Número del led a verificar
 */
int leds_on_verify(int led);

void leds_turn_on_leds_off(uint16_t * puerto);

#ifdef __cplusplus
}
#endif

#endif /* APP_INC_AO_LED_H_ */
/********************** end of file ******************************************/