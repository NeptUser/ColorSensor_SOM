/***********************************************************************
  colorSOM.h - Biblioteca para uso do sensor de cor basedo na rede SOM

  Autores:
    - Cleberson Costa   | Treinamento da rede
    - Daniel Moura      | Coleta de dados
    - Gabriel Vantuil   | Design do Circuito
    - Pedro Albuquerque | Criação da biblioteca
    - Rutileno Gabriel  | Design da PCB
    - Orivaldo Santana  | Orientador

  Criado em 18/12/24
  Versão de teste 1.0
  Biblioteca criada para a disciplina ECT3694 - Aprendizado de Máquina
  https://github.com/
***********************************************************************/
#ifndef COLORSOM_H
#define COLORSOM_H

#include <Arduino.h>

#define SOM_MAX_L 6
#define SOM_MAX_C 6
#define SOM_MAX_F 5

class colorSOM{
  public:
    SOMA_Arduino( );
    void setup();
    char bestResponse(int feature[SOM_MAX_F]);
    void bestDist(int feature[SOM_MAX_F], int &bestL, int &bestC);
    float dist(int feature[SOM_MAX_F], int i, int j); 
    char getLabel(int i, int j); 
 

  private:
    int matrizNeuronios[SOM_MAX_L][SOM_MAX_C][SOM_MAX_F] = 
      {
       // Inserir a matriz de neurônios
      };  

    char matrizLabels[SOM_MAX_L][SOM_MAX_C] =  
      {
        // Rotular neurônios
      };  
  
}; 
 
#endif