#include <time.h>

typedef struct Rcili{
	char * ordem = {"T","F","T","M","-"};
	float (*tempodemaquina)();
	int pri = 1;
}Rcili;

typedef struct Rcone{
	char * ordem = {"T","M","T","-"};
	float (*tempodemaquina)();
	int pri = 2;
}Rcone;

 
typedef struct Resferico{
	char * ordem = {"F","M","T","-"};
	float (*tempodemaquina)();
	int pri = 3;
}Resferico; 

 
typedef struct Rtita{
	char * ordem = {"F","M","T","F","T"};
	float (*tempodemaquina)();
	int pri = 3;
}Rtitan;

float chegadaPedido(float param) {
 float u=0;
 do {
 u = (float) (rand()%RAND_MAX) / RAND_MAX;
 } while ((u==0) || (u==1));
 return (float) (-param * log (u));
}

float tempoMaquina() {
 return 2.0 * <EstadiaEquipamentoRolamento> * rand() / (RAND_MAX + 1.0);
}
