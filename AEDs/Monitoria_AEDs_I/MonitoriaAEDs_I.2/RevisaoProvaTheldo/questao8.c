#include <stdio.h>

// clear && gcc questao8.c && ./a.out

long long int fat(int N) {
    if (N == 1) return 1;
    return N * fat(N - 1);
}

float CnK(int N, int K) {
    float resultado = fat(N) / (fat(K) * fat(N - K));
	return resultado;
}

int main() {

    int N, K;
    scanf("%d %d", &N, &K);
	float resultado = CnK(N, K);
    printf("Resultado: %f\n", resultado);
}