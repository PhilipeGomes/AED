#include <stdlib.h>
#include <stdio.h>

typedef struct Notabela {
    int valor;
    int chave;
}Notabela;


void display(Notabela* vetor, int size) {
    int i;
    printf("valor\tchave\n");
    for (i = 0; i < size; i++) {
        printf("%d\t%d\n",vetor[i].valor, vetor[i].chave);
    }
    
}


int main(){
    system("clear");
    int size, i, temp;
    printf("qual o tamanho?");
    scanf("%d", &size);
    Notabela vetor_tabela[size];

    for(i = 0; i<size; i++) {
        printf("digite um valor: ");
        scanf("%d", &temp);
        vetor_tabela[temp % size].valor = temp;
        vetor_tabela[temp % size].chave = temp % size;
    }
    printf("\n");
    display(vetor_tabela,size);
    return 0;
}


