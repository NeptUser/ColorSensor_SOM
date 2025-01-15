#ifndef L9110_H
#define L9110_H

#include <Arduino.h>

/*
  Classe para controle do motor DC com o driver L9110. Contêm 4 movimentos 
  básicos: frente, ré, esquerda e direita.
  Código baseado no código feito por Luis Martins, https://github.com/Natalnet/ura-codes/blob/master/codigos/arduino/uracar/include/L9110H.h, 
  e Orivaldo, https://github.com/Natalnet/lib_ura_esp/tree/master/ESP32/L9110. 

  ## Motor A - Esquerdo  
  # Sugestão de Pinos 
  #A_IA  -->  Motor A PWM Speed --> 11 
  #A_IB  -->  Motor A Direction --> 10

  ## Motor B - Direito 
  # Sugestão de Pinos 
  #B_IA  -->  Motor B PWM Speed --> 13
  #B_IB  -->  Motor B Direction --> 12 

*/

class L9110
{
  public:
    L9110(); // Construtor padrão
    L9110(int pinVelE, int pinDirE, int pinVelD, int pinDirD);
    void frente(int velocidade = 255, int tempo = 1000);
    void re(int velocidade = 255, int tempo = 1000);
    void esquerda(int velocidade = 255, int tempo = 1000);
    void direita(int velocidade = 255, int tempo = 1000);
    void parar();
  private:
    int _pinVelocidadeMotorEsquerdo;
    int _pinVelocidadeMotorDireito;
    int _pinDirecaoMotorEsquerdo;
    int _pinDirecaoMotorDireito;
    int _tempoMaximoMovimento;
};

#endif