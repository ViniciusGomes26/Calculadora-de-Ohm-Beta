#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void calculadora_lei_de_ohm () {
    char opcao;
    float tensao, corrente, resistencia;
    float resultado;

    printf("\n--- Calculadora de Lei de Ohm ---\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS); 
    
    printf("Escolha a grandeza que deseja encontrar:\n");
    printf("V - Tensao | I - Corrente | R - Resistencia\n");
    
    while (scanf(" %c", &opcao) < 1 ){
       vTaskDelay(1000 / portTICK_PERIOD_MS); 
    }

    switch (opcao) {
        case 'V':
        case 'v':
            printf("Informe a Resistencia: ");
            while (scanf("%f", &resistencia) < 1 ){
            vTaskDelay(1000 / portTICK_PERIOD_MS); 
            }
            printf("Informe a Corrente: ");
            while (scanf("%f", &corrente) < 1 ){
            vTaskDelay(1000 / portTICK_PERIOD_MS); 
            }
            
            resultado = resistencia * corrente;

            printf("Resultado: Tensao = %.2f V\n", resultado);
            break;

        case 'I':
        case 'i':
            printf("Informe a Tensao: ");
            while (scanf("%f", &tensao) < 1){
            vTaskDelay(1000 / portTICK_PERIOD_MS); 
            }
            printf("Informe a Resistencia: ");
            while (scanf("%f", &resistencia) <1){
            vTaskDelay(1000 / portTICK_PERIOD_MS); 
            }
            
            if (resistencia != 0) { 
                resultado = tensao / resistencia;
                printf("Resultado: Corrente = %.2f A\n", resultado);
            } else {
                printf("Erro: Resistencia nao pode ser zero!\n");
            }
            break;

        case 'R':
        case 'r':
            printf("Informe a Tensao: ");
            while (scanf("%f", &tensao) <1){
            vTaskDelay(1000 / portTICK_PERIOD_MS); 
            }

            printf("Informe a Corrente: ");
            while (scanf("%f", &corrente) <1){
            vTaskDelay(1000 / portTICK_PERIOD_MS); 
            }
            
            if (corrente != 0) { 
                resultado = tensao / corrente;
                printf("Resultado: Resistencia = %.2f $\Omega$\n", resultado); // Unidade corrigida
            } else {
                printf("Erro: Corrente nao pode ser zero!\n");
            }
            break;

        default:
            printf("Opcao [%c] invalida!\n", opcao);
            break;
    }
    vTaskDelay(2000 / portTICK_PERIOD_MS);
}

void app_main() {
    while(1) {
        calculadora_lei_de_ohm();
        vTaskDelay(500 / portTICK_PERIOD_MS); 
    }
}