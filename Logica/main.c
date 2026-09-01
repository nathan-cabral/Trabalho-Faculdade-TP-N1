#include<stdio.h>
#include <locale.h>


int main(){
    
    //arrumar acentuacao Pt-Br
    printf("MENU\n");
    printf("1) Obter a quantidade M (M <= 30) de elementos e também os elementos de um primeiro vetor de números inteiros\n"\
    "2) Obter a quantidade N (N <= 20) de elementos e também os elementos de um segundo vetor de números inteiros\n"\
    "3) Listar os elementos de um vetor de números inteiros\n"\
    "4) Gerar um terceiro vetor obtido através da adição de dois vetores de números inteiros (adicionar os elementos correspondentes dos dois vetores\n"\
    "5) Gerar um segundo vetor obtido através da multiplicação de um escalar por um vetor de números inteiros\n");
    int M;
    printf("Quantidade de elementos M (max: 30): ");
    scanf("%d",&M);
    while(M>30){
        printf("Valor invalido, maximo 30: ");
        scanf("%d",&M);
    }
    int vetorM[M];
    for(int i=0;i<M;i++){
        printf("Vetor M[%d]: ",i);
        scanf("%d",&vetorM[i]);
    }

    int N;
    printf("Quantidade de elementos N (max: 20): ");
    scanf("%d",&N);
    while(N>20){
        printf("Valor invalido, maximo 20: ");
        scanf("%d",&N);
    }
    int vetorN[N];
    for(int i=0;i<20;i++){
        printf("Vetor N[%d]: ",i);
        scanf("%d",&vetorN[i]);
    }




    return 0;
}