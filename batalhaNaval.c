#include <stdio.h>

#define TAM 10      // tamanho do tabuleiro (10x10)
#define NAVIO 3     // valor que representa navio
#define AGUA 0      // valor que representa água
#define TAM_NAVIO 3 // tamanho fixo dos navios

// Função auxiliar para verificar se pode posicionar um navio
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna) {
    return tabuleiro[linha][coluna] == AGUA;
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ========================
    // Posicionando os navios
    // ========================

    // Navio 1 - Vertical
    int linhaNavioV = 1, colunaNavioV = 2;
    if (linhaNavioV + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (podePosicionar(tabuleiro, linhaNavioV + i, colunaNavioV)) {
                tabuleiro[linhaNavioV + i][colunaNavioV] = NAVIO;
            }
        }
    }

    // Navio 2 - Horizontal
    int linhaNavioH = 5, colunaNavioH = 4;
    if (colunaNavioH + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (podePosicionar(tabuleiro, linhaNavioH, colunaNavioH + i)) {
                tabuleiro[linhaNavioH][colunaNavioH + i] = NAVIO;
            }
        }
    }

    // Navio 3 - Diagonal principal (↘)
    int linhaNavioD1 = 2, colunaNavioD1 = 2;
    if (linhaNavioD1 + TAM_NAVIO <= TAM && colunaNavioD1 + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (podePosicionar(tabuleiro, linhaNavioD1 + i, colunaNavioD1 + i)) {
                tabuleiro[linhaNavioD1 + i][colunaNavioD1 + i] = NAVIO;
            }
        }
    }

    // Navio 4 - Diagonal secundária (↙)
    int linhaNavioD2 = 2, colunaNavioD2 = 7;
    if (linhaNavioD2 + TAM_NAVIO <= TAM && colunaNavioD2 - (TAM_NAVIO - 1) >= 0) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (podePosicionar(tabuleiro, linhaNavioD2 + i, colunaNavioD2 - i)) {
                tabuleiro[linhaNavioD2 + i][colunaNavioD2 - i] = NAVIO;
            }
        }
    }

    // ========================
    // Exibindo o tabuleiro
    // ========================
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}