#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void quick_sort(int *a, int left, int right);

	int main(int argc, char** argv){
		int i, vet[MAX];
		// Lê MAX os 10 valores
		for(i = 0; i < MAX; i++){
			printf("Digite um valor: ");
			scanf("%d", &vet[i]);
		}
		// Ordena os valores
		quick_sort(vet, 0, MAX - 1);
		// Imprime os valores ordenados
		printf("Valores ordenados:\n");
		for(i = 0; i < MAX; i++){
			printf("%d  ", vet[i]);
		}
		printf("\n");
		system("pause");
		return 0;
	}
	// Função de Ordenação do Quick Sort
	void quick_sort(int *a, int left, int right) {
	    int i, j, pivo, aux;
	     
	    i = left; //i recebe esquerda
	    j = right;// j recebe direita
	    pivo = a[(left + right) / 2]; // Definir qual sera o pivo
	     
	    while(i <= j) {
	        while(a[i] < pivo && i < right) {//Enquanto o elemento da erquerda for menor que o pivo ele incrementa
	            i++;
	        }
	        while(a[j] > pivo && j > left) {//Enquanto o elemento da direita for maior que o pivo decrementa
	            j--;
	        }
	        if(i <= j) {//realizar a troca se a esquerda for menor ou igual a direita
	            aux = a[i];//aux  recebe o elemento da esquerda
	            a[i] = a[j];//Esquerda recebe o elemento da direita
	            a[j] = aux;//Por fim o elemento da direita recebe o da elemento da esquerda que esta armazenado na variavel aux
	            i++;// incrementa esquerda
	            j--;	//decrementa o da direita
	        }
	    }
	     
	    if(j > left) {//se o elemento da direita for maior que o da esquerta: Chama a função de forma recursiva assim ordenando
	        quick_sort(a, left, j);
	    }
	    if(i < right) {//se o elemento da esquerda for menor que o da direita: Chama a funcao de forma recursiva assim ordenando
	        quick_sort(a, i, right);
	    }
	}