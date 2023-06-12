#include <stdio.h>

void merge(int v[], int inicio, int meio, int fim){
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int L[n1], R[n2];

    for(i=0; i<n1; i++){
        L[i] = v[inicio + i];
    }
    for(j=0; j<n2; j++){
        R[j] = v[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            v[k] = L[i];
            i++;
        }else{
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        v[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int v[], int inicio, int fim){
    if(inicio < fim){
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(v, inicio, meio);
        mergeSort(v, meio+1, fim);

        merge(v, inicio, meio, fim);
    }
}

int main(){
    int A[8] = {5,4,1,1,3,3,2,1};
    int inicio = 0;
    int fim = 8;
    mergeSort(A, inicio, fim);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", A[i]);
    }
}