#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

typedef struct teste{
	void (*fun)();
}Teste;

void num(){
	for(int i =0; i < 10; i++){
		printf("%d",i);
	}
}

int main(){
	Teste n;
	n.fun = num;
	n.fun();
	return 0;
	
}