#include <stdio.h>
#include <stdlib.h>

int vetorM[30];
int vetorN[20];

void limparTela() {
    system("cls");
}

void pausar() {
    printf("\n");
    system("pause");
}

// FUNCOES DE LEITURA

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

    lerVetor(vetorM, M, 'M');

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

    lerVetor(vetorN, N, 'N');

    return N;
}

// FUNCOES DE EXIBICAO

void listarVetor(int vetor[], int tamanho, char nomeVetor) {

    printf("\n+-------------------------------------------------+\n");
    printf("| ELEMENTOS DO VETOR %c                            |\n", nomeVetor);
    printf("+-------------------------------------------------+\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%c[%d] = %d\n", nomeVetor, i, vetor[i]);
    }

    printf("+-------------------------------------------------+\n");
}

void menuPrincipal() {

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
        " [0] Sair\n"
        "===============================================================\n"
    );
}

//OPERACOES COM VETORES

void somarVetores(
    int vetorM[],
    int vetorN[],
    int vetorSoma[],
    int tamanho){

    for (int i = 0; i < tamanho; i++) {
        vetorSoma[i] = vetorM[i] + vetorN[i];
    }
}

void multiplicarVetorPorEscalar(
    int vetorOriginal[],
    int vetorResultado[],
    int tamanho,
    int escalar){

    for (int i = 0; i < tamanho; i++) {
        vetorResultado[i] = vetorOriginal[i] * escalar;
    }
}

void verificarExistencia(
    int buscado,
    int vetor[],
    int tamanho){

    int encontrado = 0;

    for (int i = 0; i < tamanho; i++) {

        if (vetor[i] == buscado) {

            printf("\nValor achado!\n");
            printf("Valor = %d\n", vetor[i]);
            printf("Posicao = [%d]\n", i);

            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("\nO valor %d nao foi encontrado.\n", buscado);
    }
}

// OPCOES DO MENU

void opcaoListar(
    int M,
    int N,
    int checkM,
    int checkN){

    char escolha;

    printf("+-------------------------------------------------+\n");
    printf("| LISTAR VETOR                                    |\n");
    printf("+-------------------------------------------------+\n");

    printf("Escolha o vetor que deseja listar [M/N]: ");
    scanf(" %c", &escolha);

    if (escolha == 'M' || escolha == 'm') {

        if (!checkM) {
            printf("\nO vetor M ainda nao foi preenchido.\n");
        }
        else {
            listarVetor(vetorM, M, 'M');
        }
    }

    else if (escolha == 'N' || escolha == 'n') {

        if (!checkN) {
            printf("\nO vetor N ainda nao foi preenchido.\n");
        }
        else {
            listarVetor(vetorN, N, 'N');
        }
    }

    else {
        printf("\nOpcao invalida. Escolha M ou N.\n");
    }
}

void opcaoSomar(
    int M,
    int N,
    int checkM,
    int checkN,
    int vetorSoma[],
    int *checkS){

    if (!checkM || !checkN) {

        printf("Erro: crie os vetores M e N antes de soma-los.\n");
        return;
    }

    if (M != N) {

        printf("Erro: os vetores precisam ter o mesmo tamanho.\n");
        printf("M possui %d elementos e N possui %d elementos.\n",M,N);

        return;
    }

    somarVetores(vetorM, vetorN, vetorSoma, M);

    *checkS = 1;

    printf("\nVetores somados com sucesso!\n");

    listarVetor(vetorSoma, M, 'S');
}

void opcaoEscalar(
    int M,
    int N,
    int checkM,
    int checkN,
    int vetorEscalar[],
    int *checkEM,
    int *checkEN){

    char escolha;
    int escalar;

    printf("+-------------------------------------------------+\n");
    printf("| MULTIPLICAR VETOR POR ESCALAR                   |\n");
    printf("+-------------------------------------------------+\n");

    printf("Escolha o vetor [M/N]: ");
    scanf(" %c", &escolha);

    if (escolha == 'M' || escolha == 'm') {

        if (!checkM) {
            printf("\nO vetor M ainda nao foi preenchido.\n");
            return;
        }

        printf("Digite o valor do escalar: ");
        scanf("%d", &escalar);

        multiplicarVetorPorEscalar(vetorM,vetorEscalar,M,escalar);

        *checkEM = 1;

        printf("\nVetor M multiplicado por %d com sucesso!\n",escalar);

        listarVetor(vetorEscalar, M, 'E');
    }

    else if (escolha == 'N' || escolha == 'n') {

        if (!checkN) {
            printf("\nO vetor N ainda nao foi preenchido.\n");
            return;
        }

        printf("Digite o valor do escalar: ");
        scanf("%d", &escalar);

        multiplicarVetorPorEscalar(
            vetorN,
            vetorEscalar,
            N,
            escalar
        );

        *checkEN = 1;

        printf(
            "\nVetor N multiplicado por %d com sucesso!\n",
            escalar
        );

        listarVetor(vetorEscalar, N, 'E');
    }

    else {
        printf("\nOpcao invalida. Escolha M ou N.\n");
    }
}

void opcaoPesquisar(
    int M,
    int N,
    int checkM,
    int checkN,
    int vetorSoma[],
    int vetorEscalar[],
    int checkS,
    int checkEM,
    int checkEN){

    char escolhaVetor;
    int valorBuscado;

    printf("+-------------------------------------------------+\n");
    printf("| BUSCAR NUMERO DENTRO DO VETOR                  |\n");
    printf("+-------------------------------------------------+\n");

    printf("Escolha um vetor [M / N / S / E]: ");
    scanf(" %c", &escolhaVetor);

    printf("\n");

    if (escolhaVetor == 'M' || escolhaVetor == 'm') {

        if (!checkM) {
            printf("O vetor M ainda nao foi preenchido.\n");
            return;
        }

        printf("Qual valor voce deseja encontrar no vetor: ");
        scanf("%d", &valorBuscado);

        verificarExistencia(valorBuscado, vetorM, M);
    }

    else if (escolhaVetor == 'N' || escolhaVetor == 'n') {

        if (!checkN) {
            printf("O vetor N ainda nao foi preenchido.\n");
            return;
        }

        printf("Qual valor voce deseja encontrar no vetor: ");
        scanf("%d", &valorBuscado);

        verificarExistencia(valorBuscado, vetorN, N);
    }

    else if (escolhaVetor == 'S' || escolhaVetor == 's') {

        if (!checkS) {
            printf("O vetor S ainda nao foi preenchido.\n");
            return;
        }

        printf("Qual valor voce deseja encontrar no vetor: ");
        scanf("%d", &valorBuscado);

        verificarExistencia(valorBuscado, vetorSoma, M);
    }

    else if (escolhaVetor == 'E' || escolhaVetor == 'e') {

        char escolha;

        printf("Qual vetor escalar deseja pesquisar [M/N]: ");
        scanf(" %c", &escolha);

        if (escolha == 'M' || escolha == 'm') {

            if (!checkEM) {
                printf("O vetor escalar de M ainda nao foi criado.\n");
                return;
            }

            printf("Qual valor voce deseja encontrar no vetor: ");
            scanf("%d", &valorBuscado);

            verificarExistencia(
                valorBuscado,
                vetorEscalar,
                M
            );
        }

        else if (escolha == 'N' || escolha == 'n') {

            if (!checkEN) {
                printf("O vetor escalar de N ainda nao foi criado.\n");
                return;
            }

            printf("Qual valor voce deseja encontrar no vetor: ");
            scanf("%d", &valorBuscado);

            verificarExistencia(
                valorBuscado,
                vetorEscalar,
                N
            );
        }

        else {
            printf("Opcao invalida. Escolha M ou N.\n");
        }
    }

    else {
        printf("Opcao invalida. Escolha M, N, S ou E.\n");
    }
}



int main() { 
    int vetorSoma[30];
    int vetorEscalar[30];

    int M = 0;
    int N = 0;

    int checkM = 0;
    int checkN = 0;
    int checkS = 0;
    int checkEM = 0;
    int checkEN = 0;

    int menuEscolha = -1;

    while (menuEscolha != 0) {

        limparTela();

        menuPrincipal();

        printf("Escolha uma opcao: ");
        scanf("%d", &menuEscolha);

        limparTela();

        switch (menuEscolha) {

            case 1:
                M = obterValorM();
                checkM = 1;
                break;

            case 2:
                N = obterValorN();
                checkN = 1;
                break;

            case 3:
                opcaoListar(M,N,checkM,checkN);
                break;

            case 4:
                opcaoSomar(M,N,checkM,checkN,vetorSoma,&checkS);
                break;

            case 5:
                opcaoEscalar(M,N,checkM,checkN,vetorEscalar,&checkEM,&checkEN);
                break;

            case 6:
                opcaoPesquisar(M,N,checkM,checkN,vetorSoma,vetorEscalar,checkS,checkEM,checkEN);
                break;

            case 7:
                printf("Opcao 7 ainda nao implementada.\n");
                break;

            case 8:
                printf("Opcao 8 ainda nao implementada.\n");
                break;

            case 0:
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

        if (menuEscolha != 0) {
            pausar();
        }
    }

    limparTela();

    printf("\nPrograma encerrado!\n");

    return 0;
}