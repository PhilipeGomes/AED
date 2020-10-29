#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
 
typedef struct ArvoreBinaria {
	struct ArvoreBinaria* esq, * dir;
	int num;
}ABB;
 
void inserir(ABB** raiz, int num) {
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
 
ABB* busca(ABB* raiz, int num) {
	while (raiz != NULL) {
		if (raiz->num == num) {
			return raiz;
		}
		else if (num < raiz->num) {
			raiz = raiz->esq;
		}
		else {
			raiz = raiz->dir;
		}
	}
	return NULL;
}
 
 
ABB* noPai(ABB* raiz, int num) {
	while (raiz != NULL) {
		if (raiz->dir != NULL && raiz->esq != NULL) {
			if (raiz->num == raiz->dir->num || raiz->num == raiz->esq->num) {
				return raiz;
			}
		}
		else if (raiz->dir == NULL && num == raiz->esq->num) {
			return raiz;
		}
		else if (raiz->esq == NULL && num == raiz->dir->num) {
			return raiz;
		}
		if (num < raiz->num) {
			raiz = raiz->esq;
		}
		else {
			raiz = raiz->dir;
		}
	}
	return NULL;
}
 
ABB* sucessor(ABB* raiz, int num) {
	ABB*pai, * aux = busca(raiz, num);
	if (aux == NULL) {
		return NULL;
	}
	if (aux->dir != NULL) {
		aux = aux->dir;
		while (aux != NULL && aux->esq != NULL) {
			aux = aux->esq;
		}
		return aux;
	}
	else {
		pai = noPai(raiz, num);
		while (pai != NULL && aux == pai->dir) {
			pai = noPai(raiz, pai->num);
		}
		return pai;
	}
	return NULL;
}
 
int main() {
	ABB* arvore = NULL, * aux = NULL;
	int op, valor;
	setlocale(LC_ALL, "portuguese");
 
	do {
		printf(" ===MENU=== \n\n");
		printf("1. Inserir\n");
		printf("2. Sucessor\n\n");
		printf("3. Sair\n\n");
		printf("Opcao: ");
		scanf("%d", &op);
		if (op == 1) {
			printf("Informe o valor: ");
			scanf("%d", &valor);
			inserir(&arvore, valor);
			printf("Valor %d inserido na árvore\n", valor);
		}
		else if (op == 2) {
			printf("Informe o valor para encontrar seu sucessor: ");
			scanf("%d", &valor);
			aux = sucessor(arvore, valor);
			if (aux == NULL) {
				printf("Valor não encontrado\n");
			}
			else {
				printf("Sucessor de %d, é o %d\n",valor,aux->num);
			}
		}
	} while (op != 3);
 
}