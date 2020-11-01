/* 
a) a funcao leva um inteiro n e aplica ele como condicao ao for
e com isso atualiza o valor de j; j=J+i;
b) 100
*/


//C
#include <stdio.h>
#include <stdlib.h>
int F1 ( unsigned int n)
{
//     if(n==0) return n;
//     int i , j;
//     for ( i = j = 1; i<2 *n-1 ; i+=2, j +=i);
//     return j;
    if(n==0) return n;
    int i,k,j=1;
    for(i=3;i<=2*n-1;i+=2){
        for(k=1; k<=i;k++){
            j++;
            printf("%d|%d: %d\n", i, k, j);
        }
    }
    return j;
}

int main(){
    int j;

    j = F1(10);
    printf("%d", j);
    return 0;
}