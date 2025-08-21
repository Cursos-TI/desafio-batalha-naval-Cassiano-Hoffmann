#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

#define TAM 10      // tamanho do tabuleiro (10x10)
#define NAVIO 3     // valor que representa o navio
#define AGUA 0      // valor que representa água
#define TAM_NAVIO 3 // tamanho fixo dos navios

int main() {
    // Declaração do tabuleiro
    int tabuleiro[TAM][TAM];

    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Definindo coordenadas iniciais dos navios
    // Exemplo fixo (pode alterar para testar)
    int linhaNavioVertical = 1, colunaNavioVertical = 2; // posição inicial do navio vertical
    int linhaNavioHorizontal = 5, colunaNavioHorizontal = 4; // posição inicial do navio horizontal

    // Validação simples para não ultrapassar o limite do tabuleiro
    if (linhaNavioVertical + TAM_NAVIO <= TAM) {
        // Posiciona navio vertical
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = NAVIO;
        }
    }

    if (colunaNavioHorizontal + TAM_NAVIO <= TAM) {
        // Posiciona navio horizontal
        for (int i = 0; i < TAM_NAVIO; i++) {
            // Verifica se não há sobreposição
            if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] == AGUA) {
                tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = NAVIO;
            }
        }
    }

    // Exibe o tabuleiro
    printf("=== TABULEIRO BATALHA NAVAL ===\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
