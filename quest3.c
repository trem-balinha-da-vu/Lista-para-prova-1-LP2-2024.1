//------------------------------------------------------------------
/**
 * a. Faça uma função que crie dinamicamente uma matriz de n x m elementos inteiros.
 * b. Faça uma outra função do tipo void para inicializar a matriz com zeros usando um ponteiro para a matriz.
 * c. Faça outra função void preenche(int **mat, int n, int m, int opcao), para preencher 
 * uma matriz de n x m da seguinte forma:
 *      i. Se o parâmetro de nome opcao for igual a ´p´: com os números pares começando na posição 0 até (n x m)-1.
 *      ii. Se o parâmetro de nome opcao for igual a ´i´: com os números ímpares começando na posição 0 até (n x m)-1.
 *      iii. Se o parâmetro de nome opcao for igual a ´d´: com os números 
 * múltiplos de 10 da posição 0 até a posição (n x m)-1
 *      iv. Se o parâmetro de nome opcao for igual a ´s´: com os números 
 * sequenciais (1,2,3,4...) da posição 0 até a posição (n x m)-1
 * d. Faça uma função para mostrar na tela uma matriz de tamanho definido pelo usuário.
 * e. Faça um programa para testar as funções acima.
 * f. Verifique e informe qual é a qualidade (Coesão e Acoplamento) de suas funções.
*/
#include <stdio.h>
#include <stdlib.h>

//letra a
int ** aloca_matriz (int linha, int coluna)
{
    int **matriz;
    matriz = (int **) malloc(linha * sizeof(int *));

    for (int i = 0; i < linha; i++)
    {
        *(matriz + i) = (int *)malloc(coluna * sizeof(int));
    }
    
    return matriz;
}

void inicializa_com_zeros(int ** matriz, int linha, int coluna)
{
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
           matriz[i][j] = 0;
        }  
    }
}
void preenche_com_pares(int **matriz, int linha, int coluna)
{
    int num_par = 0; 

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
           matriz[i][j] = num_par;
           num_par += 2;
        }  
    }
}

void preenche_com_impares(int **matriz, int linha, int coluna)
{
    int num_impar = 1; 

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
           matriz[i][j] = num_impar;
           num_impar = num_impar + 2;
        }  
    }
}

void preenche_com_multiplos_de_dez(int **matriz, int linha, int coluna)
{
    int num_multiplo = 0; 

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
           matriz[i][j] = num_multiplo;
           num_multiplo += 10;
        }  
    }
}

void preenche_com_sequenciais(int **matriz, int linha, int coluna)
{
   int num_sequencial = 0;

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
           matriz[i][j] = num_sequencial++;
        }  
    }
}

void preenche(int **matriz, int n, int m, int opcao)
{
    switch (opcao)
    {
    case 'p':
        preenche_com_pares(matriz, n, m);
        break;
    case 'i':
        preenche_com_impares(matriz, n, m);
        break;
    case 'd':
        preenche_com_multiplos_de_dez(matriz, n, m);
        break;
    case 's':
        preenche_com_sequenciais(matriz, n, m);
        break;
    default:
        break;
    }
}


void mostra_matriz (int **matriz, int linha, int coluna)
{
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void liberar_matriz(int linha, int **matriz)
{
    for (int i = 0; i < linha; i++)
    {
        free(*(matriz + i));
    }
    free(matriz);
}

int main()
{
    int linha, coluna, **matriz;
    char opcao;

    printf("Informe a quantidade de linhas: \n");
    scanf("%d", &linha);
    printf("Informe a quantidade de colunas: \n");
    scanf("%d", &coluna);

    matriz = aloca_matriz(linha, coluna);

    inicializa_com_zeros(matriz, linha, coluna);

    mostra_matriz(matriz, linha, coluna);

    do 
    {
        printf("Digite como vc prefere preencher sua matriz: \n p = numeros pares\n i = numeros impares \n d = multiplos de 10 \n s = sequenciais.");
        scanf(" %c", &opcao);
    }while (!((opcao == 'p' || opcao == 'i') || (opcao == 'd' || opcao == 's')));

    preenche(matriz, linha, coluna, opcao);

    mostra_matriz(matriz, linha, coluna);
    liberar_matriz(linha, matriz);

    return 0;

}