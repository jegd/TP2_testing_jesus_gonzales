/*
Con todos los leds apagados prender un led y verificar que al consultarlo el estado es el mismo en info
Prender todos los leds que están apagados antes de al operación
Apagar todos los leds que ya estan prendidos
Prender leds que ya esten prendidos antes
Apagar leds que ya esten apagados
Comprobar valores prohibidos
Comprobar los valores límite
*/

#include "unity.h"
#include "leds.h"

static uint16_t leds_virtuales;
static const int LED=3;

//Al iniciar el controlador los leds deben quedar todos 
//los bits en 0 sin importar el estado anterior
void test_todos_los_leds_inician_apagados(void){
    uint16_t leds_virtuales = 0xFF;
    leds_init(&leds_virtuales);
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_virtuales);    
}

void setUp(void){
    leds_init(&leds_virtuales);
}

//Con todos los leds apagados prender el led 3 y verificar que 
//efectivamente  el bit 2 se pone en 1 y el resto de bits permanece en 0

void test_prender_un_led(void){
    leds_turn_on(LED);
    //El bit 2 se pone en alto
    TEST_ASSERT_BIT_HIGH(LED-1, leds_virtuales);
    //Todos los otros bits estan en bajo
    TEST_ASSERT_BITS_LOW(~(1<<(LED-1)),leds_virtuales);

}

//Apagar un led prendido y ver que efectivamente se apaga y el resto no cambia
void test_apagar_un_led(void){
    leds_turn_on(LED);
    leds_turn_off(LED);
    
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_virtuales);

}

//Apagar un led prendido y ver que efectivamente 
//se apagay que el resto no cambia.
void test_prender_y_apagar_varios_leds(void){
    leds_turn_on(5);
    leds_turn_on(7);
    leds_turn_on(5);
    leds_turn_off(5);
    leds_turn_off(9);

    TEST_ASSERT_EQUAL_UINT16((1<<(7-1)), leds_virtuales);
}