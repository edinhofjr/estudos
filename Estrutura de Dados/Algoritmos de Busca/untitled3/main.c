#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 41

struct PontoTuristico {
    char descricao[TAM];
    float latitude;
    float longitude;
    struct PontoTuristico *proximo;
};

void lerPontoTuristico(struct PontoTuristico *aux);
struct PontoTuristico* inserir_inicio(struct PontoTuristico* cabeca);
struct PontoTuristico* inserir_final(struct PontoTuristico* cabeca);
int verificar_lista_vazia(struct PontoTuristico* cabeca);
struct PontoTuristico* criar_lista(void);
struct PontoTuristico* buscar_lista(struct PontoTuristico* cabeca, char *desc);
struct PontoTuristico* remover_lista(struct PontoTuristico* cabeca, char *desc);
struct PontoTuristico* liberar_lista(struct PontoTuristico* cabeca);
struct PontoTuristico* remover_nodos(struct PontoTuristico* cabeca, int num);
void imprimir(struct PontoTuristico *aux);

int main() {
    struct PontoTuristico *cabeca; char descricao[TAM];
    cabeca = criar_lista();
    cabeca = inserir_final(cabeca);
    cabeca = inserir_final(cabeca);
    cabeca = inserir_final(cabeca);
    cabeca = inserir_final(cabeca);
    cabeca = inserir_final(cabeca);
    printf("Imprimindo os nodos inseridos..."); getchar();
    imprimir(cabeca);
    cabeca = remover_nodos(cabeca, 6);
    printf("Imprimindo os nodos inseridos..."); getchar();
    imprimir(cabeca);
/*    printf("Qual nodo voce deseja procurar? ");
    scanf("%[^\n]", descricao);
    struct PontoTuristico *procura = buscar_lista(cabeca, descricao);
    printf("Imprimindo todas as informacoes do nodo..."); getchar();
    if (procura != NULL)
        printf("%s: latitude\t%.2f\t\tlongitude\t%.2f\n",procura->descricao, procura->latitude, procura->longitude);
    else
        printf("Ponto Turistico nao encontrado");
    printf("Qual nodo voce deseja remover? ");
    scanf("%[^\n]", descricao);
    printf("Removendo o nodo %s...", descricao); getchar();
    cabeca = remover_lista(cabeca, descricao);
    printf("Imprimindo os nodos restantes..."); getchar();
    imprimir(cabeca);
    printf("Liberando todos os nodos da lista..."); getchar();
    cabeca = liberar_lista(cabeca);*/
}

struct PontoTuristico* criar_lista(void) {
    return NULL;
};

void lerPontoTuristico(struct PontoTuristico *aux) {
    printf("\nDescricao: ");
    scanf("%[^\n]", aux->descricao);
    fflush(stdin);
    printf("\nLatitude: ");
    scanf("%f", &aux->latitude);
    fflush(stdin);
    printf("\nLongitude: ");
    scanf("%f", &aux->longitude);
    fflush(stdin);
}

void imprimir(struct PontoTuristico *cabeca) {
    struct PontoTuristico *paux;
    for (paux = cabeca; paux != NULL; paux = paux->proximo)
        printf("Descricao: %-41s\t%u\tLatitude: %.2f\t\t%u\tLongitude: %.2f\t\t%u\t%u\t\n",
        paux->descricao, paux->descricao,
        paux->latitude, &paux->latitude,
        paux->longitude, &paux->longitude, paux->proximo);
}

/*
cabeca -> 700
paux = 700

|  1 |  1 | NH  | 2500 |  ----->  |  2 |  2 | POA  | 3000 |  ----->  |  3 | 3  | SL  | NULL |
       700                                 2500                                3000
*/


struct PontoTuristico* inserir_inicio(struct PontoTuristico* cabeca) {
    struct PontoTuristico* novo = (struct PontoTuristico*) malloc(sizeof(struct PontoTuristico));
    lerPontoTuristico(novo);
    novo->proximo = cabeca;
    return(novo);
}

/* Função da atividade de estudo
   Ela é responsável pela inserção de um nodo no final da lista
*/
struct PontoTuristico* inserir_final(struct PontoTuristico* cabeca) {
    struct PontoTuristico *paux, *anterior_paux = NULL;
    struct PontoTuristico* novo = (struct PontoTuristico*) malloc(sizeof(struct PontoTuristico));
    lerPontoTuristico(novo);
    novo->proximo = NULL;
    if (verificar_lista_vazia(cabeca))
        cabeca = novo;
    else {
        paux = cabeca;
        while (paux != NULL) {
            anterior_paux = paux;
            paux = paux->proximo;
        }
        anterior_paux->proximo = novo;
    }
    return cabeca;
}

int verificar_lista_vazia(struct PontoTuristico* cabeca) {
    return (cabeca == NULL);
}

struct PontoTuristico* buscar_lista(struct PontoTuristico* cabeca, char *desc) {
    struct PontoTuristico  *paux;
    for (paux=cabeca; paux!=NULL; paux=paux->proximo)
        if (strcmp(paux->descricao, desc) == 0)
            return paux;
    return NULL;
}

struct PontoTuristico* remover_lista(struct PontoTuristico* cabeca, char *desc) {
    struct PontoTuristico *paux = cabeca;
    struct PontoTuristico *anterior_paux = NULL;
    while (paux != NULL && strcmp(paux->descricao, desc) != 0) {
        anterior_paux = paux;
        paux = paux->proximo;
    }
    if (paux == NULL)
        return cabeca;
    if (anterior_paux == NULL)
        cabeca = paux->proximo;
    else
        anterior_paux->proximo = paux->proximo;
    free(paux);
    return cabeca;
}

struct PontoTuristico* liberar_lista(struct PontoTuristico* cabeca) {
    struct PontoTuristico *paux = cabeca, *aux = NULL;
    while (paux != NULL) {
        aux = paux->proximo;
        free(paux);
        paux = aux;
    }
    return NULL;
}

struct PontoTuristico* remover_nodos(struct PontoTuristico* cabeca, int num) {
    int andar = 0;
    struct PontoTuristico* paux = cabeca;
    struct PontoTuristico* aux = NULL;
    while (paux != NULL && andar < num) {
        aux = paux->proximo;
        free(paux);
        paux = aux;
        andar++;
    }
    return paux;
};

struct PontoTuristico* lremove_nodos(struct PontoTuristico* cabeca, int num) {
    
}