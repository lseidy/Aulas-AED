#include <stdio.h>
#include <stdlib.h>

char *Teste (char *s1, const char *s2) {
    char *aux=s1;
    while (*s1) s1++;
    for ( ; (*s1 = *s2) != '\0' ; s1++, s2++);
    return aux;
}

int main(){
    char *s1, *s2;
    s1 = (char*) malloc(4*sizeof(char));
    s2 = (char*) malloc(4*sizeof(char));
    s1 = "bola";
    s2 = "casa";
    


    return 0;
}