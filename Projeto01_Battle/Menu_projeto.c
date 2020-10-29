#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
void print(int i){
  int j;
  for(j = 0; j < i;j++){
    printf("-");
    sleep(1/2);
  }
}

void print_imagem(){
printf("             XX                                   XX\n"
"           XX  X                                 X  XX\n"
"         XX     X                               X     XX\n"
"    XXXXX     XX                                 XX     XXXXX\n"
"   X        XX%%;;@                            @%%%;;XX        X\n"
"   X       X  @%%%;;@                         @%%%;;@  X       X\n"
"   X      X     @%%%;;@                     @%%%;;@     X      X\n"
"    X    X        @%%%;;@                 @%%%;;@        X    X\n"
"     X   X          @%%%;;@             @%%%;;@          X   X\n"
"      X  X            @%%%;;@         @%%%;;@            X  X\n"
"       XX X             @%%%;;@     @%%%;;@             X XX\n"
"         XXX              @%%%;;@  @%%%;;@              XXX\n"
"                            @%%%;;%%%;;@\n"
"                              @%%%;;@\n"
"                            @%%%;;@..@@\n"
);
}

int main(){
    setlocale(LC_ALL, "ptbr");
    system("clear");
    printf("\t\t*******BEM-VINDOS À BATALHA *******\n\n");
    print_imagem();
    printf("\nJOGADOR 1:");
    printf("\nMonte seu exército para a batalha!");
    //chama a função inserir
    printf("\nJOGADOR 2:");
    printf("\nMonte seu exército para a batalha!");
    //chama a função inserir
    getchar();
    system("clear");
    int opc, i, relat_time;
    do{
      system("clear");
      printf("\n\n\t\t-=-=-=-=-=-=-=-=-= MENU -=-=-=-=-=-=-=-=-=-=\n\n\n");
      printf("1.INSERIR JOGADOR\n");
      printf("2.RELATÓRIO DO TIME\n");
      printf("3.FUGA DE LUTADOR\n");
      printf("4.INICIAR COMBATE\n"); 
      printf("5.SAIR\n");   
      printf("\nOpção:");
      scanf("%d", &opc);
      for(i = 0; i<=100;i++){
        system("clear");
        if(i%10==0 && opc == 4){
        print(i);
        printf("%d%%\n", i);
        sleep(1);
        }
      }
      switch(opc){
        case 1:break;
        case 2:
        printf("RELATÓRIO DO TIME 1 OU 2:");
        scanf("%d",&relat_time);
        //chamar a função passando relat
        break;
        case 3:
        printf("INFORME O ID DO LUTADOR:");
        //scanf("%d",) preciso saber qual o tipo que sera o id
        break;
        case 4:break;
        case 5:break;
        default:;
      }
    } while (opc != 5);

    return 0;
}