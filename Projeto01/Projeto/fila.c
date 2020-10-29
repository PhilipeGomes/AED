#include "type.h"
#include "fila.h"
#include <stdlib.h>


void initialize(Fila* fila) {
	fila->qtd = 0;
}

int enqueue(Fila* fila, int num){
	if (isFull(fila)) {
		return 0;
	}
	else {
		fila->vetor[fila->qtd] = num;
		fila->qtd++;
	}
	return 1;
}

int dequeue(Fila* fila){
	int i;
	int remover;
	if(isEmpty(fila)){
		return 0;
	}
	else {
		remover = fila->vetor[0];
		for (i = 0; i < fila->qtd; i++) {
			fila->vetor[i] = fila->vetor[i + 1];
		}
		fila->qtd--;
		return remover;
	}
}

int isEmpty(Fila* fila){
	if (fila == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFull(Fila* fila) {
	if (fila->qtd == 999) {
		return 1;
	}
	else {
		return 0;
	}
}
