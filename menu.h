#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void mensajeBinvenida();

void animacionCargando();

void opcionesUniversidad(Universidad u);

void opcionesDeptos(Departamento d[],int arrayTDAlen);

void opcionesCarreras(Carrera c[],int arrayTDAlen);

void modificarCarrera(Carrera c[],int arrayTDAlen);

void opcionesMaterias(Materia m[],int arrayTDAlen);

void opcionesIntegrantes(Integrante integrantes[],int arrayTDAlen);

void modificarIntegrante(Integrante integrantes[], int arrayTDAlen, char TipoIntegrante[]);

void buscarIntegrante(Integrante integrantes[], int arrayTDAlen);
#endif // MENU_H_INCLUDED
