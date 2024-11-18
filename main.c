#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int valor;
    int estado;
}dado;

void jogar(int x,char j1[], char j2[],dado dados[]){
    int i;
    srand(time(NULL));

    for (i = 0; i < 6; i++) {
        dados[i].estado = -1;  // Nenhum dado guardado inicialmente
        dados[i].valor = 0;  // Valor inicial do dado
    }
    
    if(x == 1){
        for(i=0;i<6;i++){
            if(dados[i].estado == -1){
                dados[i].valor = (rand() % 6+1);
                printf("Dado %d: %d\n",i+1,dados[i].valor);
            }
        }
    }
    else{
        printf("Vez do jogador: %s\n",j2);
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
