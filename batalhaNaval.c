#include <stdio.h>

#define TAM 10      // tamanho do tabuleiro (10x10)
#define NAVIO 3     // valor que representa navio
#define AGUA 0      // valor que representa água
#define HABILIDADE 5 // valor que representa área de habilidade
#define TAM_HAB 5   // tamanho da matriz das habilidades (5x5)

// Função auxiliar para verificar se pode posicionar um navio
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna) {
    return tabuleiro[linha][coluna] == AGUA;
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para sobrepor matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int hab[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int meio = TAM_HAB / 2; // centro da matriz de habilidade

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (hab[i][j] == 1) {
                int linha = origemLinha + (i - meio);
                int coluna = origemColuna + (j - meio);

                // valida se está dentro dos limites do tabuleiro
                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                    if (tabuleiro[linha][coluna] == AGUA) { // não sobrescreve navios
                        tabuleiro[linha][coluna] = HABILIDADE;
                    }
                }
            }
        }
    }
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
    // Posicionando navios fixos (exemplo)
    // ========================
    for (int i = 0; i < 3; i++) {
        tabuleiro[1 + i][2] = NAVIO; // navio vertical
        tabuleiro[5][4 + i] = NAVIO; // navio horizontal
    }

    // ========================
    // Construindo matrizes de habilidades
    // ========================

    int cone[TAM_HAB][TAM_HAB] = {0};
    int cruz[TAM_HAB][TAM_HAB] = {0};
    int octaedro[TAM_HAB][TAM_HAB] = {0};

    int meio = TAM_HAB / 2;

    // Cone (↘ aberto para baixo)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= meio - i && j <= meio + i && i <= meio) {
                cone[i][j] = 1;
            }
        }
    }

    // Cruz
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == meio || j == meio) {
                cruz[i][j] = 1;
            }
        }
    }

    // Octaedro (losango)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio) {
                octaedro[i][j] = 1;
            }
        }
    }

    // ========================
    // Aplicando habilidades no tabuleiro
    // ========================
    aplicarHabilidade(tabuleiro, cone, 2, 2);     // cone no ponto (2,2)
    aplicarHabilidade(tabuleiro, cruz, 5, 5);     // cruz no ponto (5,5)
    aplicarHabilidade(tabuleiro, octaedro, 7, 7); // octaedro no ponto (7,7)

    // ========================
    // Exibindo o tabuleiro
    // ========================
    imprimirTabuleiro(tabuleiro);

    return 0;
}