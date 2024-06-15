#include <iostream>
void insertionsort(int* array, int size) {
	for (int i = 1; i < size; i++) {
		for (int j = i; j < size; j++) {
			for (int k = j; k < i; k++) {
				if (array[j] < array[k]) {
					int temp = array[j];
					array[j] = array[k];
					array[k] = temp;
				}
			}
		}
	}
}

void printArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	}
}

int main() {
	int array[] = { 2, 8, 5, 3, 9,4,1 };
	int size = 7;

	insertionsort(array, size);
	printArray(array, size);

}