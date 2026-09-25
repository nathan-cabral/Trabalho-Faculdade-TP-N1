#include<stdio.h>
#include<stdlib.h>

#define tam_m 30
#define tam_n 20
#define tam_unic (tam_m+tam_n)
#define tam_intercalado (tam_m+tam_n)

int vetM[tam_m];
int vetN[tam_n];
int vetSoma[tam_m];
int vetEscalarM[tam_m];
int vetEscalarN[tam_n];
int vetUnico[tam_unic];
int vetIntercalado[tam_intercalado];

typedef struct{
    int M,N;
    int checkM,checkN,checkS;
    int checkEM,checkEN,checkU;
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
void listarVet(int vetor[],int tamanho, char nomeVetor){
    printf("\n+-------------------------------------------------+\n");
    printf("| ELEMENTOS DO VETOR %c|\n", nomeVetor);
    printf("+-------------------------------------------------+\n");
    for(int i=0;i<tamanho;i++){
        printf("%c[%d] = %d\n",nomeVetor,i,vetor[i]);
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

// operacoes

void somarVet(int vetM[],int vetN[],int vetSoma[],int vetEscalarM[],
                int vetEscalarN[],int vetUnico[],int vetIntercalado[],
                int vetSoma[],int tamanho)
                {
                    for(int i=0;i<tamanho)
                }


// opcoes menu



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