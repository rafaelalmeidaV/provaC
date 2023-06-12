#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *vetor, int tamanho);
void sort(int *vetor, int *vAuxiliar , int posicaoInicial , int posicaoFinal);
void merge(int *vetor, int *vAuxiliar , int posicaoInicial , int metade , int posicaoFinal);

int main(){
	
	int i;
	int vetor[8]={9,8,7,6,5,4,3,2};
	
	mergeSort(vetor,8);
	
	for(i = 0 ; i<8 ; i++)
		printf(" %d ",vetor[i]);
		
}
 
void mergeSort(int *vetor, int tamanho){
	
	//A função mergeSort aloca um espaço na memória para servir de vetor auxiliar
	int *vAuxiliar = malloc(sizeof(int)*tamanho);
	//Chama a função sort para começar o processo de divisão do vetor 
	sort(vetor,vAuxiliar,0,tamanho-1);
	//E limpa a memória alocada
	free(vAuxiliar);
	
}

void sort(int *vetor, int *vAuxiliar , int posicaoInicial , int posicaoFinal){
	//A função sort verifica se o vetor tem tamanho maior que 1
	if(posicaoInicial>=posicaoFinal)
		return;
		
	//Com o vetor de tamnho maior que 1 ele divide esse vetor pegando a posicao que fica na metade do vetor;
	int metade = (posicaoInicial+posicaoFinal) / 2;
	
	//Faz uma chamada recursiva para ordenar a primeira metade do vetor
	sort(vetor,vAuxiliar,posicaoInicial,metade);
	//Faz uma chamada recursiva para ordenar a segunda metade do vetor
	sort(vetor,vAuxiliar,metade+1,posicaoFinal);
	
	//Faz uma verificação para saber se os vetores estão ordenados entre si
	if(vetor[metade]<=vetor[metade+1])
		return;
	
	//E chama a função merge para reorganizar o vetor
	merge(vetor,vAuxiliar,posicaoInicial,metade,posicaoFinal);
	
}

void merge(int *vetor, int *vAuxiliar , int posicaoInicial , int metade , int posicaoFinal){
	
	//A função merge cria 3 variaveis
	int contador;
	//Armazena a posição inicial do vetor principal
	int inicioVetor = posicaoInicial;
	//Armazena a posição inicial do vetor auxiliar
	int inicioVAuxiliar = metade + 1;
	
	//Faz uma cópia do vetor princpal para o vetor auxiliar
	for(contador = posicaoInicial ; contador <= posicaoFinal ; contador ++)
		vAuxiliar[contador]=vetor[contador];
	
	//Reinicia o contador
	contador = posicaoInicial;
	
	//Percorre os vetores 
	while(inicioVetor <= metade && inicioVAuxiliar <= posicaoFinal){
		//Verifica qual valores são maior e menor  e reorganiza o vator principal
		if(vAuxiliar[inicioVetor]<vAuxiliar[inicioVAuxiliar])
			vetor[contador++]=vAuxiliar[inicioVetor++];
		else
			vetor[contador++]=vAuxiliar[inicioVAuxiliar++];
		
	}
	
	//Passa o que sobrar da primeira metade para o vetor principal
	while(inicioVetor<=metade)
		vetor[contador++] = vAuxiliar[inicioVetor++];
	
	//Passa o que sobrar da segunda metade para o vetor principal
	while(inicioVAuxiliar<=posicaoFinal)
		vetor[contador++] = vAuxiliar[inicioVAuxiliar++];
}