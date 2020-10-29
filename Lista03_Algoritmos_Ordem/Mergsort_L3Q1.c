#include <stdio.h>

void conquistar(int *vetor,int inicio1,int fim1,int inicio2, int fim2, int m){
    int temp[fim2 - inicio1 + 1];
    int i, j, k;
    i = inicio1;
    j =inicio2;
    k=0;
    
    while(i <= fim1 && j <= fim2){
        if (vetor[i] < vetor[j])
        {
            temp[k++] = vetor[i++];
        }else
        {
            temp[k++] = vetor[j++];
        }        
    }
    while (i <= fim1)
    {
        temp[k++] = vetor[i++];
    }
    while (j <= fim2)
    {
        temp[k++] = vetor[j++];
    }

    for (i = inicio1, j = 0; i <= fim2; i++,j++)
    {
        vetor[i] = temp[j];
    }
    printf("\nprint do vetor de dados modificado:\n");
        for (i = 0; i <= m; i++,j++)
    {
        printf("%d ",vetor[i]);
    }
    
};

void dividir(int *vetor,int inicio,int fim,int m ){
    if (inicio < fim){
        int meio = (fim + inicio) /2;
        dividir(vetor, inicio, meio, m);
        dividir(vetor, meio + 1, fim, m);
        conquistar(vetor, inicio, meio, meio + 1, fim, m);
    }
}

int main(){
    system("clear");
    int m;
    printf("Informe o valor de m:");
    scanf("%d",&m);
    int vetor[m];
    for (int i = 0; i<m ; i++)
    {
        printf("digite:");
        scanf("%d", &vetor[i]);
    }
    printf("Print vetor original\n");
        for (int i = 0; i<m ; i++)
    {
        printf("%d ", vetor[i]);
    }
    
    dividir(vetor, 0, m - 1, m-1);
    return 0;
}