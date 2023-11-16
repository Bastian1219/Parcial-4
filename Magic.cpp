#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Matriz(int A[][7], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = rand() % (10 + 1 - 1) + 1;
            printf("(%d,%d): %d ", i, j, A[i][j]);
        }
        printf("\n");
    }
}

int SumDiagonal(int A[][7], int n, int m) {
    int suma = 0;
    int minDim = (n < m) ? n : m;

    for (int i = 0; i < minDim; i++) {
        suma += A[i][i];
    }
    return suma;
}

int SumDiagonalInversa(int A[][7], int n, int m) {
    int suma = 0;
    int minDim = (n < m) ? n : m;

    for (int i = 0; i < minDim; i++) {
        suma += A[i][m - i - 1];
    }
    return suma;
}

int SumFila(int A[][7], int n, int m, int fila) {
    int suma = 0;
    for (int j = 0; j < m; j++) {
        suma += A[fila][j];
    }
    return suma;
}

int SumColumna(int A[][7], int n, int m, int columna) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += A[i][columna];
    }
    return suma;
}

int EsMatrizMagica(int A[][7], int n, int m) {
    
    int diagonalSum = SumDiagonal(A, n, m);

    int diagonalInversaSum = SumDiagonalInversa(A, n, m);

    if (diagonalSum != diagonalInversaSum) 
	{
        return 0; 
    }

    for (int i = 0; i < n; i++) {
        int sumaFila = SumFila(A, n, m, i);
        if (sumaFila != diagonalSum) {
            return 0;
        }
    }

    for (int j = 0; j < m; j++) {
        int sumaColumna = SumColumna(A, n, m, j);
        if (sumaColumna != diagonalSum) {
            return 0;
        }
    }

    return 1; 
}

int main() {
    int n;
    printf("Ingrese el tamaño de la matriz: ");
    scanf("%d", &n);

    srand(time(NULL));
    int A[n][7];
    printf("Matriz A:\n");

    Matriz(A, n, n);

    int diagonalSum = SumDiagonal(A, n, n);
    printf("La suma de la diagonal principal es: %d\n", diagonalSum);

    int diagonalInversaSum = SumDiagonalInversa(A, n, n);
    printf("La suma de la diagonal inversa es: %d\n", diagonalInversaSum);

    
    for (int i = 0; i < n; i++) {
        int sumaFila = SumFila(A, n, n, i);
        printf("La suma de la fila %d es: %d\n", i + 1, sumaFila);
    }

    
    for (int j = 0; j < n; j++) {
        int sumaColumna = SumColumna(A, n, n, j);
        printf("La suma de la columna %d es: %d\n", j + 1, sumaColumna);
    }
    
    if (EsMatrizMagica(A, n, n)) 
	{
        printf("La matriz es magica.\n");
    }
	else 
	{
        printf("La matriz no es magica.\n");
    }

    return 0;
}

