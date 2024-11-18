#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int valor;
    int estado;
}dado;

void jogar(int x,char j1[], char j2[],dado dados[]){
    int i,op1=0,re_roll=0,op2=0;
    srand(time(NULL));

    for (i = 0; i < 6; i++) {
        dados[i].estado = -1;  // Nenhum dado guardado inicialmente pelo jogador
        dados[i].valor = 0;  // Valor inicial do dado
    }
    
    if(x == 1){
        printf("Vez do jogador %s\n",j1);
        do{
          for(i=0;i<6;i++){
              if(dados[i].estado == -1){
                  dados[i].valor = (rand() % 6+1);
                  printf("Dado %d: %d\n",i+1,dados[i].valor);
              }
          }
          printf("Escolher dados para guardar (1-6)\n(0 - para nao guradar mais): \n");
          do{
            printf("--> ");
            scanf("%d",&op2);
            if(op2 > 0 && op2 <= 6){
              dados[op2-1].estado = 1;
            }
          }while(op2 != 0);
          printf("Deseja lançar de novo os dados? \n(0- Nao 1- Sim )\n--> ");
          scanf("%d",&op1);
          re_roll++;
          if(re_roll >= 3){
            op1=0;
          }
        }while(op1 != 0);
    }
    else{
        printf("Vez do jogador %s\n",j2);
        for(i=0;i<6;i++){
            if(dados[i].estado == -1){
                dados[i].valor = (rand() % 6+1);
                printf("Dado %d: %d\n",i+1,dados[i].valor);
            }
        }
    }
    getchar();
}

int main(){
    int turno=1,i,tabela[2][20];
    char p1[30], p2[30];
    dado dados[6];
    
    printf("Intruduzir nome do jogador 1: ");
    scanf("%s",p1);
    printf("Intruduzir nome do jogador 2: ");
    scanf("%s",p2);
    getchar();
    
    for(i=0;i<40;i++){
        jogar(turno,p1,p2,dados);
        turno *= -1;
    }
    
    return 0;
}
