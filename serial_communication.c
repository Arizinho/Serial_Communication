#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "pico/bootrom.h"

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
        switch (tecla)
        {
        case '1':
            //liga a cor vermelha do led rgb
            liga_led_rgb(1,0,0);
            printf("RED LED ON\n");
            break;

        case '2':
            //liga a cor verde do led rgb
            liga_led_rgb(0,1,0);
            printf("GREEN LED ON\n");
            break;
        
        case '3':
            //liga a cor azul do led rgb
            liga_led_rgb(0,0,1);
            printf("BLUE LED ON\n");
            break;
        
        case '4':
            //liga a cor branca do led rgb
            printf("WHITE LED ON\n");
            liga_led_rgb(1,1,1);
            break;

        case '0':
            //desliga o led
            printf("LED OFF\n");
            liga_led_rgb(0,0,0);
            break;

        case '5':
            //aciona buzzer durante 1 segundo
            printf("BUZZER PLAYING\n");
            pwm_set_chan_level(SLICE_GPIO10, CHANNEL_GPIO10, (TOP + 1)/2); //dutty cycle de 50%
            sleep_ms(1000);
            pwm_set_chan_level(SLICE_GPIO10, CHANNEL_GPIO10, 0);
            break;  

        case '6':
            //coloca a placa em modo de armazenamento
            printf("STORAGE MODE ON\n");
            reset_usb_boot(0,0);
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


