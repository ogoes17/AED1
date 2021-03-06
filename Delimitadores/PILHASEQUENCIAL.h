#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	char dado;
	int linha;
}DEL;

typedef DEL Tipo;

typedef struct{
	Tipo* vetor;
	int top;
	int tam;
}Pilha;

Pilha* Pilha_Criar(); // feita
int Pilha_Push(Pilha* P, Tipo* item); // feita
Tipo* Pilha_Pop1(Pilha* P); // feita
int Pilha_Pop2(Pilha* P, Tipo* end); // feita
int Pilha_Top(Pilha* P, Tipo* end); // feita
int Pilha_Aumentar(Pilha* P); // feita
int Pilha_Diminuir(Pilha* P); // feita
void Pilha_Imprimir(Pilha* P, void (*printElemento)(Pilha*)); // feita
int Pilha_tamanho(Pilha* P); // feita

int Pilha_tamanho(Pilha* P){
	if(!P) return 0;
	return P->tam;
}
void Pilha_Imprimir(Pilha* P, void (*printElemento)(Pilha*)){
	
	(*printElemento)(P);
}
void Pilha_Verifica(Pilha* P){
	if(!P)
		P = Pilha_Criar();
	else if(((float)P->top/(float)P->tam)*100 <= 25 && P->tam > 5)
		Pilha_Diminuir(P);
	else if(P->top == P->tam)
		Pilha_Aumentar(P);
}
int Pilha_Aumentar(Pilha* P){
	if(!P) return 0;
	Tipo* V = (Tipo* ) calloc(P->tam, sizeof(Tipo));
	memcpy(V, P->vetor, sizeof(Tipo)*P->top);
	free(P->vetor);
	P->tam *= 2;
	P->vetor = (Tipo* ) calloc(P->tam, sizeof(Tipo));
	for(int i = 0; i < P->tam; ++i){
		P->vetor[i] = V[i];
	}
	return 1;
}
int Pilha_Diminuir(Pilha* P){
	if(!P) return 0;
	Tipo* V = (Tipo* ) calloc(P->top+1, sizeof(Tipo));
	memcpy(V, P->vetor, sizeof(Tipo)*P->top);
	free(P->vetor);
	P->tam /= 2;
	P->vetor = (Tipo* ) calloc(P->tam, sizeof(Tipo));
	memcpy(P->vetor, V,sizeof(Tipo));

	return 1;
}
Pilha* Pilha_Criar(){
	Pilha* P = (Pilha* ) calloc(1, sizeof(Pilha));
	P->top = 0;
	P->tam = 5;
	P->vetor = (Tipo* )calloc(P->tam, sizeof(Tipo));
	
	return P;
}
int Pilha_Push(Pilha* P, Tipo* item){
	if(!P) return 0;
	Pilha_Verifica(P);
	P->vetor[P->top].dado = item->dado;
	P->vetor[P->top].linha = item->linha;

	++P->top;
	return 1;
}
Tipo* Pilha_Pop1(Pilha* P){
	if(P->top == 0) return NULL;
	Tipo* V = (Tipo* ) calloc(1, sizeof(Tipo));
	--P->top;
	V->dado = P->vetor[P->top].dado;
	V->linha = P->vetor[P->top].linha;
	return V;
}
int Pilha_Pop2(Pilha* P, Tipo* end){
	if(P->top == 0 || !end) return 0;
	--P->top;
	end->dado = P->vetor[P->top].dado;
	end->linha = P->vetor[P->top].linha;

	return 1;
}
int Pilha_Top(Pilha* P, Tipo* end){
	if(P->top == 0 || !end) return 0;
	end->dado = P->vetor[P->top-1].dado;
	end->linha = P->vetor[P->top-1].linha;
	return 1;
}