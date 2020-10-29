#define TAM 100

typedef struct Fila{
	int qtd;
	int vetor[TAM];
} Fila;

void initialize(Fila* fila);
int enqueue(Fila* fila, int num);
int dequeue(Fila* fila);
int isEmpty(Fila* fila);
int isFull(Fila* fila);