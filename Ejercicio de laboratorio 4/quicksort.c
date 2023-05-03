// C code to implement quicksort

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int *GenerarArregloAleatorio(int tamArr)
{
    int *iniArr = (int *)malloc(sizeof(int) * tamArr);
    int i;                                            


    srand(time(NULL));
    for (i = 0; i < tamArr; i++)
        iniArr[i] = rand() % tamArr;

    printf("Consumo: %d bytes\n", (sizeof(int) * 2) + (sizeof(int) * tamArr) + sizeof(int *));

    return iniArr;
}


// Function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// Partition the array using the last element as the pivot
int partition(int arr[], int low, int high)
{
	// Choosing the pivot
	int pivot = arr[high];
	
	// Index of smaller element and indicates
	// the right position of pivot found so far
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		
		// If current element is smaller than the pivot
		if (arr[j] < pivot) {
			
			// Increment index of smaller element
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quickSort(int *arr, int low, int high)
{
	if (low < high) {
		
		// pi is partitioning index, arr[p]
		// is now at right place
		int pi = partition(arr, low, high);
		
		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// Driver code
int main()
{
	int tamArr = 10000;
	int *arreglo = GenerarArregloAleatorio(tamArr);
	int N = tamArr;
	clock_t ini,fin;
	double tiempot;
	// Function call
	ini=clock();
	quickSort(arreglo, 0, N - 1);
	printf("Sorted array: \n");
	for (int i = 0; i < N; i++)
		printf("%d ", arreglo[i]);

	fin=clock();

	tiempot=(double)(fin - ini) / CLOCKS_PER_SEC;
	printf("\n El tiempo transcurrido es %f", tiempot);
	return 0;
}
