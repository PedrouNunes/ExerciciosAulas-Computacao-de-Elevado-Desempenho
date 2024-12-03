#include <iostream> // Biblioteca padrão para entrada e saída
#include <fstream>  // Biblioteca para manipulação de arquivos
#include "farao.h"  // Cabeçalho com a declaração de `heat_diffusion_2d`

int main() {
    // Imprime uma mensagem no console
    std::cout << "Pedro Nunes, aluno de Mestrado !!!" << std::endl;

    // Dimensões da matriz
    const int M = 1000; // Número de linhas
    const int N = 1000; // Número de colunas

    // Alocação dinâmica de memória para as matrizes A e B
    double** A = new double*[M];
    double** B = new double*[M];
    for (int k = 0; k < M; k++) {
        A[k] = new double[N];
        B[k] = new double[N];
    }

    // Chama a função que simula a difusão de calor
    heat_diffusion_2d(A, B, M, N);

    // Cria um objeto para manipular arquivos de saída
    std::ofstream out_file; 

    // Abre (ou cria) o arquivo "simul30seg.txt"
    out_file.open("simul30seg.txt");

    // Salva os índices e o valor de cada elemento de A no arquivo
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            out_file << m << ' ' << n << ' ' << A[m][n] << std::endl;
        }
    }
    // Adiciona uma linha em branco e fecha o arquivo
    out_file << std::endl; 
    out_file.close();      

    // Libera a memória alocada dinamicamente
    for (int k = 0; k < M; k++) {
        delete[] A[k];
        delete[] B[k];
    }
    delete[] A;
    delete[] B;

    return 0; // Finaliza o programa
}

