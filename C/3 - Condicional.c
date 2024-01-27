#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int numeroAleatorio = rand() % 100 + 1;

    printf("Numero aleatorio gerado: %d\n", numeroAleatorio);

    if (numeroAleatorio % 2 == 0) {
        printf("O numero gerado e par.\n");
    } else {
        printf("O numero gerado e impar.\n");
    }

    return 0;
}
