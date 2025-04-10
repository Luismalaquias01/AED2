#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 2

struct tipo_pessoa{
    int idade;
    float peso;
    char nome[50];
};

typedef struct tipo_pessoa tipo_pessoa;

int main () {

    tipo_pessoa lista[TAM];

    for(int i = 0; i < TAM; i++){
        int c;
        printf("Insira os respectivos dados (%d):\n", i+1);
        printf("Nome: ");
        scanf(" %50[^\n]", lista[i].nome);
        while ((c = getchar()) != '\n' && c != EOF);

        printf("Idade: ");
        scanf("%d", &lista[i].idade);
        while ((c = getchar()) != '\n' && c != EOF);

        printf("Peso: ");
        scanf("%f", &lista[i].peso);
        printf("\n");
        while ((c = getchar()) != '\n' && c != EOF);
    } 

    system("clear");

    printf("Os dados fornecidos foram: \n");
    for(int i = 0; i < TAM; i++){
        printf("Cadastro %d\n", i+1);
        printf("Nome: %s\nIdade: %d\nPeso: %.2f\n", lista[i].nome, lista[i].idade, lista[i].peso);
    }
     
    return 0;

}