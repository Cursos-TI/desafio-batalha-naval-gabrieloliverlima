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

    // Posiciona um navio diagonalmente (
    for (i = 1; i < 4; i++) {
        tabuleiro[i][i] = 3;
    }

    // Posiciona um navio diagonalmente (/)
    for (i = 1; i < 4; i++) {
        tabuleiro[i][9 - i] = 3;
    }
    
    // Adiciona habilidades especiais ao tabuleiro
    int origemCone[2] = {5, 5};
    int origemCruz[2] = {3, 3};
    int origemOctaedro[2] = {6, 6};

    // Aplicando área de efeito - Cone
    for (i = 0; i < 3; i++) {
        for (j = -i; j <= i; j++) {
            if (origemCone[0] + i < 10 && origemCone[1] + j >= 0 && origemCone[1] + j < 10) {
                tabuleiro[origemCone[0] + i][origemCone[1] + j] = 5;
            }
        }
    }

    // Aplicando área de efeito - Cruz
    for (i = -2; i <= 2; i++) {
        if (origemCruz[0] + i >= 0 && origemCruz[0] + i < 10) {
            tabuleiro[origemCruz[0] + i][origemCruz[1]] = 5;
        }
        if (origemCruz[1] + i >= 0 && origemCruz[1] + i < 10) {
            tabuleiro[origemCruz[0]][origemCruz[1] + i] = 5;
        }
    }

    // Aplicando área de efeito - Octaedro
    for (i = -2; i <= 2; i++) {
        for (j = -2 + abs(i); j <= 2 - abs(i); j++) {
            if (origemOctaedro[0] + i >= 0 && origemOctaedro[0] + i < 10 && origemOctaedro[1] + j >= 0 && origemOctaedro[1] + j < 10) {
                tabuleiro[origemOctaedro[0] + i][origemOctaedro[1] + j] = 5;
            }
        }
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
