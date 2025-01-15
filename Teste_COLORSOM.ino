/****************************************************************
      CÓDIGO DE DESENVOLVIMENTO
****************************************************************/
#include "som.h"
#include <Adafruit_NeoPixel.h>

// Sensor de cor
Adafruit_NeoPixel led1(1, 6, NEO_GRB, + NEO_KHZ800);

float avg_Red, avg_Blue, avg_Green, avg_White, avg_Bypass;

int calculateMode(int arr[], int size) {
  int maxValue = 0, maxCount = 0;

  for (int i = 0; i < size; ++i) {
    int count = 0;
    
    for (int j = 0; j < size; ++j) {
      if (arr[j] == arr[i])
        ++count;
    }

    if (count > maxCount) {
      maxCount = count;
      maxValue = arr[i];
    }
  }

  return maxValue;
}

float normalizeLDR(int rawValue, int minValue, int maxValue) {
  return (float)(rawValue - minValue) / (maxValue - minValue);
}

void getColor(){
  if (millis() - time1 > 1000){
    int values_Red[10], values_Green[10], values_Blue[10], values_White[10], values_Bypass[10];

    // read channel R
    led.setPixelColor(0, led.Color(255, 0, 0));
    led.show();
    for (int i = 0; i < 10; i++){
      values_Red[i] = analogRead(PINLDR);
      delay(10);
    }
    avg_Red = calculateMode(values_Red, 10);
    avg_Red = normalizeLDR(avg_Red, 0, 1023); // Normalizing the value
    delay(10);

    // read channel G
    led.setPixelColor(0, led.Color(0, 255, 0));
    led.show();
    for (int i = 0; i < 10; i++){
      values_Green[i] = analogRead(PINLDR);
      delay(10);
    }
    avg_Green = calculateMode(values_Green, 10);
    avg_Green = normalizeLDR(avg_Green, 0, 1023); // Normalizing the value
    delay(10);

    // read channel B
    led.setPixelColor(0, led.Color(0, 0, 255));
    led.show();
    for (int i = 0; i < 10; i++){
      values_Blue[i] = analogRead(PINLDR);
      delay(10);
    }
    avg_Blue = calculateMode(values_Blue, 10);
    avg_Blue = normalizeLDR(avg_Blue, 0, 1023); // Normalizing the value
    delay(10);

    // read channel W
    led.setPixelColor(0, led.Color(255, 255, 255));
    led.show();
    for (int i = 0; i < 10; i++){
      values_White[i] = analogRead(PINLDR);
      delay(10);
    }
    avg_White = calculateMode(values_White, 10);
    avg_White = normalizeLDR(avg_White, 0, 1023); // Normalizing the value
    delay(10);

    // read channel Bypass
    led.setPixelColor(0, led.Color(0, 0, 0));
    led.show();
    for (int i = 0; i < 10; i++){
      values_Bypass[i] = analogRead(PINLDR);
      delay(10);
    }
    avg_Bypass = calculateMode(values_Bypass, 10);
    avg_Bypass = normalizeLDR(avg_Bypass, 0, 1023); // Normalizing the value
  }
}

// Número de clusters e dimensões dos pesos
#define NUM_CLUSTERS 10
#define DIMENSIONS 3

// Matriz de pesos treinada fornecida
float trainedWeights[NUM_CLUSTERS][DIMENSIONS] = {
    {1.219158670546884e-61, 1.3213663886808326e-61, 1.818916844656929e-61},
    {0.9215437400706677, 0.20320379078208395, 0.9912202589060347},
    {0.2981869393552521, 0.7766165884444418, 0.11224334613876952},
    {0.26768131813385765, 0.24308671220616673, 0.21036083305740327},
    {0.9209203161402222, 0.7869182106103366, 0.2141714089363015},
    {0.787157369116226, 0.5442009319751475, 0.19011005080902887},
    {0.716378774884004, 0.08762158795530861, 0.2880662954940917},
    {0.39945388234921564, 0.473110954932799, 0.36640738789157135},
    {1.628338077395458e-31, 1.0, 1.0},
    {0.56843759748957, 0.39042163291770016, 0.29641167077879027}
};
void getColor()
// SOM instanciada
SOM som(NUM_CLUSTERS, DIMENSIONS);

void setup() {
    Serial.begin(9600);

    // Carregar os pesos fornecidos na rede SOM
    som.loadWeights(&trainedWeights[0][0]);

    Serial.println("Pesos treinados:");
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        Serial.print("Cluster ");
        Serial.print(i);
        Serial.print(": ");
        for (int j = 0; j < DIMENSIONS; j++) {
            Serial.print(trainedWeights[i][j]);
            Serial.print(" ");
        }
        Serial.println();
    }
}

void loop() {
    // Gerar valores aleatórios para simular leitura do LDR
    float ldrReading[DIMENSIONS];
    for (int i = 0; i < DIMENSIONS; i++) {
        ldrReading[i] = analogRead(A5);
    }

    // Mostrar valores do LDR
    Serial.print("Leitura LDR: ");
    for (int i = 0; i < DIMENSIONS; i++) {
        Serial.print(ldrReading[i]);
        Serial.print(" ");
    }
    Serial.println();

    // Prever o cluster vencedor
    int cluster = som.predict(ldrReading);

    // Mostrar o cluster vencedor
    Serial.print("Cluster vencedor: ");
    Serial.println(cluster);

    delay(3000); // Esperar 3 segundos antes de repetir
}

