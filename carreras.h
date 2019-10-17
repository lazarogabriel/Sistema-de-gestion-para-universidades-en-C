#ifndef CARRERAS_H_INCLUDED
#define CARRERAS_H_INCLUDED

struct EstructuraCarrera;

typedef struct EstructuraCarrera * Carrera;

Carrera constructorCarrera(char nombre[120], char titulo[120],char codigo_depto[6], char codigo_carrera[2]);
Carrera constructCarreraTeclado();
Carrera fConstructorCarrera(char fcontent[], char delimitador);
void destructorCarrera(Carrera c);

void mostrarCarrera(Carrera c);

char * getNombreCarrera(Carrera c);
char * getTituloCarrera(Carrera c);
char * getCodigoCarreraCarrera(Carrera c);
char * getCodigoDeptoCarrera(Carrera c);
int getCantidadMaterias(Carrera c);


void setNombreCarrra(Carrera c, char newName[120]);
void setTituloCarrra(Carrera c, char newTitulo[120]);
void setCodigoCarreraCarrera(Carrera c, char newCodigo_carrera[2]);
void setCodigoDeptoCarrera(Carrera c, char newCodigo_depto[6]);


#endif // CARRERAS_H_INCLUDED
