#include <stdio.h>
int main(){
int array[5] = {10, 20, 30, 40, 50};
int *p; 
p = &array[2]; // p agora aponta para o endereço do terceiro elemento do array

printf("Valor de array[2]: %d\n", *p); // Mostra 30
printf("Endereço de p: %p\n", p);   // Mostra o endereço hexadecimal de p
}