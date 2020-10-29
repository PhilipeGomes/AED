#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NoHashTable {
    int chave;
    struct NoHashTable* proximo;
}NoHashTable;
 
typedef struct HashTable {
    NoHashTable* tabela;
}HashTable;
 
HashTable* criarLista() {
    NoHashTable* l = (NoHashTable*)malloc(sizeof(NoHashTable));
    l = NULL;
    return l;
}
 
void inicializar_tabela(int tamanho, HashTable** tabela) {
    int i;
    for (i = 0; i < tamanho; i++) {
        tabela[i]->tabela = criarLista();
    }
}
 
int hashFunction(int chave, int tamanho) {
    return chave % tamanho;
}
 
void inserirLista(NoHashTable** L, int num) {
    NoHashTable* aux;
    NoHashTable* novo = (NoHashTable*)malloc(sizeof(NoHashTable));
    novo->proximo = NULL;
    novo->chave = num;
    if (*L == NULL) {
        *L = novo;
    }
    else {
        aux = *L;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}
 
NoHashTable* searchLista(NoHashTable* L, int chave) {
    NoHashTable* aux;
    aux = L;
    while (aux != NULL) {
        if (aux->chave == chave) {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}
 
void removerLista(NoHashTable** L, int num) {
    if (L == NULL) {
        printf("Erro.Lista não existe\n");
    }if ((*L) == NULL) {
        printf("Erro.Lista vazia\n");
    }
    NoHashTable* aux = *L;
    NoHashTable* ant = *L;
    while (aux->chave != num && aux != NULL) {
        aux = aux->proximo;
        ant = aux;
    }if (aux->chave == num) {
        ant->proximo = aux->proximo;
        aux = NULL;
    }
    else {
        printf("Erro, chave inexistente\n");
    }
}
 
NoHashTable* searchHashTableClosed(HashTable* hashTableClosed, int chave, int tamanho) {
    NoHashTable* L;
    int k = hashFunction(chave, tamanho);
    L = hashTableClosed[k].tabela;
    return searchLista(L, chave);
}
 
void insertHashTableClosed(HashTable* hashTable, int chave, int tamanho) {
    NoHashTable* L;
    int k = hashFunction(chave, tamanho);
    L = hashTable[k].tabela;
    inserirLista(&L, chave);
}
 
void removerTabelaHashClosed(HashTable* hashTable, int chave, int tamanho) {
    NoHashTable* L;
    int k = hashFunction(chave, tamanho);
    L = hashTable[k].tabela;
    removerLista(L, chave);
}
 
void Imprimir_tabela(HashTable* HashTable, int tamanho) {
    NoHashTable* no = HashTable->tabela;
    int i = 0;
    system("clear");
    printf("-=-=-=-=-= PRINT TABELA-=-=-=-=-=-=\n\n");
    for (i = 0; i < tamanho; i++) {
        printf("Lista posição: %d\n", i);
        printf("%d\n", no->chave);
    }
}
 
int main() {
    int tamanho_tabela, opc, chave;
 
    printf("digite o tamanho da tabela:");
    scanf("%d", &tamanho_tabela);
 
    HashTable tabela[tamanho_tabela];
    inicializar_tabela(tamanho_tabela, &tabela);
    do {
        printf("\nMENU\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Buscar\n");
        printf("4. Imprimir\n");
        printf("5. Sair\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            printf("Digite a chave:");
            scanf("%d", &chave);
            insertHashTableClosed(tabela, chave, tamanho_tabela);
            break;
        case 2:
            printf("Digite a chave:");
            scanf("%d", &chave);
            removerTabelaHashClosed(tabela, chave, tamanho_tabela);
            break;
        case 3:
            printf("Digite a chave:");
            scanf("%d", &chave);
            if (searchHashTableClosed(tabela, chave, tamanho_tabela) == NULL) {
                printf("No não encontrado;");
            }else {
                printf("A chave do no eh: %d", chave);
            }
            break;
        case 4:
            Imprimir_tabela(tabela, tamanho_tabela);
            break;
        }
    } while (opc != 5);
    return 0;
}