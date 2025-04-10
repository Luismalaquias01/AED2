#ifndef CARDAPIO_H
#define CARDAPIO_H

//Definição opaca da estrutura 
typedef struct Cardapio Cardapio; //Declaro o novo apelido da minha struct 

//Função para manipular o cardápio 
Cardapio* criarCardapio();
void adicionarItem(Cardapio* cardapio, int id, char nome[], float preco);
void removerItem(Cardapio* cardapio, char nome[]);
void listarCardapio(Cardapio* cardapio);
void liberarCardapio(Cardapio* cardapio);
char* cardapio_obter_nome(Cardapio* cardapio, int id);
float cardapio_obter_preco(Cardapio* cardapio, int id);
void cardapio_destruir(Cardapio* cardapio);

#endif