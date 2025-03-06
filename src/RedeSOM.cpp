#include "RedeSOM.h"

// Constructor for the RedeSOM class
RedeSOM::RedeSOM() {
  // Initialization code if needed
}

// Inicializa a Rede SOM
void RedeSOM::setup() {}

// Calcula a distância entre o vetor de características e o neurônio na posição (i, j)
float RedeSOM::distancia(float caracteristicas[SOM_MAX_F], int i, int j) {
  float soma = 0;
  for (int f = 0; f < SOM_MAX_F; f++) {
    soma += pow(caracteristicas[f] - matrizNeuronios[i][j][f], 2); 
  }
  return sqrt(soma); 
}

// Encontra o neurônio com a menor distância em relação ao vetor de características
void RedeSOM::melhorDistancia(float caracteristicas[SOM_MAX_F], int &melhorL, int &melhorC) {
  melhorL = 0;
  melhorC = 0; 
  float melhorDist = distancia(caracteristicas, melhorL, melhorC); 
  for (int i = 0; i < SOM_MAX_L; i++) {
    for (int j = 0; j < SOM_MAX_C; j++) {
      float d = distancia(caracteristicas, i, j);
      if (d < melhorDist) {
        melhorL = i;
        melhorC = j;
        melhorDist = d;  
      }
    }
  }
}

// Retorna o label associado ao neurônio que tem a menor distância
char RedeSOM::melhorResposta(float caracteristicas[SOM_MAX_F]) {
  int melhorLinha = 0; 
  int melhorColuna = 0; 
  melhorDistancia(caracteristicas, melhorLinha, melhorColuna); 
  return matrizLabels[melhorLinha][melhorColuna];
}
