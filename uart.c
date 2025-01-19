#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define LED_VERDE_PIN 11
#define LED_AZUL_PIN 12
#define LED_VERMELHO_PIN 13
#define BUZZER_PIN 21

void desligar_leds() {
    gpio_put(LED_VERDE_PIN, 0);
    gpio_put(LED_AZUL_PIN, 0);
    gpio_put(LED_VERMELHO_PIN, 0);
}

void ligar_verde() {
    desligar_leds();
    gpio_put(LED_VERDE_PIN, 1);
}

void ligar_azul() {
    desligar_leds();
    gpio_put(LED_AZUL_PIN, 1);
}

void ligar_vermelho() {
    desligar_leds();
    gpio_put(LED_VERMELHO_PIN, 1);
}

void ligar_branco() {
    gpio_put(LED_VERDE_PIN, 1);
    gpio_put(LED_AZUL_PIN, 1);
    gpio_put(LED_VERMELHO_PIN, 1);
}

void acionar_buzzer() {
    gpio_put(BUZZER_PIN, 1);  // Liga o buzzer
    sleep_ms(2000);            // Espera 2 segundos
    gpio_put(BUZZER_PIN, 0);  // Desliga o buzzer
}

int main() {
    stdio_init_all();

    // Configura os pinos GPIO
    gpio_init(LED_VERDE_PIN);
    gpio_set_dir(LED_VERDE_PIN, GPIO_OUT);
    
    gpio_init(LED_AZUL_PIN);
    gpio_set_dir(LED_AZUL_PIN, GPIO_OUT);

    gpio_init(LED_VERMELHO_PIN);
    gpio_set_dir(LED_VERMELHO_PIN, GPIO_OUT);

    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    // Mensagem inicial
    printf("Sistema de controle de LEDs e Buzzer - Aguardando comandos...\n");

    // Loop principal para ler comandos via Serial
    while (true) {
        // Lê um único caractere da entrada serial
        char c = getchar();  // Lê um caractere da entrada serial
        
        // Verifica se o caractere lido é um número
        if (c >= '1' && c <= '7') {
            // Converte o caractere para o valor numérico correspondente
            int comando = c - '0';  // Converte de char para int (ex: '1' -> 1)

            // Executa a ação correspondente ao número lido
            switch (comando) {
                case 1:  // Ligar LED verde
                    ligar_verde();
                    break;
                case 2:  // Ligar LED azul
                    ligar_azul();
                    break;
                case 3:  // Ligar LED vermelho
                    ligar_vermelho();
                    break;
                case 4:  // Ligar todos os LEDs (luz branca)
                    ligar_branco();
                    break;
                case 5:  // Desligar todos os LEDs
                    desligar_leds();
                    break;
                case 6:  // Acionar o buzzer
                    acionar_buzzer();
                    break;
                default:
                    printf("Comando desconhecido. Digite uma opção válida.\n");
                    break;
            }
        } else {
            printf("Comando inválido. Digite um número entre 1 e 7.\n");
        }
    }

    return 0;
}
