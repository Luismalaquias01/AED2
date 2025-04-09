#include <stdio.h>

// Definição da estrutura
struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    struct Pessoa p1 = {"Ana", 30, 1.65};
    struct Pessoa *ptr = &p1;  // Ponteiro para a estrutura

    printf("Nome: %s\n", ptr->nome);  // Usamos "->" para acessar os campos
    printf("Idade: %d\n", ptr->idade);
    printf("Altura: %.2f\n", ptr->altura);

    // Modificando valores via ponteiro
    ptr->idade = 31;

    printf("\nApós modificação:\n");
    printf("Idade: %d\n", p1.idade);

    return 0;
}
