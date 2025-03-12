#include <stdio.h>

int main() {
    int tabuleiro[10][10]; // Matriz 10x10 representando o tabuleiro
    int i, j;
    
    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // Posiciona um navio horizontalmente na linha 2, começando da coluna 4
    for (j = 4; j < 7; j++) {
        tabuleiro[2][j] = 3;
    }
    
    // Posiciona um navio verticalmente na coluna 6, começando da linha 5
    for (i = 5; i < 8; i++) {
        tabuleiro[i][6] = 3;
    }
    
    // Posiciona um navio na diagonal principal (de cima para baixo)
    for (i = 0; i < 3; i++) {
        tabuleiro[i][i] = 3;
    }
    
    // Posiciona um navio na diagonal secundária (de cima para baixo, da direita para a esquerda)
    for (i = 0; i < 3; i++) {
        tabuleiro[i][9 - i] = 3;
    }
    
    // Exibe o tabuleiro
    printf("Tabuleiro:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
