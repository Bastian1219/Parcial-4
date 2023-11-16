#include <stdio.h>

#define ORDEN 3


void llenarMatriz(int matriz[ORDEN][ORDEN]) {
    printf("Ingrese los elementos de la matriz de 3x3:\n");
	int i,j;
    for (i = 0; i < ORDEN; i++) {
        for (j = 0; j < ORDEN; j++) {
            printf("Elemento en la posicion [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}


void imprimirMatriz(int matriz[ORDEN][ORDEN]) {
    printf("Matriz :\n");
	int i,j;
    for ( i = 0; i < ORDEN; i++) {
        for ( j = 0; j < ORDEN; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}


int esMatrizMagica(int matriz[ORDEN][ORDEN]) {
    int sumaFila, sumaColumna, sumaDiagonal1 = 0, sumaDiagonal2 = 0;
	int i,j;
    
    sumaFila = 0;
    for ( j = 0; j < ORDEN; j++) {
        sumaFila += matriz[0][j];
    }


    for ( i = 1; i < ORDEN; i++) {
        int sumaFilaActual = 0;
        for ( j = 0; j < ORDEN; j++) {
            sumaFilaActual += matriz[i][j];
        }

        if (sumaFilaActual != sumaFila) {
            return 0; 
        }
    }

    
    for ( j = 0; j < ORDEN; j++) {
        sumaColumna = 0;
        for ( i = 0; i < ORDEN; i++) {
            sumaColumna += matriz[i][j];
        }

        if (sumaColumna != sumaFila) {
            return 0; 
        }
    }

    for ( i = 0; i < ORDEN; i++) {
        sumaDiagonal1 += matriz[i][i];
    }

   
    for ( i = 0; i < ORDEN; i++) {
        sumaDiagonal2 += matriz[i][ORDEN - 1 - i];
    }

    
    return (sumaDiagonal1 == sumaFila) && (sumaDiagonal2 == sumaFila);
}

int main() {
    int matriz[ORDEN][ORDEN];

    llenarMatriz(matriz);

    imprimirMatriz(matriz);

    if (esMatrizMagica(matriz)) {
        printf("La matriz es magica.\n");
    } else {
        printf("La matriz no es magica.\n");
    }

    return 0;
}
