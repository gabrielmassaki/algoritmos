#include <stdio.h>

void selectionSort (int *vetor, int tamanho) {

	int i, j, k, aux;

	for (i = 0; i < tamanho - 1; i ++) {

		k = i;

		for (j = i + 1; j < tamanho; j ++) {

			if (vetor[k] > vetor[j])
				k = j;

			aux = vetor[i];
			vetor[i] = vetor[k];
			vetor[k] = aux;
		
		}
	}
}

int main (void) {

	int vetor[10] = {2, 3, 6, 8, 1, 4, 9, 5, 7, 0};
	int i;

	selectionSort(vetor, 10);
	
	for (i = 0; i < 10; i ++)
		printf("%d ", vetor[i]);

	putchar('\n');

	return 0;

}
