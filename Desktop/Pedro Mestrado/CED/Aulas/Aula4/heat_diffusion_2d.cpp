#include <iostream> // Biblioteca para mensagens no console
#include <omp.h>    // Biblioteca para paralelismo com OpenMP

void heat_diffusion_2d(double** A, double** B, int M, int N) {
    // Indica no console que a função foi chamada
    std::cout << "heat_diffusion_2d" << std::endl;

    // Parâmetros da simulação
    double alfa_gold = 127;  // Coeficiente de difusão térmica (mm²/s)
    double T0 = 25.0;        // Temperatura inicial (Celsius)
    double Tb = 100.0;       // Temperatura nas bordas (Celsius)

    // Inicialização dos valores internos da matriz
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            A[m][n] = T0;
            B[m][n] = T0;
        }
    }

    // Inicialização das bordas com temperatura fixa
    for (int m = 0; m < M; m++) {
        A[m][0] = Tb;       // Primeira coluna
        B[m][0] = Tb;
        A[m][N-1] = Tb;     // Última coluna
        B[m][N-1] = Tb;
    }
    for (int n = 0; n < N; n++) {
        A[0][n] = Tb;       // Primeira linha
        B[0][n] = Tb;
        A[M-1][n] = Tb;     // Última linha
        B[M-1][n] = Tb;
    }

    // Tempo total de simulação (30 segundos)
    int final_time = 30000; 

    // Evolução temporal usando OpenMP para paralelismo
    #pragma omp parallel for
    for (int t = 0; t < final_time; t++) {
        // Atualização dos valores internos da matriz
        for (int m = 1; m < M-1; m++) {
            for (int n = 1; n < N-1; n++) {
                double a0 = A[m][n];       // Valor atual
                double aW = A[m+1][n];     // Vizinho à esquerda
                double aE = A[m-1][n];     // Vizinho à direita
                double aN = A[m][n+1];     // Vizinho acima
                double aS = A[m][n-1];     // Vizinho abaixo

                // Atualiza o valor em B[m][n] com base na equação de difusão
                B[m][n] = a0 + (aW + aE + aS + aN - 4.0 * a0) / alfa_gold;
            }
        }

        // Copia os valores de B para A
        for (int m = 1; m < M-1; m++) {
            for (int n = 1; n < N-1; n++) {
                A[m][n] = B[m][n];
            }
        }
    }
}

