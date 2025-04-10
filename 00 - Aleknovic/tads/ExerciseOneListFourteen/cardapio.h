#ifndef CARDAPIO_H
#define CARDAPIO_H

//Definição opaca da estrutura 
typedef struct Cardapio Cardapio; //Declaro o novo apelido da minha struct 

//Função para manipular o cardápio 
Cardapio* criarCardapio();
void adicionarItem(Cardapio* cardapio, char nome[], float preco);
void removerItem(Cardapio* cardapio, char nome[]);
void listarCardapio(Cardapio* cardapio);
void liberarCardapio(Cardapio* cardapio);
float buscarPreco(Cardapio* cardapio, char nome[]);

#endif