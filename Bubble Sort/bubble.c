#include <stdio.h>

void bubbleSort(int *vetor, int tamanho) {

	int i, j, aux;

	for (i = 0; i < tamanho - 1; i ++) {

		for (j = i + 1; j < tamanho; j ++) {

			if (vetor[i] > vetor[j]) {

				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;

			}
		}
	}
}

int main (void) {

	int vetor[10] = {2, 3, 6, 8, 1, 4, 9, 5, 7, 0};
	int i;

	bubbleSort(vetor, 10);
	
	for (i = 0; i < 10; i ++)
		printf("%d ", vetor[i]);

	putchar('\n');

	return 0;

}
