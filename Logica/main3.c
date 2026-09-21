#include<stdio.h>
#include<stdlib.h>

int vetM[30];
int vetN[20];

void clear(){
    system("cls");
}

void pausa(){
    printf("\n");
    system("pause");
}

void menu(){
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
        "===============================================================\n");
}

void opcao_menu(int *escolha){
    printf("DIGITE A OPCAO DESEJADA: ");
    scanf("%d",escolha);
}

void lerVet(int v[],int vetSize,int nameVet){
    printf("\nInforme os elementos do vetor %c:\n", nameVet);
    printf("---------------------------------------------------\n");

    for(int i=0;i<vetSize;i++){
        printf("%c[%d] = ",nameVet,i);
        scanf("%d",&v[i]);
    }

    printf("---------------------------------------------------\n");
    printf("Vetor %c armazenado com sucesso!\n", nameVet);

}   

// get vetores
int get_vetM(){

    int M=0;

    printf("\n+-------------------------------------------------+\n");
    printf("| LEITURA DO VETOR M                                |\n");
    printf("+---------------------------------------------------+\n");

    printf("Quantidade de posicoes do vetor M (maximo 30): ");
    scanf("%d",&M);

    while(M<1 || M>30){
        printf("Valor invalido. Insira um valor entre 1 e 30: ");
        scanf("%d",&M);
    }

    lerVet(vetM,M,'M');

    return M;
}

int get_vetN(){
    int N=0;

    printf("\n+-------------------------------------------------+\n");
    printf("| LEITURA DO VETOR N                                |\n");
    printf("+---------------------------------------------------+\n");

    printf("Quantidade de posicoes do vetor N (maximo 20): ");
    scanf("%d",&N);

    while(N<1 || N>20){
        printf("Valor invalido. Insira um valor entre 1 e 20: ");
        scanf("%d",&N);
    }

    lerVet(vetN,N,'N');

    return N;
}

int main(){

    int menu_escolha=-1;
    int M=0, N=0;

    int checkM=0, checkN=0;

    while(menu_escolha!=9){

        clear();
        menu();
        opcao_menu(&menu_escolha);
        clear();

        switch (menu_escolha){

        case 1:

            M = get_vetM();
            checkM=1;   
            break;

        case 2:

            N = get_vetN();
            checkN=1;
            break;

        case 3: 


            break; 
        default:
            break;
        }
    }

    return 0;
}