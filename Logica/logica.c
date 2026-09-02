#include<stdio.h>
void texto(){
    printf("programa encerrado\n");
}

int idade(int i){
    if(i<13){
        printf("crianca\n");
    }else if(i<18){
        printf("adolescente\n");
    }else{
        printf("adulto\n");
    }
}
int main(){
    int vet[20];
    for(int i=0;i<20;i++){
        scanf("%d",&vet[i]);
    }
    texto();
    int idade;
    scanf("%d",&idade);

    return 0;
}