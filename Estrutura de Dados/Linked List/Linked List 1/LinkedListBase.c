#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PontoTuristico {
    char descricao[41];
    float latitude;
    float longitude;
    struct PontoTuristico *proximo;
}PontoTuristico;

PontoTuristico* criar_lista(void);
PontoTuristico* inserir_inicio(struct PontoTuristico* cabeca);
void lePontoTuristico(struct PontoTuristico *aux);
void imprimir(struct PontoTuristico* cabeca);
PontoTuristico* buscar_lista(struct PontoTuristico* cabeca, const char* descricao);

int main() {
    PontoTuristico *cabeca;
    cabeca = criar_lista();
    cabeca = inserir_inicio(cabeca);
    cabeca = inserir_inicio(cabeca);
    cabeca = inserir_inicio(cabeca);
    imprimir(cabeca);
    struct PontoTuristico* busca = buscar_lista(cabeca, "poa");
    if (busca) {
        printf("Ponto turistico encontrado: %s - Lat: %.2f - Long: %.2f\n",
               busca->descricao, busca->latitude, busca->longitude);
    }
    return 0;
}

struct PontoTuristico* criar_lista(void) {
    return NULL;
}

void lePontoTuristico(struct PontoTuristico *aux) {
    printf("Descricao: ");
    scanf(" %[^\n]", aux->descricao); // Alterado para incluir um espaço antes de %[^\n] para consumir qualquer newline anterior
    printf("\nLat: ");
    scanf("%f", &aux->latitude);
    printf("\nLong: ");
    scanf("%f", &aux->longitude);
    while(getchar() != '\n'); // Alterado para limpar o buffer de entrada de forma portável
}

struct PontoTuristico* inserir_inicio(struct PontoTuristico* cabeca) {
    struct PontoTuristico* novo = (struct PontoTuristico*) malloc(sizeof(struct PontoTuristico));
    if (novo == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    lePontoTuristico(novo);
    novo->proximo = cabeca;
    return(novo);
}

void imprimir(struct PontoTuristico* cabeca) {
    struct PontoTuristico* paux;
    for (paux = cabeca; paux != NULL; paux = paux->proximo)
        printf("%s: lat: %.2f, long: %.2f\n", paux->descricao, paux->latitude, paux->longitude);
}

struct PontoTuristico* buscar_lista(struct PontoTuristico* cabeca, const char* descricao) {
    for (struct PontoTuristico* atual = cabeca; atual != NULL; atual = atual->proximo) {
        if (strstr(atual->descricao, descricao) != NULL) {
            return atual;
        }
    }
    return NULL; // Retorna NULL se não encontrar
}
