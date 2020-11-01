#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void comparador(float *vet, int cont){
    int n=0, m=1, i=1;
    float *novo = (float*) malloc(1*sizeof(float));

    if(cont>0){
        novo[0] = vet[0]; // o valor 0 nao precisa testar
    }
    while(m<cont){ //passa m
        for(n=0; n<m;n++){ // inicia um for de 0 até o valor atual de m
            if(vet[m] == vet[n]){ // compara o vetor de m com todos os outros até entao
                break;
            }else{
                if(n==m-1){ // se passou por todos e nao achou um repetido ele coloca no novo vetor
                    i++;
                    printf("%d\n", i);
                    novo = (float*) realloc(novo, i*sizeof(float));
                    novo[i-1] = vet[m];
                }
            }
        }
        m++;
    }
    m=0;
    while(m<i){
        printf("\n num %d-> %.2f", m, novo[m]);
        m++;
    }

    free(novo);
}

int main(){
    float *n = (float*) malloc(1*sizeof(float));
    int cont=0;
    n[0]= '\0';
    
    while(1){
        printf("Digite enter para sair e qualquer coisa pra continuar");
        
        if(getch() == '\r'){
            break;
        }

        cont++;
        n =(float*) realloc(n, cont*sizeof(float));
        printf("\nDigite um valor decimal: ");
        scanf("%f", &n[cont-1]);
    }
    comparador(n, cont);
    free(n);
    printf("\n----Programa Encerrado----");
    return 0;
}
