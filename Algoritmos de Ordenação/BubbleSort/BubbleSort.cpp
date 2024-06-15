#include <iostream>
void bubblesort(int *array, int size) {
	size--;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array[j] > array[j + 1]) {
				int tmp = array[j]; 
				array[j] = array[j + 1];
				array[j + 1] = tmp; 
			}
		}
	}
}

void printArray(int *array, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	}
}

int main() {
	int array[] = { 2,8,5,3,9,4,1 };
	int size = 7;

	bubblesort(array, size);
	printArray(array, size);
}