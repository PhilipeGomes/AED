#include <stdio.h>
void troca(int *vetor, int pos1, int pos2) {
    int aux = vetor[pos1];
    vetor[pos1] = vetor[pos2];
    vetor[pos2] = aux;
}
 
 
void maxHeapfy(int *vetor, int i, int tamanho_heap, int *cont_troca) {
    int l = i * 2 + 1;
    int r = (i * 2) + 2;
    int maior = 0;
    if ((l <= tamanho_heap) && (vetor[l] > vetor[i])) {
        maior = l;
    }
    else {
        maior = i;
    }
    if ((r <= tamanho_heap) && (vetor[r] > vetor[maior])) {
        maior = r;
    }
    if (maior != i) {
        troca(vetor, i, maior);
        *cont_troca = *cont_troca + 1;
        maxHeapfy(vetor, maior, tamanho_heap,&(*cont_troca));
    }
 
}
 
void construirMaxHeap(int *vetor, int tamanho_heap, int tam_vetor, int *cont_troca,int *cont_heap_fy) {
	printf("PARTICIONA: \n");
    for (int k = (tamanho_heap - 1 / 2); k >= 0; k--) {
        maxHeapfy(vetor, k, tamanho_heap - 1,&(*cont_troca));
        *cont_heap_fy = *cont_heap_fy + 1;
        for (int i = 0; i < tam_vetor; i++) {
            printf("%d ", vetor[i]);
        }
        printf("\n");
    }
 
}
 
 
void heapsort(int *vetor, int tam_vetor, int *cont_troca,int *cont_heap_fy) {
    int tamanho_heap = tam_vetor;
    int k;
    construirMaxHeap(vetor, tamanho_heap, tam_vetor, &(*cont_troca), &(*cont_heap_fy));
    printf("\nVETOR APOS O construirMaxheap:\n");
    for (int i = 0; i < tam_vetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
 
    tamanho_heap--;
    for (k = tam_vetor - 1; k >= 1; k--) {
        troca(vetor, 0, k);
        *cont_troca = *cont_troca + 1;
        tamanho_heap = tamanho_heap - 1;
        maxHeapfy(vetor, 0, tamanho_heap, &(*cont_troca));
        *cont_heap_fy = *cont_heap_fy + 1;
    }
 
}
 
int main() {
    system("clear");
 
    int m;
    int *vetor;
    int cont_troca = 0, cont_heap_fy = 0;
    printf("Digite o tamanho do vetor:");
    scanf("%d", &m);
    vetor = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        printf("Digite um numero:");
        scanf("%d", &vetor[i]);
    }
    printf("\nVETOR ORIGINAL:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
 
    heapsort(vetor, m, &cont_troca,&cont_heap_fy);
    printf("\n");
 
    printf("\nVETOR MODIFICADO:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    printf("MAXHEAPFY: %d\n", cont_heap_fy);
    printf("Quantidade de trocas: %d\n", cont_troca);
    
 
 
    return 0;
}