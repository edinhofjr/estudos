#include <stdio.h>
#include <math.h>

void binarySearch(int *arr, int size, int target) {
    int start,end,mid;
    start = 0;
    end = size - 1;

    while(start <= end) {
        mid = (start + end)/2;

        if(arr[mid] == target) {
            printf("Valor encontrado no index %d", mid);
            break;
        }

        if(arr[mid] > target) {
            end = mid - 1 ;
        }

        if(arr[mid] < target) {
            start = mid + 1;
        }
    }
}
int main(void) {
    int valores[] = {0,1,2,3,4};
    binarySearch(valores, 5,0);
}
