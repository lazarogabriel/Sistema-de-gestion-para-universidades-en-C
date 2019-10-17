#ifndef INTEGRANTE_H_INCLUDED
#define INTEGRANTE_H_INCLUDED

struct EstructuraIntegrante;

typedef struct EstructuraIntegrante * Integrante;

Integrante constructorIntegrante(char nombre[46], char apellido[46], char dni[9],char TipoIntegrante[10], char codigo_depto[7], char codigo_carrera[3]);
Integrante constructIntegranteTeclado();
Integrante fConstructorIntegrante(char fcontent[], char delimitador);

void destructorIntegrante(Integrante i);
void mostrarIntegrante(Integrante i);

char * getNombreIntegrante(Integrante i);
char * getApellidoIntegrante(Integrante i);
char * getDniIntegrante(Integrante i);
char * getTipoIntegranteIntegrante(Integrante i);
char * getCodigoDeptoIntegrante(Integrante i);
char * getCodigoCarreraIntegrante(Integrante i);


void setNombreIntegrante(Integrante i, char newName[46]);
void setApellidoIntegrante(Integrante i, char newLastName[46]);
void setDniIntegrante(Integrante i, char newDni[9]);
void setTipoDeIntegrante(Integrante i, char newTipoIntegrante[10]);
void setCodigoDeptoIntegrante(Integrante i, char newCodigoDepto[7]);
void setCodigoCarreraIntegrante(Integrante i, char newCodigoCarrera[3]);

#endif // INTEGRANTE_H_INCLUDED
