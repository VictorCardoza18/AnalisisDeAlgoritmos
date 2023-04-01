#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. Funcion que genera arreglo de numero aleatorios
int *GenerarArregloAleatorio(int tamArr) // 1er variable entera
{
    int *iniArr = (int *)malloc(sizeof(int) * tamArr); // Arreglo de enternos tamaño n y apuntador a entero
    int i;                                             // 2da variable entera

    if (!(tamArr > 4))
    {
        printf("El tam del arreglo debe ser mayor a 5\n");
        return NULL;
    }

    srand(time(NULL));
    for (i = 0; i < tamArr; i++)
        iniArr[i] = rand() % tamArr;

    printf("Consumo: %d bytes\n", (sizeof(int) * 2) + (sizeof(int) * tamArr) + sizeof(int *));

    return iniArr;
}

// 2. Funcion para imprimir el contenido del arreglo
void ImpArreglo(int *iniArreglo, int tamArr) // 1er variable entera y una variable apuntador a entero
{
    int i; // 2da variable entera
    if (iniArreglo == NULL)
    {
        printf("El arreglo que deseas imprimir esta vacio\n");
        return;
    }
    if (!(tamArr > 0))
    {
        printf("El tam del arreglo debe ser mayor a 0");
        return;
    }
    for (i = 0; i < tamArr; i++)
        printf("%d, ", iniArreglo[i]);

    printf("\nConsumo: %d bytes\n", sizeof(int) * 2 + sizeof(int *));
}

// 3. Busqueda secuencial
int BusquedaSecuencial(int *iniArr, int tamArr, int elem_A_Buscar) // dos variables enteras y un apuntador a entero
{
    int i; // 3er variable entera
    for (i = 0; i < tamArr; i++)
    {
        if (iniArr[i] == elem_A_Buscar)
        {
            printf("consumo: %d bytes\n", (sizeof(int) * 3) + sizeof(int *));
            return i;
        }
    }
    printf("consumo: %d bytes\n", (sizeof(int) * 3) + sizeof(int *));
    return -1;
}

// 4. Funcion de Oredenamiento, burbuja
void Burbuja(int *iniArr, int tamArr) // Apuntador a entero y variable entera
{
    int i, j, aux; // 3 variables enteras
    for (i = 0; i < tamArr; i++)
    {
        for (j = 0; j < tamArr - 1; j++)
        {
            if (iniArr[j] > iniArr[j + 1])
            {
                aux = iniArr[j];
                iniArr[j] = iniArr[j + 1];
                iniArr[j + 1] = aux;
            }
        }
    }
    printf("Consumo: %d bytes\n", (sizeof(int) * 4) + sizeof(int *));
}

int main()
{
    int tamArr = 1000000, elemBuscar = 50;

    // 6. Calculo de tiempo de ejecucion 1 a 5 ---------------------------------------------------
    double tiempoTranscurrido;

    // 1) Generar arreglo de enteros aleatorios
    printf("Generacion de arreglo:\n");
    clock_t inicio = clock();
    int *arreglo = GenerarArregloAleatorio(tamArr);
    clock_t fin = clock();
    tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo transcurrido: %f segundos\n\n", tiempoTranscurrido);
    getchar(); // QUITAR AL FINALIZAR ---------------------------------------------

    // 2) Funcion para imprimir el arreglo
    printf("Impresion de arreglo:\n");
    inicio = clock();
    ImpArreglo(arreglo, tamArr);
    fin = clock();
    tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo transcurrido: %f segundos\n\n", tiempoTranscurrido);

    // 3) Funcion de busqueda secuencial
    printf("Busqueda secuencial:\n");
    inicio = clock();
    BusquedaSecuencial(arreglo, tamArr, elemBuscar);
    fin = clock();
    tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo transcurrido: %f segundos\n\n", tiempoTranscurrido);

    // 4) Funcion de ordenamiento
    printf("Funcion de ordenamiento:\n");
    inicio = clock();
    Burbuja(arreglo, tamArr);
    fin = clock();
    tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo transcurrido: %f segundos\n\n", tiempoTranscurrido);

    // 5) Busqueda con arreglo ordenado
    printf("Busqueda de arreglo ordenado:\n");
    inicio = clock();
    BusquedaSecuencial(arreglo, tamArr, elemBuscar);
    fin = clock();
    tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo transcurrido: %f segundos\n\n", tiempoTranscurrido);

    return 0;
}
