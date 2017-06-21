#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noconte{
	int id;
		
}Noconte;

typedef struct no{
	Noconte conteudo;// nao tem como passar conteudo vazio; mudar para void 
	struct no* anterior;
	struct no* proximo;
}No;

typedef struct lista{
	No * cabeca;
	No * final;
	int tam;
	
}Lista;

Lista * criaLista(){
	
	Lista * lista = (Lista*) malloc(sizeof(Lista));
	lista->tam = 0;
	lista->cabeca = NULL;
	lista->final = NULL;
	
	return lista;
}

void push(Lista* lista,Noconte item){ // insere o elemento no inicio da lista, vai ter que receber um ponteiro para void
	
	No* no = (No*) malloc(sizeof(No)); // vai ser a cabeça da lista
	no -> conteudo = item;
	if(lista->cabeca == NULL){
		lista->cabeca = no;
	}else{
		no -> proximo = lista->cabeca;
		lista -> cabeca-> anterior= no;
		lista->cabeca = no;
		no->anterior = NULL;		
	}

	lista -> tam++; 
	
}


bool vazia(Lista* lista){
	return (lista->tam == 0);
}

void imprimeLista(Lista* lista){ // imprimindo lista
	No* apontador = lista->cabeca;
	int i = 0;
	
	if(lista->tam==0){
		printf("lista vazia");
	}
	
	while(i < lista -> tam){
		printf(" %d",apontador->conteudo.id);
		apontador = apontador -> proximo;
		i++;
	}
	printf("\n");
}

void pop(Lista* lista){
	
	if(!vazia(lista)){
		
		No* ponteiro = lista -> cabeca;
		lista -> cabeca = ponteiro->proximo;
		ponteiro->anterior = NULL;
		lista->final = ponteiro->anterior;
		lista -> tam--;
		free(ponteiro);
	}
	

}

No* posicao(Lista*lista, int indice){
	
	if((indice >= 0) && (indice < lista->tam)){
		No* no = lista->cabeca;
		
		for(int i=0; i<indice ; i++){
			no = no->proximo;
		}
		return no;
	}
	return NULL;
}


int main(){
	Lista* lista = criaLista();
	Noconte item;
	//23item.id = 2;
	//push(lista,item);
	
	for(int i=1;i<10;i++){
		item.id = i;
		push(lista,item);
	}
	
	imprimeLista(lista);
	pop(lista);
	item.id = 44;
	push(lista,item);
	posicao(lista,1);
	imprimeLista(lista);
	free(lista);
	return 0;
}


