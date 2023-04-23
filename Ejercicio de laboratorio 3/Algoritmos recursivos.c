#include <stdio.h>

void stooge_sort(int arr[], int bajo, int alto)
{
    if (bajo >= alto)
        return;

    // Si el primer elemento es mayor que el último, intercámbialos
    if (arr[bajo] > arr[alto])
    {
        int aux = arr[bajo];
        arr[bajo] = arr[alto];
        arr[alto] = aux;
    }

    // Si hay 3 o más elementos en la matriz, ordena los primeros 2/3
    // elementos, los últimos 2/3 elementos y los primeros 2/3 elementos de nuevo
    if (alto - bajo + 1 >= 3)
    {
        int tercera = (alto - bajo + 1) / 3;

        stooge_sort(arr, bajo, alto - tercera);
        stooge_sort(arr, bajo + tercera, alto);
        stooge_sort(arr, bajo, alto - tercera);
    }
}

int BusquedaBinaria(int arr[], int ini, int fin, int elem)
{
    if (fin >= ini)
    {
        int mid = ini + (fin - ini) / 2;

        if (arr[mid] == elem)
            return mid;

        if (arr[mid] > elem)
            return BusquedaBinaria(arr, ini, mid - 1, elem);

        return BusquedaBinaria(arr, mid + 1, fin, elem);
    }
    return -1;
}

int factorial(int n)
{
    return n == 0 ? 1 : n * factorial(n - 1);
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int elem = 6;

    stooge_sort(arr, 0, 9);

    for (int i = 0; i < 10; i++)
        printf("%d, ", arr[i]);

    printf("\n");

    printf("Posicion elemento a buscar = %d\n", BusquedaBinaria(arr, 0, 9, elem));
    printf("La secuancia de fibonacci del elemento %d es:\n", elem);
    for (int i = 0; i < elem; i++)
        printf("%d, ", fibonacci(i));

    printf("\n%d", factorial(elem));
}