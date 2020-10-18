#include "voidbib.h"
/*
    ********************ATENDCAO**************
    *PARA COMPILAR NO VS CODE, COLOQUE OS ARQUIVOS NA MESMA PASTA E DIGITE NO TERMINAL
    gcc voidex.c voidbib.c -o agenda    (ou nome que vc quiser)
    
    *DEPOIS ABRA O EXECUTAVEL COM
    cmd /c .\"agenda.exe"    (ou nome que vc digitou)

*/

int main(){
    void *pbuffer;
    pbuffer = (varvoid*) malloc(sizeof(varvoid));
    
    pbuffer = iniciar(pbuffer);
    
    do{
        limpa();
        switch(menu(pbuffer)){
            case 1:
                pbuffer = incluir(pbuffer);
            break;
            case 2:
                pbuffer = apagar(pbuffer);
            break;
            case 3:
                buscar(pbuffer);
            break;
            case 4:
                listar(pbuffer);
            break;
            case 5:
                free(pbuffer);
                return 0;
            break;
        }

    }while(1);
    return 0;
}