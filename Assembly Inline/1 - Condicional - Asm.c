#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int numeroAleatorio = rand() % 100 + 1;

    printf("Numero aleatorio gerado: %d\n", numeroAleatorio);

    int paridade;
    asm volatile("mov eax, %1;"
        "test eax, 1;"
        "jz par_label;"
        "mov %0, 0;"
        "jmp fim_label;"
        "par_label: mov %0, 1;"
        "fim_label:"
        : "=r"(paridade)
        : "r"(numeroAleatorio)
        : "eax");

    if (paridade) {
        printf("O numero gerado e par.\n");
    } else {
        printf("O numero gerado e impar.\n");
    }

    return 0;
}
