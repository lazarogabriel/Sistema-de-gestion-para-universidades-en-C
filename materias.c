#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones_procedimientos.h"

#include "materias.h"

struct EstructuraMateria{
    char nombre[121];
    char codigo_materia[7];
    char codigo_depto[7];
    char codigo_carrera[3];
    int cant_integrantes;
};

Materia constructorMateria(char nombre[120],char codigo_materia[6],char codigo_depto[6],char codigo_carrera[2]){

    Materia m = malloc(sizeof(struct EstructuraMateria));

    strcpy(m->nombre, nombre);
    strcpy(m->codigo_carrera, codigo_carrera);
    strcpy(m->codigo_depto, codigo_depto);
    strcpy(m->codigo_materia, codigo_materia);
    m->cant_integrantes = 0;

    return m;
}

Materia constructMateriaTeclado(){
   Materia m = malloc(sizeof(struct EstructuraMateria));

    m->cant_integrantes = 0;
    printf("\n  Ingrese el nombre de la materia: ");
    escaneaCadena(m->nombre, 120);

    printf("\n  Ingrese el codigo de materia: ");
    escaneaCadena(m->codigo_materia, 6);
    printf("\n  Ingrese el codigo de departamento: ");
    escaneaCadena(m->codigo_depto, 6);
    printf("\n  Ingrese el codigo de carrea: ");
    escaneaCadena(m->codigo_carrera, 2);

    printf("\n\n  Cuantos integrantes desea cargar (minimo uno): \n");
    while(m->cant_integrantes < 1){
        m->cant_integrantes = escaneaEntero(m->cant_integrantes);
    }
    return m;
}
Materia fConstructorMateria(char fcontent[], char delimitador){
    Materia m = malloc(sizeof(struct EstructuraMateria));

    int i;
    int tope=strlen(fcontent);
    int cont=0;
    int posic=0;
    char nombre[121] = " ";
    char codigo_depto[7] = " ";
    char codigo_materia[7] = " ";
    char codigo_carrera[3] = " ";
    char cant_integrantes[5] = " ";

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
                    codigo_materia[posic] = fcontent[i];
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
                    codigo_carrera[posic] = fcontent[i];
                    posic++;
                }else{
                    posic = 0;
                    cont++;
                }
            break;
            case 4:
                if(fcontent[i] != delimitador){
                    cant_integrantes[posic] = fcontent[i];
                    posic++;
                }else{
                    posic = 0;
                    cont++;
                }
            break;
        }

    }

    strcpy(m->nombre, nombre);
    strcpy(m->codigo_materia, codigo_materia);
    strcpy(m->codigo_depto, codigo_depto);
    strcpy(m->codigo_carrera, codigo_carrera);
    m->cant_integrantes= atoi(cant_integrantes);

    return m;
}

void destructorMateria(Materia m){
    free(m);
}

//GETTERS---------------------------------------------------------------------------------
char * getNombreMateria(Materia m){
    return m->nombre;
}
char * getCodigoDeptoMateria(Materia m){
    return m->codigo_depto;
}
char * getCodigoMeteriaMateria(Materia m){
    return m->codigo_materia;
}
char * getCodigoCarreraMateria(Materia m){
    return m->codigo_carrera;
}
int getCantidadIntegrantes(Materia m){
    return m->cant_integrantes;
}


//SETTERS----------------------------------------------------------------------------------
void setNombreMateria(Materia m, char newName[120]){
    strcpy(m->nombre, newName);
}
void setCodigoMateriaMateria(Materia m, char newCodigo_materia[6]){
    strcpy(m->nombre, newCodigo_materia);
}
void setCodigoCarreraMateria(Materia m, char newCodigo_carrera[2]){
    strcpy(m->codigo_carrera, newCodigo_carrera);
}
void setCodigoDeptoMateria(Materia m, char newCodigo_depto[6]){
    strcpy(m->codigo_depto, newCodigo_depto);
}


//MOSTRAR MATERIA------------------------------------------------------------------------
void mostrarMateria(Materia m){
    printf("Materia: %s", m->nombre);
    printf("\nCodigo materia: %s", m->codigo_materia);
    printf("\nCodigo carrera: %s", m->codigo_carrera);
    printf("\nCodigo departamento: %s", m->codigo_depto);
    printf("\nCantidad de integrantes: %d", m->cant_integrantes);
}
