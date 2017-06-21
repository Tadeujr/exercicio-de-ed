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

No *criaNo(void*conteudo){
  No* no = (No*) malloc(sizeof(No));
  no->data = conteudo;

  }

Lista * criaLista(){ // criando a lista 
	Lista * lista = (Lista*) malloc(sizeof(Lista));
	
	lista-> tam = 0; //inicia com tamanho
	lista-> cabeca = NULL; // seu inicio e null pq e claro
	
	return lista; // retorna o tipo lista com o tamanho e inicio
}

void push(Lista* lista,void * data){ // insere o elemento no inicio da lista
  No* no = criaNo(data);   
	
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


void imprimeLista(Lista* lista){ // imprimindo lista
	
	if(vazia(lista)){
		printf("Lista vazia \n");
	}	
	
	No* apontador = lista->cabeca;
	int num = apontador->data;
	
	while(apontador){
		printf(" %d",apontador->data);
		apontador = (int)apontador -> proximo;
		num = apontador->data;
	}
	printf("\n");
	
}

int main(){
	Lista* lista = criaLista(); 
	No* cont;
	int i;
	//data.id = 5;
	//push(lista,data);// fazendo a primeira posição receber 5
	
	for(i=0;i<10;i++){
		cont = criaNo(i);
		push(lista,cont);
	}
	
	//printf("%d\n",posicao(lista,9)->data.id);
	//pop(lista);
	
	imprimeLista(lista);
	//removeno(lista,1);
	//data.id = 66;
	//insereNo(lista,data,10);
	//imprimeLista(lista);
	//printf("%d",);
	//printf("%d",indiceNo(lista,9));
	//trocaNo(lista,lista->cabeca->proximo,lista->cabeca->proximo->proximo); // tem que passar a posicao da lista
	//imprimeLista(lista);
	//printf("%d",min(lista,8)->data.id);
	return 0;
}