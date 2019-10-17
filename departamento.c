#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones_procedimientos.h"

#include "departamento.h"

 struct EstructuraDepartamento{
    char nombre[120];
    char descripcion[300];
    char codigo_depto[6];
    int cant_carreras;

};

Departamento constructorDepartamento(char nombre[120], char descripcion[300], char codigo_depto[6]){
   Departamento depto = malloc(sizeof(struct EstructuraDepartamento));

    strcpy(depto->nombre, nombre);
    strcpy(depto->descripcion, descripcion);
    strcpy(depto->codigo_depto, codigo_depto);
    depto->cant_carreras=0;

    return depto;
}

Departamento constructDeptosTeclado(){
    Departamento depto = malloc(sizeof(struct EstructuraDepartamento));

    depto->cant_carreras=0;

    printf("\n Ingrese el nombre del departamento: ");
    escaneaCadena(depto->nombre, 120);

    printf("\n Ingrese la descripcion del departamento %s: ", depto->nombre);
    escaneaCadena(depto->descripcion, 300);

    printf("\n Ingrese el codigo del departamento: ");
    escaneaCadena(depto->codigo_depto, 6);

    printf("\n Ingrese la cantidad de carreras que tiene este departamnto (minimo una): \n");
    while(depto->cant_carreras< 1){
        depto->cant_carreras= escaneaEntero(depto->cant_carreras);
    }

    return depto;
}

Departamento fConstructorDepartamentos(char fcontent[], char delimitador){

    Departamento d = malloc(sizeof(struct EstructuraDepartamento));

    int i;
    int tope=strlen(fcontent);
    int cont=0;
    int posic=0;
    char nombre[100]=" ";
    char codigo_depto[7]=" ";
    char descripcion[251]=" ";
    char cant_carreras[3]=" ";

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
                    descripcion[posic] = fcontent[i];
                    posic++;
                }else{
                    posic = 0;
                    cont++;
                }
            break;
            case 2:
                if(fcontent[i] != delimitador){
                    codigo_depto[posic] = fcontent[i];
                    posic++;
                }else{
                    posic = 0;
                    cont++;
                }
            break;
            case 3:
                if(fcontent[i] != delimitador){
                    cant_carreras[posic] = fcontent[i];
                    posic++;
                }else{
                    posic = 0;
                    cont++;
                }
            break;
        }

    }

    strcpy(d->nombre, nombre);
    strcpy(d->codigo_depto, codigo_depto);
    strcpy(d->descripcion, descripcion);
    d->cant_carreras = atoi(cant_carreras);

    return d;
}


void destructorDepartamento(Departamento d){
    free(d);
}


//GETTERS----------------------------------------------------------------------------------------
char * getNombeDepartamento(Departamento d){
    return d->nombre;
}
char * getDescripcionDepartamento(Departamento d){
     return d->descripcion;
}
char * getCodigoDepartamento(Departamento d){
    return d->codigo_depto;
}
int getCantCarrerasDepartamento(Departamento d){
     return d->cant_carreras;
}



//SETTERS----------------------------------------------------------------------------------------
void setCodigoDepartamento(Departamento d,char newCodigo_depto[6]){
    strcpy(d->codigo_depto, newCodigo_depto);
}
void setNombreDepartamento(Departamento d, char newName[120]){
    strcpy(d->nombre, newName);
}
void setDescripcionDepartamento(Departamento d,char newDesc[300]){
    strcpy(d->descripcion, newDesc);
}


//MOSTRAR----------------------------------------------------------------------------------------
void mostrarDepartamento(Departamento d){
    printf("\n\n Departamento: %s", d->nombre);
    printf("\n Descripcion: %s", d->descripcion);
    printf("\n Cantidad de carreras: %d", d->cant_carreras);
    printf("\n Codigo: %s", d->codigo_depto);
}
