#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fecha {
    int anio;
    int mes;
    int dia;
};

struct Autor {
    char nombre[50];
    char apellido[50];
};

struct Editorial {
    char nombreedit[50];
    struct Fecha fecha;
};

struct Libro {
    char titulo[50];
    int edicion;
    int paginas;
    struct Autor autor;
    struct Fecha fecha;
    struct Editorial editorial;
};

void ingresarDatos(struct Libro *libro, int numeroLibro){
    printf("Ingrese los datos del libro %d:\n", numeroLibro);
    
    printf("Titulo: \n");
    fflush(stdin);
    gets(libro->titulo);
    
    printf("Edicion: \n");
    scanf("%d", &libro->edicion);
    
    printf("Nro. de paginas: \n");
    scanf("%d", &libro->paginas);
    
    printf("Nombre del autor: \n");
    fflush(stdin);
    gets(libro->autor.nombre);
    
    printf("Apellido del autor: \n");
    fflush(stdin);
    gets(libro->autor.apellido);
    
    printf("Año: \n");
    scanf("%d", &libro->fecha.anio);
    
    printf("Mes: \n");
    scanf("%d", &libro->fecha.mes);
    
    printf("Día: \n");
    scanf("%d", &libro->fecha.dia);
    
    printf("Nombre de la editorial: \n");
    fflush(stdin);
    gets(libro->editorial.nombreedit);
}

void imprimirDatos(struct Libro datoslib, int numeroLibro){
    printf("\nLibro %d:\n", numeroLibro);
    printf("Titulo: %s\n", datoslib.titulo);
    printf("Edicion: %d\n", datoslib.edicion);
    printf("Numero de paginas: %d\n", datoslib.paginas);
    printf("Nombre del autor: %s %s\n", datoslib.autor.nombre, datoslib.autor.apellido);
    printf("Fecha de publicacion: %d/%d/%d\n", datoslib.fecha.dia, datoslib.fecha.mes, datoslib.fecha.anio);
    printf("Nombre de la editorial: %s\n", datoslib.editorial.nombreedit);
    printf("\n");
}

int main() {
    int n;
    
    printf("Cuantos libros desea ingresar: \n");
    scanf("%d", &n);
    
    struct Libro datoslib[n];
    
    for(int i = 0; i < n; i++){
        ingresarDatos(&datoslib[i], i + 1);
    }
    
    printf("\n--------------------------------------------------------------------------------------------\n");
    printf("\nDatos de los libros ingresados:\n");
    for (int i = 0; i < n; i++){
    	printf("\n--------------------------------------------------------------------------------------------\n");
        imprimirDatos(datoslib[i], i + 1);
        printf("\n--------------------------------------------------------------------------------------------\n");
    }
    
    return 0;
}


