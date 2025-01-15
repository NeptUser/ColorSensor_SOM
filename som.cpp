#include "som.h"

// Definindo o construtor da classe SOM
SOM::SOM(int clusters, int dimensions) : numClusters(clusters), dim(dimensions) {
    weights = new float*[numClusters];
    for (int i = 0; i < numClusters; ++i) {
        weights[i] = new float[dim];
    }
}

// Definindo o destrutor da classe SOM
SOM::~SOM() {
    for (int i = 0; i < numClusters; ++i) {
        delete[] weights[i];
    }
    delete[] weights;
}

// Definindo o método para carregar os pesos
void SOM::loadWeights(const float* weightsArray) {
    for (int i = 0; i < numClusters; ++i) {
        for (int j = 0; j < dim; ++j) {
            weights[i][j] = weightsArray[i * dim + j];
        }
    }
}

// Definindo o método para prever o cluster vencedor
int SOM::predict(const float* sample) {
    int winner = -1;
    float minDistance = 3.4E38f;  // Valor máximo para um float (aproximadamente o maior valor possível)

    for (int i = 0; i < numClusters; ++i) {
        float distance = 0.0f;
        for (int j = 0; j < dim; ++j) {
            distance += (sample[j] - weights[i][j]) * (sample[j] - weights[i][j]);
        }
        if (distance < minDistance) {
            minDistance = distance;
            winner = i;
        }
    }
    return winner;
}