// #include <stdio.h>

// void funcQuickSort(int v[], int inicio, int fim){
//     int i, j, pivo, aux;
//     i = inicio;
//     j = fim - 1;
//     pivo = v[(inicio + fim) / 2];

//     while(i<=j){
//         while(v[i] < pivo && i < fim){
//             i++;
//         }
//         while (v[j] > pivo && j > inicio){
//             j--;
//         }
//         if( i <= j){
//             aux = v[i];
//             v[i] = v[j];
//             v[j] = aux;
//             i++;
//             j--;
//         }
//         if(j > inicio){
//             funcQuickSort(v, inicio, j+1);
//         }
//         if(i < fim){
//             funcQuickSort(v, i, fim);
//         }
//     }

// }

// int main(){
//     int A[8] = {5,4,1,1,3,3,2,1};
//     int inicio = 0;
//     int fim = 8;
//     funcQuickSort(A, inicio, fim);
//     for (int i = 0; i < 8; i++)
//     {
//         printf("%d ", A[i]);
//     }
// }


#include <stdio.h>

int trocas = 0; // Variável para contar as trocas

void quickSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = partition(v, inicio, fim);
        quickSort(v, inicio, pivo - 1);
        quickSort(v, pivo + 1, fim);
    }
}

int partition(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j <= fim - 1; j++) {
        if (v[j] <= pivo) {
            i++;
            trocar(&v[i], &v[j]);
        }
    }

    trocar(&v[i + 1], &v[fim]);
    return (i + 1);
}

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    trocas++; // Incrementa a contagem de trocas
}

int main() {
    int A[8] = {5, 4, 1, 1, 3, 3, 2, 1};
    int tamanho = 8;
    trocas = 0; // Zera a contagem antes de executar o Quick Sort

    quickSort(A, 0, tamanho - 1);

    printf("Número de trocas: %d\n", trocas);

    return 0;
}