#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
	void *data;
	struct no* proximo;
	int prioridade;
}No;

typedef struct lista{
	int tam;
	No* cabeca;
}Lista;

No *criaNo(void * conteudo){
  No* no = (No*) malloc(sizeof(No));
  no->data = conteudo;

}

Lista * criaLista(){ // criando a lista 
	Lista * lista = (Lista*) malloc(sizeof(Lista));
	
	lista-> tam = 0; //inicia com tamanho
	lista-> cabeca = NULL; // seu inicio e null pq e claro
	
	return lista; // retorna o tipo lista com o tamanho e inicio
}

void push(Lista* lista,void * data, int prioridade){ // insere o elemento no inicio da lista
  No* no = criaNo(data);   
  no->prioridade = prioridade;

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

void insereNo(Lista * lista, int indice, void * data,int prioridade){
	
	if(indice == 0){
		push(lista,data, prioridade);
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

int tamLista(Lista * lista){
	return lista->tam - 1;
}

void imprimeLista(Lista* lista){ // imprimindo lista
	
	if(vazia(lista)){
		printf("Lista vazia \n");
	}	
	
	No* apontador = lista->cabeca;

	
	while(apontador!=NULL){
		printf(" %d",(int)apontador->data);
		apontador = apontador -> proximo;
		
	}
	printf("\n");
	
}

void destruirLista(Lista*lista){

	while(!vazia(lista)){
		
		No* ponteiro = lista -> cabeca;
		lista -> cabeca = ponteiro->proximo;
		free(ponteiro);
		lista -> tam--;
	}


} 



No* maxpri(Lista*lista, int indice){

	No * ponteiro = posicao(lista,indice);

	if(ponteiro!= NULL){
		No * max = ponteiro;

		while(ponteiro!= NULL){
			if(ponteiro->prioridade > max->prioridade){
				
				max =  ponteiro;
			}
			ponteiro = ponteiro-> proximo;
		}
		return max;
	}

	return NULL;
}

void  ordenaLista(Lista*lista){
	int i =0;

	for(i=0; i< lista->tam -1; i++){
		trocaNo(lista, posicao(lista,i),maxpri(lista,i));
	}
}

int main(){
	Lista* lista = criaLista(); 
	No *n = (No*) malloc(sizeof(No));
	

	push(lista,(int*)1,4);
	push(lista,(int*)122,3);
	push(lista,(int*)11,2);
	push(lista,(int*)445,1);


	
	imprimeLista(lista);
	//printf("%d\n", min(lista,0)->data);
	//printf("%d\n", max(lista,0)->data);
	//printf("%d\n",posicao(lista,4)->data);
	ordenaLista(lista);
	imprimeLista(lista);
	free(n);
	

	return 0;
}
