#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct no{
	int data;
	struct no* anterior;
}No;

typedef struct pilha{
	int tam;
	No * topo;	

} Pilha;


No *criaNo(int conteudo){
  No* no = (No*) malloc(sizeof(No));
  no->data = conteudo;
  return no;
}

Pilha * criaPilha(){
	Pilha * pilha = (Pilha*) malloc(sizeof(Pilha));
	
	pilha -> tam = 0;
	pilha -> topo = NULL;
	
	return pilha;

}

void push(Pilha * pilha, int  conteudo){
	No * no;

	no = criaNo(conteudo);

	no->anterior = pilha->topo;
	pilha->topo = no;
	pilha->tam++;

}


bool vazia(Pilha* pilha){
	return (pilha->tam == 0);
}

void pop(Pilha * pilha){

	if(!vazia(pilha)){

		No* ponteiro = pilha -> topo;
		pilha ->topo  = ponteiro->anterior;
		
		free(ponteiro);
		pilha -> tam--;
		
	}


}

void imprimiInt( No* elemento ) {
    printf( "%d\n", (int*) elemento->data );
}

void imprimiPilha(Pilha * pilha){
	
	if(vazia(pilha)){
		printf("Lista vazia \n");
	}	
	
	No* apontador = pilha->topo;
	
	while(apontador){
		printf( "%d\n", apontador-> data);
		apontador = apontador->anterior;
		
	}
	printf("\n");

}


int main(){
	Pilha * p;
	No * n;
	int i = 1; 
	//data.id = 5;

	p = criaPilha();
  
	push(p,3); 
	push(p,2); 
	push(p,1); 
	
	imprimiPilha(p);

	
	
	return 0;


}
/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct no{
	void *data;
	struct no* anterior;
}No;

typedef struct pilha{
	int tam;
	No * topo;	

} Pilha;


No *criaNo(void * conteudo){
  No* no = (No*) malloc(sizeof(No));
  no->data = conteudo;
  return no;
}

Pilha * criaPilha(){
	Pilha * pilha = (Pilha*) malloc(sizeof(Pilha));
	
	pilha -> tam = 0;
	pilha -> topo = NULL;
	
	return pilha;

}

void push(Pilha * pilha, void * conteudo){
	No * no;

	no = criaNo(conteudo);

	no->anterior = pilha->topo;
	pilha->topo = no;
	pilha->tam++;

}

bool vazia(Pilha* pilha){
	return (pilha->tam == 0);
}

void pop(Pilha * pilha){

	if(!vazia(pilha)){

		No* ponteiro = pilha -> topo;
		pilha ->topo  = ponteiro->anterior;
		free(ponteiro);
		pilha -> tam--;
	}


}

int main(){
	Pilha * p;
	No * n;
	int * i = 1; 
	//data.id = 5;
	n = criaNo(i);
	p = criaPilha();
  
	push(p,n); 
	i =2;
	n = criaNo(i);
	push(p,n); 
	i =100;
	n = criaNo(i);
	push(p,n); 
	
	printf(" %d\n", n->data); // criar um no auxiliar para imprimir a pilha no->data = pilha->topo; 
	return 0;


}
*/