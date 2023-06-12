#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct No{
	int valor; //armazena o dado do nó
	struct No *proximos; // guarda o endereço do proximo
//	struct Aluno aluno;
};

//struct Aluno{
//	char nome[100];
//	int RA;
//};

int main(){
	setlocale(LC_ALL,"");
	//exemplo para Listas de inteiros
	struct No *inicio = NULL;
	printf("\nNo inicio o programa a lista é: %p", inicio);
	printf("\nO inicio é uma variavel com outra qualquer e esta em: %p", &inicio);
	
	
	// alocando um nó
	struct No *novo = (struct No*)malloc(sizeof(struct No));
	printf("\nO nó foi alocado em %p", novo);
	printf("\nO endereco de novo é: %p", &novo);
	
	novo->valor=10;
	novo->proximos = NULL;
	
	//criar a ligação do nó com a lista
	
	inicio = novo; // recebe o endereço
	printf("Se inicio recebe o novo então: %d = %d",novo->valor, inicio->valor);
	
	// exercicio 3: alocar o nó para guardar o 20
	novo =(struct No*)malloc(sizeof(struct No));
	novo->valor=20;
	novo->proximos = NULL;
	
	//Exercicio 4: colocar o nó 20 como sucessor do nó 10.
	inicio->proximos = novo;
	//exercicio 5: a partir do nó inicio, imprimir o valor 20
	printf("\nO segundo elemento vale %d", inicio->proximos->valor);
}