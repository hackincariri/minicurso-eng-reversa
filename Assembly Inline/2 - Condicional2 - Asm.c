#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <senha>\n", argv[0]);
        return 1;
    }

    const char *senha_correta = "senha123";

    int resultado;
    asm volatile(
        "mov edi, %1;"          // Endereço da senha fornecida como argumento
        "mov esi, %2;"          // Endereço da senha correta
        "xor ecx, ecx;"         // Inicializa o registrador ECX com zero (será usado como contador)
        "comparar_loop:"
        "movzx eax, byte ptr [edi];" // Carrega o próximo byte de EDI em EAX
        "cmp al, 0;"            // Compara o byte com zero (verifica o término da string)
        "je senha_correta;"     // Se sim, salta para a etiqueta senha_correta
        "cmp al, [esi];"        // Compara AL (byte da senha fornecida) com o byte em ESI (senha correta)
        "jne senha_incorreta;"  // Se não são iguais, salta para a etiqueta senha_incorreta
        "inc ecx;"              // Incrementa o contador
        "inc edi;"              // Incrementa o ponteiro da senha fornecida
        "inc esi;"              // Incrementa o ponteiro da senha correta
        "jmp comparar_loop;"    // Continua o loop

        "senha_incorreta:"
        "mov %0, 1;"            // Define o resultado como 1 (senha incorreta)
        "jmp fim_comparacao;"   // Salta para o final

        "senha_correta:"
        "mov %0, 0;"            // Define o resultado como 0 (senha correta)

        "fim_comparacao:"
        : "=r"(resultado)
        : "r"(argv[1]), "r"(senha_correta)
        : "eax", "edi", "esi", "ecx", "cc"
    );

    if (resultado == 0) {
        printf("Senha correta! Logado.\n");
    } else {
        printf("Senha incorreta! Tente novamente.\n");
    }

    return 0;
}
