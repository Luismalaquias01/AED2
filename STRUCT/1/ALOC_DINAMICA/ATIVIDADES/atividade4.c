#include <stdio.h>
#include <stdlib.h>

int main (){
    char *ptr;

    ptr = (char *) malloc(50*sizeof(char));

    printf("Digite uma frase: \n");
    fgets(ptr,50, stdin);
    fflush(stdin);

    printf("%s", ptr);

    free(ptr);
    return 0;
}