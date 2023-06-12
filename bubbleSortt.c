
#include <stdio.h>

void function(int v[], int tamanho){

    int i, j, trocou=1, aux;
    int trocado = 0;

    i = tamanho-1;

    while( i >= 1 && trocou==1){
        trocou = 0;

        for(j=0; j<i; j++){
            if(v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                trocado ++;
                trocou = 1;
            }
        }
        i = i-1;
    }
    printf("%d\n", trocado);
}

int main(){
    
    int A[5] = {5,4,3,2,1};
    int tamanho = 5;
    function(A, tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", A[i]);
        
    }    
    
    return 0;
}