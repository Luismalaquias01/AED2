#ifndef SIMPLELIST_H //evita multiplas inclusões 
#define SIMPLELIST_H

#define MAX 100
const int   G = 0;

struct aluno{
    int matricula; 
    char nome[30];
    float n1, n2, n3;
};
typedef struct lista Lista;
struct aluno dados_aluno;

Lista* cria_lista();

int tamanho_lista(Lista *li);

int lista_cheia(Lista *li);

int lista_vazia(Lista *li);

int insere_lista_final(Lista *li, struct aluno al);

int insere_lista_inicio(Lista *li, struct aluno al);

int insere_lista_ordenada(Lista *li, struct aluno al);

int remove_lista_inicio(Lista *li);

int remove_lista_final(Lista *li);

int remove_lista(Lista *li, int mat);





void libera_lista(Lista *li);



#endif //Sempre que abrir o ifndef eu preciso fechar com o endif 