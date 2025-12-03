#include <stdio.h>

int main() {

    // ---------------- VARIÁVEIS DA CARTA 1 ----------------
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidade1;
    float pibPerCapita1;

    // ---------------- VARIÁVEIS DA CARTA 2 ----------------
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2;
    float pibPerCapita2;

    // --------------------------------------------------------
    // CADASTRO DA CARTA 1
    // --------------------------------------------------------
    printf("=== Cadastro da Carta 1 ===\n");

    printf("Estado: ");
    scanf(" %c", &estado1);

    printf("Codigo (ex: A01): ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("Populacao: ");
    scanf("%d", &populacao1);

    printf("Area (km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculos da carta 1
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0f) / populacao1;


    // --------------------------------------------------------
    // CADASTRO DA CARTA 2
    // --------------------------------------------------------
    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Estado: ");
    scanf(" %c", &estado2);

    printf("Codigo (ex: B01): ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Populacao: ");
    scanf("%d", &populacao2);

    printf("Area (km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos da carta 2
    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0f) / populacao2;


    // --------------------------------------------------------
    // ESCOLHA DO ATRIBUTO PARA COMPARAÇÃO:
    // Troque aqui para testar outros atributos:
    //
    // 1 = População
    // 2 = Área
    // 3 = PIB
    // 4 = Densidade Populacional  (MENOR vence)
    // 5 = PIB per Capita
    // --------------------------------------------------------
    int atributoEscolhido = 1;  // <<< ALTERE AQUI SE QUISER

    printf("\n\n===== COMPARAÇÃO DE CARTAS =====\n");

    if (atributoEscolhido == 1) {
        // ---------------- POPULAÇÃO ----------------
        printf("Comparacao de cartas (Atributo: Populacao)\n");
        printf("Carta 1 - %s: %d habitantes\n", nomeCidade1, populacao1);
        printf("Carta 2 - %s: %d habitantes\n", nomeCidade2, populacao2);

        if (populacao1 > populacao2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        }

    } else if (atributoEscolhido == 2) {
        // ---------------- ÁREA ----------------
        printf("Comparacao de cartas (Atributo: Area)\n");
        printf("Carta 1 - %s: %.2f km²\n", nomeCidade1, area1);
        printf("Carta 2 - %s: %.2f km²\n", nomeCidade2, area2);

        if (area1 > area2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        }

    } else if (atributoEscolhido == 3) {
        // ---------------- PIB ----------------
        printf("Comparacao de cartas (Atributo: PIB)\n");
        printf("Carta 1 - %s: %.2f bilhoes de reais\n", nomeCidade1, pib1);
        printf("Carta 2 - %s: %.2f bilhoes de reais\n", nomeCidade2, pib2);

        if (pib1 > pib2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        }

    } else if (atributoEscolhido == 4) {
        // ---------------- DENSIDADE POPULACIONAL (MENOR VENCE!) ----------------
        printf("Comparacao de cartas (Atributo: Densidade Populacional)\n");
        printf("Carta 1 - %s: %.2f hab/km²\n", nomeCidade1, densidade1);
        printf("Carta 2 - %s: %.2f hab/km²\n", nomeCidade2, densidade2);

        if (densidade1 < densidade2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        }

    } else if (atributoEscolhido == 5) {
        // ---------------- PIB PER CAPITA ----------------
        printf("Comparacao de cartas (Atributo: PIB per Capita)\n");
        printf("Carta 1 - %s: %.2f reais\n", nomeCidade1, pibPerCapita1);
        printf("Carta 2 - %s: %.2f reais\n", nomeCidade2, pibPerCapita2);

        if (pibPerCapita1 > pibPerCapita2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        }
    }

    return 0;
}
