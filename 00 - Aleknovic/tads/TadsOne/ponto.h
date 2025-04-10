#ifndef Ponto_H //evita multiplas inclusões 
#define Ponto_H 

typedef struct Ponto Ponto; //estrutura opaca (não revela detalhes importantes)
  
//função do tad
Ponto* criarPonto(float x, float y);
void destruirPonto(Ponto* p);
void moverPont(Ponto* p, float dx, float dy);
void exibirPonto(Ponto* p);


#endif //Sempre que abrir o ifndef eu preciso fechar com o endif 