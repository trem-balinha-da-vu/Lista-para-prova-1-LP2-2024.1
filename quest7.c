//------------------------------------------------------------------------------------------------
/**
 * A nota de produtividade dos funcionários de determinado setor é dada pela seguinte função do
 * primeiro grau: f(x) = 3x + 12, onde x é a quantidade de processos despachados pelo funcionário
 * na semana.
 * Faça um programa que o usuário digite para cada funcionário da empresa, seu nome, seu
 * número de matrícula e a quantidade de processos despachados e calcule e mostre na tela a
 * sua nota de produtividade. O programa deve funcionar para qualquer tamanho de empresa,
 * de 1 a n funcionários.
 * Analise a qualidade das funções criadas.
*/
//-------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

typedef struct Funcionario{
    int matricula;
    char nome[50];
    int qtd_processos_despach;
    struct Funcionario *prox;
} Funcionario;

double calcular_nota_produtividade(int processos_despachados) {
    return 3 * processos_despachados + 12;
}

void imprimir_dados_e_nota(Funcionario *funcionario) {
    double nota_produtividade = calcular_nota_produtividade(funcionario->qtd_processos_despach);

    printf("Funcionario: %s\n", funcionario->nome);
    printf("Matricula: %d\n", funcionario->matricula);
    printf("Quantidade de processos despachados: %d\n", funcionario->qtd_processos_despach);
    printf("Nota de produtividade: %.2f\n", nota_produtividade);
}

void liberar_memoria(Funcionario *inicio) {
    Funcionario *atual = inicio;
    while (atual != NULL) {
        Funcionario *prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

Funcionario *novo_funcionario() {
    Funcionario *novo = (Funcionario *)malloc(sizeof(Funcionario));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    printf("Digite o nome do funcionario: ");
    scanf("%s", novo->nome);
    printf("Digite o numero de matricula do funcionario: ");
    scanf("%d", &novo->matricula);
    printf("Digite a quantidade de processos despachados pelo funcionario na semana: ");
    scanf("%d", &novo->qtd_processos_despach);
    novo->prox = NULL;
    return novo;
}

int main() {
    int numero_funcionarios;

    printf("Digite o numero de funcionarios da empresa: ");
    scanf("%d", &numero_funcionarios);

    Funcionario *inicio = NULL;
    Funcionario *atual = NULL;

    for (int i = 0; i < numero_funcionarios; i++) {
        printf("\nFuncionario %d:\n", i + 1);
        Funcionario *novo = novo_funcionario();

        if (inicio == NULL) {
            inicio = novo;
        } else {
            atual->prox = novo;
        }
        atual = novo;
    }

    atual = inicio;
    while (atual != NULL) {
        printf("\n");
        imprimir_dados_e_nota(atual);
        atual = atual->prox;
    }

    liberar_memoria(inicio);

    return 0;
}
