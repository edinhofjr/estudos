#include <stdio.h>

int linearSearch(int *array, int arraySize, int target) {
    for (int i = 0; i < arraySize; i++) {
        if (array[i] == target) {
            printf("valor %d encontrado no index %d\n", target, i);
            return i;
        }
    }
    printf("Valor não encontrado.");
    return -1;
}
int main() {
    int valores[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("%d", linearSearch(valores,10,11));
}
