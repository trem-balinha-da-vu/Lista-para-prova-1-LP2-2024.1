//-------------------------------------------------------------------------------
/**
 * Após várias experiências em laboratórios, observou-se que a concentração de certo
 * antibiótico, no sangue de cobaias, varia de acordo com a função y = 12x – 2x², em que x é o
 * tempo decorrido, em horas, após a ingestão do antibiótico. Nessas condições, qual o tempo
 * necessário para atingir o nível máximo de concentração desse antibiótico, no sangue dessas
 * cobaias?
*/

#include <stdio.h>
#include <math.h>


double concentracao_antibiotico (float tempo)
{
    return ((12 * tempo) - (2 * pow(tempo, 2)));
}

int main()
{
    float tempo, x_nivel_maximo, y_nivel_maximo;

    //explicacao: nesse caso, o tempo pra atingir o nivel maximo 
    //de concentracao é o x do vértice da função, dado por: -b/2*a
    x_nivel_maximo = (-12.0/(2.0 * -2.0));
    y_nivel_maximo = concentracao_antibiotico(x_nivel_maximo);

    printf("tempo para q haja concentracao maxima em horas: %.2f\n", x_nivel_maximo);
    printf("concentracao maxima do antibiotico: %.2f", y_nivel_maximo);

    return 0;

}

