#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Fecha {
    int anio;
    int mes;
    int dia;
};

struct Autor {
    char nombre[20];
    char apellido[20];
    Fecha fecha;
};

struct Editorial {
    char nombreedit[15];
    Fecha fecha;
};

struct Libro {
    char titulo[30];
    int edicion;
    int paginas;
    Autor autor;
    Fecha fecha;
    Editorial editorial;
};

void ingresarDatos(struct Libro *libro, int nLibro){
	
    printf("Ingrese los datos del libro %d:\n", nLibro);
    
    printf("Titulo: \n");
    fflush(stdin);
    gets(libro->titulo);
    
    printf("Edición: \n");
    scanf("%d", &libro->edicion);
    
    printf("Número de paginas: \n");
    scanf("%d", &libro->paginas);
    
    printf("Nombre del autor: \n");
    fflush(stdin);
    gets(libro->autor.nombre);
    
    printf("Apellido del autor: \n");
    fflush(stdin);
    gets(libro->autor.apellido);
    
    printf("Fecha de nacimiento del autor: (formato dd mm aa)\n");
    scanf("%d %d %d", & libro->autor.fecha.dia, &libro->autor.fecha.mes, &libro->autor.fecha.anio);
    
    printf("Fecha de publicacion del libro: (formato dd mm aa)\n");
    fflush(stdin);
    scanf("%d %d %d", &libro->fecha.dia, &libro->fecha.mes, &libro->fecha.anio);
    
    printf("Nombre de la editorial: \n");
    fflush(stdin);
    gets(libro->editorial.nombreedit);
}

void imprimirDatos(struct Libro datoslib, int nLibro){
    printf("Libro %d:\n", nLibro);
    printf("Titulo: %s\n", datoslib.titulo);
    printf("Edicion: %d\n", datoslib.edicion);
    printf("Número de paginas: %d\n", datoslib.paginas);
    printf("Nombre del autor: %s %s\n", datoslib.autor.nombre, datoslib.autor.apellido);
    printf("Fecha de nacimiento del autor: %d/%d/%d \n", datoslib.autor.fecha.dia, datoslib.autor.fecha.mes, datoslib.autor.fecha.anio);
    printf("Fecha de publicación: %d/%d/%d \n", datoslib.fecha.dia, datoslib.fecha.mes, datoslib.fecha.anio);
    printf("Nombre de la editorial: %s\n", datoslib.editorial.nombreedit);
    printf("\n");
}

void guardar_lista(struct Libro datoslib, int nLibro){
	
	FILE *datoslibr=fopen("Libros.txt","a");

	fflush(datoslibr);
	
	fprintf(datoslibr, "Libro %d:\n", nLibro);
	fprintf(datoslibr, "Titulo: %s\n", datoslib.titulo);
	fprintf(datoslibr, "Edicion: %d\n", datoslib.edicion);
	fprintf(datoslibr, "Numero de paginas: %d\n", datoslib.paginas);
	fprintf(datoslibr, "Nombre del autor: %s %s\n", datoslib.autor.nombre, datoslib.autor.apellido);
	fprintf(datoslibr, "Fecha de nacimiento del autor: %d/%d/%d \n", datoslib.autor.fecha.dia, datoslib.autor.fecha.mes, datoslib.autor.fecha.anio);
	fprintf(datoslibr, "Fecha de publicacion: %d/%d/%d \n", datoslib.fecha.dia, datoslib.fecha.mes, datoslib.fecha.anio);
	fprintf(datoslibr, "Nombre de la editorial: %s\n", datoslib.editorial.nombreedit);
	fprintf(datoslibr, "\n");
	
	fclose(datoslibr);
}

int main() {
	setlocale(LC_ALL,("SPANISH"));
	
    int n;
    
    printf("Cuantos libros desea ingresar: \n");
    scanf("%d", &n);
    
    struct Libro datoslib[n];
    
    for(int i = 0; i < n; i++){
        ingresarDatos(&datoslib[i], i + 1);
    }
    
    system("cls");
    
    printf("Datos de los libros ingresados:\n");
    for (int i = 0; i < n; i++){
        imprimirDatos(datoslib[i], i + 1);
    }
    
    for(int i=0; i<n;i++){
    guardar_lista(datoslib[i], i+1);
	}
    return 0;
}
