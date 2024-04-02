#include <stdio.h>

int main() {
    printf("\033[1;31m"); // Cor vermelha e negrito
    printf("H");
    printf("\033[1;32m"); // Cor verde e negrito
    printf("e");
    printf("\033[1;33m"); // Cor amarela e negrito
    printf("l");
    printf("\033[1;34m"); // Cor azul e negrito
    printf("l");
    printf("\033[1;35m"); // Cor magenta e negrito
    printf("o");
    printf("\033[1;36m"); // Cor ciano e negrito
    printf(" ");
    printf("\033[1;37m"); // Cor branca e negrito
    printf("W");
    printf("\033[1;31m"); // Cor vermelha e negrito
    printf("o");
    printf("\033[1;32m"); // Cor verde e negrito
    printf("r");
    printf("\033[1;33m"); // Cor amarela e negrito
    printf("l");
    printf("\033[1;34m"); // Cor azul e negrito
    printf("d");
    printf("\033[0m");    // Restaura a cor padrão
    printf("\n");
    return 0;
}
