#include <stdio.h>

// Número de casas para cada peça
const int casasTorre = 3;
const int casasBispo = 3;
const int casasRainha = 3;

// ============================
// TORRE – Recursiva
// ============================
void moverTorreCima(int casas) {
    if (casas <= 0) return;
    printf("Cima\n");
    moverTorreCima(casas - 1);
}

void moverTorreDireita(int casas) {
    if (casas <= 0) return;
    printf("Direita\n");
    moverTorreDireita(casas - 1);
}

// ============================
// BISPO – Recursiva com Loops Aninhados
// ============================
void moverBispo(int vertical, int horizontal) {
    if (vertical <= 0 || horizontal <= 0) return;

    for (int v = 0; v < vertical; v++) {
        for (int h = 0; h < horizontal; h++) {
            printf("Diagonal Superior Direita\n");
        }
    }

    moverBispo(vertical - 1, horizontal - 1); // Recursão reduzindo o movimento
}

// ============================
// RAINHA – Recursiva (combina Torre + Bispo)
// ============================
void moverRainhaCima(int casas) {
    if (casas <= 0) return;
    printf("Cima\n");
    moverRainhaCima(casas - 1);
}

void moverRainhaDiagonal(int casas) {
    if (casas <= 0) return;
    printf("Diagonal Superior Direita\n");
    moverRainhaDiagonal(casas - 1);
}

// ============================
// CAVALO – Loops Complexos
// ============================
void moverCavalo() {
    int movimentos = 3; // Quantas vezes queremos simular o movimento
    printf("Movimento do Cavalo:\n");

    for (int i = 0; i < movimentos; i++) {
        for (int j = 0; j < movimentos; j++) {
            if (i == j) continue; // Evita movimentos redundantes
            if (i + j > 3) break; // Controle de fluxo

            printf("2 casas para cima, 1 para a direita (L)\n");
        }
    }
}

// ============================
// Função Principal
// ============================
int main() {
    // Movimento da Torre
    printf("Movimento da Torre:\n");
    moverTorreCima(casasTorre);
    moverTorreDireita(casasTorre);

    printf("\n");

    // Movimento do Bispo
    printf("Movimento do Bispo:\n");
    moverBispo(casasBispo, casasBispo);

    printf("\n");

    // Movimento da Rainha
    printf("Movimento da Rainha:\n");
    moverRainhaCima(casasRainha);
    moverRainhaDiagonal(casasRainha);

    printf("\n");

    // Movimento do Cavalo
    moverCavalo();

    return 0;
}
