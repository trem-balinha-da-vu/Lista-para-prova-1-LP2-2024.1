//-------------------------------------------------------------------------
/**
 * Em uma indústria metalúrgica o custo de produção de uma peça automotiva corresponde a
 * um custo fixo mensal de R$ 5 000,00 acrescido de um custo variável de R$ 55,00 por unidade
 * produzida mais 25% de impostos sobre o custo variável. Considerando que o preço de venda
 * dessa peça pela indústria aos comerciantes é de R$ 102,00, determine:
 *          a. a função custo da produção de x peças.
 *          b. a função receita referente a venda de x peças.
 *          c. a função lucro na venda de x peças.
 *          d. o lucro obtido com a venda de 500 unidades.
*/
//--------------------------------------------------------------------------

#include <stdio.h>

double custo_producao(int x) {
    double custo_fixo = 5000.0;
    double custo_variavel_por_peca = 55.0;
    double impostos = 0.25;

    double custo_variavel = custo_variavel_por_peca * x;
    double custo_total = custo_fixo + (custo_variavel * (1 + impostos));

    return custo_total;
}

double receita_venda(int x) {
    double preco_venda_por_peca = 102.0;

    double receita_total = preco_venda_por_peca * x;

    return receita_total;
}

double lucro_venda(int x) {
    double custo = custo_producao(x);
    double receita = receita_venda(x);

    double lucro = receita - custo;

    return lucro;
}

int main() {
    int x = 500; 

    double custo = custo_producao(x);
    printf("a. O custo da produção de %d peças é de R$ %.2f\n", x, custo);

    double receita = receita_venda(x);
    printf("b. A receita da venda de %d peças é de R$ %.2f\n", x, receita);

    double lucro = lucro_venda(x);
    printf("c. O lucro da venda de %d peças é de R$ %.2f\n", x, lucro);

    printf("d. O lucro obtido com a venda de 500 unidades é de R$ %.2f\n", lucro);

    return 0;
}
