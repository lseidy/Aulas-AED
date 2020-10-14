#include "AEDHeader.h"

int main(){
    int op, i=0, tam=0;
    char *agenda;
    
    do{
        menu(&op);

        switch(op){
            case 1:
               agenda = addnome(agenda, &tam, &i);
            break;
            case 2:
               agenda = apaga(agenda, &tam, &i);
            break;
            case 3:
                listar(agenda);
            break;
        }  
    }while(op != '\r');
    
    free(agenda);
    return 0;
}