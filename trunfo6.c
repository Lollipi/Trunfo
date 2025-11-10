#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Estrutura de dados
    // Carta 1
    char estado1;
    char codigo1[4];
    char nome_cidade1[50];
    unsigned long int populacao1;
    float area1, pib1;
    int pontos_turisticos1;
    float densidade1, pib_per_capita1;

    // Carta 2
    char estado2;
    char codigo2[4];
    char nome_cidade2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int pontos_turisticos2;
    float densidade2, pib_per_capita2;

    //Entrada de dados
    printf("Cadastro da Carta 1\n");
    printf("Letra do estado (A - H): ");
    scanf(" %c", &estado1);

    printf("Código da cidade (ex: A01): ");
    scanf("%s", codigo1);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", nome_cidade1);

    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Número de pontos turísticos: ");
    scanf("%d", &pontos_turisticos1);

    printf("\nCadastro da Carta 2\n");
    printf("Letra do estado (A - H): ");
    scanf(" %c", &estado2);

    printf("Código da cidade (ex: A02): ");
    scanf("%s", codigo2);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", nome_cidade2);

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de pontos turísticos: ");
    scanf("%d", &pontos_turisticos2);

    // Cálculos
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pib_per_capita1 = (pib1 * 1000000000) / populacao1;
    pib_per_capita2 = (pib2 * 1000000000) / populacao2;

    // Menu de comparação
    int opcao1, opcao2;
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;

    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade demográfica (menor vence)\n");
    printf("6 - PIB per capita\n");
    scanf("%d", &opcao1);

    // Menu dinâmico (remove a opção já escolhida)
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i != opcao1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos turísticos\n"); break;
                case 5: printf("5 - Densidade demográfica (menor vence)\n"); break;
                case 6: printf("6 - PIB per capita\n"); break;
            }
        }
    }
    scanf("%d", &opcao2);

    if (opcao1 == opcao2) {
        printf("Erro: os dois atributos devem ser diferentes.\n");
        return 0;
    }

    // Função auxiliar de comparação
    float obterValor(int opcao, float *v1, float *v2) {
        switch (opcao) {
            case 1: *v1 = populacao1; *v2 = populacao2; break;
            case 2: *v1 = area1; *v2 = area2; break;
            case 3: *v1 = pib1; *v2 = pib2; break;
            case 4: *v1 = pontos_turisticos1; *v2 = pontos_turisticos2; break;
            case 5: *v1 = densidade1; *v2 = densidade2; break;
            case 6: *v1 = pib_per_capita1; *v2 = pib_per_capita2; break;
            default: *v1 = 0; *v2 = 0;
        }
        return 0;
    }

    obterValor(opcao1, &valor1_carta1, &valor1_carta2);
    obterValor(opcao2, &valor2_carta1, &valor2_carta2);

    // Comparação individual e soma
    float soma1 = 0, soma2 = 0;

    float resultado1 = (opcao1 == 5) ?
        (valor1_carta1 < valor1_carta2 ? 1 : (valor1_carta1 > valor1_carta2 ? -1 : 0)) :
        (valor1_carta1 > valor1_carta2 ? 1 : (valor1_carta1 < valor1_carta2 ? -1 : 0));

    float resultado2 = (opcao2 == 5) ?
        (valor2_carta1 < valor2_carta2 ? 1 : (valor2_carta1 > valor2_carta2 ? -1 : 0)) :
        (valor2_carta1 > valor2_carta2 ? 1 : (valor2_carta1 < valor2_carta2 ? -1 : 0));

    soma1 = valor1_carta1 + valor2_carta1;
    soma2 = valor1_carta2 + valor2_carta2;

    printf("\nResultado da comparação:\n");
    printf("%s vs %s\n", nome_cidade1, nome_cidade2);
    printf("Atributo 1: ");
    switch (opcao1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos turísticos\n"); break;
        case 5: printf("Densidade demográfica\n"); break;
        case 6: printf("PIB per capita\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n", nome_cidade1, valor1_carta1, nome_cidade2, valor1_carta2);

    printf("Atributo 2: ");
    switch (opcao2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos turísticos\n"); break;
        case 5: printf("Densidade demográfica\n"); break;
        case 6: printf("PIB per capita\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n", nome_cidade1, valor2_carta1, nome_cidade2, valor2_carta2);

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", nome_cidade1, soma1);
    printf("%s: %.2f\n", nome_cidade2, soma2);

    if (soma1 > soma2)
        printf("Vencedora: %s\n", nome_cidade1);
    else if (soma2 > soma1)
        printf("Vencedora: %s\n", nome_cidade2);
    else
        printf("Empate!\n");

    return 0;
}
