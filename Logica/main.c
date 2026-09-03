#include <stdio.h>
#include <stdlib.h>

void limparTela() {
    system("cls");
}

void pausar() {
    printf("\n");
    system("pause");
}

int obterValorM() {
    int M;

    printf("\n+-------------------------------------------------+\n");
    printf("| LEITURA DO VETOR M                              |\n");
    printf("+-------------------------------------------------+\n");
    printf("Quantidade de elementos de M (maximo 30): ");
    scanf("%d", &M);

    while (M < 1 || M > 30) {
        printf("Valor invalido. Digite um valor entre 1 e 30: ");
        scanf("%d", &M);
    }

    return M;
}

int obterValorN() {
    int N;

    printf("\n+-------------------------------------------------+\n");
    printf("| LEITURA DO VETOR N                              |\n");
    printf("+-------------------------------------------------+\n");
    printf("Quantidade de elementos de N (maximo 20): ");
    scanf("%d", &N);

    while (N < 1 || N > 20) {
        printf("Valor invalido. Digite um valor entre 1 e 20: ");
        scanf("%d", &N);
    }

    return N;
}

void lerVetor(int vetor[], int tamanho, char nomeVetor) {
    printf("\nInforme os elementos do vetor %c:\n", nomeVetor);
    printf("---------------------------------------------------\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%c[%d] = ", nomeVetor, i);
        scanf("%d", &vetor[i]);
    }

    printf("---------------------------------------------------\n");
    printf("Vetor %c armazenado com sucesso!\n", nomeVetor);
}

void listarVetor(int vetor[], int tamanho, char nomeVetor) {
    printf("\n+-------------------------------------------------+\n");
    printf("| ELEMENTOS DO VETOR %c                            |\n", nomeVetor);
    printf("+-------------------------------------------------+\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%c[%d] = %d\n", nomeVetor, i, vetor[i]);
    }

    printf("+-------------------------------------------------+\n");
}

void somarVetores(int vetorM[], int vetorN[], int vetorSoma[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetorSoma[i] = vetorM[i] + vetorN[i];
    }
}

void multiplicarVetorPorEscalar(int vetorOriginal[],int vetorResultado[],int tamanho,int escalar){
    for (int i = 0; i < tamanho; i++) {
        vetorResultado[i] = vetorOriginal[i] * escalar;
    }
}

void MenuPrincipal() {
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
        "===============================================================\n"
    );
}

int main() {
    int vetorM[30], vetorN[20];
    int vetorSoma[30], vetorEscalar[30];

    int M = 0, N = 0;
    int checkM = 0, checkN = 0;

    int menuEscolha = -1;
    int escalar;
    char escolhaListagem;
    char escolhaVetor;

    while (menuEscolha != 0) {
        limparTela();
        MenuPrincipal();

        printf("Escolha uma opcao: ");
        scanf("%d", &menuEscolha);

        if (menuEscolha == 0) {
            break;
        }

        limparTela();

        switch (menuEscolha) {
            case 1:
                M = obterValorM();
                lerVetor(vetorM, M, 'M');
                checkM = 1;
                break;

            case 2:
                N = obterValorN();
                lerVetor(vetorN, N, 'N');
                checkN = 1;
                break;

            case 3:
                printf("+-------------------------------------------------+\n");
                printf("| LISTAR VETOR                                    |\n");
                printf("+-------------------------------------------------+\n");
                printf("Escolha o vetor que deseja listar [M/N]: ");
                scanf(" %c", &escolhaListagem);

                if (escolhaListagem == 'M' || escolhaListagem == 'm') {
                    if (checkM == 0) {
                        printf("\nO vetor M ainda nao foi preenchido.\n");
                        printf("Escolha a opcao 1 no menu primeiro.\n");
                    } else {
                        listarVetor(vetorM, M, 'M');
                    }
                } else if (escolhaListagem == 'N' || escolhaListagem == 'n') {
                    if (checkN == 0) {
                        printf("\nO vetor N ainda nao foi preenchido.\n");
                        printf("Escolha a opcao 2 no menu primeiro.\n");
                    } else {
                        listarVetor(vetorN, N, 'N');
                    }
                } else {
                    printf("\nOpcao invalida. Escolha M ou N.\n");
                }
                break;

            case 4:
                if (checkM == 0 || checkN == 0) {
                    printf("Erro: crie os vetores M e N antes de soma-los.\n");
                } else if (M != N) {
                    printf("Erro: os vetores precisam ter o mesmo tamanho.\n");
                    printf("M possui %d elementos e N possui %d elementos.\n", M, N);
                } else {
                    somarVetores(vetorM, vetorN, vetorSoma, M);

                    printf("\nVetores somados com sucesso!\n");
                    listarVetor(vetorSoma, M, 'S');
                }
                break;

            case 5:
                printf("+-------------------------------------------------+\n");
                printf("| MULTIPLICAR VETOR POR ESCALAR                   |\n");
                printf("+-------------------------------------------------+\n");
                printf("Escolha o vetor [M/N]: ");
                scanf(" %c", &escolhaVetor);

                if (escolhaVetor == 'M' || escolhaVetor == 'm') {
                    if (checkM == 0) {
                        printf("\nO vetor M ainda nao foi preenchido.\n");
                    } else {
                        printf("Digite o valor do escalar: ");
                        scanf("%d", &escalar);

                        multiplicarVetorPorEscalar(
                            vetorM, vetorEscalar, M, escalar
                        );

                        printf("\nVetor M multiplicado por %d com sucesso!\n", escalar);
                        listarVetor(vetorEscalar, M, 'E');
                    }
                } else if (escolhaVetor == 'N' || escolhaVetor == 'n') {
                    if (checkN == 0) {
                        printf("\nO vetor N ainda nao foi preenchido.\n");
                    } else {
                        printf("Digite o valor do escalar: ");
                        scanf("%d", &escalar);

                        multiplicarVetorPorEscalar(
                            vetorN, vetorEscalar, N, escalar
                        );

                        printf("\nVetor N multiplicado por %d com sucesso!\n", escalar);
                        listarVetor(vetorEscalar, N, 'E');
                    }
                } else {
                    printf("\nOpcao invalida. Escolha M ou N.\n");
                }
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

        pausar();
    }

    limparTela();
    printf("\nPrograma encerrado !\n");
    


    return 0;
}