#include <stdio.h>
#include <stdlib.h>
 
typedef struct ArvoreBinaria {
	struct ArvoreBinaria* esq, * dir;
	int num;
}ABB;
 
 
void inserir(ABB** raiz, int num) { //Está sendo passada por referência o endereço do (raiz)
	ABB* novo;
	if (*raiz == NULL) {
		novo = (ABB*)malloc(sizeof(ABB));
		novo->num = num;
		novo->dir = NULL;
		novo->esq = NULL;
		*raiz = novo;
	}
	else if (num < (*raiz)->num) {
		inserir(&(*raiz)->esq, num);
	}
	else {
		inserir(&(*raiz)->dir, num);
	}
}
 
void inseirNRecursivo(ABB** raiz, int num) {
	ABB* novo, * aux;
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
 
void sucessor(ABB* raiz, int num) {
	while (raiz != NULL) {
		if (raiz->num == num) {
			if (raiz->dir != NULL) {
				printf("Sucessor: %d\n", raiz->dir->num);
				return;
			}
			else {
				printf("Sucessor eh nulo\n");
				return;
			}
		}
		if (num < raiz->num) {
			raiz = raiz->esq;
		}
		else {
			raiz = raiz->dir;
		}
	}
	printf("Nao achou o numero\n");
}
 
int main() {
	ABB* arvore = NULL;
	inserir(&arvore, 8);
	inserir(&arvore, 15);
	inserir(&arvore, 5);
	inserir(&arvore, 12);
	inserir(&arvore, 19);
	inserir(&arvore, 14);
	inserir(&arvore, 10);
	inserir(&arvore, 3);
	inserir(&arvore, 2);
	printf("\n\nImprimir EM ORDEM\n\n");
	emOrdemRecursivo(arvore);
	printf("\n\nImprimir PRE ORDEM\n\n");
	preOrdemRecursivo(arvore);
	printf("\n\nImprimir POS ORDEM\n\n");
	posOrdemRecursivo(arvore);
 
	sucessor(arvore, 19);
}