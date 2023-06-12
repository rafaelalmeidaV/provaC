#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Definição do nó da lista, aquele que vai 
//guardar as informações a serem processadas

struct No{
	char nome[21]; //nome possui no maximo 20 caracteres
                   //1 para guardar o \0
	struct No* proximo; //deve guardar o endereçco do próximo elemento			     	
};

struct No* inicio = NULL;

/*
adiciona um nome à lista
*/
void insereNoInicio (char nome[]){
	
	//Primeiro passo: construir um nó para armazenar o nome
	 struct No* novo = malloc(sizeof(struct No));
	 
	 //Segundo passo: guardar as informações no No
	 strcpy(novo->nome, nome);
	 //Terceiro passo 
	 novo->proximo = inicio;
	 
	 //Quarto passo:
	 inicio  = novo;
}

void insereNoFinal(char nome[]){
	
	//Primeiro passo: construir um nó para armazenar o nome
	 struct No* novo = malloc(sizeof(struct No));
	 
	 //Segundo passo: guardar as informações no No
	 strcpy(novo->nome, nome);
	 novo->proximo = NULL;
	 
	 //Terceiro passo: avaliar lista vazia
	 if(inicio ==NULL){
	 	inicio = novo;
	 }
	 
	 //Quarto passo: andar até o ultimo nó
	 else{
	 
	 	struct No* temp = inicio;
	 	while(temp->proximo!=NULL){
	 		temp = temp->proximo;
	 	}
	 	//insere após o ultimo
	 	temp->proximo= novo;
	}
	
}

void imprime(){
	
	struct No* temp = inicio;
	
	//Passo1: para cada nó que não for o ultimo
	while(temp!=NULL){
	
	
	
	//Passo 2: imprime o nome guardado no nó
		printf("%s\n",temp->nome);
	//Passo 3: passe o ponteiro para a próxima posição da lista
		temp = temp->proximo;
	}
	
}

//Fazer as seguintes funções:
int tamanhoLista(){
	//deve calcular quantos nós existem na lista
	//e retornar
	
	//Copiar o inicio em um auxiliar
	struct No* temp = inicio;
	int cont= 0;
	
	while(temp!=NULL){
		cont++;
		temp  = temp->proximo;
	}
	return cont;
}

struct No* procura (char nome[]){
	//deve procurar o nome na lista 
	//caso não encontre, retorna NULL
	//se encontrar retorna o nó na lista onde o nome está
	
	//Copiar o inicio em um auxiliar
	struct No* temp = inicio;
	 
	 while(temp!=NULL){
	 	if(!strcmp(temp->nome, nome)) {
		 //se a diferença entre os nomes for zero, então são iguais
		 return temp; //retorna o nó onde está o nome
		}
		temp= temp->proximo;
	 }
	 return temp; //retorna o NULL caso não encontre
	
	
}
void inverteLista(){
	//dada uma lista 
	//criar outra para imprimir a lista na ordem inversa;
	//ou seja se a lista for Luizinho, Huguinho e Zezinho
	//deve gerar a Zezinho, Huguinho e Luizinho 
	
	//Passo 1 - guardar a lista em um auxiliar
	struct No* inicioAntigo = inicio;
	
	//Passo 2 - posso destruir a lista inicio?? sim
	inicio= NULL;
	
	//Passo3 - para cada elemento da lista antiga
	while(inicioAntigo!=NULL){
		//colocar esse elemento na nova lista, inserindo
		// na "cabeça", para inverter a lista
		insereNoInicio(inicioAntigo->nome);
		
		//passar para o proximo elemento da lista antiga
		inicioAntigo = inicioAntigo->proximo; 
		
	} 
}

void pointsegundoLista(){
    struct No* temp = inicio->proximo;

    //Passo1: para cada nó que não for o ultimo
	while(temp!=NULL){
	
	//Passo 2: imprime o nome guardado no nó
		printf("%s\n",temp->nome);
	//Passo 3: passe o ponteiro para a próxima posição da lista
		temp = temp->proximo;
	}
}

void segundoLista(){
    inicio = inicio->proximo;

    //Passo1: para cada nó que não for o ultimo
	while(inicio!=NULL){
	
	//Passo 2: imprime o nome guardado no nó
		printf("%s\n",inicio->nome);
	//Passo 3: passe o ponteiro para a próxima posição da lista
		inicio = inicio->proximo;
	}
}



void voltaaoprimeiro(){
    struct No* temp = inicio->proximo;
    temp = inicio;
    //Passo1: para cada nó que não for o ultimo
	while(temp!=NULL){
	
	//Passo 2: imprime o nome guardado no nó
		printf("%s\n",temp->nome);
	//Passo 3: passe o ponteiro para a próxima posição da lista
		temp = temp->proximo;
	}
}





int main(){
	
	insereNoFinal("Zezinho"); //a lista está vazia - e ocupa o 1o lugar
	insereNoFinal("Huguinho");//a lista ja tem zé e Hugo é colocado depois
	insereNoFinal("Luizinho");
	printf("Tamanho da lista = %d", tamanhoLista());
	
	struct No *procurado = procura("huguinho");
	if(procurado!=NULL){
		printf("\nElemento encontrado no endereço %p",procurado);
	}
	else{
		printf("\nElemento nao esta na lista");
	}
	
	printf("\nLista Original\n");
	imprime();
	
	printf("\nLista invertida\n");
	inverteLista();
	imprime();

    
	
    printf("\nSegundo elemento da lista\n");
    pointsegundoLista();
    // segundoLista();
    
	
}	
	

