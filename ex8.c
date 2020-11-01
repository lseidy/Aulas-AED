#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void funcao(char* linha){
    int i=0, n=-1;
    char novo[n];

    for(i=0;i<strlen(linha);i++){
        if(linha[i] != ' '){
            n++;
            novo[n] = linha[i];
       }
        if(linha[i] == ' ' && linha[i-1] != ' '){
            if(i == strlen(linha)-1){
                break;
            }else{
                n++;
                novo[n] = '\n';
            }
        }
    }
    n++;
    novo[n] = '\0';
    printf("%s", novo);
}

int main(){
    char linha[80];
    do{
        printf("digita uma frase ai: ");
        fgets(linha,80,stdin);
    }while(strlen(linha)>80);

    funcao(linha);
    return 0;
}