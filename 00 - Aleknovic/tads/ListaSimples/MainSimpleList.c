#include "SimpleList.c"
#include <stdio.h> 

int main(){
    //Para começar a trabalhar com esse código, precisaremos inserir um menu para que possamos saber o que queremos fazer 
    //Depois de inserir o menu, ir manipulando as funções e os códigos para que possamos inserir alunos, talvez precisemos usar o for para inserir esses
    //alunos dentro da struct sempre usando  -> e ponteiros. Seria uma boa também criar a função para começar a criar os al(aluno novo)
    Lista *li;
    int mat;
    li = cria_lista();

    int x = tamanho_lista(li);
    printf("%d\n", x);

    int y = lista_cheia(li);
    printf("%d\n", y);

    int z = lista_vazia(li); //retorna -1 se a lista não existir e 1 se estiver vazia
    printf("%d\n", z); 

    int w = insere_lista_final(li, dados_aluno);
    printf("%d\n", w); 

    int a = insere_lista_inicio(li, dados_aluno);
    printf("%d\n", a); 

    int b = insere_lista_ordenada(li, dados_aluno);
    printf("%d\n", b); 

    int c = remove_lista_final(li);
    printf("%d\n", c); 

    int d = remove_lista_inicio(li);
    printf("%d\n", d); 

    int e = remove_lista(li, matricula_aluno);
    printf("%d\n", e);






    libera_lista(li);
}