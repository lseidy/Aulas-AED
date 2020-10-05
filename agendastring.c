#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "AEDHeader.h"

int main(){
    int op;
    
    do{
        menu(&op);

    }while(op != '\r');


    return 0;
}