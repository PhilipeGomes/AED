typedef struct Lutador {
	int ID;
	int time;
	int valor_dano;
	int numero_vida;
	int base_iniciativa;
	struct Lutador* proximo;
}Lutador;

typedef struct Time {
	Lutador* lutador;
	Lutador* inicio;
	Lutador* fim;
}Time;
