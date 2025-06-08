#include <stdio.h>

int main() {
    // Constantes declaradas com 'const'
    const int TAMANHO_TABULEIRO = 10;
    const int TAMANHO_NAVIO = 3;
    const int VALOR_AGUA = 0;
    const int VALOR_NAVIO = 3;

    // Declaração do tabuleiro 10x10, inicializado com água (0)
    int tabuleiro[10][10] = {0};  // tamanho fixo 

    // Coordenadas do navio horizontal (linha e coluna iniciais)
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    // Coordenadas do navio vertical (linha e coluna iniciais)
    int linhaVertical = 5;
    int colunaVertical = 7;

    // Validação do navio horizontal (verifica se cabe no tabuleiro)
    if (colunaHorizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Posicionamento do navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaHorizontal][colunaHorizontal + i] != VALOR_AGUA) {
            printf("Erro: Sobreposição detectada ao posicionar navio horizontal.\n");
            return 1;
        }
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = VALOR_NAVIO;
    }

    // Validação do navio vertical (verifica se cabe no tabuleiro)
    if (linhaVertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Posicionamento do navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaVertical + i][colunaVertical] != VALOR_AGUA) {
            printf("Erro: Sobreposição detectada ao posicionar navio vertical.\n");
            return 1;
        }
        tabuleiro[linhaVertical + i][colunaVertical] = VALOR_NAVIO;
    }

    // Exibição do tabuleiro
    printf("Tabuleiro final:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
