#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[50];
    char codigo[10];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
};

int main() {
    struct Carta c1, c2;
    int opcao;

    // ============================
    // LEITURA DOS DADOS (Reaproveitado do desafio anterior)
    // ============================
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado: ");
    fgets(c1.estado, 50, stdin);
    printf("Codigo: ");
    fgets(c1.codigo, 10, stdin);
    printf("Nome da cidade: ");
    fgets(c1.nome, 50, stdin);
    printf("Populacao: ");
    scanf("%lu", &c1.populacao);
    printf("Area: ");
    scanf("%f", &c1.area);
    printf("PIB: ");
    scanf("%f", &c1.pib);
    printf("Pontos turisticos: ");
    scanf("%d", &c1.pontosTuristicos);

    getchar(); // limpeza do buffer

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado: ");
    fgets(c2.estado, 50, stdin);
    printf("Codigo: ");
    fgets(c2.codigo, 10, stdin);
    printf("Nome da cidade: ");
    fgets(c2.nome, 50, stdin);
    printf("Populacao: ");
    scanf("%lu", &c2.populacao);
    printf("Area: ");
    scanf("%f", &c2.area);
    printf("PIB: ");
    scanf("%f", &c2.pib);
    printf("Pontos turisticos: ");
    scanf("%d", &c2.pontosTuristicos);

    // ============================
    // CÁLCULOS AUTOMÁTICOS
    // ============================
    c1.densidade = c1.populacao / c1.area;
    c2.densidade = c2.populacao / c2.area;

    c1.pibPerCapita = c1.pib / c1.populacao;
    c2.pibPerCapita = c2.pib / c2.populacao;

    // ============================
    // MENU INTERATIVO (SWITCH)
    // ============================
    printf("\n=== MENU DE COMPARACAO ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("6 - PIB per Capita\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);

    printf("\n=== RESULTADO DA COMPARACAO ===\n");

    switch(opcao) {

        case 1:  // POPULAÇÃO
            printf("Atributo: Populacao\n");
            printf("%s: %lu\n", c1.nome, c1.populacao);
            printf("%s: %lu\n", c2.nome, c2.populacao);

            if (c1.populacao > c2.populacao)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.populacao > c1.populacao)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 2:  // ÁREA
            printf("Atributo: Area\n");
            printf("%s: %.2f\n", c1.nome, c1.area);
            printf("%s: %.2f\n", c2.nome, c2.area);

            if (c1.area > c2.area)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.area > c1.area)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 3:  // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f\n", c1.nome, c1.pib);
            printf("%s: %.2f\n", c2.nome, c2.pib);

            if (c1.pib > c2.pib)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.pib > c1.pib)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 4:  // PONTOS TURISTICOS
            printf("Atributo: Pontos Turisticos\n");
            printf("%s: %d\n", c1.nome, c1.pontosTuristicos);
            printf("%s: %d\n", c2.nome, c2.pontosTuristicos);

            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 5:  // DENSIDADE (MENOR VENCE!)
            printf("Atributo: Densidade Demografica\n");
            printf("%s: %.2f hab/km²\n", c1.nome, c1.densidade);
            printf("%s: %.2f hab/km²\n", c2.nome, c2.densidade);

            if (c1.densidade < c2.densidade)  // menor vence
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.densidade < c1.densidade)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 6:  // PIB PER CAPITA
            printf("Atributo: PIB per Capita\n");
            printf("%s: %.2f\n", c1.nome, c1.pibPerCapita);
            printf("%s: %.2f\n", c2.nome, c2.pibPerCapita);

            if (c1.pibPerCapita > c2.pibPerCapita)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.pibPerCapita > c1.pibPerCapita)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opcao invalida! Escolha um numero de 1 a 6.\n");
            break;
    }

    return 0;
}
