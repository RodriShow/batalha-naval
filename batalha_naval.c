#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10

typedef struct {
    char estado;
} Celula;

Celula tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

void habilidade_cone(int x, int y, int direcao, int alcance) {
    for (int i = 0; i < alcance; i++) {
        for (int j = -i; j <= i; j++) {
            int nx = x, ny = y;
            if (direcao == 0) { nx = x - i; ny = y + j; } // cima
            if (direcao == 1) { nx = x + i; ny = y + j; } // baixo
            if (direcao == 2) { ny = y - i; nx = x + j; } // esquerda
            if (direcao == 3) { ny = y + i; nx = x + j; } // direita

            if (nx >= 0 && ny >= 0 && nx < TAMANHO_TABULEIRO && ny < TAMANHO_TABULEIRO) {
                tabuleiro[nx][ny].estado = 'X';
            }
        }
    }
}

void habilidade_cruz(int x, int y, int alcance) {
    for (int i = -alcance; i <= alcance; i++) {
        if (x + i >= 0 && x + i < TAMANHO_TABULEIRO)
            tabuleiro[x + i][y].estado = 'X';
        if (y + i >= 0 && y + i < TAMANHO_TABULEIRO)
            tabuleiro[x][y + i].estado = 'X';
    }
}

void habilidade_octaedro(int x, int y, int alcance) {
    for (int i = -alcance; i <= alcance; i++) {
        for (int j = -alcance; j <= alcance; j++) {
            if (abs(i) + abs(j) <= alcance) {
                int nx = x + i;
                int ny = y + j;
                if (nx >= 0 && ny >= 0 && nx < TAMANHO_TABULEIRO && ny < TAMANHO_TABULEIRO) {
                    tabuleiro[nx][ny].estado = 'X';
                }
            }
        }
    }
}

void imprimir_tabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j].estado);
        }
        printf("\n");
    }
}

int main() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
            tabuleiro[i][j].estado = '~';

    habilidade_cone(5, 5, 0, 3);       // Cone para cima
    habilidade_cruz(3, 3, 2);          // Cruz centrada em (3,3)
    habilidade_octaedro(7, 7, 2);      // Octaedro centrado em (7,7)

    imprimir_tabuleiro();

    return 0;
}
