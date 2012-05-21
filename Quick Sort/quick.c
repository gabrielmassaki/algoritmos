#include <stdio.h>

void quickSort (int *vetor, int inicio, int fim) {

	int i, j, pivot, aux;

	pivot = vetor[inicio];

	i = inicio;
	j = fim;

	do {

		while (vetor[i] < pivot)
			i ++;
		while (vetor[j] > pivot)
			j --;

		if (i <= j) {

			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i ++;
			j --;

		}

	} while (i <= j);

	if (inicio < j)
		quickSort(vetor, inicio, j);
	
	if (fim > i)
		quickSort(vetor, i, fim);

}

int main (void) {

	int vetor[10] = {2, 3, 6, 8, 1, 4, 9, 5, 7, 0};
	int i;

	quickSort(vetor, 0, 10 - 1);
	
	for (i = 0; i < 10; i ++)
		printf("%d ", vetor[i]);

	putchar('\n');

	return 0;

}
