#include <stdio.h>
#include <stdlib.h>

#define TAMNOTE 4

int contarCaracteres(char cadena[], char caracter);

float realizarDescuento(float precio);


typedef struct
{
    int id;
    char procesador[30];
    char marca[30];
    float precio;

} eNotebook;

void ordenarNotebooks(eNotebook lista[], int tam);
void mostrarNotebooks(eNotebook* x,int tam);
void mostrarNotebook(eNotebook x);


int main()
{

    /*  char cadena[20];
      char caracter;


      printf("Ingrese cadena: ");
      fflush(stdin);
      scanf("%s",&cadena);

      printf("Ingrese caracter a contar: ");
      fflush(stdin);
      scanf("%c",&caracter);

      printf("Su cadena tiene: %d veces el caracter %c\n" ,contarCaracteres(cadena,caracter),caracter);  */

    //-----------------------------------------------------------------------

    /*   float precioProducto;
       printf("Ingrese el precio del producto: ");
        scanf("%f",&precioProducto);


       realizarDescuento(precioProducto);
       printf("El precio con descuento es: %.2f",realizarDescuento(precioProducto));

    */

//----------------------------------------------------------------------------------------
    eNotebook listaNotebooks[TAMNOTE] = {{1,"amd 3400g", "hp", 40000},{2,"amd athlon x4","hitachi",45000}, {3,"i7 9800k", "lenovo", 60000}, {4,"amd phenom x4", "lenovo",50000 }};



     ordenarNotebooks(listaNotebooks,TAMNOTE);
    mostrarNotebooks(listaNotebooks,TAMNOTE);



    return 0;
}



int contarCaracteres(char cadena[], char caracter)
{

    int cantidadCaracteres = 0;

    for(int i = 0; cadena[i] != '\0'; i++)
    {
        if(cadena[i] == caracter)
        {
            cantidadCaracteres++;
        }
    }

    return cantidadCaracteres;

}


float realizarDescuento(float precio)
{
    float precioFinal;

    precioFinal=precio-((precio*5) /100);


    return precioFinal;
}



void ordenarNotebooks(eNotebook lista[], int tam)
{
    eNotebook aux;
    for(int i = 0; i < tam -1 ; i++)
    {
        for(int j = i + 1; j < tam ; j ++)
        {
            if(strcmp(lista[i].marca,lista[j].marca) == -1)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;


            }
            else if(strcmp(lista[i].marca,lista[j].marca) == 0 && lista[i].precio < lista[j].precio )
            {

                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;

            }

        }


    }




}

void mostrarNotebooks(eNotebook* lista,int tam)
{


    printf("**Lista de Notebooks**\n");
    printf("ID         Marca           Precio                Procesador\n");
    for(int i = 0; i < tam ; i++)
    {

        mostrarNotebook(lista[i]);

    }

}
void mostrarNotebook(eNotebook lista)
{

    printf("%d     %10s      %.2f     %20s\n",lista.id,lista.marca,lista.precio,lista.procesador);

}
