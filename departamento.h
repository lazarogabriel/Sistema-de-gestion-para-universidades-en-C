#ifndef DEPARTAMENTO_H_INCLUDED
#define DEPARTAMENTO_H_INCLUDED

 struct EstructuraDepartamento;


typedef struct EstructuraDepartamento * Departamento;

Departamento constructorDepartamento(char nombre[120], char descripcion[300], char codigo_depto[6]);
Departamento constructDeptosTeclado();
Departamento fConstructorDepartamentos(char fcontent[], char delimitador);

void destructorDepartamento(Departamento d);

void mostrarDepartamento(Departamento d);

char * getNombeDepartamento(Departamento d);
char * getDescripcionDepartamento(Departamento d);
char * getCodigoDepartamento(Departamento d);
int getCantCarrerasDepartamento(Departamento d);

void setNombreDepartamento(Departamento d, char newName[120]);
void setDescripcionDepartamento(Departamento d,char newDesc[300]);
void setCodigoDepartamento(Departamento d,char newCodigo_depto[6]);
#endif // DEPARTAMENTO_H_INCLUDED
