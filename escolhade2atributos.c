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

float obterAtributo(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidade;
        case 6: return c.pibPerCapita;
        default: return 0;
    }
}

void menuAtributos(int excluir) {
    printf("\nEscolha um atributo para comparar:\n");
    if (excluir != 1) printf("1 - Populacao\n");
    if (excluir != 2) printf("2 - Area\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turisticos\n");
    if (excluir != 5) printf("5 - Densidade Demografica\n");
    if (excluir != 6) printf("6 - PIB per Capita\n");
    printf("Opcao: ");
}

int main() {
    struct Carta c1, c2;
    int atr1, atr2;

    // ===============================
    // CADASTRO (Reutilizado dos desafios anteriores)
    // ===============================

    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado: "); fgets(c1.estado, 50, stdin);
    printf("Codigo: "); fgets(c1.codigo, 10, stdin);
    printf("Nome: "); fgets(c1.nome, 50, stdin);
    printf("Populacao: "); scanf("%lu", &c1.populacao);
    printf("Area: "); scanf("%f", &c1.area);
    printf("PIB: "); scanf("%f", &c1.pib);
    printf("Pontos Turisticos: "); scanf("%d", &c1.pontosTuristicos);
    getchar();

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado: "); fgets(c2.estado, 50, stdin);
    printf("Codigo: "); fgets(c2.codigo, 10, stdin);
    printf("Nome: "); fgets(c2.nome, 50, stdin);
    printf("Populacao: "); scanf("%lu", &c2.populacao);
    printf("Area: "); scanf("%f", &c2.area);
    printf("PIB: "); scanf("%f", &c2.pib);
    printf("Pontos Turisticos: "); scanf("%d", &c2.pontosTuristicos);

    // Cálculos automáticos
    c1.densidade = c1.populacao / c1.area;
    c2.densidade = c2.populacao / c2.area;

    c1.pibPerCapita = c1.pib / c1.populacao;
    c2.pibPerCapita = c2.pib / c2.populacao;

    // ===============================
    // ESCOLHA DO PRIMEIRO ATRIBUTO
    // ===============================

    menuAtributos(0);
    scanf("%d", &atr1);

    if (atr1 < 1 || atr1 > 6) {
        printf("Opcao inválida!\n");
        return 0;
    }

    // ===============================
    // ESCOLHA DO SEGUNDO ATRIBUTO (dinâmico)
    // ===============================

    menuAtributos(atr1);
    scanf("%d", &atr2);

    if (atr2 < 1 || atr2 > 6 || atr2 == atr1) {
        printf("Opcao inválida!\n");
        return 0;
    }

    // ===============================
    // OBTENDO OS VALORES DOS ATRIBUTOS
    // ===============================

    float v1a = obterAtributo(c1, atr1);
    float v2a = obterAtributo(c2, atr1);

    float v1b = obterAtributo(c1, atr2);
    float v2b = obterAtributo(c2, atr2);

    // ===============================
    // COMPARAÇÃO DOS ATRIBUTOS (com if-else aninhado + regra especial)
    // ===============================

    // Para densidade (5), o menor vence
    int r1 = (atr1 == 5) ? (v1a < v2a) : (v1a > v2a);
    int r2 = (atr2 == 5) ? (v1b < v2b) : (v1b > v2b);

    // ===============================
    // SOMA FINAL DOS VALORES
    // ===============================

    float soma1 = v1a + v1b;
    float soma2 = v2a + v2b;

    // operador ternário para determinar vencedor
    const char* vencedor = (soma1 > soma2) ? c1.nome :
                           (soma2 > soma1) ? c2.nome : "Empate!";

    // ===============================
    // EXIBIÇÃO FINAL DOS RESULTADOS
    // ===============================

    printf("\n=================================\n");
    printf("      RESULTADO DA RODADA\n");
    printf("=================================\n");

    printf("Carta 1: %s", c1.nome);
    printf("Carta 2: %s\n", c2.nome);

    printf("\nAtributo 1 escolhido: %d\n", atr1);
    printf("%s: %.2f\n", c1.nome, v1a);
    printf("%s: %.2f\n", c2.nome, v2a);
    printf("Vencedor do atributo 1: %s\n",
           r1 ? c1.nome : (!r1 && v1a != v2a ? c2.nome : "Empate"));

    printf("\nAtributo 2 escolhido: %d\n", atr2);
    printf("%s: %.2f\n", c1.nome, v1b);
    printf("%s: %.2f\n", c2.nome, v2b);
    printf("Vencedor do atributo 2: %s\n",
           r2 ? c1.nome : (!r2 && v1b != v2b ? c2.nome : "Empate"));

    printf("\nSoma dos atributos:\n");
    printf("%s = %.2f\n", c1.nome, soma1);
    printf("
