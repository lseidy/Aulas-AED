#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "AEDHeader.h"

void limpa(){ //pra nao ficar limpando toda hora
    system("cls");
}
void menu(int *op){
    char aux;
    
    //printa o menu e limpa tela sempre que chamar a funcao
    
    do{ // laco pra ficar repetindo o processo
        limpa();

        printf("|____________MENU_____________|\n");
        printf("|1- Adicionar nome            |\n");
        printf("|2- Remover nome              |\n");
        printf("|3 - Listar agenda            |\n");
        printf("\n Digite Enter para sair . . . ");
        fflush(stdin);
        aux = getch();
        fflush(stdin);

        if(aux == '\r'){ // testa se o usuario fechou o programa
            *op = '\r';
            return;
        }else{
            *op= aux - '0'; // modifica o valor de op -'0'para tirar o char
            
            if(*op>3 || *op<1){ // se digitar um valor invalido ele pede pra digitar certo
                limpa();
                printf("Digite um valor Valido\n");
                system("pause");
            }
            return;
        }
        
    }while(aux != '\r'); //parada
}
char* addnome(char *agenda, int *tam, int *i ){
    char novonome[50]; int posicao=0;
    
    do{
        limpa();
        printf("Digite o novo nome: ");
        fflush(stdin);
        fgets(novonome, 50, stdin); //fgets le até o \n do final da frase
        if(strlen(novonome)>=49 || novonome[0] == '\n'){
            printf("Nome muito comprido, ou invalido, digite novamente\n");
            system("pause");
        }
    }while(strlen(novonome)>=49|| novonome[0] == '\n');

    limpa();
    *tam = *tam + strlen(novonome);

    if(*i==0){
        agenda = malloc(*tam*sizeof(char));
        strcpy(agenda,novonome); // recebe o novo nome inclusive o \n do final
        *i=*i+1; 
        agenda[*tam] = '\0'; //coloca o \0 no final pro cod entender que ali é o ultimo caracter
        return agenda;
    }else{
        posicao = strlen(agenda); //pega a o tamanho da agenda até agora
        agenda =  realloc(agenda, *tam*sizeof(char)); //realoca o tamanho da agenda
        strcpy(agenda+posicao,novonome); 
        agenda[*tam]='\0'; //bota \0 no final pra entender que ali acaba
        *i=*i+1;
        return agenda;
    }    
}
void listar(char *agenda){
    int aux, in=0;
    limpa();

    for(aux=0;agenda[aux] != '\0' ;aux++){
       if(aux==0 || agenda[aux-1] == '\n'){ //printa o numero da palavra no comeco e depois de cada \n
            printf("%d - ", in);
            in++;
       }
        printf("%c", agenda[aux]);
    
    }
    system("pause");
}
char* apaga(char *agenda, int *tam, int *i){
    int qtdnome=0, remover;

    limpa();
    
    do{ //impede erros
        limpa();
        printf("Digite o numero do nome a ser removido (confira a lista antes): ");
        scanf("%i", &remover);
        fflush(stdin);
        if(remover> *i || remover < 0){
            printf("\nDigito incorreto, digite um valor valido\n");
            system("pause");
        }
    } while(remover > *i || remover < 0);

    int n, m=0;
    for(n=0;agenda[n] != '\0'; n++) //esse for percorre a agenda para contar as palavras nos if
    {
        if(agenda[n-1] == '\n' && n > 0){ // descobre se uma palavra foi contada
            qtdnome++;
        } 
        if(qtdnome==remover){ //se o contador de palavras for o mesmo do digito de remocao ele entra
            if(agenda[n] == '\n'){ 
                agenda[n-m] = agenda[n+1]; //se encontrou o \n significa que a palavra pra remover acabou
            }else{
                agenda[n-m] = agenda[n]; //o primeiro caracter da palavra a ser removida vai sendo jogando pra frente
                m++; // vai contando pra ver o tamanho da palavra que vai ser removida
            }
        } 
        if(qtdnome> remover){
            agenda[n-m] = agenda[n+1]; //ignora o periodo entre n e m (ou seja a palavra)

        }
    }
    *i=*i-1;
    agenda = realloc(agenda,*tam*sizeof(char));
    return agenda;
}