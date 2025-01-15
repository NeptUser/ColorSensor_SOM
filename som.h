#ifndef SOM_H
#define SOM_H

class SOM {
private:
    float** weights;  // Matriz de pesos
    int numClusters;  // Número de clusters
    int dim;          // Dimensão de cada vetor

public:
    SOM(int clusters, int dimensions);
    ~SOM();
    void loadWeights(const float* weightsArray); // Carrega os pesos para a matriz
    int predict(const float* sample);           // Retorna o índice do cluster vencedor
};

#endif