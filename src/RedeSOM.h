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
#ifndef REDESOM_H
#define REDESOM_H
 
#include <Arduino.h>

#define SOM_MAX_L 3
#define SOM_MAX_C 3
#define SOM_MAX_F 3 

class RedeSOM
{
  public:
    RedeSOM();
    void setup();
    char melhorResposta(float caracteristicas[SOM_MAX_F]);
    void melhorDistancia(float caracteristicas[SOM_MAX_F], int &melhorL, int &melhorC);
    float distancia(float caracteristicas[SOM_MAX_F], int i, int j); 
    char getLabel(int i, int j); 

  private:
    float matrizNeuronios[SOM_MAX_L][SOM_MAX_C][SOM_MAX_F] = 
      {
        { {0.8059331762683735, 0.8103771981141525, 0.7149841263330463}, 
          {0.8051411350818715, 0.8103357960453269, 0.6842252185931023}, 
          {0.8050158221299619, 0.8103430475916589, 0.675167350848771} },
          
        { {0.8354615120049846, 0.8105409908706593, 0.6740108489653516}, 
          {0.9100092401236485, 0.8111283200336047, 0.6718461573109517}, 
          {0.9099803212897359, 0.7564936522918071, 0.6710016937304123} },
          
        { {0.9099591228252338, 0.7120604321692304, 0.6701809061098863}, 
          {0.8191499121804825, 0.7108114855186386, 0.7308355638371488}, 
          {0.7807266585544608, 0.7101971203533916, 0.756564696107488} }
      };  

    char matrizLabels[SOM_MAX_L][SOM_MAX_C] =  
      {
        {'G', 'G', 'G'},
        {'G', 'R', 'R'},
        {'R', 'B', 'B'}
      };  
}; 
 
#endif
