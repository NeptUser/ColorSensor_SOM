/***********************************************************************
  colorSOM.cpp
***********************************************************************/
#include "colorSOM.h"

void ccolorSOM::Setup(){

}

float colorSOM::dist(int feature[SOM_MAX_F], int i, int j){
  float soma = 0
  for (int f = 0;f < SOM_MAX_F; f++){
    soma += pow(features[f] - matrixNeuronios[i][j][f],2);
  }
  return sqrt(soma);
}

void colorSOM::bestDist(int feature[SOM_MAX_F], int &bestL, int &bestC){
  int bestL = 0;
  int bestC = 0;

  float bestDist = dist(features, bestL, bestC);
  for (int i = 0; i < SOM_MAX_L; i++){
    for (int j = 0; j < SOM_MAX_C; j++){
      float d = dist(features, i, j);
      if (d < bestDist){
        bestL = i;
        bestC = j;
        bestDist = d;
      }
    } 
  }
}

char colorSOM::bestResponse(int feature[SOM_MAX_F]){
  int bestLine = 0;
  int bestColum = 0;

  //adicionar normalização dos dados

  bestDist(feature, bestLine, bestColum);

  return matrizLabels[bestline][bestcolum];
}