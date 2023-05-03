#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 1000000

int DAC_Max(int a[], int index, int l);
int DAC_Min(int a[], int index, int l);

int DAC_Max(int a[], int index, int l)
{
	int max;
	if (l - 1 == 0)
		return a[index];

	if (index >= l - 2)
	{
		if (a[index] > a[index + 1])
			return a[index];
		else
			return a[index + 1];
	}

	max = DAC_Max(a, index + 1, l);

	if (a[index] > max)
		return a[index];
	else
		return max;
}

int DAC_Min(int a[], int index, int l)
{
	int min;
	if (l - 1 == 0)
		return a[index];

	if (index >= l - 2)
	{
		if (a[index] < a[index + 1])
			return a[index];
		else
			return a[index + 1];
	}

	min = DAC_Min(a, index + 1, l);

	if (a[index] < min)
		return a[index];
	else
		return min;
}

int main()
{
	int min, max;

	int a[tam];
	srand(time(NULL));

	for (int i = 0; i < tam; i++)
		a[i] = rand() % 10000;

	clock_t start_time = clock();

	max = DAC_Max(a, 0, 7);

	min = DAC_Min(a, 0, 7);

	clock_t end_time = clock();
	double time_elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	printf("The minimum number in a given array is : %d\n", min);
	printf("The maximum number in a given array is : %d\n", max);
	printf("Tiempo de ejecucion: %f segundos\n", time_elapsed);
	return 0;
}
