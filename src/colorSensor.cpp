#include "colorSensor.h"

ColorSensor::ColorSensor(int neoPixelPin, int ldrPin) : _ldrPin(ldrPin), _pixels(1, neoPixelPin, NEO_GRB + NEO_KHZ800) {}

void ColorSensor::begin() {
    pinMode(_ldrPin, INPUT);
    _pixels.begin();
    _pixels.clear();
    _pixels.show();
}

void ColorSensor::readFeatures(int features[3]) {
    uint32_t colors[3] = {_pixels.Color(255, 0, 0), _pixels.Color(0, 255, 0), _pixels.Color(0, 0, 255)};
    for (int i = 0; i < 3; i++) {
        int reading = captureReadings(colors[i]);
        features[i] = map(reading, 0, 1023, 0, 1023);
    }
    // Ilumina o LED com branco ao final de cada ciclo de leitura
    _pixels.setPixelColor(0, _pixels.Color(255, 255, 255));
    _pixels.show();
}

int ColorSensor::captureReadings(uint32_t color) {
    const int NUM_READINGS = 10;
    int readings[NUM_READINGS];

    _pixels.setPixelColor(0, color);
    _pixels.show();
    delay(10);

    for (int i = 0; i < NUM_READINGS; i++) {
        readings[i] = analogRead(_ldrPin);
        delay(10); // Tempo entre leituras
    }
    return calculateMode(readings, NUM_READINGS);
}

int ColorSensor::calculateMode(int readings[], int size) {
    int mode = readings[0];
    int maxCount = 0;

    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (readings[j] == readings[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mode = readings[i];
        }
    }
    return mode;
}
