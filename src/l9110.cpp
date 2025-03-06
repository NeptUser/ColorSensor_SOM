#include "l9110.h"

#include <Arduino.h> 

L9110::L9110(int pinVelE, int pinDirE, int pinVelD, int pinDirD)
{
  _pinVelocidadeMotorEsquerdo = pinVelE;
  _pinDirecaoMotorEsquerdo = pinDirE;
  _pinVelocidadeMotorDireito = pinVelD;
  _pinDirecaoMotorDireito = pinDirD;
  _tempoMaximoMovimento = 3000;
  
  pinMode(_pinVelocidadeMotorEsquerdo, OUTPUT);
  pinMode(_pinDirecaoMotorEsquerdo, OUTPUT);
  pinMode(_pinVelocidadeMotorDireito, OUTPUT);
  pinMode(_pinDirecaoMotorDireito, OUTPUT);
}

void L9110::frente(int velocidade, int tempo)
{
  digitalWrite(_pinDirecaoMotorEsquerdo, HIGH);
  digitalWrite(_pinDirecaoMotorDireito, HIGH);
  analogWrite(_pinVelocidadeMotorEsquerdo, 255 - velocidade);
  analogWrite(_pinVelocidadeMotorDireito, 255 - velocidade);
  if (tempo > _tempoMaximoMovimento)
  {
    delay(_tempoMaximoMovimento);
  }
  else
  {
    delay(tempo);
  }
}

void L9110::re(int velocidade, int tempo)
{
  digitalWrite(_pinDirecaoMotorEsquerdo, LOW);
  digitalWrite(_pinDirecaoMotorDireito, LOW);
  analogWrite(_pinVelocidadeMotorEsquerdo, velocidade);
  analogWrite(_pinVelocidadeMotorDireito, velocidade);
  if (tempo > _tempoMaximoMovimento)
  {
    delay(_tempoMaximoMovimento);
  }
  else
  {
    delay(tempo);
  }
}

void L9110::esquerda(int velocidade, int tempo)
{
  digitalWrite(_pinDirecaoMotorEsquerdo, LOW);
  digitalWrite(_pinDirecaoMotorDireito, HIGH);
  analogWrite(_pinVelocidadeMotorEsquerdo, velocidade);
  analogWrite(_pinVelocidadeMotorDireito, 255 - velocidade);
  if (tempo > _tempoMaximoMovimento)
  {
    delay(_tempoMaximoMovimento);
  }
  else
  {
    delay(tempo);
  }
}

void L9110::direita(int velocidade, int tempo)
{
  digitalWrite(_pinDirecaoMotorEsquerdo, HIGH);
  digitalWrite(_pinDirecaoMotorDireito, LOW);
  analogWrite(_pinVelocidadeMotorEsquerdo, 255 - velocidade);
  analogWrite(_pinVelocidadeMotorDireito, velocidade);
  if (tempo > _tempoMaximoMovimento)
  {
    delay(_tempoMaximoMovimento);
  }
  else
  {
    delay(tempo);
  }
} 

void L9110::parar()
{
  digitalWrite(_pinDirecaoMotorEsquerdo, HIGH);
  digitalWrite(_pinDirecaoMotorDireito, HIGH);
  analogWrite(_pinVelocidadeMotorEsquerdo, 255);
  analogWrite(_pinVelocidadeMotorDireito, 255);
}