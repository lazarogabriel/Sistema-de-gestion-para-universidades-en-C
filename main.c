#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "funciones_procedimientos.h"
#include "universidad.h"
#include "departamento.h"
#include "carreras.h"
#include "materias.h"
#include "integrante.h"
#include "menu.h"

int main(){

   mensajeBinvenida();

   int i;
   int c_deptos=0;
   int c_carreras=0;
   int c_materias=0;
   int c_integrantes=0;
   char delimitador = ';';

//INSTACIA TDA UNIVERSIDAD---------------------------------------------------------------------------
    Universidad u;
    FILE * funiversidad = NULL;

    funiversidad = fopen("universidad.txt", "r");
    if(!funiversidad){
        u = constructUniversidadTeclado();
    }else{
        char fcontent_universidad[250];
        fgets(fcontent_universidad, 250, funiversidad);
        u = fconstructUniversidad(fcontent_universidad, delimitador);
    }
//ICIERRE DE MODULO---------------------------------------------------------------------------


//MODULO QUE INSTANCIA TDAs DE DEPARTAMENTOS---------------------------------------------------------
    c_deptos = getCantidadDepartamentos(u);
    Departamento d[c_deptos];
    FILE * fdepartamentos = NULL;
    fdepartamentos = fopen("departamentos.txt", "r");
    if(!fdepartamentos){
        for(i = 0; i < c_deptos; i++){
            d[i]= constructDeptosTeclado();
            c_carreras = c_carreras+getCantCarrerasDepartamento(d[i]);
        }
    }else{
        char fcontent_deptos[c_deptos][250];
        for(int i = 0; i < c_deptos; i++){
            fgets(fcontent_deptos[i], 250, fdepartamentos);
        }
        fclose(fdepartamentos);
        for(i = 0; i < c_deptos; i++){
            d[i]= fConstructorDepartamentos(fcontent_deptos[i], delimitador);
            c_carreras = c_carreras+getCantCarrerasDepartamento(d[i]);
        }
    }
//CIERRE DE MODULO----------------------------------------------------------------------------------


//MODULO QUE INSTANCIA TDAs DE CARRERAS---------------------------------------------------------
    Carrera c[c_carreras];
    FILE * fcarreras = NULL;
    fcarreras = fopen("carreras.txt", "r");
    if(!fcarreras){
        for(i = 0; i < c_carreras; i++){
            c[i]= constructCarreraTeclado();
            c_materias = c_materias+getCantidadMaterias(c[i]);
        }
    }else{
        char fcontent_carreras[c_carreras][250];
        for(int i = 0; i < c_carreras; i++){
            fgets(fcontent_carreras[i], 250, fcarreras);
        }
        fclose(fcarreras);
        for(i = 0; i < c_carreras; i++){
            c[i]= fConstructorCarrera(fcontent_carreras[i], delimitador);
            c_materias = c_materias+getCantidadMaterias(c[i]);
        }
    }
//CIERRE DE MODULO----------------------------------------------------------------------------------


//MODULO QUE INSTANCIA TDAs DE MATERIAS---------------------------------------------------------
    Materia m[c_materias];
    FILE * fmaterias= NULL;
    fmaterias = fopen("materias.txt", "r");
    if(!fmaterias){
        for(i = 0; i < c_materias; i++){
            m[i]= constructMateriaTeclado();
            c_integrantes = c_integrantes+getCantidadIntegrantes(m[i]);
        }
    }else{
        char fcontent_materias[c_materias][250];
        for(int i = 0; i < c_materias; i++){
            fgets(fcontent_materias[i], 250, fmaterias);
        }
        fclose(fmaterias);
        for(i = 0; i < c_materias; i++){
            m[i]= fConstructorMateria(fcontent_materias[i], delimitador);
            c_integrantes = c_integrantes+getCantidadIntegrantes(m[i]);
        }
    }
//CIERRE DE MODULO----------------------------------------------------------------------------------

   c_integrantes++;
//MODULO QUE INSTANCIA TDAs DE INTEGRANTES---------------------------------------------------------
    Integrante integrantes[c_integrantes];
    FILE * fintegrantes= NULL;
    fintegrantes = fopen("integrantes.txt", "r");
    if(!fintegrantes){
        for(i = 0; i< c_integrantes; i++){
            integrantes[i] = constructIntegranteTeclado();
        }
    }else{
        char fcontent_integrantes[c_integrantes][250];
        for(int i = 0; i < c_integrantes; i++){
            fgets(fcontent_integrantes[i], 250, fintegrantes);
        }
        fclose(fintegrantes);
        for(i = 0; i< c_integrantes; i++){
            integrantes[i] = fConstructorIntegrante(fcontent_integrantes[i], delimitador);
        }
    }
//CIERRE DE MODULO----------------------------------------------------------------------------------
    fclose(funiversidad);
    fclose(fdepartamentos);
    fclose(fcarreras);
    fclose(fmaterias);
    fclose(fintegrantes);

//MENU PRINCIPAL---------------------------------------------------------------------------------------
    do{
        system("cls");

        int opcion;

        printf("                            --Opciones para gestionar/administrar.--\n\n");
        printf("\n A continuacion seleccione un numero correspondiente a la seccion:\n\n ");
        printf(" 1- Universidad.\n");
        printf("  2- Departamentos.\n");
        printf("  3- carrera.\n");
        printf("  4- Materias.\n");
        printf("  5- Integrantes.\n");
        printf("  0- Guardar y salir\n\n");

        printf("Opcion: ");
        opcion = escaneaEntero();
        if(!opcion)break;
        switch(opcion){
            case 1:opcionesUniversidad(u);break;
            case 2:opcionesDeptos(d,c_deptos);break;
            case 3:opcionesCarreras(c,c_carreras);break;
            case 4:opcionesMaterias(m,c_materias);break;
            case 5:opcionesIntegrantes(integrantes,c_integrantes);break;
            default:
            printf("Opcion invalida.");
            animacionCargando();
        }
    }while(1);
//CIERRE DE MENU PRINCIPAL


//MODULO GUARDAR TDAs EN ARCHIVOS-------------------------------------------------------------------------------------------
    c_deptos = sizeof(d)/sizeof(d[0]);
    c_carreras = sizeof(c)/sizeof(c[0]);
    c_materias = sizeof(m)/sizeof(m[0]);
    c_integrantes = sizeof(integrantes)/sizeof(integrantes[0]);

    funiversidad = NULL;
    funiversidad = fopen("universidad.txt", "w");
    fprintf(funiversidad,"%s;%s;%s;%d\n",getNombreUniversidad(u),getUbicacionUniversidad(u),getContactoUniversidad(u),getCantidadDepartamentos(u));
    fclose(funiversidad);

    fdepartamentos = NULL;
    fdepartamentos = fopen("departamentos.txt", "w");
    for(i = 0; i < c_deptos ; i++ ){
        fprintf(fdepartamentos,"%s;%s;%s;%d\n",getNombeDepartamento(d[i]),getDescripcionDepartamento(d[i]),getCodigoDepartamento(d[i]),getCantCarrerasDepartamento(d[i]));
    }
    fclose(fdepartamentos);

    fcarreras = NULL;
    fcarreras = fopen("carreras.txt", "w");
    for(i = 0; i < c_carreras ; i++ ){
        fprintf(fcarreras,"%s;%s;%s;%s;%d\n",getNombreCarrera(c[i]),getTituloCarrera(c[i]),getCodigoDeptoCarrera(c[i]),getCodigoCarreraCarrera(c[i]), getCantidadMaterias(c[i]));
    }
    fclose(fcarreras);

    fmaterias = NULL;
    fmaterias = fopen("materias.txt", "w");
    for(i = 0; i < c_materias ; i++ ){
        fprintf(fmaterias,"%s;%s;%s;%s;%d\n",getNombreMateria(m[i]),getCodigoMeteriaMateria(m[i]),getCodigoDepartamento(m[i]),getCodigoCarreraMateria(m[i]), getCantidadIntegrantes(m[i]));
    }
    fclose(fmaterias);

    fintegrantes = NULL;
    fintegrantes = fopen("integrantes.txt", "w");
    for(i = 0; i < c_integrantes ; i++ ){
        fprintf(fintegrantes,"%s;%s;%s;%s;%s;%s\n",getNombreIntegrante(integrantes[i]),getApellidoIntegrante(integrantes[i]),getDniIntegrante(integrantes[i]),getCodigoDeptoIntegrante(integrantes[i]), getCodigoCarreraIntegrante(integrantes[i]));
    }
    fclose(fintegrantes);
//MODULO GUARDAR TDAs EN ARCHIVOS---------------------------------------------------------------------


//MODULO BORRA DE LA MEMORIA DINAMICA---------------------------------------------------------------------
    destructorUniversidad(u);

    for(i = 0; i< c_deptos; i++){
      destructorDepartamento(d[i]);
    }
    for(i = 0; i< c_carreras; i++){
      destructorCarrera(c[i]);
    }
    for(i = 0; i< c_materias; i++){
      destructorMateria(m[i]);
    }
    for(i = 0; i< c_integrantes; i++){
      destructorIntegrante(integrantes[i]);
    }
//MODULO BORRA DE LA MEMORIA DINAMICA---------------------------------------------------------------------

    return 0;
}

