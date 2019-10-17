#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED

struct EstructuraMateria;

typedef struct EstructuraMateria * Materia;

Materia constructorMateria(char nombre[120],char codigo_materia[10],char codigo_depto[10],char codigo_carrera[10]){

Materia constructMateriaTeclado();

void destructorMateria(Materia m);

char * getNombreMateria(Materia m);
char * getCodigoMateria(Materia m);
char * getCodigoDeptoMateria(Materia m);
char * getCodigoMeteriaMateria(Materia m);
char * getCodigoCarreraMateria(Materia m);
int * getCantidadIntegrantes(Materia m);

void setNombreMateria(Materia m, char newName[120]);
void setCodigoMateriaMateria(Materia m, char newCodigo_materia[10]);
void setCodigoCarreraMateria(Materia m, char newCodigo_carrera[10]);
void setCodigoDeptoMateria(Materia m, char newCodigo_depto[10]);


void mostrarMateria(Materia m);



#endif // MATERIA_H_INCLUDED
