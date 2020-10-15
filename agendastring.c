#include "AEDHeader.h"

/*
    ********************ATENDCAO**************
    *PARA COMPILAR NO VS CODE, COLOQUE OS ARQUIVOS NA MESMA PASTA E DIGITE NO TERMINAL
    gcc agendastring.c AEDHeader.c -o agenda    (ou nome que vc quiser)
    
    *DEPOIS ABRA O EXECUTAVEL COM
    cmd /c .\"agenda.exe"    (ou nome que vc digitou)

*/
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