#include <stdio.h>

int soma(int a, int b) {
    return a + b;
}

int main() {
    int numero1, numero2;

    printf("Digite o primeiro numero: ");
    scanf("%d", &numero1);

    printf("Digite o segundo numero: ");
    scanf("%d", &numero2);

    int resultado = soma(numero1, numero2);
    printf("A soma de %d e %d eh: %d\n", numero1, numero2, resultado);

    return 0;
}
