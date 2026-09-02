#include<stdio.h>
void texto(){
    printf("programa encerrado");
}
int main(){
    int vet[20];
    for(int i=0;i<20;i++){
        scanf("%d",&vet[i]);
    }
    texto();

    return 0;
}