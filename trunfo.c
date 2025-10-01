#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Informações da Carta 1
    char estado1;
    char codigo1[4];  // Exemplo: "A01, B01, C01"
    char nome_cidade1[50]; //colocar _ ou digitar o nome todo junto.
    int populacao1;
    float area1; //Utilizar virgula nas casas decimais(a localidade "pt_BR.UTF-8" so le numero decimal com virgula)
    float pib1; //Utilizar virgula nas casas decimais
    int pontos_turisticos1;

    // Informações da Carta 2
    char estado2;
    char codigo2[4];  // Exemplo: "A02, B02, C02"
    char nome_cidade2[50]; //colocar _ ou digitar o nome todo junto
    int populacao2;
    float area2; //Utilizar virgula nas casas decimais
    float pib2; //Utilizar virgula nas casas decimais
    int pontos_turisticos2;

    //Entrada de informações carta 1

    printf("\nDigite os dados da carta 1:\n");

    printf("\nLetra do estado (A - H): ");
    scanf(" %c", &estado1);

    printf("Codigo da cidade (A01, B01, C01): ");
    scanf("%s", codigo1);

    printf("Nome da cidade : ");
    scanf(" %s", nome_cidade1);

    printf("Populacao: ");
    scanf("%d", &populacao1);

    printf("Area (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Pontos turisticos: ");
    scanf("%d", &pontos_turisticos1);



    //Entrada de informações carta 2

    printf("\nDigite os dados da carta 2:\n");

    printf("Letra do estado (A - H): ");
    scanf(" %c", &estado2);

    printf("Codigo da cidade (A02, B02, C02): ");
    scanf(" %s", codigo2);

    printf("Nome da cidade: ");
    scanf(" %s", nome_cidade2);

    printf("Populacao: ");
    scanf("%d", &populacao2);

    printf("Area (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Pontos turisticos: ");
    scanf("%d", &pontos_turisticos2);

    //Saida da Carta 1
    printf("\nCarta 1:\n"); 
    printf("Estado: %c\n", estado1);
    printf("Codigo da cidade: %s\n", codigo1);
    printf("Nome da cidade: %s\n", nome_cidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: R$ %.2f Bilhões de reais\n", pib1);
    printf("Pontos turisticos: %d\n", pontos_turisticos1);

    //Saida da Carta 2
    printf("\nCarta 2:\n"); 
    printf("Estado: %c\n", estado2);
    printf("Codigo da cidade: %s\n", codigo2);
    printf("Nome da cidade: %s\n", nome_cidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: R$ %.2f Bilhões de reais\n", pib2);
    printf("Pontos turisticos: %d\n", pontos_turisticos2);

    return 0;
}

     



