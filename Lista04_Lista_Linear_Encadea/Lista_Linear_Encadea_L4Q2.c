#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NoListaDuplaEnc {
	int chave;
	struct NoListaDuplaEnc* anterior;
	struct NoListaDuplaEnc* proximo;
}NoListaDuplaEnc;

typedef struct ListaDuplaEnc {
	struct NoListaDuplaEnc* cabeca;
	struct NoListaDuplaEnc* fim;
}ListaDuplaEnc;

ListaDuplaEnc* alocarLista() {
	ListaDuplaEnc* aux = (ListaDuplaEnc*)malloc(sizeof(ListaDuplaEnc));
	aux->cabeca = NULL;
	aux->fim = NULL;
	return aux;
}


NoListaDuplaEnc* BuscarListaDuplaEnc(int x, ListaDuplaEnc* l) {
	NoListaDuplaEnc *aux, *pt = l->cabeca;
	if (l->cabeca == NULL) {
		return NULL;
	}
	else {
		if (pt->chave == x) {
			return pt;
		}
		else {
			aux = pt;
			pt = pt->proximo;
			while (pt != aux) {
				if (pt->chave == x) {
					return pt;
				}
				else if(pt->chave>= x) {
					return NULL;
				}
				pt = pt->proximo;
			}
			return NULL;
		}
	}
}

void InserirListaDuplaEnc(ListaDuplaEnc* l, int chave) {
	NoListaDuplaEnc* no = (NoListaDuplaEnc*)malloc(sizeof(NoListaDuplaEnc));
	no->chave = chave;
	NoListaDuplaEnc* pt = BuscarListaDuplaEnc(no->chave, l);
	NoListaDuplaEnc* aux = l->cabeca;
	if (pt == NULL) {
		if (l->cabeca == NULL) {
			no->anterior = no;
			no->proximo = no;
			l->cabeca = no;
			l->fim = no;
		}
		else if (no->chave < aux->chave) {
			no->proximo = aux;
			no->anterior = aux->anterior;
			aux->anterior->proximo = no;
			aux->anterior = no;
			l->cabeca = no;
			l->fim = no->anterior;
		}
		else {
			while (no->chave > aux->chave && aux->proximo->chave != l->cabeca->chave) {
				aux = aux->proximo;
			}
			if (no->chave < aux->chave) {
				no->proximo = aux;
				no->anterior = aux->anterior;
				no->anterior->proximo = no;
				aux->anterior = no;
			}
			else {
				no->anterior = aux;
				no->proximo = aux->proximo;
				aux->proximo->anterior = no;
				aux->proximo = no;
				l->fim = no;
			}
		}
	}
	else printf("ERRO: No %d ja existe\n", no->chave);
}

void RemoverListaDuplaEnc(int x, ListaDuplaEnc* l) {
	NoListaDuplaEnc* pt = BuscarListaDuplaEnc(x, l);
	if (pt != NULL) {
		if (l->cabeca->chave == x) {
			pt->proximo->anterior = pt->anterior;
			pt->anterior->proximo = pt->proximo;
			l->cabeca = pt->proximo;
		}
		else {
			pt->anterior->proximo = pt->proximo;
			pt->proximo->anterior = pt->anterior;
			if (pt->chave == l->fim->chave)l->fim = pt->anterior;
		}
		pt->proximo = NULL;
		pt->anterior = NULL;
	}
	else printf("\nERRO: No %d nao existe na lista\n", x);
}

void ImprimirListaDuplaEnc(ListaDuplaEnc* l, int tipo) {
	NoListaDuplaEnc* pt, *aux;
	if (l->cabeca == NULL) {
		printf("LISTA VAZIA\n");
	}
	else {
		if (tipo == 1) {
			pt = l->cabeca;
			aux = l->cabeca;
			while (pt->proximo != aux) {
				printf("%d->",pt->chave);
				pt = pt->proximo;
			}
			printf("%d\n", pt->chave);
		}
		else {
			pt = l->fim;
			aux = l->fim;
			while (pt->anterior != aux) {
				printf("%d->", pt->chave);
				pt = pt->anterior;
			}
			printf("%d\n", pt->chave);
		}
	}
}

int main(void) {
	system("clear");
	ListaDuplaEnc* Lista = alocarLista();
	int opc;
	int valor;
	int imprimir = -1;
	setlocale(LC_ALL, "portuguese");
	system("clear");
	do {
		printf("    MENU    \n\n");
		printf("1.Inserir Lista\n");
		printf("2.Remover Lista\n");
		printf("3.Buscar valor\n");
		printf("4.Imprimir lista\n\n");
		printf("Digite sua opcao: ");
		scanf("%d", &opc);
		switch (opc) {

		case 1:
			system("clear");
			printf("Informe o valor para inserir: ");
			scanf("%d", &valor);
			InserirListaDuplaEnc(Lista, valor);
			break;
		case 2:
			system("clear");
			printf("Informe o valor para remover: ");
			scanf("%d", &valor);
			RemoverListaDuplaEnc(valor, Lista);
			break;
		case 3:
			printf("Informe o valor a ser buscado: ");
			scanf("%d", &valor);
			if (BuscarListaDuplaEnc(valor, Lista) == NULL) {
				printf("Valor %d não encontrado\n", valor);
			}
			else {
				printf("Valor %d encontrado na lista\n", valor);
			}
			break;
		case 4:
			system("clear");
			printf("Informe como deseja imprimir.\n");
			printf("1. Direta\n");
			printf("2. Reversa\n");
			printf("Informe a opção: ");
			scanf("%d", &imprimir);
			ImprimirListaDuplaEnc(Lista, imprimir);
			break;
		default:
			break;
		}
		// system("clear");
	} while (opc != 0);
	printf("ACABOUUUUU\n");
	return 0;
}