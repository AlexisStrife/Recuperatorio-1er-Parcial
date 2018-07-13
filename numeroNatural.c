#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "numeroNatural.h"
#include "input.h"

void inicializarNum(numeroNatural num[], int cantidad){
    int i;

    for(i=0; i<cantidad; i++){
        num[i].estado = 0;
        num[i].par = 0;
        num[i].impar = 0;
        num[i].primo = 0;
    }
}

int obtenerEspacioLibreNum(numeroNatural num[], int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(num[i].estado == 0)
        {
            return i;
        }
    }
    return -1;
}

void altaNum(numeroNatural num[], int cantidad){
    int i;
    int validoNum, validoNom;
    system("cls");
    printf("---Alta de Numero---\n\n");
    i = obtenerEspacioLibreNum(num, cantidad);
    if(i == -1)
    {
        printf("No hay espacio libre para dar de alta.\n");
    }
    else
    {
        do{
            validoNum = getInt(&num[i].numero,"Numero Natural: ","Rango valido [1 - 99999]",1,99999);
        }
        while(validoNum == -1);
        do{
            validoNom = getString(num[i].nombre,"Nombre del Numero: ","Maximo 50 caracteres",1,50);
        }
        while(validoNom == -1);
        num[i].estado = 1;
    }
    printf("\n");
}

int buscarPorNumero(numeroNatural num[], int cantidad, int numero)
{
    int indice = -1;
    int i;

    for(i=0; i < cantidad; i++)
    {
        if(num[i].estado == 1 && num[i].numero == numero)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarNumero(numeroNatural num)
{
    printf("\nNumero: %d   Nombre: %s \n", num.numero, num.nombre);
}

void bajaNum(numeroNatural num[], int cantidad)
{
    int numero;
    int esta;
    char confirma;

    system("cls");
    printf("---Baja Numero---\n\n");
    printf("Ingrese Numero: ");
    scanf("%d", &numero);

    esta = buscarPorNumero(num, cantidad, numero);

    if(esta == -1)
    {
        printf("\nEl Numero %d no se encuentra en el sistema\n\n", numero);
    }
    else
    {
        mostrarNumero(num[esta]);

        do{
            printf("\nConfirma baja? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's'){
            num[esta].estado = 0;
            printf("\nSe ha realizado la baja\n\n");
        }
        else{
            printf("\nSe ha cancelado la baja\n\n");
        }
    }
}

void modificarNum(numeroNatural num[], int cantidad)
{
    int numero;
    int esta, validoNum, validoNom;

    system("cls");
    printf("---Modificar Numero---\n\n");

    printf("Ingrese Numero: ");
    scanf("%d", &numero);

    esta = buscarPorNumero(num, cantidad, numero);

    if(esta == -1)
    {
        printf("\nEl Numero %d no se encuentra en el sistema\n\n", numero);
    }
    else
    {
        mostrarNumero(num[esta]);
        printf("\n---Nuevos datos---\n");

        do{
            validoNum = getInt(&num[esta].numero,"Nuevo Numero: ","Rango valido [1 - 99999]",1,99999);
        }
        while(validoNum == -1);

        do{
            validoNom = getString(num[esta].nombre,"Nuevo Nombre del Numero: ","Maximo 50 caracteres",1,50);
        }
        while(validoNom == -1);
    }
    printf("\n");
}

void calculaDatos(numeroNatural num[], int cantidad)
{
    int i, j, contador;
    int validoNum, validoNom;
    system("cls");
    printf("---Datos faltantes calculados---\n");
    i = obtenerEspacioLibreNum(num, cantidad);
    if(i == 0)
    {
        printf("No hay numeros para calcular.\n");
    }
    else
    {
        for (i=0; i<cantidad; i++){
            if(num[i].estado == 1){
                if(num[i].numero % 2 == 0){
                    num[i].par = 1;
                    num[i].impar = 0;
                }
                else
                {
                    num[i].par = 0;
                    num[i].impar = 1;
                }
                contador = 0;
                for(j=1;j<=num[i].numero;j++)
                {
                    if(num[i].numero%j==0){
                        contador++;
                    }
                }
                if(contador==2)
                {
                    num[i].primo = 1;
                }
                else
                {
                    num[i].primo = 0;
                }
            }
        }
    }
    printf("\n");
}

void informar(numeroNatural num[], int cantidad)
{
    int i, hayDatos = 0;
    system("cls");
    for(i = 0; i < cantidad; i++)
    {
        if(num[i].estado == 1)
        {
            hayDatos = 1;
            break;
        }
    }
    if(hayDatos == 1)
    {
        printf("---Informes---\n\n");
        int cantCeros = 0, cantPar = 0, cantImp = 0, cantPri = 0;
        for (i=0; i<cantidad; i++){
            if(num[i].estado == 1){
                if(num[i].numero == 0){
                    cantCeros++;
                }
                if(num[i].par == 1){
                    cantPar++;
                }
                if(num[i].impar == 1){
                    cantImp++;
                }
                if(num[i].primo == 1){
                    cantPri++;
                }
            }
        }
        printf("La cantidad de ceros es: %d\n", cantCeros);
        printf("La cantidad de numeros pares es: %d\n", cantPar);
        printf("La cantidad de numeros impares es: %d\n", cantImp);
        printf("La cantidad de numeros primos es: %d\n\n", cantPri);
    }
}

void hardCodeNum(numeroNatural num[], int cantidad)
{
    num[0].numero = 3;
    strcpy(num[0].nombre, "Tres");
    num[0].estado = 1;

    num[1].numero = 7;
    strcpy(num[1].nombre, "Siete");
    num[1].estado = 1;

    num[2].numero = 4;
    strcpy(num[2].nombre, "Cuatro");
    num[2].estado = 1;

    num[3].numero = 12;
    strcpy(num[3].nombre, "Doce");
    num[3].estado = 1;

}
