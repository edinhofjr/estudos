#include <iostream>
void selectionsort(int *array, int size) {
	for (int i = 0; i < size; i++) {
		int *min = &array[i];
		for (int j = i; j < size; j++) {
			if (array[j] < *min) {
				min = &array[j];
			}
		}
		int temp = array[i]; 
		array[i] = *min;
		*min = temp;

	}
}

void printArray(int *array, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << " "; 
	}
}

int main() {
	int array[] = {2, 8, 5, 3, 9,4,1};
	int size = 7;

	selectionsort(array, size);
	printArray(array, size);

}