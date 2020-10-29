#include <stdio.h>

void ganhador(char jogador)
{
    printf("\n\n ******* %c GANHOU!!!!! *******\n\n", jogador);
}

void preencher_jogo(char jogo[][3])
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            jogo[x][y] = ' ';
        }
    }
}

void imprimir_jogo(const char jogo[][3])
{
    printf("   0   1   2   \n");
    printf(" 0 %c | %c | %c \n",jogo[0][0],jogo[0][1],jogo[0][2]);
    printf("  ---|---|--- \n ");
    printf("1 %c | %c | %c \n",jogo[1][0],jogo[1][1],jogo[1][2]);
    printf("  ---|---|--- \n ");
    printf("2 %c | %c | %c \n",jogo[2][0],jogo[2][1],jogo[2][2]);
}

int verifica_linha(const char jogo[][3], int linha, char jogador, int *ptr_status)
{
    for (int coluna = 0; coluna < 3; coluna ++)
    {
        if(jogo[linha][coluna] != jogador)
        {
            return 0;
        }
    }

    ganhador(jogador);
    *ptr_status = 1;
    return 0;
}

int verifica_coluna(const char jogo[][3], int coluna, char jogador, int *ptr_status)
{
    for (int linha = 0; linha < 3; linha ++)
    {
        if(jogo[linha][coluna] != jogador)
        {
            return 0;
        }
    }

    ganhador(jogador);
    *ptr_status = 1;
    return 0;
}

int verifica_diagonal(const char jogo[][3], char jogador, int *ptr_status)
{
    for(int linha = 0, coluna = 0; linha < 3; linha ++, coluna ++)
    {
        if (jogo[linha][coluna] != jogador)
        return 0;
    }

    ganhador(jogador);
    *ptr_status = 1;
    return 0;
}

int verifica_diagonal_secundaria(const char jogo[][3], char jogador, int *ptr_status)
{
    for(int linha = 0, coluna = 0; linha < 3; linha ++, coluna ++)
    {
        if (jogo[linha][2-coluna] != jogador)
        return 0;
    }

    ganhador(jogador);
    *ptr_status = 1;
    return 0;
}

int main()
{
    char jogo[3][3];
    int linha, coluna, velha = 0, status = 0;

    preencher_jogo(jogo);

    while((velha <= 9) && (status == 0))
    {
        printf("\n\nVez do O\n\n");
        printf("Faca sua jogada, digite a linha e coluna desejada: ");
        scanf("%i%i", &linha, &coluna);
        velha ++;

        jogo[linha][coluna]='O';

        imprimir_jogo(jogo);
        verifica_coluna(jogo, coluna, 'O', &status);
        verifica_diagonal(jogo, 'O', &status);
        verifica_diagonal_secundaria(jogo, 'O', &status);
        verifica_linha(jogo, linha, 'O', &status);

        if((velha >= 9) || (status != 0)) break;

        printf("\n\nVez do X\n\n");
        printf("Faca sua jogada, digite a linha e coluna desejada: ");
        scanf("%i%i", &linha, &coluna);
        velha ++;

        jogo[linha][coluna]='X';

        imprimir_jogo(jogo);
        verifica_coluna(jogo, coluna, 'X', &status);
        verifica_diagonal(jogo, 'X', &status);
        verifica_diagonal_secundaria(jogo, 'X', &status);
        verifica_linha(jogo, linha, 'X', &status);
    }

    return 0;
}
