#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///BRISA ORTIZ, COMISION 107

///VARIABLES GLOBALES:
int dim = 100;

///PROTOTIPADO DE FUNCIONES:
///PUNTO 1:
int cargarArr(int arr[]);
int cargarPila(Pila *pila);
///PUNTO 2:
int cargarArrRand(int arr[]);
void recorrerArr(int arr[], int validos);
int buscarMenorArr(int arr[], int validos);
int retorPosicionElementomenor(int arr[], int validos);
///PUNTO 3:
void cargarPilaRand(Pila *pila);
int mayorCantidadDeNumerosPares(Pila *pila, int arr[], int validos);
///PUNTO 4:
int cargarArreglosParalelos(int anio[], int km[]);
void recorrerParalelos(int anio[], int km[], int validos);
void MostrarConElAnio(int anio[], int km[], int validos, int dato);
///PUNTO 5:
float coincidenciasConDato(Pila *pila, int dato);

int main()
{

///PUNTO 1:
    Pila pila;
    inicpila(&pila);
    int arr[dim];
    int validos = cargarArr(arr);
    printf("\n");
    printf("CANTIDAD DE VALIDOS DEL ARREGLO: %i", validos);
    printf("\n");
    int validosPilas = cargarPila(&pila);
    printf("\n");
    printf("CANTIDAD DE VALIDOS DE LA PILA: %i", validosPilas);
    printf("\n");

///PUNTO 2
///cargar array rand:
int arrRand[dim];
int validosArr = cargarArrRand(arrRand);
recorrerArr(arrRand, validosArr);
printf("\n");
printf("\n");

int pos = retorPosicionElementomenor(arrRand, validosArr);
printf("\n La posicion del elemento menor es: %i ", pos);

///PUNTO 3:
Pila pila1;
inicpila(&pila1);
int arr1[dim];
///Cargar pila rand con 10 elementos
cargarPilaRand(&pila1);
///cargar arreglo
int validos1 = cargarArrRand(arr1);
recorrerArr(arr1, validos1);
int tieneMasElementosPares = mayorCantidadDeNumerosPares(&pila1, arr1, validos1);
printf("\n");
if(tieneMasElementosPares == 1){
    printf("\nEl arreglo tiene mas numeros pares.\n");
}else{
    printf("\nLa pila tiene mas numeros pares.\n");
}

///PUNTO 4:
int anio[dim];
int km[dim];

///cargar array paralelos:
int validos2 = cargarArreglosParalelos(anio, km);
///Mostramos para corroborar:
recorrerParalelos(anio,km,validos2);

int anioBuscar;
printf("\nIngrese el modelo y le mostrare los km del auto: ");
fflush(stdin);
scanf("%i", &anioBuscar);

MostrarConElAnio(anio,km,validos,anioBuscar);

///PUNTO 5:
Pila pila2;
inicpila(&pila2);
cargarPilaRand(&pila2);
mostrar(&pila2);
int dato;
printf("Ingrese el numero: ");
fflush(stdin);
scanf("%i", &dato);
float promedio = coincidenciasConDato(&pila2, dato);
printf("\nEl promedio de coincidencias es de %.2f ", promedio);
printf("\n");
}
///FUNCIONES PUNTO 1:
int cargarArr(int arr[]){
    int i = 0;
    char eleccion = 's';

    while(eleccion == 's' && i < dim){
        printf("\nIngrese un elemento: ");
        fflush(stdin);
        scanf("%i", &arr[i]);
        i++;

        printf("\nPulsa 's' si dese acontinuar: ");
        fflush(stdin);
        scanf("%c", &eleccion);
    }
    return i;
}
int cargarPila(Pila *pila){
    int i = 0;
    char eleccion = 's';

    while(eleccion == 's'){
        leer(pila);
        i++;
        printf("\nPulsa 's' si desea continuar: ");
        fflush(stdin);
        scanf("%c", &eleccion);
    }
    return i;
}
///PUNTO 2:
int cargarArrRand(int arr[]){
    int i;
    srand(time(NULL));
    for(i = 0; i < 10; i++){
        arr[i] = rand()%50+1;
    }
    return i;
}
///MOSTRAR ARR PARA CORROBORAR:
void recorrerArr(int arr[], int validos){
    int i;
    for(i = 0; i < validos; i++){
        printf("|%i| ", arr[i]);
    }
}
///RETORNAR POS ELEMENTO MENOR:
int buscarMenorArr(int arr[], int validos){
    int i = 0;
    int menor = arr[i];
    i = i + 1;

    while(i < validos - 1){
        if(arr[i] < menor){
            menor = arr[i];
            arr[i] = menor;
        }
        i++;
    }
    return menor;
}

int retorPosicionElementomenor(int arr[], int validos){
    int elementoMenor = buscarMenorArr(arr, validos);
    int i;
    for(i = 0; i < validos -1; i++){
        if(elementoMenor == arr[i]){
            return i;
        }
    }
}
///PUNTO 3:
///CARGAR PILA:
void cargarPilaRand(Pila *pila){
    srand(time(NULL));
    int i;
    for(i =  0; i < 11;i++){
        apilar(pila, rand()%10+1);
    }
}

int mayorCantidadDeNumerosPares(Pila *pila, int arr[], int validos){
    int contador = 0;
    int i = 0;
    int i2 = 0;
    Pila aux;
    inicpila(&aux);
    int flag = 0;

    ///While del arreglo:
    while(contador < validos){
        if((arr[contador]) % 2 == 0){
            i++;
        }
        contador++;
    }

    ///While de la pila:
    while(!pilavacia(pila)){
        if((tope(pila)) % 2 == 0){
            i2++;
            apilar(&aux, desapilar(pila));
        }else{
            apilar(&aux, desapilar(pila));
        }
    }

    if(i > i2){
        flag = 1;
    }
    return flag;
}

///PUNTO 4:
int cargarArreglosParalelos(int anio[], int km[]){
    int i = 0;
    char eleccion = 's';
    while(eleccion == 's' && i < dim){
        printf("Ingrese el anio del vehiculo: ");
        fflush(stdin);
        scanf("%i", &anio[i]);

        printf("\nIngrese los KM del auto: ");
        fflush(stdin);
        scanf("%i", &km[i]);

        i++;

        printf("\nPulsa 's' si desea continuar: ");
        fflush(stdin);
        scanf("%c", &eleccion);

    }
    return i;
}
///Mostramos para corroborar:
void recorrerParalelos(int anio[], int km[], int validos){
    int i;
    for(i = 0; i < validos; i++){
        printf("Anio Vehiculo: |%i| Kilometraje: |%i| ", anio[i], km[i]);
        printf("\n");
    }
}

void MostrarConElAnio(int anio[], int km[], int validos, int dato){
    int i;
    for(i = 0; i < validos; i++){
        if(dato == anio[i]){
            printf("Kilometraje: |%i| ", km[i]);
        }
    }
}

///PUNTO 5:
float coincidenciasConDato(Pila *pila, int dato){
    Pila aux;
    inicpila(&aux);
    int i = 0;
    float promedio;

    while(!pilavacia(pila)){
        if(tope(pila) == dato){
            i++;
            apilar(&aux, desapilar(pila));
        }else{
            apilar(&aux, desapilar(pila));
        }
    }
    promedio = 10 / i;
    return promedio;
}
