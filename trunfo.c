#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Informações da Carta 1
    char estado1;
    char codigo1[4];
    char nome_cidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    float densidade1;
    float pib_per_capita1;
    float super_poder1;

    // Informações da Carta 2
    char estado2;
    char codigo2[4];
    char nome_cidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidade2;
    float pib_per_capita2;
    float super_poder2;

    // Entrada de informações carta 1
    printf("\nDigite os dados da carta 1:\n");
    printf("\nLetra do estado (A - H): ");
    scanf(" %c", &estado1);

    printf("Código da cidade (A01, B01, C01): ");
    scanf("%s", codigo1);

    printf("Nome da cidade: ");
    scanf(" %s", nome_cidade1);

    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Pontos turísticos: ");
    scanf("%d", &pontos_turisticos1);

    // Entrada de informações carta 2
    printf("\nDigite os dados da carta 2:\n");
    printf("Letra do estado (A - H): ");
    scanf(" %c", &estado2);

    printf("Código da cidade (A02, B02, C02): ");
    scanf("%s", codigo2);

    printf("Nome da cidade: ");
    scanf(" %s", nome_cidade2);

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Pontos turísticos: ");
    scanf("%d", &pontos_turisticos2);

    // Cálculos Carta 1
    densidade1 = populacao1 / area1;
    pib_per_capita1 = (pib1 * 1000000000) / populacao1;
    super_poder1 = (float)populacao1 + area1 + pib1 + pontos_turisticos1 + pib_per_capita1 + (1 / densidade1);

    // Cálculos Carta 2
    densidade2 = populacao2 / area2;
    pib_per_capita2 = (pib2 * 1000000000) / populacao2;
    super_poder2 = (float)populacao2 + area2 + pib2 + pontos_turisticos2 + pib_per_capita2 + (1 / densidade2);

    // Saída de dados das cartas
    printf("\n--- Dados das Cartas ---\n");

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código da cidade: %s\n", codigo1);
    printf("Nome da cidade: %s\n", nome_cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: R$ %.2f bilhões\n", pib1);
    printf("Pontos turísticos: %d\n", pontos_turisticos1);
    printf("Densidade populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per capita: R$ %.2f\n", pib_per_capita1);
    printf("Super Poder: %.2f\n", super_poder1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código da cidade: %s\n", codigo2);
    printf("Nome da cidade: %s\n", nome_cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: R$ %.2f bilhões\n", pib2);
    printf("Pontos turísticos: %d\n", pontos_turisticos2);
    printf("Densidade populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per capita: R$ %.2f\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);

    // Comparação detalhada: População
    printf("\nPopulação:\n");
    printf("Carta 1: %lu | Carta 2: %lu\n", populacao1, populacao2);
    if (populacao1 > populacao2)
        printf("Carta 1 venceu (maior população)\n");
    else if (populacao2 > populacao1)
        printf("Carta 2 venceu (maior população)\n");
    else
        printf("Empate\n");

    /* 
    // Comparação de atributos: Área
    printf("\nÁrea:\n");
    printf("Carta 1: %.2f km² | Carta 2: %.2f km²\n", area1, area2);
    if (area1 > area2)
        printf("Carta 1 venceu (maior área)\n");
    else if (area2 > area1)
        printf("Carta 2 venceu (maior área)\n");
    else
        printf("Empate\n");

    // Comparação de atributos: PIB
    printf("\nPIB:\n");
    printf("Carta 1: R$ %.2f bi | Carta 2: R$ %.2f bi\n", pib1, pib2);
    if (pib1 > pib2)
        printf("Carta 1 venceu (maior PIB)\n");
    else if (pib2 > pib1)
        printf("Carta 2 venceu (maior PIB)\n");
    else
        printf("Empate\n");

    // Densidade populacional (menor vence)
    printf("\nDensidade Populacional:\n");
    printf("Carta 1: %.2f hab/km² | Carta 2: %.2f hab/km²\n", densidade1, densidade2);
    if (densidade1 < densidade2)
        printf("Carta 1 venceu (menor densidade populacional)\n");
    else if (densidade2 < densidade1)
        printf("Carta 2 venceu (menor densidade populacional)\n");
    else
        printf("Empate\n");

    // Comparação de atributos: PIB per capita
    printf("\nPIB per capita:\n");
    printf("Carta 1: R$ %.2f | Carta 2: R$ %.2f\n", pib_per_capita1, pib_per_capita2);
    if (pib_per_capita1 > pib_per_capita2)
        printf("Carta 1 venceu (maior PIB per capita)\n");
    else if (pib_per_capita2 > pib_per_capita1)
        printf("Carta 2 venceu (maior PIB per capita)\n");
    else
        printf("Empate\n");

    // Comparação de atributos: Super Poder
    printf("\nSuper Poder:\n");
    printf("Carta 1: %.2f | Carta 2: %.2f\n", super_poder1, super_poder2);
    if (super_poder1 > super_poder2)
        printf("Carta 1 venceu (maior super poder)\n");
    else if (super_poder2 > super_poder1)
        printf("Carta 2 venceu (maior super poder)\n");
    else
        printf("Empate\n");

    printf("\n--- Fim da Comparação ---\n");
    */

    return 0;
}
