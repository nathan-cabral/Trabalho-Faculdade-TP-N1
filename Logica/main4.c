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


// operacoes

void somarVet(int vM[],int vN[],int vS[],int tam){
    for(int i=0;i<tam;i++){
        vetSoma[i]=vetM[i]+vetN[i];
    }
}

void multiplicarEscalar(int vetOrig[],int vetResult[],int tam,int escalar){
    for(int i=0;i<tam;i++){
        vetResult[i]=vetOrig[i]*escalar;
    }
}

void verificarExistencia(int buscado,int vetor[],int tam){
    int encontrado=0;

    for(int i=0;i<tam;i++){
         if (vetor[i] == buscado) {
            printf("\nValor achado!\n");
            printf("Valor = %d\n", vetor[i]);
            printf("Posicao = [%d]\n", i);
            encontrado = 1;
        }
    }

    if(!encontrado) printf("\nO valor %d nao foi encontrado.\n",buscado);

}

int existeNoVetor(int valor,int vet[],int tam){
    for(int i=0;i<tam;i++){
        if(vet[i]==valor)return 1;
    }
    return 0;
}

void gerarVetUnico(int vetA[],int tamA,int vetB[],int tamB,int resul[],int *tamResul){
    int k = 0;

    for (int i = 0; i < tamA; i++) {
        if (!existeNoVetor(vetA[i], vetB, tamB)) {
            resul[k++] = vetA[i];
        }
    }

    for (int i = 0; i < tamB; i++) {
        if (!existeNoVetor(vetB[i], vetA, tamA)) {
            resul[k++] = vetB[i];
        }
    }

    *tamResul= k;
}

int estaOrdenadoCrescente(int vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] < vetor[i - 1]) return 0;
    }
    return 1;
}

void intercalarVetoresOrdenados(int vetorA[], int tamA, int vetorB[], int tamB, int resultado[], int *tamResultado) {
    int i = 0, j = 0, k = 0;

    while (i < tamA && j < tamB) {
        if (vetorA[i] <= vetorB[j]) {
            resultado[k++] = vetorA[i++];
        } else {
            resultado[k++] = vetorB[j++];
        }
    }

    while (i < tamA) resultado[k++] = vetorA[i++];
    while (j < tamB) resultado[k++] = vetorB[j++];

    *tamResultado = k;
}

// opcoes menu

void opcaoEscalar(Estado *estado) {
    char escolha;
    int escalar;

    printf("+-------------------------------------------------+\n");
    printf("| MULTIPLICAR VETOR POR ESCALAR                   |\n");
    printf("+-------------------------------------------------+\n");
    printf("Escolha o vetor [M/N]: ");
    scanf(" %c", &escolha);

    if (escolha == 'M' || escolha == 'm') {
        if (!estado->checkM) {
            printf("\nO vetor M ainda nao foi preenchido.\n");
            return;
        }

        printf("Digite o valor do escalar: ");
        scanf("%d", &escalar);

        multiplicarVetorPorEscalar(vetM, vetEscalarM, estado->M, escalar);
        estado->checkEM = 1;

        printf("\nVetor M multiplicado por %d com sucesso!\n", escalar);
        listarVetor(vetEscalarM, estado->M, "EscalarM");

    } else if (escolha == 'N' || escolha == 'n') {
        if (!estado->checkN) {
            printf("\nO vetor N ainda nao foi preenchido.\n");
            return;
        }

        printf("Digite o valor do escalar: ");
        scanf("%d", &escalar);

        multiplicarVetorPorEscalar(vetN, vetEscalarN, estado->N, escalar);
        estado->checkEN = 1;

        printf("\nVetor N multiplicado por %d com sucesso!\n", escalar);
        listarVetor(vetEscalarN, estado->N, "EscalarN");

    } else {
        printf("\nOpcao invalida. Escolha M ou N.\n");
    }
}

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
    }else 
    if(escolha=='S'|| escolha=='s'){
        if(estado->checkS==0) printf("\nO vetor Soma ainda nao foi gerado\n");
        else listarVet(vetSoma,estado->M,"Soma");
        return;
    }else 
    if(escolha=='E'|| escolha=='e'){
        char escalar;
        printf("Escolha o Escalar [M/N/S]: ");
        scanf("%d",&escalar);
        
        if(escalar=='M'||escalar=='m'){
            if(estado->checkEM==0) printf("\nO vetor Escalar de M ainda nao foi gerado.\n");
            else listarVet(vetEscalarM,estado->M,"EscalarM");
        }else if(escalar=='N'||escalar=='n'){
            if(estado->checkN==0) printf("\nO vetor Escalar de N ainda nao foi gerado.\n");
            else listarVet(vetEscalarN,estado->N,"EscalarN");
        }else if(escalar=='S'|| escalar=='s'){
            if(estado->checkS==0)printf("\nO vetor Escalar de Soma ainda nao foi gerado.\n");
            else listarVet(vetEscalarSoma,estado->M,"EscalarS");
        }
        else{
            printf("\nOpcao invalida. Escolha M ou N\n");
        }
        return;
    }else{
        printf("\nOpcao invalida.\n");
    }
}

void opcaoSomar(Estado *estado){
    if(estado->checkM==0 ||estado->checkN==0){
        printf("Erro: crie os vetores M e N antes de soma-los\n");
        return ;
    }else if(estado->M != estado->N){
        printf("Erro: os vetores precisam ter o mesmo tamanho.\n");
        printf("M possui %d elementos e N possui %d elementos.\n", estado->M, estado->N);
        return;
    }
    somarVet(vetM,vetN,vetSoma,estado->M);
    estado->checkS=1;
    printf("\n Vetores armazenados com sucesso!\n");
    listarVet(vetSoma,estado->M,"Soma");
}

void opcaoPesquisar(Estado *estado) {
    char escolhaVetor;
    int valorBuscado;

    printf("+-------------------------------------------------+\n");
    printf("| BUSCAR NUMERO DENTRO DO VETOR                   |\n");
    printf("+-------------------------------------------------+\n");
    printf("Vetores disponiveis: [M] [N] [S]oma [E]scalar [U]nico [I]ntercalado\n");
    printf("Escolha um vetor: ");
    scanf(" %c", &escolhaVetor);
    printf("\n");

    switch (escolhaVetor) {

        case 'M': case 'm':
            if (!estado->checkM) { printf("O vetor M ainda nao foi preenchido.\n"); return; }
            printf("Qual valor voce deseja encontrar no vetor: ");
            scanf("%d", &valorBuscado);
            verificarExistencia(valorBuscado, vetorM, estado->M);
            break;

        case 'N': case 'n':
            if (!estado->checkN) { printf("O vetor N ainda nao foi preenchido.\n"); return; }
            printf("Qual valor voce deseja encontrar no vetor: ");
            scanf("%d", &valorBuscado);
            verificarExistencia(valorBuscado, vetorN, estado->N);
            break;

        case 'S': case 's':
            if (!estado->checkS) { printf("O vetor Soma ainda nao foi gerado.\n"); return; }
            printf("Qual valor voce deseja encontrar no vetor: ");
            scanf("%d", &valorBuscado);
            verificarExistencia(valorBuscado, vetorSoma, estado->M);
            break;

        case 'E': case 'e': {
            char sub;
            printf("Escalar de qual vetor [M/N]: ");
            scanf(" %c", &sub);

            if (sub == 'M' || sub == 'm') {
                if (!estado->checkEM) { printf("O vetor Escalar de M ainda nao foi gerado.\n"); return; }
                printf("Qual valor voce deseja encontrar no vetor: ");
                scanf("%d", &valorBuscado);
                verificarExistencia(valorBuscado, vetorEscalarM, estado->M);
            } else if (sub == 'N' || sub == 'n') {
                if (!estado->checkEN) { printf("O vetor Escalar de N ainda nao foi gerado.\n"); return; }
                printf("Qual valor voce deseja encontrar no vetor: ");
                scanf("%d", &valorBuscado);
                verificarExistencia(valorBuscado, vetorEscalarN, estado->N);
            } else {
                printf("Opcao invalida. Escolha M ou N.\n");
            }
            break;
        }

        case 'U': case 'u':
            if (!estado->checkU) { printf("O vetor Unico ainda nao foi gerado.\n"); return; }
            printf("Qual valor voce deseja encontrar no vetor: ");
            scanf("%d", &valorBuscado);
            verificarExistencia(valorBuscado, vetorUnico, estado->tamU);
            break;

        case 'I': case 'i':
            if (!estado->checkI) { printf("O vetor Intercalado ainda nao foi gerado.\n"); return; }
            printf("Qual valor voce deseja encontrar no vetor: ");
            scanf("%d", &valorBuscado);
            verificarExistencia(valorBuscado, vetorIntercalado, estado->tamI);
            break;

        default:
            printf("Opcao invalida. Escolha M, N, S, E, U ou I.\n");
    }
}

void opcaoGerarUnico(Estado *estado) {
    printf("+-------------------------------------------------+\n");
    printf("| VETOR UNICO (elementos exclusivos de M ou N)    |\n");
    printf("+-------------------------------------------------+\n");

    if (!estado->checkM || !estado->checkN) {
        printf("Erro: crie os vetores M e N antes de gerar este vetor.\n");
        return;
    }

    gerarVetUnico(vetM, estado->M, vetN, estado->N, vetUnico, &estado->tamU);
    estado->checkU = 1;

    printf("\nVetor gerado com sucesso!\n");
    listarVetor(vetUnico, estado->tamU, "Unico");
}

void opcaoGerarIntercalado(Estado *estado) {
    printf("+-------------------------------------------------+\n");
    printf("| VETOR INTERCALADO (merge de M e N ordenados)    |\n");
    printf("+-------------------------------------------------+\n");

    if (!estado->checkM || !estado->checkN) {
        printf("Erro: crie os vetores M e N antes de gerar este vetor.\n");
        return;
    }

    if (!estaOrdenadoCrescente(vetM, estado->M) || !estaOrdenadoCrescente(vetN, estado->N)) {
        printf("Aviso: M e/ou N nao estao em ordem crescente.\n");
        printf("A intercalacao assume vetores ja ordenados; o resultado pode nao ficar ordenado.\n");
    }

    intercalarVetoresOrdenados(vetM, estado->M, vetN, estado->N, vetIntercalado, &estado->tamI);
    estado->checkI = 1;

    printf("\nVetor gerado com sucesso!\n");
    listarVetor(vetIntercalado, estado->tamI, "Intercalado");
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
            estado.M=obterValorM();
            estado.checkM=1;
            break;
        case 2:
            estado.N=obterValorN();
            estado.checkN=1;
            break;
        case 3:
            opcaoListar(&estado);
            break;
        case 4:
            
        default:
            break;
        }

    }
    return 0;
}