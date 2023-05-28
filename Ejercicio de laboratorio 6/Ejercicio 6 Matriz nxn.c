#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define R 100
#define C 100

int** generarMatrizAleatoria(int n) {
    int** matriz = (int**)malloc(n * sizeof(int*));
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            matriz[i][j] = rand() % n;
    }
    return matriz;

}

void imprimirMatriz(int** matriz, int n) {
    for (int i = 0; i < n; i++) {
        printf("| ");
        for (int j = 0; j < n; j++)
            printf("%d ", matriz[i][j]);
        printf("|\n");
    }
}

int min(int x,int y,int z) {

    if(x < y)
        return (x < z) ? x:z;
    else
        return (y < z) ? y:z;
}


// Si se recibe matriz constante cambiar el doble apuntador por matriz
int mincost(int** cost,int m, int n) {

    int i,j;
    int tc[R][C];

    tc[0][0] = cost[0][0];

    for(i=1; i<=m; i++)
        tc[i][0]=tc[i-1][0]+cost[i][0];

    for(j=1; j<=n; j++)
        tc[0][j]=tc[0][j-1] + cost[0][j];

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            tc[i][j] = min(tc[i-1][j-1],tc[i-1][j],tc[i][j-1]) + cost[i][j];
    return tc[m][n];
}

int minCostRecursivo(int** cost, int n, int m)
{
    if (n < 0 || m < 0)
        return 1000000;
    else if (m == 0 && n == 0)
        return cost[m][n];
    else
        return cost[m][n] + min(minCostRecursivo(cost, m - 1, n - 1), minCostRecursivo(cost, m - 1, n), minCostRecursivo(cost, m, n - 1));
}

int main() {
    int** matriz2 = generarMatrizAleatoria(R);
 
    printf("Matriz generada:\n");
    imprimirMatriz(matriz2, R);
    
    clock_t ini = clock() ;
    printf("Costo minimo: %d", mincost(matriz2, R - 1, R - 1));
    clock_t fin = clock();

    double tiempo= (double)(fin-ini)/CLOCKS_PER_SEC;

    printf("\nTiempo de costo minimo %lf",tiempo);

    clock_t ini2 = clock() ;
    printf("\nCosto minimo recursivo: %d\n", minCostRecursivo(matriz2, R - 1, R - 1));
    clock_t fin2 = clock();
    double tiempo2= (double)(fin2-ini2)/CLOCKS_PER_SEC;
    
    printf("Tiempo de costo minimo recursivo %f",tiempo2);

    return 0;



}

















    