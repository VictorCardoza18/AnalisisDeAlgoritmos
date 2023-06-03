#include<stdio.h>

void asignarMemoria(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    int i, j;
    
    for (i = 0; i < n; i++)
        allocation[i] = -1;

    for (i = 0; i < n; i++) {
        int bloque = -1;
        for (j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bloque == -1 || blockSize[j] < blockSize[bloque]) 
                    bloque = j;
            }
        }
        if (bloque != -1) {
            allocation[i] = bloque;
            blockSize[bloque] -= processSize[i];
        }
    }
    printf("Asignaciones de memoria:\n");
    for (i = 0; i < n; i++) 
        printf("Proceso %d asignado al bloque %d\n", i + 1, allocation[i] + 1);
}

int main() {
    int blockSize[] = {100, 200, 300, 500, 600};
    int processSize[] = {212, 417, 112, 426};
    
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);
    
    asignarMemoria(blockSize, m, processSize, n);
    return 0;
}
    