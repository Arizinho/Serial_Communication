#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define LED_RED 13
#define LED_GREEN 11
#define LED_BLUE 12
#define BUZZER 21

#define SLICE_GPIO21 2
#define CHANNEL_GPIO21 PWM_CHAN_B
#define TOP 8877
#define DIV 32

//protótipo das funções
void led_rgb_init(void);
void liga_led_rgb(bool red, bool green, bool blue);
void buzzer_init(void);

int main()
{   
    char tecla;

    //inicializa comunicação serial
    stdio_init_all();

    //inicializa os GPIOs do LED RGB e do Buzzer
    led_rgb_init();
    buzzer_init();

    while (true) {
        //lê tecla pressionada
        tecla = getchar();
        switch ('1')
        {
        case /* constant-expression */:
            /* code */
            break;

        switch ('2')
        {
        case /* constant-expression */:
            /* code */
            break;

        switch ('3')
        {
        case /* constant-expression */:
            /* code */
            break;

        switch ('4')
        {
        case /* constant-expression */:
            /* code */
            break;

        switch ('5')
        {
        case /* constant-expression */:
            /* code */
            break;
        
        default:
            break;
        }
    }
}

//função para inicializar os pinos do led rgb
void led_rgb_init(void){
    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);

    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
}

//função para ligar leds selecionados
void liga_led_rgb(bool red, bool green, bool blue){
    gpio_put(LED_RED, red);
    gpio_put(LED_GREEN, green);
    gpio_put(LED_BLUE, blue);
}

//função para inicializar o pwm do buzzer
void buzzer_init(void){
    //inicializa o pino do buzzer como pwm
    gpio_set_function(BUZZER, GPIO_FUNC_PWM);
    //seta valor máximo de contagem do PWM (TOP)
    pwm_set_wrap(SLICE_GPIO10, TOP);
    //seta valor de divisão do clock do PWM
    pwm_set_clkdiv(SLICE_GPIO10, DIV);

    /*
    valor de TOP e DIV previamente calculado para emitir som da nota LÁ 4 (440 Hz): 
    f_pwm = f_sys /((TOP + 1) * (DIV) * (CSR_PH_CORRECT + 1)) ~ 440 
    .: CSR_PH_CORRECT não setado -> 0
    */

    //seta valor inicial de dutty cycle como 0
    pwm_set_chan_level(SLICE_GPIO10, CHANNEL_GPIO10, 0);
    //abilita PWM
    pwm_set_enabled(SLICE_GPIO10, true);
}


