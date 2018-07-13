#include <stdio.h>
#include <stdlib.h>
#include "numeroNatural.h"
#include "input.h"

#define TAM 10

int main()
{
    char seguir='s';
    char auxOpcion[2];
    int opcion=0;
    int validado;
    numeroNatural num[TAM];
    inicializarNum(num, TAM);
    hardCodeNum(num, TAM);

    while(seguir=='s')
    {
        menu();
        do
        {
            fflush(stdin);
            scanf("%s", auxOpcion);
            validado = validaNumero(auxOpcion);
        }
        while(validado == 0);

        opcion = atoi(auxOpcion);

        switch(opcion)
        {
            case 1:
                altaNum(num, TAM);
                break;
            case 2:
                modificarNum(num, TAM);
                break;
            case 3:
                bajaNum(num, TAM);
                break;
            case 4:
                calculaDatos(num, TAM);
                break;
            case 5:
                informar(num, TAM);
                break;
            case 6:
                seguir = 'n';
                break;
            default:
                system("cls");
                printf("Opcion no valida.\n\n");
        }
    }
    return 0;
}
