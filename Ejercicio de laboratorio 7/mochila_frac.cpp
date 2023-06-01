#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Item
{
	int profit, weight;

	Item(int profit, int weight)
	{
		this->profit = profit;
		this->weight = weight;
	}
};

Item *generarArreglo(int tam)
{
	Item *arr = (Item *)malloc(sizeof(Item) * tam);
	srand(time(NULL));
	for (int i = 0; i < tam; i++)
	{
		arr[i].profit = (rand() % (tam * 10)) + 10;
		arr[i].weight = (rand() % (tam * 10)) + 10;
	}
	return arr;
}

void impArreglo(Item *arr, int tam)
{
	for (int i = 0; i < tam; i++)
		cout << "{ " << arr[i].profit << ", " << arr[i].weight << " }";
	cout << "\n";
}

static bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.profit / (double)a.weight;
	double r2 = (double)b.profit / (double)b.weight;
	return r1 > r2;
}

void fractionalKnapsack(int W, struct Item arr[], int N)
{
	sort(arr, arr + N, cmp);

	double finalvalue = 0.0;
	double finalweight = 0.0;

	for (int i = 0; i < N; i++)
	{
		if (arr[i].weight <= W)
		{
			W -= arr[i].weight;
			finalvalue += arr[i].profit;
			finalweight += arr[i].weight;
		}
		else
		{
			finalvalue += arr[i].profit * ((double)W / (double)arr[i].weight);
			finalweight += arr[i].weight * ((double)W / (double)arr[i].weight);
			break;
		}
	}
	cout << "Peso final: " << finalweight << "\n";
	cout << "Valor final: " << finalvalue << "\n\n";
}

int main()
{
	// Peso igual para todos los casos
	int W = 50;

	// caso 1
	cout << "Primer caso(base)\n";
	Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
	int N = sizeof(arr) / sizeof(arr[0]);
	fractionalKnapsack(W, arr, N);

	// caso 2
	cout << "Caso 2\n";
	int tam = 4;
	Item *arreglo = generarArreglo(tam);
	impArreglo(arreglo, tam);
	fractionalKnapsack(W, arreglo, tam);

	// caso 3
	cout << "Caso 3\n";
	tam++;
	Item *arreglo2 = generarArreglo(tam);
	impArreglo(arreglo2, tam);
	fractionalKnapsack(W, arreglo2, tam);

	// caso 4
	cout << "Caso 4\n";
	tam++;
	Item *arreglo3 = generarArreglo(tam);
	impArreglo(arreglo3, tam);
	fractionalKnapsack(W, arreglo3, tam);

	return 0;
}
