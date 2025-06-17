# Batalha Naval

Este é um projeto em linguagem C que simula um jogo de Batalha Naval com uma novidade: **habilidades especiais** que afetam áreas específicas do tabuleiro.

## Funcionalidades

- **Cone**: ataca em formato de cone em uma direção (cima, baixo, esquerda ou direita).
- **Cruz**: ataca a linha e coluna da posição alvo.
- **Octaedro**: ataca em forma de diamante (distância de Manhattan).

## Tabuleiro

O tabuleiro é uma matriz 10x10, onde:
- `~` representa água (vazio),
- `X` representa uma célula atingida,
- `O` pode ser usado futuramente para defesa.

## Como rodar
   
gcc batalha_naval.c -o batalha

./batalha
