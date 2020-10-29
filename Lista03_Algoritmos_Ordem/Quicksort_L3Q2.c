#include <stdio.h>
#include <stdlib.h>
 void troca(int *vet,int a, int b) {
	int aux;
	aux = vet[a];
	vet[a] = vet[b];
	vet[b] = aux;
}
int particiona(int *vet, int esquerda, int direita,int *cont_troca) {
	int ptr = esquerda - 1;
	int pivo = vet[direita];
	int i;
	for (i = esquerda; i < direita; i++) {
		if (vet[i] <= pivo) {
			ptr++;
			troca(vet,ptr,i);
			*cont_troca = *cont_troca + 1;
		}
	}
	troca(vet,ptr + 1,direita);
	*cont_troca = *cont_troca + 1;
	return ptr + 1;
}
 
 
void quickSort(int *vet, int esquerda, int direita,int tam,int *cont_troca) {
	int pivo;
	if (esquerda < direita) {
		pivo = particiona(vet, esquerda, direita,&(*cont_troca));
		printf("PARTICIONA: ");
		for (int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    	}printf("\n");
		quickSort(vet,esquerda,pivo - 1,tam,&(*cont_troca));
		quickSort(vet,pivo + 1,direita,tam,&(*cont_troca));
	}
 
}
 
int main() {
	system("clear");
	int *vet, tam, i, cont_troca = 0;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam);
	vet = (int*)malloc(tam * sizeof(int));
	for (i = 0; i < tam; i++) {
		printf("Digite um numero:");
		scanf("%d", &vet[i]);
	}
	printf("\nVETOR ORIGINAL\n");
	for (i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
	quickSort(vet, 0, tam - 1, tam, &cont_troca);
	printf("\nVETOR ORDENADO\n");
	for (i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }printf("\n");
	printf("Quantidade de trocas: %d", cont_troca);
	printf("\n");
	return 0;
}