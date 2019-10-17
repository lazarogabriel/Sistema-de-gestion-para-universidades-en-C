#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones_procedimientos.h"

//PRE: NECESITA; LA DIRECCION DE LA CADENA Y LA CADENA A INGRESAR, Y SU TAMAÑO
//POST: VALIDA SI EL TAMAÑO DE LA CADENA INGRESADA POR STDIN ES MENOR AL TAMAÑO DE CARACTERES INGRESADOS
void escaneaCadena(char *cadena, int tam_cadena){
    char * auxiliar = malloc(sizeof(char)*400);
    fflush(stdin);
    gets(auxiliar);
    while(strlen(auxiliar) > tam_cadena){
        printf("\n\nIngrese maximo %d caracteres: ", tam_cadena);
        fflush(stdin);
        gets(auxiliar);
    }
    strcpy(cadena, auxiliar);
    free(auxiliar);

}

//PRE: NECESITA UN VALOR ENTERO PARA QUE RETORNE...
//POST: RETORNA UN VALOR ENTERO DISTINTO DE CHAR
int escaneaEntero(){
    fflush(stdin);
    int entero;
    while(!scanf("%d", &entero)){
        fflush(stdin);
        printf("Debe ser de tipo numerico, vuelva a ingresar: ");
    }
   return entero;
}

//PRE: TIENE QUE HABER UN ARCHIVO INICIALIZADO Y NO TIENE QUE SER NULO
//POST: RETORNA CANTIDAD DE CARACTERES DE UN ARCHIVO TXT
int fileCantChars(FILE *f){
    int contador=0;
    char c;
    while((c = fgetc(f)) != EOF){
        contador++;
    }
    rewind(f);

    return contador;
}
