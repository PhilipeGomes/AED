#include <stdio.h>
#include <stdlib.h>
 
typedef struct ArvoreBinaria {
	struct ArvoreBinaria* esq, * dir;
	int num;
}ABB;
 
typedef struct Arvore {
	ABB* arvore;
}Arvore;
 
void inserirRecursivo(Arvore** raiz, int num) { 
	ABB* novo;
	if ((*raiz)->arvore == NULL) {
		novo = (ABB*)malloc(sizeof(ABB));
		novo->num = num;
		novo->dir = NULL;
		novo->esq = NULL;
 
		(*raiz)->arvore = novo;
	}
	else if (num < (*raiz)->arvore->num) {
		inserirRecursivo(&((*raiz)->arvore->esq), num);
	}
	else {
		inserirRecursivo(&((*raiz)->arvore->dir), num);
	}
}
 
void inseirImperativo(ABB** raiz, int num) {
	ABB* novo, *aux;
	novo = (ABB*)malloc(sizeof(ABB));
	novo->num = num;
	novo->dir = NULL;
	novo->esq = NULL;
 
	if (*raiz == NULL) {
		*raiz = novo;
	}
	else {
		aux = *raiz;
		while (aux != NULL) {
			if (num < aux->num) {
				if (aux->esq != NULL) {
					aux = aux->esq;
				}
				else {
					aux->esq = novo;
					break;
				}
			}
			else {
				if (aux->dir != NULL) {
					aux = aux->dir;
				}
				else {
					aux->dir = novo;
					break;
				}
			}
		}
	}
}
 
void emOrdemRecursivo(ABB* raiz) {
	if (raiz != NULL) {
		emOrdemRecursivo(raiz->esq);
		printf("%d\n", raiz->num);
		emOrdemRecursivo(raiz->dir);
	}
}
 
void preOrdemRecursivo(ABB* raiz) {
	if (raiz != NULL) {
		printf("%d\n", raiz->num);
		emOrdemRecursivo(raiz->esq);
		emOrdemRecursivo(raiz->dir);
	}
}
 
void posOrdemRecursivo(ABB* raiz) {
	if (raiz != NULL) {
		emOrdemRecursivo(raiz->esq);
		emOrdemRecursivo(raiz->dir);
		printf("%d\n", raiz->num);
	}
}
 
int main() {
	Arvore* arvore = NULL;
	arvore = (Arvore*)malloc(sizeof(Arvore));
	arvore->arvore = NULL;
	
  inseirImperativo(&arvore, 8); //problemas nessa passagem

//o inserir imperativo só consegui usando uma unica struct. Se for pra usar 2, mesmo problema com ponteiros.


	inserirRecursivo(&arvore, 8);
    inserirRecursivo(&arvore, 15);
	inserirRecursivo(&arvore, 5);
	inserirRecursivo(&arvore, 12);
    inserirRecursivo(&arvore, 19);
	inserirRecursivo(&arvore, 14);
	inserirRecursivo(&arvore, 10);
	inserirRecursivo(&arvore, 3);
	inserirRecursivo(&arvore, 2);
	printf("\n\nImprimir EM ORDEM\n\n");
	emOrdemRecursivo(arvore); //problemas nessa passagem
	printf("\n\nImprimir PRE ORDEM\n\n");
	preOrdemRecursivo(arvore); //problemas nessa passagem
	printf("\n\nImprimir POS ORDEM\n\n");
	posOrdemRecursivo(arvore); //problemas nessa passagem
}