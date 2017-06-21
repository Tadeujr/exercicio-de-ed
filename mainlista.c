#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

void imprimeLista(Lista* lista){ // imprimindo lista
	
	if(vazia(lista)){
		printf("Lista vazia \n");
	}	
	
	No* apontador = lista->cabeca;
	DataNode num = apontador->data;
	
	while(apontador){
		printf(" %d",num);
		apontador = apontador -> proximo;
		num = apontador -> data;
	}
	printf("\n");
}

int main(){
	Lista* lista = criaLista(); 
	DataNode data;
	//data.id = 5;
	//push(lista,data);// fazendo a primeira posição receber 5
	
	for(int i=0;i<10;i++){
		data.id = i;
		push(lista,data);
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