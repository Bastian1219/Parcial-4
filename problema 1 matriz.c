#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Matriz(int A[][7], int n) 
{
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < 7; j++) 
		{
            A[i][j] = rand() % (2 + 1 - 1) + 1;
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int SumDiagonal(int A[][7], int n) 
{
    int suma = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < 7; j++) 
        {
            if (i == j) 
            {
                suma += A[i][j];
            }
        }
    }
    return suma;
}

int SumTrianguloSuperior(int A[][7], int n) 
{
    int suma = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < 7; j++) 
        {
            suma += A[i][j];
        }
    }
    return suma;
}

int SumTrianguloInferior(int A[][7], int n) 
{
    int suma = 0;
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < 7; j++) 
		{
            if (i >= j) 
			{ 
                suma += A[i][j];
            }
        }
    }
    return suma;
}

int SumFilaPares(int A[][7], int n, int fila) 
{
    int suma = 0;
    for (int j = 0; j < 7; j++) 
	{
        suma += A[fila][j];
    }
    return suma;
}

int SumColumnasImpares(int A[][7], int n, int columna) 
{
    int suma = 0;
    for (int i = 0; i < n; i++) 
	{
        suma += A[i][columna];
    }
    return suma;
}

int SumUltimaColumna(int A[][7], int n) 
{
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += A[i][6]; 
    }
    return suma;
}

int main() {
    int n = 5;
    srand(time(NULL));
    int A[5][7];
    printf("Matriz A:\n");

    Matriz(A, n);

    int diagonalSum = SumDiagonal(A, n);
    printf("La suma de la diagonal principal es: %d\n", diagonalSum);
    int sumFilaPar1 = SumFilaPares(A, n, 0);
    printf("La suma de la fila 1 es: %d\n", sumFilaPar1);
    int sumUltimaColumna = SumUltimaColumna(A, n);
    printf("La suma de la columna 7 es: %d\n", sumUltimaColumna);
	printf("\n");
   
    int totalSumFilaPares = 0; 
    for (int i = 0; i < n; i += 2) 
	{ 
        int sumFilaPar = SumFilaPares(A, n, i);
        totalSumFilaPares += sumFilaPar;
        printf("La suma de la fila %d es: %d\n", i+1, sumFilaPar);
    }
    printf("La suma total de las filas pares es: %d\n", totalSumFilaPares);
    printf("\n");
    
    int totalSumColumnasImpares = 0;
    for (int j = 1; j < 7; j += 2) 
	{ 
        int sumColumnaImpar = SumColumnasImpares(A, n, j);
        totalSumColumnasImpares += sumColumnaImpar;
        printf("La suma de la columna %d es: %d\n", j+1, sumColumnaImpar);
    }
    printf("La suma total de las columnas impares es: %d\n", totalSumColumnasImpares);
	printf("\n");
	
    printf("La suma de la diagonal principal es: %d\n", diagonalSum);
    int upperTriangleSum = SumTrianguloSuperior(A, n);
    printf("Suma del triangulo superior con diagonal: %d\n", upperTriangleSum);
    printf("\n");
    
    printf("La suma de la diagonal principal es: %d\n", diagonalSum);
    int lowerTriangleSum = SumTrianguloInferior(A, n);
    printf("Suma del triangulo inferior con diagonal: %d\n", lowerTriangleSum);

    return 0;
}



