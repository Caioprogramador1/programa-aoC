#include <stdio.h>
#include <string.h>

int main() {
    // Variáveis para a primeira carta
    char estado1;
    char codigo1[4];
    char cidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    float densidade1;

    // Variáveis para a segunda carta
    char estado2;
    char codigo2[4];
    char cidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidade2;

    // Solicitação dos dados da primeira carta
    printf("=== SUPER TRUNFO - CADASTRO DE CARTAS ===\n\n");
    printf("Digite os dados da primeira carta:\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);

    printf("População: ");
    scanf("%d", &populacao1);

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos1);

    // Solicitação dos dados da segunda carta
    printf("\nDigite os dados da segunda carta:\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Código da Carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("População: ");
    scanf("%d", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);

    // Cálculo da densidade demográfica
    densidade1 = (area1 > 0) ? populacao1 / area1 : 0;
    densidade2 = (area2 > 0) ? populacao2 / area2 : 0;

    // Exibição dos dados das cartas
    printf("\n=== CARTAS CADASTRADAS ===\n");
    
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Demográfica: %.2f hab/km²\n", densidade1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Demográfica: %.2f hab/km²\n", densidade2);

    // Menu interativo para comparação
    int opcao;
    do {
        printf("\n=== MENU DE COMPARAÇÃO - SUPER TRUNFO ===\n");
        printf("Escolha o atributo para comparar as cartas:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Número de Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("0 - Sair do jogo\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        // Variáveis para armazenar resultados da comparação
        int resultado;
        char* atributo;
        float valor1, valor2;

        switch(opcao) {
            case 1: // População
                atributo = "POPULAÇÃO";
                valor1 = populacao1;
                valor2 = populacao2;
                resultado = (populacao1 > populacao2) ? 1 : (populacao2 > populacao1) ? 2 : 0;
                break;

            case 2: // Área
                atributo = "ÁREA";
                valor1 = area1;
                valor2 = area2;
                resultado = (area1 > area2) ? 1 : (area2 > area1) ? 2 : 0;
                break;

            case 3: // PIB
                atributo = "PIB";
                valor1 = pib1;
                valor2 = pib2;
                resultado = (pib1 > pib2) ? 1 : (pib2 > pib1) ? 2 : 0;
                break;

            case 4: // Pontos Turísticos
                atributo = "PONTOS TURÍSTICOS";
                valor1 = pontos_turisticos1;
                valor2 = pontos_turisticos2;
                resultado = (pontos_turisticos1 > pontos_turisticos2) ? 1 : 
                           (pontos_turisticos2 > pontos_turisticos1) ? 2 : 0;
                break;

            case 5: // Densidade Demográfica (regra invertida)
                atributo = "DENSIDADE DEMOGRÁFICA";
                valor1 = densidade1;
                valor2 = densidade2;
                // Para densidade, menor valor vence (regra invertida)
                resultado = (densidade1 < densidade2) ? 1 : (densidade2 < densidade1) ? 2 : 0;
                break;

            case 0: // Sair
                printf("\nObrigado por jogar Super Trunfo!\n");
                break;

            default:
                printf("\nOpção inválida! Por favor, escolha uma opção entre 0 e 5.\n");
                continue; // Volta para o início do loop
        }

        // Exibir resultado da comparação (apenas para opções válidas de 1-5)
        if (opcao >= 1 && opcao <= 5) {
            printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
            printf("Atributo escolhido: %s\n", atributo);
            printf("%s: %.2f\n", cidade1, valor1);
            printf("%s: %.2f\n", cidade2, valor2);
            
            // Lógica de decisão aninhada para determinar o vencedor
            if (resultado == 1) {
                printf("\n🏆 VENCEDOR: %s\n", cidade1);
                printf("Parabéns! A carta de %s venceu!\n", cidade1);
            } 
            else if (resultado == 2) {
                printf("\n🏆 VENCEDOR: %s\n", cidade2);
                printf("Parabéns! A carta de %s venceu!\n", cidade2);
            } 
            else {
                printf("\n🤝 EMPATE!\n");
                printf("As duas cartas têm o mesmo valor no atributo %s!\n", atributo);
            }

            // Informação adicional sobre a regra usada
            if (opcao == 5) {
                printf("\n💡 Regra especial: Para Densidade Demográfica, vence a carta com MENOR valor.\n");
            } else {
                printf("\n💡 Regra padrão: Para este atributo, vence a carta com MAIOR valor.\n");
            }
        }

    } while (opcao != 0);

    return 0;
}