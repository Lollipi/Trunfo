#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Estrutura de dados — duas cartas
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char nome_cidade1[50], nome_cidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontos_turisticos1, pontos_turisticos2;
    float densidade1, densidade2, pib_per_capita1, pib_per_capita2;

    // Entrada de dados
    printf("\nCadastro da Carta 1\n");
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

    // Cálculos derivados
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pib_per_capita1 = (pib1 * 1000000000) / populacao1;
    pib_per_capita2 = (pib2 * 1000000000) / populacao2;

    // Menu de seleção de atributos
    int opcao1, opcao2;
    printf("\nMenu de Atributos\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade demográfica (menor vence)\n");
    printf("6 - PIB per capita\n");

    // Escolha do primeiro atributo
    do {
        printf("\nEscolha o primeiro atributo (1 a 6): ");
        scanf("%d", &opcao1);
        if (opcao1 < 1 || opcao1 > 6)
            printf("Opção inválida! Tente novamente.\n");
    } while (opcao1 < 1 || opcao1 > 6);

    // Menu dinâmico para o segundo atributo
    printf("\nEscolha o segundo atributo\n");
    for (int i = 1; i <= 6; i++) {
        if (i == opcao1) continue; // Oculta o atributo já escolhido
        switch (i) {
            case 1: printf("1 - População\n"); break;
            case 2: printf("2 - Área\n"); break;
            case 3: printf("3 - PIB\n"); break;
            case 4: printf("4 - Pontos turísticos\n"); break;
            case 5: printf("5 - Densidade demográfica (menor vence)\n"); break;
            case 6: printf("6 - PIB per capita\n"); break;
        }
    }

    do {
        printf("\nEscolha o segundo atributo (1 a 6, diferente do primeiro): ");
        scanf("%d", &opcao2);
        if (opcao2 < 1 || opcao2 > 6 || opcao2 == opcao1)
            printf("Opção inválida! Tente novamente.\n");
    } while (opcao2 < 1 || opcao2 > 6 || opcao2 == opcao1);

    // Função auxiliar para obter valor do atributo
     float obterValor(int opcao, int carta) {
        switch (opcao) {
            case 1: return (carta == 1 ? populacao1 : populacao2);
            case 2: return (carta == 1 ? area1 : area2);
            case 3: return (carta == 1 ? pib1 : pib2);
            case 4: return (carta == 1 ? pontos_turisticos1 : pontos_turisticos2);
            case 5: return (carta == 1 ? densidade1 : densidade2);
            case 6: return (carta == 1 ? pib_per_capita1 : pib_per_capita2);
            default: return 0;
        }
    }

    // Captura dos valores selecionados
    float valor_carta1_attr1 = obterValor(opcao1, 1);
    float valor_carta2_attr1 = obterValor(opcao1, 2);
    float valor_carta1_attr2 = obterValor(opcao2, 1);
    float valor_carta2_attr2 = obterValor(opcao2, 2);

    // Comparações individuais
    int pontos_cidade1 = 0, pontos_cidade2 = 0;

    // Comparar primeiro atributo
    if (opcao1 == 5) { // Densidade - menor vence
        if (valor_carta1_attr1 < valor_carta2_attr1) pontos_cidade1++;
        else if (valor_carta2_attr1 < valor_carta1_attr1) pontos_cidade2++;
    } else {
        if (valor_carta1_attr1 > valor_carta2_attr1) pontos_cidade1++;
        else if (valor_carta2_attr1 > valor_carta1_attr1) pontos_cidade2++;
    }

    // Comparar segundo atributo
    if (opcao2 == 5) { // Densidade - menor vence
        if (valor_carta1_attr2 < valor_carta2_attr2) pontos_cidade1++;
        else if (valor_carta2_attr2 < valor_carta1_attr2) pontos_cidade2++;
    } else {
        if (valor_carta1_attr2 > valor_carta2_attr2) pontos_cidade1++;
        else if (valor_carta2_attr2 > valor_carta1_attr2) pontos_cidade2++;
    }

    // Soma total dos atributos
    float soma1 = valor_carta1_attr1 + valor_carta1_attr2;
    float soma2 = valor_carta2_attr1 + valor_carta2_attr2;

    // Exibição dos resultados
    printf("\nResultado da Comparação\n");
    printf("Cidades: %s vs %s\n", nome_cidade1, nome_cidade2);
    printf("----------------------------------\n");

    // Nomes dos atributos
    char nome_attr1[30], nome_attr2[30];
    char* nomes[] = {"População", "Área", "PIB", "Pontos turísticos", "Densidade demográfica", "PIB per capita"};
    strcpy(nome_attr1, nomes[opcao1 - 1]);
    strcpy(nome_attr2, nomes[opcao2 - 1]);

    printf("%-25s | %-15s | %-15s\n", "Atributo", nome_cidade1, nome_cidade2);
    printf("-------------------------------------------------------------\n");
    printf("%-25s | %-15.2f | %-15.2f\n", nome_attr1, valor_carta1_attr1, valor_carta2_attr1);
    printf("%-25s | %-15.2f | %-15.2f\n", nome_attr2, valor_carta1_attr2, valor_carta2_attr2);
    printf("-------------------------------------------------------------\n");
    printf("Soma dos atributos        | %-15.2f | %-15.2f\n", soma1, soma2);

    // Resultado final
    printf("\nResultado Final\n");
    if (soma1 > soma2)
        printf("Vencedora: %s\n", nome_cidade1);
    else if (soma2 > soma1)
        printf("Vencedora: %s\n", nome_cidade2);
    else
        printf("Empate!\n");

    printf("\nFim da Comparação\n");
    return 0;
}
