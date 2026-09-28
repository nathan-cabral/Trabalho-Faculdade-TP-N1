#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX_M 30
#define TAM_MAX_N 20
#define TAM_MAX_UNICO (TAM_MAX_M + TAM_MAX_N)
#define TAM_MAX_INTERCALADO (TAM_MAX_M + TAM_MAX_N)

// vetores globais
// fiz isso pois posso acessar os vetores de qualquer funcao
int vetorM[30];
int vetorN[20];
int vetorSoma[30];
int vetorEscalarM[30];
int vetorEscalarN[20];
int vetorUnico[50];
int vetorIntercalado[50];

typedef struct
{
    int M, N;
    int checkM, checkN;
    int checkS;
    int checkEM, checkEN;
    int checkU;
    int tamU;
    int checkI;
    int tamI;
} Estado;

void cls()
{
    system("cls");
}

void pausa()
{
    printf("\n");
    system("pause");
}

// leitrura

void lerVetor(int vetor[], int tamanho, char nomeVetor)
{
    printf("\nInforme os elementos do vetor %c:\n", nomeVetor);
    printf("---------------------------------------------------\n");

    for (int i = 0; i < tamanho; i++)
    {
        printf("%c[%d] = ", nomeVetor, i);
        scanf("%d", &vetor[i]);
    }

    printf("---------------------------------------------------\n");
    printf("Vetor %c armazenado com sucesso!\n", nomeVetor);
}

int obterValorM()
{
    int M;

    printf("\n+-------------------------------------------------+\n");
    printf("| LEITURA DO VETOR M                              |\n");
    printf("+-------------------------------------------------+\n");

    printf("Quantidade de elementos de M (maximo %d): ", TAM_MAX_M);
    scanf("%d", &M);

    while (M < 1 || M > TAM_MAX_M)
    {
        printf("Valor invalido. Digite um valor entre 1 e %d: ", TAM_MAX_M);
        scanf("%d", &M);
    }

    lerVetor(vetorM, M, 'M');
    return M;
}

int obterValorN()
{
    int N;

    printf("\n+-------------------------------------------------+\n");
    printf("| LEITURA DO VETOR N                              |\n");
    printf("+-------------------------------------------------+\n");

    printf("Quantidade de elementos de N (maximo %d): ", TAM_MAX_N);
    scanf("%d", &N);

    while (N < 1 || N > TAM_MAX_N)
    {
        printf("Valor invalido. Digite um valor entre 1 e %d: ", TAM_MAX_N);
        scanf("%d", &N);
    }

    lerVetor(vetorN, N, 'N');
    return N;
}

// exibicao

void listarVetor(int vetor[], int tamanho, const char *nomeVetor)
{
    printf("\n+-------------------------------------------------+\n");
    printf("| ELEMENTOS DO VETOR %-28s|\n", nomeVetor);
    printf("+-------------------------------------------------+\n");

    for (int i = 0; i < tamanho; i++)
    {
        printf("%s[%d] = %d\n", nomeVetor, i, vetor[i]);
    }

    printf("+-------------------------------------------------+\n");
}

void menuPrincipal()
{
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
        "===============================================================\n");
}

// operacoes

void somarVetores(int vetorM[], int vetorN[], int vetorSoma[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        vetorSoma[i] = vetorM[i] + vetorN[i];
    }
}

void multiplicarVetorPorEscalar(int vetorOriginal[], int vetorResultado[], int tamanho, int escalar)
{
    for (int i = 0; i < tamanho; i++)
    {
        vetorResultado[i] = vetorOriginal[i] * escalar;
    }
}

void verificarExistencia(int buscado, int vetor[], int tamanho)
{
    int encontrado = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] == buscado)
        {
            printf("\nValor achado!\n");
            printf("Valor = %d\n", vetor[i]);
            printf("Posicao = [%d]\n", i);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        printf("\nO valor %d nao foi encontrado.\n", buscado);
    }
}

int existeNoVetor(int valor, int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] == valor)
            return 1;
    }
    return 0;
}

void gerarVetorUnico(int vetorA[], int tamA, int vetorB[], int tamB, int resultado[], int *tamResultado)
{
    int k = 0;

    for (int i = 0; i < tamA; i++)
    {
        if (!existeNoVetor(vetorA[i], vetorB, tamB))
        {
            resultado[k++] = vetorA[i];
        }
    }

    for (int i = 0; i < tamB; i++)
    {
        if (!existeNoVetor(vetorB[i], vetorA, tamA))
        {
            resultado[k++] = vetorB[i];
        }
    }

    *tamResultado = k;
}

int estaOrdenadoCrescente(int vetor[], int tamanho)
{
    for (int i = 1; i < tamanho; i++)
    {
        if (vetor[i] < vetor[i - 1])
            return 0;
    }
    return 1;
}

void intercalarVetoresOrdenados(int vetorA[], int tamA, int vetorB[], int tamB, int resultado[], int *tamResultado)
{
    int i = 0, j = 0, k = 0;

    while (i < tamA && j < tamB)
    {
        if (vetorA[i] <= vetorB[j])
        {
            resultado[k++] = vetorA[i++];
        }
        else
        {
            resultado[k++] = vetorB[j++];
        }
    }

    while (i < tamA)
        resultado[k++] = vetorA[i++];
    while (j < tamB)
        resultado[k++] = vetorB[j++];

    *tamResultado = k;
}

// opcoes do menu

void opcaoListar(Estado *estado)
{
    char escolha;

    printf("+-------------------------------------------------+\n");
    printf("| LISTAR VETOR                                    |\n");
    printf("+-------------------------------------------------+\n");
    printf("Vetores disponiveis: [M] [N] [S]oma [E]scalar [U]nico [I]ntercalado\n");
    printf("Escolha o vetor que deseja listar: ");
    scanf(" %c", &escolha);

    if (escolha == 'M' || escolha == 'm')
    {
        if (!estado->checkM)
            printf("\nO vetor M ainda nao foi preenchido.\n");
        else
            listarVetor(vetorM, estado->M, "M");
    }
    else if (escolha == 'N' || escolha == 'n')
    {
        if (!estado->checkN)
            printf("\nO vetor N ainda nao foi preenchido.\n");
        else
            listarVetor(vetorN, estado->N, "N");
    }
    else if (escolha == 'S' || escolha == 's')
    {
        if (!estado->checkS)
            printf("\nO vetor Soma ainda nao foi gerado.\n");
        else
            listarVetor(vetorSoma, estado->M, "Soma");
    }
    else if (escolha == 'E' || escolha == 'e')
    {
        char sub;
        printf("Escalar de qual vetor [M/N]: ");
        scanf(" %c", &sub);

        if (sub == 'M' || sub == 'm')
        {
            if (!estado->checkEM)
                printf("\nO vetor Escalar de M ainda nao foi gerado.\n");
            else
                listarVetor(vetorEscalarM, estado->M, "EscalarM");
        }
        else if (sub == 'N' || sub == 'n')
        {
            if (!estado->checkEN)
                printf("\nO vetor Escalar de N ainda nao foi gerado.\n");
            else
                listarVetor(vetorEscalarN, estado->N, "EscalarN");
        }
        else
        {
            printf("\nOpcao invalida. Escolha M ou N.\n");
        }
    }
    else if (escolha == 'U' || escolha == 'u')
    {
        if (!estado->checkU)
            printf("\nO vetor Unico ainda nao foi gerado.\n");
        else
            listarVetor(vetorUnico, estado->tamU, "Unico");
    }
    else if (escolha == 'I' || escolha == 'i')
    {
        if (!estado->checkI)
            printf("\nO vetor Intercalado ainda nao foi gerado.\n");
        else
            listarVetor(vetorIntercalado, estado->tamI, "Intercalado");
    }
    else
    {
        printf("\nOpcao invalida.\n");
    }
}

void opcaoSomar(Estado *estado)
{
    if (!estado->checkM || !estado->checkN)
    {
        printf("Erro: crie os vetores M e N antes de soma-los.\n");
        return;
    }

    if (estado->M != estado->N)
    {
        printf("Erro: os vetores precisam ter o mesmo tamanho.\n");
        printf("M possui %d elementos e N possui %d elementos.\n", estado->M, estado->N);
        return;
    }

    somarVetores(vetorM, vetorN, vetorSoma, estado->M);
    estado->checkS = 1;

    printf("\nVetores somados com sucesso!\n");
    listarVetor(vetorSoma, estado->M, "Soma");
}

void opcaoEscalar(Estado *estado)
{
    char escolha;
    int escalar;

    printf("+-------------------------------------------------+\n");
    printf("| MULTIPLICAR VETOR POR ESCALAR                   |\n");
    printf("+-------------------------------------------------+\n");
    printf("Escolha o vetor [M/N]: ");
    scanf(" %c", &escolha);

    if (escolha == 'M' || escolha == 'm')
    {
        if (!estado->checkM)
        {
            printf("\nO vetor M ainda nao foi preenchido.\n");
            return;
        }

        printf("Digite o valor do escalar: ");
        scanf("%d", &escalar);

        multiplicarVetorPorEscalar(vetorM, vetorEscalarM, estado->M, escalar);
        estado->checkEM = 1;

        printf("\nVetor M multiplicado por %d com sucesso!\n", escalar);
        listarVetor(vetorEscalarM, estado->M, "EscalarM");
    }
    else if (escolha == 'N' || escolha == 'n')
    {
        if (!estado->checkN)
        {
            printf("\nO vetor N ainda nao foi preenchido.\n");
            return;
        }

        printf("Digite o valor do escalar: ");
        scanf("%d", &escalar);

        multiplicarVetorPorEscalar(vetorN, vetorEscalarN, estado->N, escalar);
        estado->checkEN = 1;

        printf("\nVetor N multiplicado por %d com sucesso!\n", escalar);
        listarVetor(vetorEscalarN, estado->N, "EscalarN");
    }
    else
    {
        printf("\nOpcao invalida. Escolha M ou N.\n");
    }
}

void opcaoPesquisar(Estado *estado)
{
    char escolhaVetor;
    int valorBuscado;

    printf("+-------------------------------------------------+\n");
    printf("| BUSCAR NUMERO DENTRO DO VETOR                   |\n");
    printf("+-------------------------------------------------+\n");
    printf("Vetores disponiveis: [M] [N] [S]oma [E]scalar [U]nico [I]ntercalado\n");
    printf("Escolha um vetor: ");
    scanf(" %c", &escolhaVetor);
    printf("\n");

    switch (escolhaVetor)
    {

    case 'M':
    case 'm':
        if (!estado->checkM)
        {
            printf("O vetor M ainda nao foi preenchido.\n");
            return;
        }
        printf("Qual valor voce deseja encontrar no vetor: ");
        scanf("%d", &valorBuscado);
        verificarExistencia(valorBuscado, vetorM, estado->M);
        break;

    case 'N':
    case 'n':
        if (!estado->checkN)
        {
            printf("O vetor N ainda nao foi preenchido.\n");
            return;
        }
        printf("Qual valor voce deseja encontrar no vetor: ");
        scanf("%d", &valorBuscado);
        verificarExistencia(valorBuscado, vetorN, estado->N);
        break;

    case 'S':
    case 's':
        if (!estado->checkS)
        {
            printf("O vetor Soma ainda nao foi gerado.\n");
            return;
        }
        printf("Qual valor voce deseja encontrar no vetor: ");
        scanf("%d", &valorBuscado);
        verificarExistencia(valorBuscado, vetorSoma, estado->M);
        break;

    case 'E':
    case 'e':
    {
        char sub;
        printf("Escalar de qual vetor [M/N]: ");
        scanf(" %c", &sub);

        if (sub == 'M' || sub == 'm')
        {
            if (!estado->checkEM)
            {
                printf("O vetor Escalar de M ainda nao foi gerado.\n");
                return;
            }
            printf("Qual valor voce deseja encontrar no vetor: ");
            scanf("%d", &valorBuscado);
            verificarExistencia(valorBuscado, vetorEscalarM, estado->M);
        }
        else if (sub == 'N' || sub == 'n')
        {
            if (!estado->checkEN)
            {
                printf("O vetor Escalar de N ainda nao foi gerado.\n");
                return;
            }
            printf("Qual valor voce deseja encontrar no vetor: ");
            scanf("%d", &valorBuscado);
            verificarExistencia(valorBuscado, vetorEscalarN, estado->N);
        }
        else
        {
            printf("Opcao invalida. Escolha M ou N.\n");
        }
        break;
    }

    case 'U':
    case 'u':
        if (!estado->checkU)
        {
            printf("O vetor Unico ainda nao foi gerado.\n");
            return;
        }
        printf("Qual valor voce deseja encontrar no vetor: ");
        scanf("%d", &valorBuscado);
        verificarExistencia(valorBuscado, vetorUnico, estado->tamU);
        break;

    case 'I':
    case 'i':
        if (!estado->checkI)
        {
            printf("O vetor Intercalado ainda nao foi gerado.\n");
            return;
        }
        printf("Qual valor voce deseja encontrar no vetor: ");
        scanf("%d", &valorBuscado);
        verificarExistencia(valorBuscado, vetorIntercalado, estado->tamI);
        break;

    default:
        printf("Opcao invalida. Escolha M, N, S, E, U ou I.\n");
    }
}


void opcaoGerarUnico(Estado *estado)
{
    printf("+-------------------------------------------------+\n");
    printf("| VETOR UNICO (elementos exclusivos de M ou N)    |\n");
    printf("+-------------------------------------------------+\n");

    if (!estado->checkM || !estado->checkN)
    {
        printf("Erro: crie os vetores M e N antes de gerar este vetor.\n");
        return;
    }

    gerarVetorUnico(vetorM, estado->M, vetorN, estado->N, vetorUnico, &estado->tamU);
    estado->checkU = 1;

    printf("\nVetor gerado com sucesso!\n");
    listarVetor(vetorUnico, estado->tamU, "Unico");
}


void opcaoGerarIntercalado(Estado *estado)
{
    printf("+-------------------------------------------------+\n");
    printf("| VETOR INTERCALADO (merge de M e N ordenados)    |\n");
    printf("+-------------------------------------------------+\n");

    if (!estado->checkM || !estado->checkN)
    {
        printf("Erro: crie os vetores M e N antes de gerar este vetor.\n");
        return;
    }

    if (!estaOrdenadoCrescente(vetorM, estado->M) || !estaOrdenadoCrescente(vetorN, estado->N))
    {
        printf("Aviso: M e/ou N nao estao em ordem crescente.\n");
        printf("A intercalacao assume vetores ja ordenados; o resultado pode nao ficar ordenado.\n");
    }

    intercalarVetoresOrdenados(vetorM, estado->M, vetorN, estado->N, vetorIntercalado, &estado->tamI);
    estado->checkI = 1;

    printf("\nVetor gerado com sucesso!\n");
    listarVetor(vetorIntercalado, estado->tamI, "Intercalado");
}




int main()
{
    Estado estado = {0};
    int menuEscolha = -1;

    while (menuEscolha != 0)
    {
        cls();
        menuPrincipal();

        printf("Escolha uma opcao: ");
        scanf("%d", &menuEscolha);

        cls();

        switch (menuEscolha)
        {
        case 1:
            estado.M = obterValorM();
            estado.checkM = 1;
            break;

        case 2:
            estado.N = obterValorN();
            estado.checkN = 1;
            break;

        case 3:
            opcaoListar(&estado);
            break;

        case 4:
            opcaoSomar(&estado);
            break;

        case 5:
            opcaoEscalar(&estado);
            break;

        case 6:
            opcaoPesquisar(&estado);
            break;

        case 7:
            opcaoGerarUnico(&estado);
            break;

        case 8:
            opcaoGerarIntercalado(&estado);
            break;

        case 0:
            break;

        default:
            printf("\nOpcao invalida. Tente novamente.\n");
        }

        if (menuEscolha != 0)
        {
            pausa();
        }
    }

    cls();
    printf("\nPrograma encerrado!\n");

    return 0;
}