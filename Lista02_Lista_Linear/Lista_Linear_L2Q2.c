#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct NoListSeq{
    int maximo;
    int ultimo;
    int *dados;
}NoListSeq;

void inicializar_lista(NoListSeq *lista, int m){
    int i;
    lista->ultimo = 0;
    lista->maximo = m;
    lista->dados = (int *)malloc(m * sizeof(int));
    for (i=0;i<m;i++){
        lista->dados[i] = NULL;
    }
}

void inserir_ordenado(NoListSeq *lista,int elemento){
    int i,j,status = 0;
    NoListSeq l = *lista;
    if (lista->ultimo < lista->maximo){
        if(buscar_elemento(l,elemento) == -1){
            if (lista->ultimo == 0){
                lista->dados[lista->ultimo] = elemento;
                lista->ultimo++;
                printf("Valor %d inserido!\n",elemento);
                return;
            }
            for(i=0;i<lista->ultimo;i++){
                if(lista->dados[i] > elemento){
                    break;
                }
            }
            
            for(j=lista->ultimo;j>i;j--){
                lista->dados[j] = lista->dados[j-1];
            }
            lista->dados[i] = elemento;
            lista->ultimo++;
            printf("Valor %d inserido!\n",elemento);
        }
        else{
            printf("Valor já existe!\n");
        }
    }
    else{
        printf("Lista cheia!\n");
    }
}

int buscar_elemento(NoListSeq lista, int elemento){
    int i;
    int n = lista.ultimo;
    NoListSeq l = lista;
    for (i=0;i<n;i++){
        if (l.dados[i] == elemento){
            if ( l.dados[i] > elemento){
                return -1;
            }
            return i;
        }
    }
    return -1; 
}

void imprimir_lista(NoListSeq lista){
    int i;
    for (i = 0; i<lista.maximo;i++){
        if (lista.dados[i] == NULL){
            printf("NULL ");
        }
        else{
            printf("%d ",lista.dados[i]);
        }
        if (i < lista.maximo - 1){
            printf("-> ");
        }
    }
    printf("\n\n");
}

void remover_lista(NoListSeq *lista,int elemento){
    int removido = 0;
    int n = lista->ultimo;
    int indice = buscar_elemento(*lista,elemento);
    if (indice != -1){
        lista->dados[indice] = NULL;
        lista->ultimo--;
        printf("%d removido!\n",elemento);
    }
    else{
        printf("Valor %d não existe\n",elemento);
    }
}

int main(){
    int opc;
    int m,valor;
    setlocale(LC_ALL, "ptbr");
    NoListSeq no;
    system("clear");
    printf("Informe o valor para o M: ");
    scanf("%d", &m);
    inicializar_lista(&no,m);
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
            inserir_ordenado(&no,valor);
			break;
        case 2:
            system("clear");
			printf("Informe o valor para remover: ");
            scanf("%d", &valor);
            remover_lista(&no,valor);
            break;
        case 3:
            printf("Informe o valor a ser buscado: ");
            scanf("%d",&valor);
            if (buscar_elemento(no,valor) == -1){
                printf("Valor %d não encontrado\n",valor);
            }
            else{
                printf("Valor %d encontrado na lista\n",valor);
            }
            break;
        case 4:
            system("clear");
            imprimir_lista(no);
            break;
        default:
            break;
        }
        // system("clear");
	} while (opc != 0);

    return 0;
}