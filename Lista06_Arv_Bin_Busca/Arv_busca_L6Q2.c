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
 
void emOrdemRecursivo(ABB* raiz) {
	if (raiz != NULL) {
		emOrdemRecursivo(raiz->esq);
		printf("%d\n", raiz->num);
		emOrdemRecursivo(raiz->dir);
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
 
/*Remoção*/
 
ABB* maior(ABB** raiz) {
	ABB* aux, * pai;
	if (*raiz == NULL) {
		return NULL;
	}
	else {
		aux = *raiz;
		while (aux->dir != NULL) {
			pai = aux;
			aux = aux->dir;
			pai->dir = aux->esq;
		}
		return aux;
	}
}
 
void removerNo(ABB** raiz) {
	ABB* pos;
	if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
		*raiz = NULL;
	}
	else if ((*raiz)->esq == NULL) {
		*raiz = (*raiz)->dir;
	}
	else if ((*raiz)->dir == NULL) {
		*raiz = (*raiz)->esq;
	}
	else {
		pos = maior(&((*raiz)->esq));
		(*raiz)->num = pos->num;
	}
}
 
void remover(ABB** raiz, int num) {
	if (*raiz == NULL) {
		printf("Vazia\n\n");
	}
	else if (num == (*raiz)->num) {
		removerNo(&(*raiz));
	}
	else if (num < (*raiz)->num) {
		removerNo(&((*raiz)->esq));
	}
	else {
		removerNo(&((*raiz)->dir));
	}
}
 
/*Fim Remoção*/
 
 
int main() {
	ABB* arvore = NULL, * aux = NULL;
	int op, valor;
	setlocale(LC_ALL, "portuguese");
 
	do {
		printf(" ===MENU=== \n\n");
		printf("1. Inserir\n");
		printf("2. Imprimir Arvore\n");
		printf("3. Buscar\n");
		printf("4. Remover\n");
		printf("5. Sair\n\n");
		printf("Opcao: ");
		scanf("%d", &op);
		if (op == 1) {
			printf("Informe o valor: ");
			scanf("%d", &valor);
			inserir(&arvore, valor);
			printf("Valor %d inserido na árvore\n", valor);
		}
		else if (op == 2) {
			emOrdemRecursivo(arvore);
		}
		else if (op == 3) {
			printf("Informe o valor: ");
			scanf("%d", &valor);
			aux = busca(arvore, valor);
			if (aux != NULL) {
				printf("Valor %d encontrado na árvore\n", aux->num);
			}
			else {
				printf("Valor %d não encontrado na árvore\n", valor);
			}
		}
		else if (op == 4) {
			printf("Informe o valor: ");
			scanf("%d", &valor);
			remover(&arvore, valor);
			printf("Valor %d removido da árvore\n", valor);
		}
	} while (op != 5);
 
}