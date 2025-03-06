#ifndef COLORSENSOR_H
#define COLORSENSOR_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class ColorSensor {
  public:
    ColorSensor(int neoPixelPin, int ldrPin);
    void begin(); // Inicializa os pinos
    void readFeatures(int features[3]); // Lê as características (RGB)
  private:
    int _ldrPin;
    Adafruit_NeoPixel _pixels;
    int captureReadings(uint32_t color); // Captura leituras do LDR para uma cor específica
    int calculateMode(int readings[], int size); // Calcula a moda das leituras
};

#endif
