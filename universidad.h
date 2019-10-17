#ifndef UNIVERSIDAD_H_INCLUDED
#define UNIVERSIDAD_H_INCLUDED

struct EstructuraUniversidad;

typedef struct EstructuraUniversidad *Universidad;

Universidad constructorUniversidad(char nombre[120], char ubicacion[120], char contacto[45], int cant_deptos);
Universidad constructUniversidadTeclado();
Universidad fconstructUniversidad(char fcontent[], char fdelimitador);

void destructorUniversidad(Universidad u);

void mostrarUniversidad(Universidad u);

//geters
char * getNombreUniversidad(Universidad u);
char * getUbicacionUniversidad(Universidad u);
char * getContactoUniversidad(Universidad u);
int getCantidadDepartamentos(Universidad u);

//seters
void setNombreUniversidad(Universidad u, char newName[120]);
void setUbicacionUniversidad(Universidad u, char newUbication[120]);
void setContactoUniversidad(Universidad u, char newContact[45]);


#endif // UNIVERSIDAD_H_INCLUDED
