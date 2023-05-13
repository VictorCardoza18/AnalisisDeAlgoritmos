

#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


typedef struct Point
{
	double x,y;

}Point;

Point* generarPuntos(int tam) {

    Point* arr = (Point*)malloc(sizeof(Point) * tam);
    srand(time(NULL));

    for(int i = 0; i < tam; i++)
        arr[i].x = rand() % (tam * tam);
        
    for(int i = 0; i < tam; i++)
        arr[i].y = rand() % (tam * tam);  

    return arr;
}

void impPuntos(Point* arr, int tam){
    for(int i = 0; i < tam; i++)
        printf("(%.2f, %.2f) ", arr[i].x, arr[i].y);
    printf("\n");
}



int compareX(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->y - p2->y);
}


float dist(Point p1, Point p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
				(p1.y - p2.y)*(p1.y - p2.y)
			);
}


float bruteForce(Point P[], int n)
{
	float min = FLT_MAX;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			if (dist(P[i], P[j]) < min)
				min = dist(P[i], P[j]);
	return min;
}


float min(float x, float y)
{
	return (x < y)? x : y;
}



float stripClosest(Point strip[], int size, float d)
{
	float min = d; 

	qsort(strip, size, sizeof(Point), compareY);


	for (int i = 0; i < size; ++i)
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
			if (dist(strip[i],strip[j]) < min)
				min = dist(strip[i], strip[j]);

	return min;
}


float closestUtil(Point P[], int n)
{

	if (n <= 3)
		return bruteForce(P, n);


	int mid = n/2;
	Point midPoint = P[mid];


	float dl = closestUtil(P, mid);
	float dr = closestUtil(P + mid, n-mid);


	float d = min(dl, dr);


	Point strip[n];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (abs(P[i].x - midPoint.x) < d)
			strip[j] = P[i], j++;


	return min(d, stripClosest(strip, j, d) );
}


float closest(Point P[], int n)
{
	qsort(P, n, sizeof(Point), compareX);

	
	return closestUtil(P, n);
}


int main()
{
	int tam=40;
	clock_t ini=clock();
	Point* arr = generarPuntos(tam);
	impPuntos(arr,tam);
	
	printf("The smallest distance is %f ", closest(arr,tam));
	clock_t fin=clock();
	double tiempo=(double)(fin - ini)/CLOCKS_PER_SEC;
	printf("\ntiempo de ejecucion : %f \n",tiempo);


	return 0;
}
