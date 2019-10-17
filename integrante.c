#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "funciones_procedimientos.h"
#include "integrante.h"

struct EstructuraIntegrante{
    char nombre[46];
    char apellido[46];
    char dni[9];
    char TipoIntegrante[10];
    char codigo_depto[7];
    char codigo_carrera[3];
};

Integrante constructorIntegrante(char nombre[46], char apellido[46], char dni[9],char TipoIntegrante[10],char codigo_depto[7], char codigo_carrera[3]){
    Integrante i = malloc(sizeof(struct EstructuraIntegrante));

    strcpy(i->nombre, nombre);
    strcpy(i->apellido, apellido);
    strcpy(i->dni, dni);
    strcpy(i->TipoIntegrante, TipoIntegrante);
    strcpy(i->codigo_carrera, codigo_carrera);
    strcpy(i->codigo_depto, codigo_depto);

    return i;
}

Integrante fConstructorIntegrante(char fcontent[],char  delimitador){
    Integrante integrante = malloc(sizeof(struct EstructuraIntegrante));

    int i;
    int tope=strlen(fcontent);
    int cont=0;
    int posic=0;
    char nombre[46]="";
    char apellido[46]="";
    char dni[9]="";
    char TipoIntegrante[10]=" ";
    char codigo_depto[7]="";
    char codigo_carrera[3]= "";

    for(i = 0; i < tope; i++){

        switch(cont){
            case 0:
                if(fcontent[i] != delimitador){
                    nombre[posic] = fcontent[i];
                    posic++;
                }else{
                    posic = 0;
                    cont++;
                }
            break;
            case 1:
                if(fcontent[i] != delimitador){
                    apellido[posic] = fcontent[i];
                    posic++;
                }else{
                    posic = 0;
                    cont++;
                }
            break;
            case 2:
                if(fcontent[i] != delimitador){
                    dni[posic] = fcontent[i];
                    posic++;
                }else{
                    posic = 0;
                    cont++;
                }
            break;
            case 3:
                if(fcontent[i] != delimitador){
                    TipoIntegrante[posic] = fcontent[i];
                    posic++;
                }else{
                    posic = 0;
                    cont++;
                }
            break;
            case 4:
                if(fcontent[i] != delimitador){
                    codigo_depto[posic] = fcontent[i];
                    posic++;
                }else{
                    posic = 0;
                    cont++;
                }
            break;
            case 5:
                if(fcontent[i] != delimitador){
                    codigo_carrera[posic] = fcontent[i];
                    posic++;
                }else{
                    cont = -1;
                }
            break;
        }
    }

    strcpy(integrante->nombre, nombre);
    strcpy(integrante->apellido, apellido);
    strcpy(integrante->dni, dni);
    strcpy(integrante->TipoIntegrante, TipoIntegrante);
    strcpy(integrante->codigo_depto, codigo_depto);
    strncpy(integrante->codigo_carrera, codigo_carrera,2);
    return integrante;
}

Integrante constructIntegranteTeclado(){
    Integrante i = malloc(sizeof(struct EstructuraIntegrante));

    int opcion;

    printf("\n\n  Ingrese el nombre del integrante: ");
    escaneaCadena(i->nombre, 46);

    printf("\n\n  Ingrese el apellido del integrante: ");
    escaneaCadena(i->apellido, 46);

    printf("\n\n  Ingrese el DNI (solo numeros, sin guiones ni puntos) del integrante: ");
    escaneaCadena(i->dni, 8);

    printf("\n\nIngrese el codigo de la carrera: ");
    escaneaCadena(i->codigo_carrera, 2);

    printf("\n\nIngrese el codigo del departamento: ");
    escaneaCadena(i->codigo_depto, 6);

    printf("\n\n  Es alumno o docente?");
    printf("\n    -Ingrese un 1(uno) si es alumno.");
    printf("\n    -Ingrese un 2(dos) si es docente.");
    printf("\n\n  Opcion: ");
     do{
        opcion = escaneaEntero();

     }while(opcion < 1 && opcion > 2);

    if(opcion){
        strcpy(i->TipoIntegrante, "alumno");
    }else{
        strcpy(i->TipoIntegrante, "docente");
    }

    return i;
}

//DESTRUCTOR --------------------------------------
void destructorIntegrante(Integrante i){
    free(i);
}


//GETTERS---------------------------------------------------------------------------------------
char * getNombreIntegrante(Integrante i){
    return i->nombre;
}
char * getApellidoIntegrante(Integrante i){
    return i->apellido;
}
char * getDniIntegrante(Integrante i){
    return i->dni;
}
char * getTipoIntegranteIntegrante(Integrante i){
    return i->TipoIntegrante;
}
char * getCodigoDeptoIntegrante(Integrante i){
    return i->codigo_depto;
}
char * getCodigoCarreraIntegrante(Integrante i){
    return i->codigo_carrera;
}


//SETTERS-------------------------------------------------------------------------------------
void setNombreIntegrante(Integrante i, char newName[45]){
    strcpy(i->nombre, newName);
}
void setApellidoIntegrante(Integrante i, char newLastName[45]){
    strcpy(i->apellido, newLastName);
}
void setDniIntegrante(Integrante i, char newDni[7]){
    strcpy(i->dni, newDni);
}
void setCodigoDeptoIntegrante(Integrante i, char newCodigoDepto[6]){
    strcpy(i->codigo_depto, newCodigoDepto);
}
void setCodigoCarreraIntegrante(Integrante i, char newCodigoCarrera[2]){
    strcpy(i->codigo_carrera, newCodigoCarrera);
}


//MOSTRAR ----------------------------------------------------------------------------
void mostrarIntegrante(Integrante i){
    printf(" Nombre del %s: %s",i->TipoIntegrante, i->nombre);
    printf("\n Apellido: %s", i->apellido);
    printf("\n DNI: %s",i->dni);
    printf("\n Codigo de departamento: %s", i->codigo_depto);
    printf("\n Codigo de carrera: %s", i->codigo_carrera);

}
