#include<stdio.h>
#include<stdlib.h>

#define tam_m 30
#define tam_n 20
#define tam_maximo (tam_m+tam_n)

int vetM[tam_m];
int vetN[tam_n];
int vetSoma[tam_m];
int vetEscalarM[tam_m];
int vetEscalarN[tam_n];
int vetEscalarSoma[tam_m];
int vetEscalarUnico[tam_maximo];
int vetEscalarIntercalado[tam_maximo];
int vetUnico[tam_maximo];
int vetIntercalado[tam_maximo];

typedef struct{
    int M,N;
    int checkM,checkN,checkS;
    int checkEM,checkEN,checkU;
    int checkES, checkEU,checkEI;
    int checkI,tamU,tamI;
}Estado;

void cls(){
    system("cls");
}

void pause(){
    printf("\n");
    system("pause");
}


// leitura
void lerVetor(int vetor[],int tamanho, char nomeVetor){

    printf("\nInforme os elementos do vetor %c:\n",nomeVetor);
    printf("---------------------------------------------------\n");

    for(int i=0;i<tamanho;i++){
        printf("%c[%d] = ",nomeVetor,i);
        scanf("%d",&vetor[i]);
    }

    printf("---------------------------------------------------\n");
    printf("Vetor %c aramazenado com sucesso !\n",nomeVetor);
}

int obterValorM(){
    int M;
    printf("\n+-------------------------------------------------+\n");
    printf("| LEITURA DO VETOR M                              |\n");
    printf("+-------------------------------------------------+\n");
    printf("Quantidade de elementos de M (maximo %d): ",tam_m);
    scanf("%d",&M);
    while(M<1||M>tam_m){
        printf("Valor invalido. Digite um valor entre 1 e %d: ",tam_m);
        scanf("%d",&M);
    }

    lerVetor(vetM,M,'M');
    return M;

}

int obterValorN(){
    int N;

    printf("\n+-------------------------------------------------+\n");
    printf("| LEITURA DO VETOR N                              |\n");
    printf("+-------------------------------------------------+\n");

    printf("Quantidade de elementos de N (maximo %d): ", tam_m);
    scanf("%d", &N);

    while (N < 1 || N > tam_m) {
        printf("Valor invalido. Digite um valor entre 1 e %d: ", tam_m);
        scanf("%d", &N);
    }

    lerVetor(vetN, N, 'N');
    return N;
}

// exibir
void listarVet(int vetor[],int tamanho, const char *nomeVetor){
    printf("\n+-------------------------------------------------+\n");
    printf("| ELEMENTOS DO VETOR %-28s|\n", nomeVetor);
    printf("+-------------------------------------------------+\n");
    for(int i=0;i<tamanho;i++){
        printf("%s[%d] = %d\n",nomeVetor,i,vetor[i]);
    }
    printf("+-------------------------------------------------+\n");

}

void menuPrincipal(){
    printf(
        "\n"
        "===============================================================\n"
        "                       MENU PRINCIPAL\n"
        "===============================================================\n"
        " [1] Ler primeiro vetor (M <= 30)\n\n"
        " [2] Ler segundo vetor (N <= 20)\n\n"
        " [3] Listar elementos de um vetor\n\n"
        " [4] Somar dois vetores\n"
        "     - Gerar terceiro vetor com a soma dos elementos\n\n"
        " [5] Multiplicar vetor por escalar\n"
        "     - Gerar novo vetor resultante\n\n"
        " [6] Pesquisar se um determinado numero existe ou nao em um vetor\n\n"
        " [7] Gerar um vetor obtido a partir de dois vetores\n"
        "     - Elementos que aparecem em apenas um dos dois vetores\n\n"
        " [8] Gerar um vetor obtido pela intercalacao de dois outros vetores\n"
        "     - Ordenados em ordem crescente\n\n"
        " [9] Sair\n"
        "===============================================================\n"
    );
}

// opcoes menu

void opcaoListar(Estado *estado){
    char escolha;
    printf("+-------------------------------------------------+\n");
    printf("| LISTAR VETOR                                    |\n");
    printf("+-------------------------------------------------+\n");
    printf("Vetores disponiveis: [M] [N] [S]oma [E]scalar [U]nico [I]ntercalado\n");
    printf("Escolha o vetor que deseja listar: ");
    scanf(" %c", &escolha);

    if(escolha=='M'||escolha=='m'){
        if(estado->checkM==0) printf("O vetor M ainda nao foi preenchido.\n");
        else listarVet(vetM,estado->M,"M");
        return;
    }

    if(escolha=='N'||escolha=='N'){
        if(estado->checkN==0) printf("\nO vetor N ainda nao foi preenchido.\n");
        else listarVet(vetN,estado->N,"N");
        return;
    }

    if(escolha=='S'|| escolha=='s'){
        if(estado->checkS==0) printf("\nO vetor Soma ainda nao foi gerado\n");
        else listarVet(vetSoma,estado->M,"Soma");
        return;
    }

    //arrumar 
    if(escolha=='E'|| escolha=='e'){
        char escalar;
        printf("Escolha o Escalar [M/N/S/U/I]: ");
        scanf("%d",&escalar);
        
        if(escalar=='M'||escalar=='m'){
            if(estado->checkEM==0) printf("\nO vetor Escalar de M ainda nao foi gerado.\n");
            else listarVet(vetEscalarM,estado->M,"EscalarM");
        }else if(escalar=='N'||escalar=='n'){
            if(estado->checkN==0) printf("\nO vetor Escalar de N ainda nao foi gerado.\n");
            else listarVet(vetEscalarN,estado->N,"EscalarN");
        }
        
        else{
            printf("\nOpcao invalida. Escolha M ou N\n");
        }
        return;
    }

    if(escolha=='U'|| escolha=='u'){
        if(estado->checkU==0)printf("\nO vetor Unico ainda nao foi gerado.\n");
        else listarVetor(vetUnico,estado->tamU,"Unico");
    }

}

int main(){

    int menuEscolha=-1;

    Estado estado={0}; // inicializa tudo dentro da struct com 0

    while(menuEscolha!=9){

        cls();
        menuPrincipal();

        printf("Escolha uma opcao: ");
        scanf("%d",&menuEscolha);

        cls();

        switch (menuEscolha)
        {
        case 1:
            
            break;
        
        default:
            break;
        }

    }
    return 0;
}