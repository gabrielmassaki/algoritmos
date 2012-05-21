#include <stdio.h>

void insertionSort (int *vetor, int tamanho) {

	int i, j, aux;

	for (i = 0; i < tamanho - 1; i ++) {

		aux = vetor[i + 1];
		j = i;

		while (j >= 0 && aux < vetor[j]) {

			vetor[j + 1] = vetor[j];
			j --;

		}

		vetor[j + 1] = aux;

	}
}

int main (void) {

	int vetor[10] = {2, 3, 6, 8, 1, 4, 9, 5, 7, 0};
	int i;

	insertionSort(vetor, 10);
	
	for (i = 0; i < 10; i ++)
		printf("%d ", vetor[i]);

	putchar('\n');

	return 0;

}
