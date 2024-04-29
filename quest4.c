//-----------------------------------------------------------------
/**
 * Faça um programa para calcular a área e o perímetro de um hexágono. O programa deve
 * implementar uma função chamada calc_hexa que calcula a área e o perímetro de um
 * hexágono regular de lado L. O programa deve solicitar ao usuário o lado do polígono, calcular e
 * imprimir a área e o perímetro do polígono. O programa termina quando for digitado um valor
 * negativo qualquer para o lado.
 * A função deve obedecer ao seguinte protótipo:
 * 
 *      void calc_hexa(float l, float *area, float *perimetro);
 * 
 * Lembrando que a área e o perímetro de um hexágono regular são dados por:
 * 
 *  area = (3 * pow(L, 2) * sqrt(3))/2
 *  perimetro = 6 * L

Para os cálculos, obrigatoriamente você deve utilizar as funções sqrt e pow da biblioteca
math.h.
*/

#include <stdio.h>
#include <math.h>

void calc_hexa(float l, float *area, float *perimetro)
{
    *area = (3 * pow(l, 2) * sqrt(3))/2;
    *perimetro = 6 * l;
}

int main ()
{
    float area, perimetro, lado;

    do
    {
        printf("Informe o tamanho do lado de seu hexágono regular (Digite um valor negativo para sair do programa): \n");
        scanf("%f", &lado);

        calc_hexa(lado, &area, &perimetro);

        printf("area do hexagono: %.2f\n", area);
        printf("perimetro do hexagono: %.2f\n", perimetro);

    } while (lado >= 0);
    
    return 0;

}