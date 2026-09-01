#include<stdio.h>

int obterValorM(){
    int M;
    printf("Quantidade de elementos M (max: 30): ");
    scanf("%d",&M);
    while(M<1 || M>30){
        printf("Valor invalido. Digite um valor entre 1 e 30: ");
        scanf("%d",&M);
    }
    return M;
}

void lerVetor(int vetor[], int tamanho){
    for(int i=0;i<tamanho;i++){
        printf("Vetor M[%d]= ",i);
        scanf("%d",&vetor[i]);
    }
}

int obterValorN(){
    int N;
    printf("Quantidade de elementos N (max: 20): ");
    scanf("%d",&N);
    while(N<1 || N>20){
        printf("Valor invalido. Digite um valor entre 1 e 20: ");
        scanf("%d",&N);
    }
    return N;
}

void listarVetor(int vetor[],int tamanho){
    for(int i=0;i<tamanho;i++){
        printf("%d\n",vetor[i]);
    }
}

void MenuPrincipal(){
    printf(
    "\n"
    "===============================================================\n"
    "                       MENU PRINCIPAL\n"
    "===============================================================\n"
    " [1] Ler primeiro vetor (M <= 30)\n"
    "     - Informar quantidade e elementos\n\n"

    " [2] Ler segundo vetor (N <= 20)\n"
    "     - Informar quantidade e elementos\n\n"

    " [3] Listar elementos de um vetor\n\n"

    " [4] Somar dois vetores\n"
    "     - Gerar terceiro vetor com a soma dos elementos\n\n"

    " [5] Multiplicar vetor por escalar\n"
    "     - Gerar novo vetor resultante\n\n"

    " [0] Sair\n"
    "===============================================================\n");

}


int main(){
    int vetorM[30],vetorN[20];
    int entryM=0,entryN=0;
    int M=0,N=0;
    int menuEscolha;
    char escolhaLisatgem;
    MenuPrincipal();
    printf("Escolha uma opcao: ");
    scanf("%d",&menuEscolha);
    while(menuEscolha!=0){
        switch(menuEscolha){
        case 1:
            M=obterValorM();
            lerVetor(vetorM,M);
            entryM++;
            break;
        case 2:
            N=obterValorN();
            lerVetor(vetorN,N);
            entryN++;
            break;
        case 3: 
            printf("\n--- LISTAR VETOR ---\n");
            printf("Escolha o vetor que deseja listar [M/N]: "); 
            scanf(" %c",&escolhaLisatgem);
            if(escolhaLisatgem=='M'){
                if(entryM==0){
                    printf("esse vetor ainda nao existe, crie-o escolhendo 1 no menu");
                }else{
                    listarVetor(vetorM,M);
                }
            }else if(escolhaLisatgem=='N'){
                if(entryN==0){
                    printf("esse vetor ainda nao existe, crie-o escolhendo 2 no menu");
                }else{
                    listarVetor(vetorN,N);
                }
            }
            break;
        

        }
        MenuPrincipal();
        printf("Escolha uma opcao: ");
        scanf("%d",&menuEscolha);

    }


    return 0;
}