#include "colorSensor.h"
#include "RedeSOM.h"
#include "l9110.h"

// Pinos para o sensor de cor
#define LED_PIN 7
#define LDR_PIN A4

// Pinos para o controle do motor
#define PIN_VEL_E 11
#define PIN_DIR_E 10
#define PIN_VEL_D 13
#define PIN_DIR_D 12

// Instâncias dos componentes
ColorSensor colorSensor(LED_PIN, LDR_PIN);
RedeSOM redeSOM;
L9110 motor(PIN_VEL_E, PIN_DIR_E, PIN_VEL_D, PIN_DIR_D);

void setup() {
    Serial.begin(9600);
    colorSensor.begin();
    redeSOM.setup();
    Serial.println("Sistema iniciado.");
}

void loop() {
    int features[3]; 
    float featuresFloat[3];
    
    colorSensor.readFeatures(features); 

    
    for (int i = 0; i < 3; i++) {
        featuresFloat[i] = features[i] / 1023.0; 
    }

    char response = redeSOM.melhorResposta(featuresFloat);

    Serial.print("Cor detectada: ");
    Serial.println(response);
    Serial.print("Características: ");
    Serial.print(featuresFloat[0]);
    Serial.print(", ");
    Serial.print(featuresFloat[1]);
    Serial.print(", ");
    Serial.println(featuresFloat[2]);

    // Realiza ação com base na cor detectada [Essa parte foi feita com IA (Verificar)]
    if (response == 'R') { // Vermelho
        motor.frente(255, 0); // Velocidade máxima, movimento contínuo
    } else if (response == 'G') { // Verde
        motor.esquerda(255, 500); // Velocidade máxima, vira por 1s
        motor.frente(255, 1000); // Velocidade máxima, movimento contínuo
    } else if (response == 'B') { // Azul
        motor.parar();
    } else {
        motor.parar(); // Para o carrinho por segurança
    }

    delay(500); // Atraso para estabilidade
}
