//------------------------------------------------------------------------
/**
 * Sabendo que um capital de x reais, aplicado em regime de juros compostos a uma taxa de t%
 * ao mês durante m meses vai render vblc reais de valor bruto de juros compostos. Ao retirar o
 * montante resultante da aplicação a pessoa terá descontado, do juro da aplicação, 7% de
 * imposto sobre aplicações financeiras envolvendo lucros, mais 0,5% de contribuição para obras
 * relacionadas à saúde pública, segurança e educação, totalizando 7,5% de descontos.
 *      a. Faça uma função para calcular o valor bruto de juros compostos recebido para um
 * capital investido durante n meses a uma taxa de x%.
 *      b. Faça uma função que calcule o valor líquido dessa aplicação, isto é, o valor do capital,
 * acrescido dos juros da aplicação, debitado os impostos.
 *      c. Verifique e informe qual é a qualidade (Coesão e Acoplamento) de suas funções.
 *      d. Faça um programa utilizando as funções que você criou, que receba do usuário um
 * vetor com 10 valores de aplicações (com a sua respectiva taxa de juros e tempo deaplicação) e mostre na tela
 * para cada valor aplicado:
 *          i. O valor aplicado, a taxa de juros aplicada, a quantidade de meses da aplicação,
 * o valor bruto recebido, O total descontado em impostos e contribuições e o
 * valor líquido da aplicação.

Observação: Podem ser criadas quantas funções você achar necessário para resolver o
problema.
*/

#include <stdio.h>
#include <math.h>

float calc_valor_bruto_juros_compostos (double capital, int qtd_meses, float taxa)
{
    return capital * pow((1 + taxa / 100), qtd_meses);
}

double calc_valor_liquido(double capital, double taxa, int meses) {
    double valor_bruto = calc_valor_bruto_juros_compostos(capital, taxa, meses);
    double imposto = 0.07;
    double contribuicao = 0.005; 

    double descontos = valor_bruto * (imposto + contribuicao);

    return valor_bruto - descontos;
}

#include <stdio.h>

int main() {
    double capital, taxa;
    int meses;

    printf("Digite o valor do capital, taxa de juros (em porcentagem) e quantidade de meses da aplicacao:\n");
    scanf("%lf %lf %d", &capital, &taxa, &meses);

    double valor_bruto = calc_valor_bruto_juros_compostos(capital, taxa, meses);

    double valor_liquido = calc_valor_liquido(capital, taxa, meses);

    printf("Valor aplicado: R$ %.2lf\n", capital);
    printf("Taxa de juros: %.2lf%%\n", taxa);
    printf("Quantidade de meses: %d\n", meses);
    printf("Valor bruto recebido: R$ %.2lf\n", valor_bruto);
    printf("Total descontado em impostos e contribuicoes: R$ %.2lf\n", valor_bruto - valor_liquido);
    printf("Valor liquido da aplicacao: R$ %.2lf\n", valor_liquido);

    return 0;
}
