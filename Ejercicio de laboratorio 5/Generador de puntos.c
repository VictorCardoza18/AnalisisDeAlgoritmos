#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct punto
{
    double x, y;
} Punto;

Punto *generarPuntos(int tam)
{

    Punto *arr = (Punto *)malloc(sizeof(Punto) * tam);
    srand(time(NULL));

    for (int i = 0; i < tam; i++)
        arr[i].x = rand() % (tam * tam);

    for (int i = 0; i < tam; i++)
        arr[i].y = rand() % (tam * tam);

    return arr;
}

void impPuntos(Punto *arr, int tam)
{
    for (int i = 0; i < tam; i++)
        printf("(%.2f, %.2f) ", arr[i].x, arr[i].y);
    printf("\n");
}

double DistanciaEntrePuntos(int x1, int y1, int x2, int y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

double DistanciaEntrePuntosP(Punto pt1, Punto pt2)
{
    double dx = pt2.x - pt1.x;
    double dy = pt2.y - pt1.y;
    return sqrt(dx * dx + dy * dy);
}

void MenorDistancia(int x, int y, int crds[x][y])
{ // Complejidad n cuadrada
    double numMenor = DistanciaEntrePuntos(crds[0][0], crds[0][1], crds[1][0], crds[1][1]);

    double res[2][2] = {{crds[0][0], crds[0][1]}, {crds[1][0], crds[1][1]}};

    for (int j = 0; j < x; j++)
    {
        for (int i = j; i < x; i++)
        {
            double distancia = DistanciaEntrePuntos(crds[j][0], crds[j][1], crds[i + 1][0], crds[i + 1][1]);
            if (distancia < numMenor)
            {
                numMenor = distancia;
                res[0][0] = crds[j][0];
                res[0][1] = crds[j][1];
                res[1][0] = crds[i + 1][0];
                res[1][1] = crds[i + 1][1];
            }
        }
    }
    printf("\nDistancia menor entre puntos: %f\n", numMenor);
    printf("(%.2f, %.2f) (%.2f, %.2f)", res[0][0], res[0][1], res[1][0], res[1][1]);
}

void MenorDistanciaP(Punto *crds, int x)
{ // Complejidad n cuadrada
    double numMenor = DistanciaEntrePuntosP(crds[0], crds[1]);

    Punto res[2] = {crds[0], crds[1]};

    for (int j = 0; j < x; j++)
    {
        for (int i = j; i < x; i++)
        {
            double distancia = DistanciaEntrePuntosP(crds[j], crds[i + 1]);
            if (distancia < numMenor)
            {
                numMenor = distancia;
                res[0] = crds[j];
                res[1] = crds[i + 1];
            }
        }
    }
    printf("\nDistancia menor entre puntos: %f\n", numMenor);
    printf("(%.2f, %.2f) (%.2f, %.2f)", res[0].x, res[0].y, res[1].x, res[1].y);
}

int main()
{
    // int crds[6][2] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    // MenorDistancia(6, 2, crds);

    clock_t inicio = clock();

    int tam = 40;
    Punto *arr = generarPuntos(tam);
    impPuntos(arr, tam);
    MenorDistanciaP(arr, tam);

    clock_t fin = clock();

    double t = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("\nTiempo transcurrido: %f\n", t);

    return 0;
}
