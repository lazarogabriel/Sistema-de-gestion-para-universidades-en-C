#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "funciones_procedimientos.h"
#include "universidad.h"


struct EstructuraUniversidad{
    char nombre[45];
    char ubicacion[45];
    char contacto[45];
    int cant_deptos;
};

Universidad constructorUniversidad(char nombre[45], char ubicacion[45], char contacto[45], int cant_deptos){
    Universidad uni = malloc(sizeof(struct EstructuraUniversidad));

   strcpy(uni->nombre, nombre);
   strcpy(uni->ubicacion, ubicacion);
   strcpy(uni->contacto, contacto);
   uni->cant_deptos=cant_deptos;

   return uni;
}

Universidad constructUniversidadTeclado(){

    Universidad u = malloc(sizeof(struct EstructuraUniversidad));

    u->cant_deptos=0;

    printf("\nIngrese el nombre de la universidad: ");
    escaneaCadena(u->nombre, 45);

    printf("\nIngrese la ubicacion de la %s: ", u->nombre);
    escaneaCadena(u->ubicacion, 45);

    printf("\nIngrese el contacto: ");
    escaneaCadena(u->contacto, 45);

    printf("\nCuantos departamentos desea cargar (minimo uno): \n");
    while(u->cant_deptos < 1){
        u->cant_deptos = escaneaEntero(u->cant_deptos);
    }

    return u;
}


Universidad fconstructUniversidad(char fcontent[], char fdelimitador){

    int i;
    int campo=0;
    int posic=0;
    char nombre[100]="";
    char ubicacion[100]="";
    char contacto[100]="";
    char cant_deptos[4]="";

    for(i = 0; i <= strlen(fcontent); i++){
        switch(campo){
            case 0:
                if(fcontent[i] != fdelimitador){
                    nombre[posic] = fcontent[i];
                    posic++;
                }else{
                    posic = 0;
                    campo++;
                }
            break;
            case 1:
                if(fcontent[i] != fdelimitador){
                    ubicacion[posic] = fcontent[i];
                    posic++;
                }else{
                    posic = 0;
                    campo++;
                }
            break;
            case 2:
                if(fcontent[i] != fdelimitador){
                   contacto[posic] = fcontent[i];
                   posic++;
                }else{
                    posic = 0;
                    campo++;
                }
            break;
            case 3:
                if(fcontent[i] != fdelimitador){
                        cant_deptos[posic] = fcontent[i];
                        posic++;
                }else{
                    posic = 0;
                    campo++;
                }
            break;
        }

    }

    return constructorUniversidad(nombre, ubicacion, contacto, atoi(cant_deptos));
}


void destructorUniversidad(Universidad u){
    free(u);
}

void mostrarUniversidad(Universidad u){
    printf("\n Nombre: %s", u->nombre);
    printf("\n Ubicacion: %s", u->ubicacion);
    printf("\n Contacto: %s", u->contacto);
    printf("\n Cantidad de departamentos: %d\n\n", u->cant_deptos);
}


//geters
char * getNombreUniversidad(Universidad u){
    return u->nombre;
}
char * getUbicacionUniversidad(Universidad u){
    return u->ubicacion;
}
char * getContactoUniversidad(Universidad u){
    return u->contacto;
}
int getCantidadDepartamentos(Universidad u){
    return u->cant_deptos;
}

//seters


void setNombreUniversidad(Universidad u, char newName[120]){
   strcpy(u->nombre, newName);
}
void setUbicacionUniversidad(Universidad u, char newUbication[120]){
    strcpy(u->ubicacion, newUbication);
}
void setContactoUniversidad(Universidad u, char newContact[45]){
    strcpy(u->contacto, newContact);
}
