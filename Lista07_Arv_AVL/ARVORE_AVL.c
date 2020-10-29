#include <stdio.h>
#include <stdlib.h>

typedef struct ArvAVL {
    int info;
    int alt;
    struct ArvAVL* esq;
    struct ArvAVL* dir;
}ArvAVL;

ArvAVL* cria_AVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(raiz != NULL) {
        raiz->alt = 0;
        raiz->info = 0;
        raiz->esq = NULL;
        raiz->dir = NULL;
    }

    return raiz;
};

int alt_NO(ArvAVL* no) {
    if(no == NULL) {
        return -1;
    }
    else {
        return  no->alt;
    }
}

int fatorBalanceamento_NO(ArvAVL* no) {
    return labs(alt_NO(no->esq) - alt_NO(no->dir));
}

int maior(int x, int y) {
    if(x > y)
        return x;
    else
        return y;    
}



int main() {
    ArvAVL* avl;

    avl = cria_AVL();

    printf("altura = %d", avl->alt);
    return 0;
}