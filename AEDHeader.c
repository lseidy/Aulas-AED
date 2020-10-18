#include "AEDHeader.h"

void limpa(){ //pra nao ficar limpando toda hora
    system("cls");
}
int menu(){
    char aux;
    int op;
    //printa o menu e limpa tela sempre que chamar a funcao
    
    limpa();

    printf("|____________MENU_____________|\n");
    printf("|1- Adicionar nome            |\n");
    printf("|2- Remover nome              |\n");
    printf("|3 - Listar agenda            |\n");
    printf("\n Digite Enter para sair . . . ");
    fflush(stdin);
    aux = getchar();
    op = aux - '0';

    if(aux == '\n'){ // testa se o usuario fechou o programa
        return 0;
    }else{       
       if(op>3 || op<1){ // se digitar um valor invalido ele pede pra digitar certo
            limpa();
            printf("Digite um valor Valido\n");
            system("pause");
        }
        return op;
    }
        
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
    *tam = *tam + strlen(novonome) + 1;

    posicao = strlen(agenda); //pega a o tamanho da agenda até agora
    agenda = (char*) realloc(agenda, *tam*sizeof(char)); //realoca o tamanho da agenda
    strcpy(agenda+posicao,novonome);
    //strcat(agenda,novonome); 
    agenda[*tam-1]='\0'; //bota \0 no final pra entender que ali acaba
    *i=*i+1;
    return agenda;    
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
    int qtdnome=0, remover=0;

    limpa();
    
    do{ //impede erros
        limpa();
        printf("Digite o numero do nome a ser removido (confira a lista antes): ");
        scanf("%i", &remover);
        if(strlen(agenda) < 1){
            return agenda;
        }
        if(remover > *i || remover < 0){
            printf("\nDigito incorreto, digite um valor valido\n");
            system("pause");
            break;
        }
    } while(remover > *i || remover < 0);

    int n=0, m=0;
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
        if(qtdnome > remover){
            agenda[n-m] = agenda[n+1]; //ignora o periodo entre n e m (ou seja a palavra)

        }
    }
    *i=*i-1;
    *tam = *tam-m;
    agenda =(char*) realloc(agenda,*tam*sizeof(char));
    agenda[*tam-1] = '\0';
    return agenda;
}