#include <stdlib.h>
#include <stdio.h>
#include "type.h"
#include "fila.h"

//int ID;
//int time;
//int valor_dano;
//int numero_vida;
//int base_iniciativa;

void inserir_lutador(Lutador **lutador) {
	Lutador* novo;
	int id = 1, valor_dano, numero_vida = 100, base_iniciativa,time;
	novo = (Lutador*)malloc(sizeof(Lutador));
	printf("Informe o time do Lutador (1|2): ");
	scanf("%d", &time);

	if (*lutador == NULL) {
		
	}

}


//void inserirInicio(TNo** L, int num) {
//	TNo* novo;
//	novo = (TNo*)malloc(sizeof(TNo));
//	novo->info = num;
//
//	if (*L == NULL) {
//		*L = novo;
//		novo->prox = NULL;
//	}
//	else {
//		novo->prox = *L;
//		*L = novo;
//	}
//}