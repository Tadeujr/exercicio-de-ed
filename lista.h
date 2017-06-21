#ifndef __LISTA_H__
#define __LISTA_H__

typedef struct no No;
typedef struct lista Lista;

typedef struct dataNode{
	int id;
		
}DataNode;

Lista* criaLista();
void push(Lista* lista, DataNode data);
//void imprimeLista(Lista* lista);
void pop(Lista* lista);// retira o primeiro no da lista
bool vazia(Lista* lista); // retorna se a lista esta vazia ou nao 
No* posicao(Lista*lista, int index);// passa a proxima posico
int indiceNo(Lista*lista,No*no);// passa o no e devolver o index
void removeno(Lista*lista,int indice); // exclui posição da lista
void insereNo(Lista * lista, DataNode data, int indice);// insere no em uma posição da lista
void trocaNo(Lista*lista,No* noA, No*B);// troca posicao do no 

#endif