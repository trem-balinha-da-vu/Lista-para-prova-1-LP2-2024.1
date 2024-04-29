//------------------------------------------------------------------------
/**
 * Faça:
 *      a. Uma função para calcular a aceleração de um objeto.
 *      b. Verifique e informe qual é a qualidade (Coesão e Acoplamento) de sua função
 *      c. Faça um programa para testar a função criada.
*/
//------------------------------------------------------------------------
#include <stdio.h>

//b - acoplamento de dados e coesão funcional 
float calcula_aceleracao(float velocidade_inicial, float velocidade_final, float tempo_inicial, float tempo_final)
{
    return ((velocidade_final - velocidade_inicial)/(tempo_final - tempo_inicial));
}

int main ()
{
    float v0, v1, t0, t1;

    printf("informe velocidade inicial: \n");
    scanf("%f", &v0);

    printf("informe velocidade final: \n");
    scanf("%f", &v1);

    printf("informe tempo inicial: \n");
    scanf("%f", &t0);

    printf("informe tempo final: \n");
    scanf("%f", &t1);

    printf("ACELERACAO MEDIA SEGUNDO OS DADOS ----------\n\n");
    printf(" velocidade inicial: %.2f m/s\n velocidade final: %.2f m/s\n tempo inicial: %.2fs\n tempo final %.2fs\n", v0, v1, t0, t1);
    printf ("\nvalor da aceleracao media: %.2fm/s²\n", calcula_aceleracao(v0,v1,t0,t1));
    
    return 0;
}


