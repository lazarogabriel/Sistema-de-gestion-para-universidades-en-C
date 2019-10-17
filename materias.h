#ifndef MATERIAS_H_INCLUDED
#define MATERIAS_H_INCLUDED

struct EstructuraMateria;

typedef struct EstructuraMateria * Materia;

Materia constructorMateria(char nombre[120],char codigo_materia[6],char codigo_depto[6],char codigo_carrera[2]);
Materia constructMateriaTeclado();
Materia fConstructorMateria(char fcontent[], char delimitador);
void destructorMateria(Materia m);

char * getNombreMateria(Materia m);
char * getCodigoMateria(Materia m);
char * getCodigoDeptoMateria(Materia m);
char * getCodigoMeteriaMateria(Materia m);
char * getCodigoCarreraMateria(Materia m);
int  getCantidadIntegrantes(Materia m);

void setNombreMateria(Materia m, char newName[120]);
void setCodigoMateriaMateria(Materia m, char newCodigo_materia10[6]);
void setCodigoCarreraMateria(Materia m, char newCodigo_carrera[2]);
void setCodigoDeptoMateria(Materia m, char newCodigo_depto[6]);


void mostrarMateria(Materia m);

#endif // MATERIAS_H_INCLUDED
