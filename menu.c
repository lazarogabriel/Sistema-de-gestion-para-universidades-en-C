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


void mensajeBinvenida(){
    printf("\n                              --Bienvenido al sistema de gestion de universidades--\n\n\n\n");
    printf("                                Este es un sistema de gestion para universidades.\n");
    printf("                                Podra administrar; departamentos, carreras, materias\n");
    printf("                                , alumnos y docentes. Ademas podra gestionar; las\n");
    printf("                                notas, documentacion de los alumnos y docentes de\n");
    printf("                                la universidad. \n\n\n\n");
    printf("                                ");
    system("pause");
    system("cls");

}
void animacionCargando(){
    system("cls");
    char cargando[] = "-\\|/";
    for(int i = 0; i< 2; i++){
        for(int j = 0; j < strlen(cargando); j++){
            printf("\n CARGANDO ");
            printf("%c\n", cargando[j]);
            Sleep(5);
            system("cls");
        }
    }
}
 void opcionesUniversidad(Universidad u){

    system("cls");

    char newName[45];
    char newUbicacion[45];
    char newContacto[45];

    do{
        int opcion;
        printf("\n Opciones de universidad:\n\n ");
        printf(" 1- Ver universidad.\n");
        printf("  2- Cambiar nombre.\n");
        printf("  3- Cambiar ubicacion.\n");
        printf("  4- Cambiar contacto.\n");
        printf("  5- Borrar todo.\n");
        printf("  0- Menu principal\n\n");

        printf("Opcion: ");
        opcion = escaneaEntero();
        if(!opcion)break;
        switch(opcion){
            case 1:
                system("cls");
                mostrarUniversidad(u);
                system("pause");
                animacionCargando();
            break;
            case 2:
                printf("\n\nCambiar nombre.\n");
                printf("\nIngrese el nuevo nombre: ");
                escaneaCadena(newName, 45);
                setNombreUniversidad(u, newName);
                printf("\n\n¡Nombre modificado correctamente!\n\n");
                system("pause");
                animacionCargando();
            break;
            case 3:
                printf("\n\nCambiar ubicacion.\n");
                printf("\nIngrese la nueva ubicacion: ");
                escaneaCadena(newUbicacion, 45);
                setUbicacionUniversidad(u, newUbicacion);
                printf("\n¡Ubicacion modificada correctamente!\n\n");
                animacionCargando();
                system("cls");
            break;
            case 4:
                printf("\n\nCambiar contacto.\n");
                printf("\nIngrese el nuevo contacto: ");
                escaneaCadena(newContacto, 45);
                setContactoUniversidad(u, newContacto);
                printf("\n\n¡Contacto modificado correctamente!\n\n");
                animacionCargando();
                system("cls");
            break;
            case 5:
                printf("\n\nAUN NO CONTAMOS CON ESA OPCION, VUELVA MAS TARDE.\n\n");
                system("pause");
            break;
            default:
            printf("\n\n¡Opcion incorrecta!\n\n");
            Sleep(500);
            animacionCargando();

        }
    }while(1);
}

void opcionesDeptos(Departamento d[],int arrayTDAlen){
    system("cls");

    int j=-1;
    int i=-1;
    int opcion;
    char elemento_a_buscar[7] = " ";
    char nombre_depto_aux[121] = " ";
    char nombre_depto_aux1[121] = " ";
    Departamento auxiliar_departamento = constructorDepartamento(" ", " ", " ");

    do{
        printf("\n Opciones de departamentos:\n\n ");
        printf(" 1- Mostrar todos los departamentos.\n");
        printf("  2- Ordernar los departamntos alfabeticamente.\n");
        printf("  3- Ordernar los departamntos numericamente por codigo.\n");
        printf("  4- Moficiar nombre de departamento.\n");
        printf("  5- Moficiar descripcion de departamento.\n");
        printf("  0- Menu principal\n\n");

        printf("Opcion: ");
        opcion = escaneaEntero();
        if(!opcion)break;

        switch(opcion){
            case 1:
                system("cls");
                printf("\nLista de departamentos: \n");
                for(i = 0; i < arrayTDAlen; i++){
                    mostrarDepartamento(d[i]);
                }
                printf("\n\n");
                system("pause");
                animacionCargando();
            break;
            case 2:
               for(i = 0; i < arrayTDAlen; i++){
                  for(j = 0; j < arrayTDAlen-1; j++){
                     strcpy(nombre_depto_aux, getNombeDepartamento(d[i]));
                     strcpy(nombre_depto_aux1, getNombeDepartamento(d[j]));
                     if(strcmp(nombre_depto_aux,nombre_depto_aux1) < 0){
                       auxiliar_departamento = d[i];
                       d[i] = d[j];
                       d[j] = auxiliar_departamento;
                     }
                  }
               }
               printf("\n\n Ordenados exitosamente!");
               Sleep(500);
               system("cls");
            break;
            case 3:
               for(i = 0; i < arrayTDAlen; i++){
                  for(j = 0; j < arrayTDAlen-1; j++){
                     if(atoi(getCodigoDepartamento(d[j])) >= atoi(getCodigoDepartamento(d[j+1]))){
                       auxiliar_departamento = d[j];
                       d[j] = d[j+1];
                       d[j+1] = auxiliar_departamento;
                     }
                  }
               }
               printf("\n\n Ordenados exitosamente!");
               Sleep(500);
               system("cls");
            break;
            case 4:
               printf("\n\n Ingrese el codigo del departamento a modificar: ");
               escaneaCadena(elemento_a_buscar,6);
               for(i = 0; i < arrayTDAlen; i++){
                  if(strcmp(elemento_a_buscar, getCodigoDepartamento(d[i]))==0){
                     j=i;
                     break;
                  }
               }
               if(j>-1){
                  char nuevoNombre[121] = " ";
                  mostrarDepartamento(d[j]);
                  printf("\n\n");
                  printf(" Ingrese un nombre para el departamento: ");
                  escaneaCadena(nuevoNombre, 120);
                  setNombreDepartamento(d[j], nuevoNombre);
                  printf("\n\n Modificado exitosamente!");
               }else{
                  printf("\n\n No se encontraron resultados");
               }
               Sleep(1000);
               system("cls");
            break;
            case 5:
               printf("\n\n Ingrese el codigo del departamento a modificar: ");
               escaneaCadena(elemento_a_buscar,6);
               for(i = 0; i < arrayTDAlen; i++){
                  if(strcmp(elemento_a_buscar, getCodigoDepartamento(d[i]))==0){
                     j=i;
                     break;
                  }
               }
               if(j>-1){
                  char nuevaDescripcion[301] = " ";
                  mostrarDepartamento(d[j]);
                  printf("\n\n");
                  printf(" Ingrese una descripcion para el departamento: ");
                  escaneaCadena(nuevaDescripcion, 300);
                  setDescripcionDepartamento(d[j], nuevaDescripcion);
                  printf("\n\n Modificado exitosamente!");
               }else{
                  printf("\n\n No se encontraron resultados");
               }
               Sleep(1000);
               system("cls");
            break;
            default:
            printf("\n\n¡Opcion incorrecta!\n\n");
            Sleep(600);
            animacionCargando();
        }

    }while(1);
   destructorDepartamento(auxiliar_departamento);
}

void opcionesCarreras(Carrera c[],int arrayTDAlen){
        system("cls");

        int i=-1;
        int j=-1;

        Carrera auxiliar_carrera;
        do{

            int opcion;

            printf("\n Opciones de carreras:\n\n ");
            printf(" 1- Ver todas las carreras.\n");
            printf("  2- Ordernar carreras por departamento.\n");
            printf("  3- Ordernar por codigo ascendente.\n");
            printf("  4- Ordernar por codigo descendente.\n");
            printf("  5- Modificar carrera.\n");
            printf("  6- Ordernar alfabeticamente.\n");
            printf("  7- Borrar carrera.\n");
            printf("  8- Cargar carrera.\n");
            printf("  0- Menu principal\n\n");

            printf("Opcion: ");
            opcion = escaneaEntero();
            if(!opcion)break;
            switch(opcion){
                case 1:
                   system("cls");
                   printf("                           --Lista de todas las carreras--\n\n");
                  for(i = 0; i < arrayTDAlen; i++){
                     mostrarCarrera(c[i]);
                     printf("\n\n");
                     if(((i+1) % 4)==0){
                        char opcion;
                        printf("\nSeguir mostrando carreras?[S/N]: \n\n");
                        opcion = getch();
                        if(opcion=='n' || opcion=='N')break;
                     }
                  }
                  printf("\n\n");
                  system("pause");
                  animacionCargando();
                break;
                case 2:
                   for(i = 0; i < arrayTDAlen; i++){
                     for(j = 0; j < arrayTDAlen-1; j++){
                        if(atoi(getCodigoDeptoCarrera(c[j])) >= atoi(getCodigoDeptoCarrera(c[j+1]))){
                          auxiliar_carrera = c[j];
                          c[j] = c[j+1];
                          c[j+1] = auxiliar_carrera;
                        }
                     }
                  }
                  printf("\n\n Ordenados exitosamente!");
                  Sleep(500);
                  system("cls");
                break;
                case 3:
                  for(i = 0; i < arrayTDAlen; i++){
                     for(j = 0; j < arrayTDAlen-1; j++){
                        if(atoi(getCodigoCarreraCarrera(c[j])) >= atoi(getCodigoCarreraCarrera(c[j+1]))){
                          auxiliar_carrera = c[j];
                          c[j] = c[j+1];
                          c[j+1] = auxiliar_carrera;
                        }
                     }
                  }
                  printf("\n\n Ordenados exitosamente!");
                  Sleep(500);
                  system("cls");
                break;
                case 4:
                   for(i = 0; i < arrayTDAlen; i++){
                     for(j = 0; j < arrayTDAlen-1; j++){
                        if(atoi(getCodigoCarreraCarrera(c[j])) <= atoi(getCodigoCarreraCarrera(c[j+1]))){
                          auxiliar_carrera = c[j+1];
                          c[j+1] = c[j];
                          c[j] = auxiliar_carrera;
                        }
                     }
                  }
                  printf("\n\n Ordenados exitosamente!");
                  Sleep(500);
                  system("cls");
                break;
                case 5:
                  modificarCarrera(c, arrayTDAlen);
                break;
                case 6:
                    for(i = 0; i < arrayTDAlen; i++){
                      for(j = 0; j < arrayTDAlen-1; j++){
                         if(strcmp(getNombreCarrera(c[i]), getNombreCarrera(c[j])) < 0){
                           auxiliar_carrera = c[i];
                           c[i] = c[j];
                           c[j] = auxiliar_carrera;
                         }
                      }
                   }
                   printf("\n\n Ordenados exitosamente!");
                   Sleep(500);
                   system("cls");
                break;
                case 8:

                break;
                default:
                printf("\n\n¡Opcion incorrecta!\n\n");
                Sleep(600);
                animacionCargando();
            }

        }while(1);
        destructorCarrera(auxiliar_carrera);
}

void modificarCarrera(Carrera c[], int arrayTDAlen){

    char elemento_a_buscar[121] = " ";
    char nuevoNombre[121] = " ";
    char nuevoTitulo[121] = " ";
    char nuevoCodigoCarrera[3] = " ";
    char nuevoCodigoDepto[7] = " ";

    int i;
    int opcion;
    int indice_elemento_encontrado = -1;

    printf("Ingrese el codigo o nombre de la carrera: ");
    escaneaCadena(elemento_a_buscar, 120);

    for(i = 0; i < arrayTDAlen; i++){
      if(strcmp(elemento_a_buscar, getCodigoCarreraCarrera(c[i]))==0 || strcmp(elemento_a_buscar, getNombreCarrera(c[i]))==0){
            indice_elemento_encontrado = i;
            break;
         }
      }

    if(indice_elemento_encontrado > -1){
      printf("\n\n Carrera encontrada :)\n\n");
      Sleep(900);
      system("cls");

      do{
         printf("\n");
         mostrarCarrera(c[indice_elemento_encontrado]);
         printf("\n\n Modificar: \n\n");
         printf("  1- Nombre.\n");
         printf("  2- Titulo.\n");
         printf("  3- Codigo de carrera.\n");
         printf("  4- Codigo de departamento.\n");
         printf("  0- Volver al menu.\n\n");

         printf(" Opcion: ");
         opcion = escaneaEntero();
         if(!opcion)break;

         switch(opcion){
            case 1:
               printf("\n\n Ingrese el nombre nuevo: ");
               escaneaCadena(nuevoNombre, 120);
               setNombreCarrra(c[indice_elemento_encontrado], nuevoNombre);
            break;
            case 2:
               printf("\n\n Ingrese un titulo nuevo: ");
               escaneaCadena(nuevoTitulo, 120);
               setTituloCarrra(c[indice_elemento_encontrado], nuevoTitulo);
            break;
            case 3:
               printf("\n\n Ingrese codigo de carrera nuevo: ");
               escaneaCadena(nuevoCodigoCarrera, 2);
               setCodigoCarreraCarrera(c[indice_elemento_encontrado], nuevoCodigoCarrera);
            break;
            case 4:
               printf("\n\n Ingrese un codigo de departamento nuevo: ");
               escaneaCadena(nuevoCodigoDepto, 6);
               setCodigoDeptoCarrera(c[indice_elemento_encontrado], nuevoCodigoDepto);
            break;
         }
         printf("\n\n Modificado con exito!\n\n");
         system("pause");
         animacionCargando();
      }while(1);

    }else{
      printf("\n\n Carrera no encontrada :(");
      Sleep(1000);
    }
    system("cls");

}

void opcionesMaterias(Materia m[],int arrayTDAlen){
        system("cls");

        int i;
        int j;
        Materia auxiliar_materias;
        do{
            int opcion;

            printf("\n Opciones de materias:\n\n ");
            printf(" 1- Ver todas las materias.\n");
            printf("  2- Ordernar alfabeticamente.\n");
            printf("  3- Ordenar materias por departamento.\n");
            printf("  4- Ordernar materias por codigo de carrera ascendente.\n");
            printf("  5- Ordernar materias por codigo de carrera descendente.\n");
            printf("  6- Borrar una materia.\n");
            printf("  0- Menu principal\n\n");

            printf("Opcion: ");
            opcion = escaneaEntero();
            if(!opcion)break;
            switch(opcion){
                case 1:
                  system("cls");
                  printf("                           --Lista de todas las materias--\n\n");
                  for(i = 0; i < arrayTDAlen; i++){
                     mostrarMateria(m[i]);
                     printf("\n\n");
                      if(((i+1) % 50)==0){
                        char opcion;
                        printf("\nSeguir mostrando materias?[S/N]: \n");
                        opcion = getch();
                        if(opcion=='n' || opcion=='N')break;
                     }
                  }
                  printf("\n\n");
                  system("pause");
                  animacionCargando();
                break;
                case 2:
                    for(i = 0; i < arrayTDAlen; i++){
                      for(j = 0; j < arrayTDAlen-1; j++){
                         if(strcmp(getNombreMateria(m[i]), getNombreMateria(m[j])) < 0){
                           auxiliar_materias = m[i];
                           m[i] = m[j];
                           m[j] = auxiliar_materias;
                         }
                      }
                   }
                   printf("\n\n Ordenados exitosamente!");
                   Sleep(500);
                   system("cls");
                break;
                case 3:
                    for(i = 0; i < arrayTDAlen; i++){
                     for(j = 0; j < arrayTDAlen-1; j++){
                        if(atoi(getCodigoDeptoMateria(m[j])) >= atoi(getCodigoDeptoMateria(m[j+1]))){
                          auxiliar_materias = m[j];
                          m[j] = m[j+1];
                          m[j+1] = auxiliar_materias;
                        }
                     }
                  }
                  printf("\n\n Ordenados exitosamente!");
                  Sleep(500);
                  system("cls");
                break;
                case 4:

                break;
                default:
                printf("\n\n¡Opcion incorrecta!\n\n");
                Sleep(600);
                animacionCargando();
            }

        }while(1);
        //FUNCION GRARDAR INTEGRANTES
        destructorMateria(auxiliar_materias);
}


void opcionesIntegrantes(Integrante integrantes[],int arrayTDAlen){

       system("cls");

       char elemento_a_buscar[46]= " ";
       int cant_resultados=0;
       int i;

        do{
            int opcion;

            printf("\n Opciones de integrantes:\n\n ");
            printf(" 1- Mostrar todos los integrantes.\n");
            printf("  2- Buscar un integrante.\n");
            printf("  3- Mostrar docentes por carrera.\n");
            printf("  4- Mostrar docentes por departamento.\n");
            printf("  5- Mostrar alumnos por carrera.\n");
            printf("  6- Mostrar alumnos por departamento.\n");
            printf("  7- Modificar alumno.\n");
            printf("  8- Modificar docente.\n");
            printf("  9- Ordenar alfabeticamente.\n");
            printf("  10- Ordenar por\n");
            printf("  11- Cargar alumno\n");
            printf("  12- Cargar docente\n");
            printf("  0- Menu principal\n\n");

            printf("Opcion: ");
            opcion = escaneaEntero();
            if(!opcion)break;
            switch(opcion){
                case 1:
                  system("cls");
                  printf("                           --Lista de todas los integrantes--\n\n");
                  for(i = 0; i < arrayTDAlen; i++){
                     mostrarIntegrante(integrantes[i]);
                     printf("\n\n");
                     if(((i+1) % 50)==0){
                        char opcion;
                        printf("Seguir mostrando integrantes?[S/N]: ");
                        opcion = getch();
                        if(opcion=='n' || opcion=='N')break;
                     }
                  }
                  printf("\n\n");
                  system("pause");
                  animacionCargando();
                break;
                case 2:
                  buscarIntegrante(integrantes, arrayTDAlen);
                break;
                case 3:
                   printf("\n\n");
                   printf("Ingrese el codigo de la carrera: ");
                   escaneaCadena(elemento_a_buscar,2);
                   printf("\n");
                   for(i = 0; i < arrayTDAlen; i++){
                     if(atoi(elemento_a_buscar)==atoi(getCodigoCarreraIntegrante(integrantes[i]))){
                        if(strcmp("docente", getTipoIntegranteIntegrante(integrantes[i]))==0){
                           printf("\n");
                           mostrarIntegrante(integrantes[i]);
                           cant_resultados++;
                        }
                      }
                     }
                   printf("\n\nCantiad de elementos encontrados: %d\n\n", cant_resultados);
                   cant_resultados=0;
                   system("pause");
                   animacionCargando();
                break;
                case 4:
                   printf("\n\n");
                   printf("Ingrese el codigo de departamento: ");
                   escaneaCadena(elemento_a_buscar,6);
                   printf("\n");
                   for(i = 0; i < arrayTDAlen; i++){
                     if(strcmp(elemento_a_buscar, getCodigoDeptoIntegrante(integrantes[i]))==0){
                        if(strcmp("docente", getTipoIntegranteIntegrante(integrantes[i]))==0){
                           printf("\n");
                           mostrarIntegrante(integrantes[i]);
                           cant_resultados++;
                        }
                      }
                     }
                   printf("\n\nCantiad de elementos encontrados: %d\n\n", cant_resultados);
                   cant_resultados=0;
                   system("pause");
                   animacionCargando();
                break;
                case 5:
                   printf("\n\n");
                   printf("Ingrese el codigo de la carrera: ");
                   escaneaCadena(elemento_a_buscar,2);
                   printf("\n");
                   for(i = 0; i < arrayTDAlen; i++){
                     if(strcmp(elemento_a_buscar, getCodigoCarreraIntegrante(integrantes[i]))==0){
                        if(strcmp("alumno", getTipoIntegranteIntegrante(integrantes[i]))==0){
                           printf("\n");
                           mostrarIntegrante(integrantes[i]);
                           cant_resultados++;
                        }
                      }
                     }
                   printf("\n\nCantiad de elementos encontrados: %d\n\n", cant_resultados);
                   cant_resultados=0;
                   system("pause");
                   animacionCargando();
                break;
                case 6:
                   printf("\n\n");
                   printf("Ingrese el codigo de departamento: ");
                   escaneaCadena(elemento_a_buscar,6);
                   printf("\n");
                   for(i = 0; i < arrayTDAlen; i++){
                     if(strcmp(elemento_a_buscar, getCodigoDeptoIntegrante(integrantes[i]))==0){
                        if(strcmp("alumno", getTipoIntegranteIntegrante(integrantes[i]))==0){
                           printf("\n");
                           mostrarIntegrante(integrantes[i]);
                           cant_resultados++;
                        }
                      }
                     }
                   printf("\n\nCantiad de elementos encontrados: %d\n\n", cant_resultados);
                   cant_resultados=0;
                   system("pause");
                   animacionCargando();
                break;
                case 7:
                  modificarIntegrante(integrantes, arrayTDAlen, "alumno");
                break;
                case 8:
                  modificarIntegrante(integrantes, arrayTDAlen, "docente");
                break;
                case 9:
                break;
                case 10:
                break;
                case 11:
                break;
                case 12:
                break;
                default:
                printf("\n\n¡Opcion incorrecta!\n\n");
                Sleep(600);
                animacionCargando();
            }
        }while(1);
        //FUNCION GRARDAR INTEGRANTE
}
void modificarIntegrante(Integrante integrantes[], int arrayTDAlen, char TipoIntegrante[]){

    char nuevoDNI[9] = " ";
    char nuevoCodigoDepto[7] = " ";
    char nuevoCodigoCarrera[3] = " ";
    char nuevoApellido[46] = " ";
    char nuevoNombre[46] = " ";
    int i;
    int opcion;
    int indice_elemento_encontrado = 0;

    printf("Ingrese el DNI del %s: ", TipoIntegrante);
    int elemento_a_buscar = escaneaEntero();

    for(i = 0; i < arrayTDAlen; i++){
      if(strcmp(TipoIntegrante, getTipoIntegranteIntegrante(integrantes[i]))==0){
         if(elemento_a_buscar == atoi(getDniIntegrante(integrantes[i]))){
            indice_elemento_encontrado = i;
            break;
         }
      }
    }

    if(indice_elemento_encontrado){
      printf("\n\n Integrante encontrado :)\n\n");
      Sleep(500);
      system("cls");

      do{
         printf("\n");
         mostrarIntegrante(integrantes[indice_elemento_encontrado]);
         printf("\n\n Modificar: \n\n");
         printf("  1- Nombre.\n");
         printf("  2- Apellido.\n");
         printf("  3- DNI.\n");
         printf("  4- Codigo de carrera.\n");
         printf("  5- Codigo de departamento.\n");
         printf("  0- Volver al menu.\n\n");

         printf(" Opcion: ");
         opcion = escaneaEntero();
         if(!opcion)break;

         switch(opcion){
            case 1:
               printf("\n\n Ingrese el nombre nuevo: ");
               escaneaCadena(nuevoNombre, 46);
               setNombreIntegrante(integrantes[indice_elemento_encontrado], nuevoNombre);
            break;
            case 2:
               printf("\n\n Ingrese un apellido nuevo: ");
               escaneaCadena(nuevoApellido, 46);
               setApellidoIntegrante(integrantes[indice_elemento_encontrado], nuevoApellido);
            break;
            case 3:
               printf("\n\n Ingrese DNI nuevo: ");
               escaneaCadena(nuevoDNI, 8);
               setDniIntegrante(integrantes[indice_elemento_encontrado], nuevoDNI);
            break;
            case 4:
               printf("\n\n Ingrese un codigo de departamento nuevo: ");
               escaneaCadena(nuevoCodigoDepto, 6);
               setCodigoDeptoIntegrante(integrantes[indice_elemento_encontrado], nuevoCodigoDepto);
            break;
            case 5:
               printf("\n\n Ingrese un codigo de carrera nuevo: ");
               escaneaCadena(nuevoCodigoCarrera, 2);
               setCodigoCarreraIntegrante(integrantes[indice_elemento_encontrado], nuevoCodigoCarrera);
            break;
         }
         printf("\n\n Modificado con exito!\n\n");
         system("pause");
         animacionCargando();
      }while(1);

    }else{
      printf("\n\n Integrante no encontrado :(");
      Sleep(1000);
      system("cls");
    }
}
void buscarIntegrante(Integrante integrantes[], int arrayTDAlen){
       system("cls");

       char elemento_a_buscar[46]= " ";
       int i;
       int cant_resultados = 0;

        do{
            int opcion;

            printf("\n Buscar integrante por:\n\n ");
            printf(" 1- Nombre.\n");
            printf("  2- Apellido.\n");
            printf("  3- DNI.\n");
            printf("  0- Menu principal\n\n");

            printf("Opcion: ");
            opcion = escaneaEntero();
            if(!opcion)break;
            switch(opcion){
                case 1:
                   printf("\n\n");
                   printf("Ingrese el nombre del integrante: ");
                   escaneaCadena(elemento_a_buscar,46);
                   printf("\n");
                   for(i = 0; i < arrayTDAlen; i++){
                        if(strcmp(elemento_a_buscar, getNombreIntegrante(integrantes[i]))==0){
                           printf("\n");
                           mostrarIntegrante(integrantes[i]);
                           cant_resultados++;
                        }
                      }
                   printf("\n\nCantiad de elementos encontrados: %d\n\n", cant_resultados);
                   cant_resultados=0;
                   system("pause");
                   animacionCargando();
                break;
                case 2:
                   printf("\n\n");
                   printf("Ingrese el apellido del integrante: ");
                   escaneaCadena(elemento_a_buscar,46);
                   printf("\n");
                   for(i = 0; i < arrayTDAlen; i++){
                     if(strcmp(elemento_a_buscar, getApellidoIntegrante(integrantes[i]))==0){
                        printf("\n");
                        mostrarIntegrante(integrantes[i]);
                        cant_resultados++;
                     }
                   }
                   printf("\n\nCantiad de elementos encontrados: %d\n", cant_resultados);
                   cant_resultados=0;
                   system("pause");
                   animacionCargando();
                break;
                case 3:
                   printf("\n\n");
                   printf("Ingrese el DNI del integrante: ");
                   escaneaCadena(elemento_a_buscar,46);
                   printf("\n");
                   for(i = 0; i < arrayTDAlen; i++){
                     if(strcmp(elemento_a_buscar, getDniIntegrante(integrantes[i]))==0){
                        printf("\n");
                        mostrarIntegrante(integrantes[i]);
                        cant_resultados++;
                     }
                   }
                   printf("\n\nCantiad de elementos encontrados: %d\n", cant_resultados);
                   cant_resultados=0;
                   system("pause");
                   animacionCargando();
                break;
                default:
                printf("\n\n¡Opcion incorrecta!\n\n");
                Sleep(600);
                animacionCargando();
            }
        }while(1);
        //FUNCION GRARDAR INTEGRANTE
      system("cls");
}




