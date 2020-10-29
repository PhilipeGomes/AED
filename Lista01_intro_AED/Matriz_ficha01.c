#include <stdio.h>

int main(){
system("clear");    
int linA, colA, linB, colB;
int i, j;

printf("\n\t\tProduto de matrizes\n\n");
printf("Quantidades de linhas de A =\n");
scanf("%d",&linA);
printf("Quantidade de colunas de A =\n");
scanf("%d",&colA);
printf("Quantidade de linhas de B =\n");
scanf("%d",&linB);
printf("Quantidade de colunas de B =\n");
scanf("%d",&colB);
printf("%d %d %d %d \n", linA, colA, linB, colB);

int A[linA] [colA], B[linB] [colB];

if(colA != linB){
    printf("Multiplicação não pode ser realizada!\n");
    printf("A quantidade de colunas de A é diferente do número  de linhas  de B.\n");
    return 0;
}
system("clear");
//CARREGAMENTO DA MATRIZ
printf("\n CARREGANDO A MATRIZ A\n\n");


for(i=0; i< linA; i++){
    for (j = 0; j < colA; j++)
    {
        printf("A[%d][%d]:", i, j);
        scanf("%d",&A[i][j]);
    }
    
}

printf("\n CARREGANDO A MATRIZ B\n\n");
for(i=0; i< linB; i++){
    for (j = 0; j < colB; j++)
    {
        printf("B[%d][%d]:", i, j);
        scanf("%d",&B[i][j]);
    }
    
}
printf("MATRIZ A");
for(i=0; i< linA; i++){
    for (j = 0; j < colA; j++)
    {
        printf("%d ",A[i][j]);
    
    }printf("\n");
}
printf("MATRIZ B");
for(i=0; i< linB; i++){
    for (j = 0; j < colB; j++)
    {
        printf("%d ",B[i][j]);
    
    }printf("\n");
}
getchar();


int k1, k2, temp;
int C[linA][colB];
system("clear");
//MULTIPLICAÇÃO

for ( k1 = 0; k1 < linA ; k1++)
{
    for (k2 = 0; k2 < colB; k2++)
    {temp = 0;
        for (i = 0; i < colA; i++)
        {
           temp = temp + A[k1][i] * B[i][k2];   
        }C[k1][k2] = temp;
        
    }
    
}
//PRINT MATRIZ C
printf("\n\nMATRIZ C = A x B\n\n");

for(i=0; i< linA; i++){
    for (j = 0; j < colB; j++)
    {
        printf("%d ",C[i][j]);
    
    }printf("\n");
}

return 0;
}
