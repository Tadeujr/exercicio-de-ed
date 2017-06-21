
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




typedef struct no{
	void *data;
	struct no* proximo;
}No;

typedef struct lista{
	int tam;
	No* cabeca;
}Lista;

Lista * criaLista(){ // criando a lista 
	Lista * lista = (Lista*) malloc(sizeof(Lista));
	
	lista-> tam = 0; //inicia com tamanho
	lista-> cabeca = NULL; // seu inicio e null pq e claro
	
	return lista; // retorna o tipo lista com o tamanho e inicio
}

void push(Lista* lista,void * data){ // insere o elemento no inicio da lista
	No* no = (No*) malloc(sizeof(No)); // vai ser a cabeça da lista
	
	no -> data = data;
	no -> proximo = lista->cabeca;
	lista -> cabeca = no;
	lista -> tam++; // incrementa para contar 
	
}

bool vazia(Lista* lista){
	return (lista->tam == 0);
}


void pop(Lista* lista){
	
	if(!vazia(lista)){
		
		No* ponteiro = lista -> cabeca;
		lista -> cabeca = ponteiro->proximo;
		free(ponteiro);
		lista -> tam--;
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

int indiceNo(Lista*lista,No*no){
	
	if(no != NULL){
		No* ponto = lista -> cabeca;
		int indice = 0;
		
		while(ponto != no && ponto!= NULL){
			ponto = ponto->proximo;
			indice++;
		}
		
		if(ponto != NULL){
			return indice;	
		}
		
	}
	printf("no nao pertence a lista");
	return -1;
}

void removeno(Lista*lista,int indice){
	
	if(indice == 0){
		pop(lista);
	}else{
		No* noA = posicao(lista,indice);
		
		if(noA!= NULL){
			No* noB = posicao(lista,indice-1);
		
			noB -> proximo = noA->proximo;
		
			free(noA);
			lista -> tam--;	
		}else{
			printf("indice nao existe");
		}
		
		
	}
}

void insereNo(Lista * lista, void * data, int indice){
	
	if(indice == 0){
		push(lista,data);
	}else{
		No* noA = posicao(lista,indice);
		
		if(noA != NULL){
			No* noB = posicao(lista,indice-1);
			
			No* novo = (No*) malloc(sizeof(No*));
			
			novo -> data = data;
			
			noB -> proximo = novo;
			novo-> proximo = noA ;
			lista-> tam++;
			
		
		}
		
	}
}

void trocaNo(Lista*lista,No* noA, No*noB){
	
	if(noA == noB){
		return;
	}
	
	int indiceA = indiceNo(lista,noA);
	int indiceB = indiceNo(lista,noB);
	
	if(indiceA == -1 || indiceB || -1)
	if(indiceA > indiceB){
		noA = noB;
		noB = posicao(lista,indiceA);
		
		indiceA = indiceB;
		indiceB = indiceNo(lista,noB);
	}
	
	No* pb = posicao(lista,indiceB -1);
	
	if(noA == lista-> cabeca){
		lista->cabeca = noB;
	}else{
		No* pa = posicao(lista,indiceA-1);
		pa->proximo = noB;
	}
	
	pb->proximo = noA;
	No*ponto = noA->proximo;
	noA->proximo = noB->proximo;
	noB->proximo = ponto;
	
}