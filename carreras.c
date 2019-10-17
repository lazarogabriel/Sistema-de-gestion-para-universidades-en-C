#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones_procedimientos.h"
#include "carreras.h"


struct EstructuraCarrera{
    char nombre[120];
    char titulo[120];
    char codigo_depto[7];
    char codigo_carrera[3];
    int cant_materias;
};

Carrera constructorCarrera(char nombre[120], char titulo[120],char codigo_depto[7], char codigo_carrera[3]){
    Carrera c= malloc(sizeof(struct EstructuraCarrera));

    strcpy(c->nombre,nombre);
    strcpy(c->titulo,titulo);
    strcpy(c->codigo_depto, codigo_depto);
    strcpy(c->codigo_carrera, codigo_carrera);
    c->cant_materias= 0;
    return c;
}
Carrera fConstructorCarrera(char fcontent[], char delimitador){
   Carrera c = malloc(sizeof(struct EstructuraCarrera));

    int i;
    int tope=strlen(fcontent);
    int cont=0;
    int posic=0;
    char nombre[121] = " ";
    char titulo[121] = " ";
    char codigo_depto[7] = " ";
    char codigo_carrera[3] = " ";
    char cant_materias[3] = " ";

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
                    titulo[posic] = fcontent[i];
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
                    cant_materias[posic] = fcontent[i];
                    posic++;
                }else{
                    posic = 0;
                    cont++;
                }
            break;
        }

    }

    strcpy(c->nombre, nombre);
    strcpy(c->titulo, titulo);
    strcpy(c->codigo_depto, codigo_depto);
    strcpy(c->codigo_carrera, codigo_carrera);
    c->cant_materias = atoi(cant_materias);

    return c;
}

Carrera constructCarreraTeclado(){
    Carrera c = malloc(sizeof(struct EstructuraCarrera));
    c->cant_materias=0;

    printf("\n  Ingrese el nombre de la carrera: ");
    escaneaCadena(c->nombre, 120);

    printf("\n  Ingrese el titulo que corresponde a la carrera: ");
    escaneaCadena(c->titulo, 120);

    printf("\n  Ingrese el codigo de departamento: ");
    escaneaCadena(c->codigo_depto, 6);
    printf("\n  Ingrese el codigo de carrera: ");
    escaneaCadena(c->codigo_carrera, 2);

    printf("\n  Cuantas materias desea cargar (minimo una): \n");
    while(c->cant_materias < 1){
        c->cant_materias = escaneaEntero(c->cant_materias);
    }

    return c;
}

void destructorCarrera(Carrera c){
    free(c);
}


//GETTERS-----------------------------------------------------------------------------------
char * getNombreCarrera(Carrera c){
    return c->nombre;
}
char * getTituloCarrera(Carrera c){
    return c->titulo;
}
char * getCodigoDeptoCarrera(Carrera c){
    return c->codigo_depto;
}
char * getCodigoCarreraCarrera(Carrera c){
    return c->codigo_carrera;
}
int getCantidadMaterias(Carrera c){
    return c->cant_materias;
}


//SETTERS-------------------------------------------------------------------------------------
void setNombreCarrra(Carrera c, char newName[120]){
    strcpy(c->nombre, newName);
}
void setTituloCarrra(Carrera c, char newTitulo[120]){
    strcpy(c->titulo, newTitulo);
}
void setCodigoCarreraCarrera(Carrera c, char newCodigo_carrera[2]){
    strcpy(c->codigo_carrera, newCodigo_carrera);
}
void setCodigoDeptoCarrera(Carrera c, char newCodigo_depto[6]){
    strcpy(c->codigo_depto, newCodigo_depto);
}

//MOSTRAR CARRERA--------------------------------------------------------------------------------
void mostrarCarrera(Carrera c){
    printf("Carrera: %s", c->nombre);
    printf("\nTitulo: %s", c->titulo);
    printf("\nCodigo de carrera: %s", c->codigo_carrera);
    printf("\nCodigo de departamento: %s", c->codigo_depto);
    printf("\nCantidad de materias: %d", c->cant_materias);

}
