#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intercalaValores (int *vetor1, int *vetor2, int esquerda, int direita, int ladoDireito) {
/* Intercala os valores do vetor 1 salvando os valores no vetor 2 */

	int i, j, k;

	i = esquerda;
	j = direita;
	k = esquerda;

	while (i < direita && j < ladoDireito) {

		if (vetor1[i] <= vetor1[j]) {

			vetor2[k] = vetor1[i];
			i ++;

		} else {

			vetor2[k] = vetor1[j];
			j ++;

		}

		k ++;

	}
	
	while (i < direita) {

		vetor2[k] = vetor1[i];
		i ++;
		k ++;

	}

	while (j < ladoDireito) {

		vetor2[k] = vetor1[j];
		j ++;
		k ++;

	}

}

void mergeSort (int *vetor, int tamanho) {

	int *aux, esquerda, direita, ladoDireito, tamanhoDivisao, par;

	aux = (int *) malloc (sizeof(int) * tamanho);

	tamanhoDivisao = 1;
	par = 0;

	while (tamanhoDivisao < tamanho) {

		esquerda = 0;
		par = !par;

		do {

			direita = esquerda + tamanhoDivisao;
			ladoDireito = direita + tamanhoDivisao;
			
			if (direita >= tamanho) { /* lado direito vazio */

				direita = tamanho;
				ladoDireito = tamanho - 1;

			} else if (ladoDireito > tamanho)
				ladoDireito = tamanho;

			if (par)
				intercalaValores(vetor, aux, esquerda, direita, ladoDireito);
			else
				intercalaValores(aux, vetor, esquerda, direita, ladoDireito);

			esquerda = direita + tamanhoDivisao;

		} while (esquerda < tamanho);

		tamanhoDivisao = tamanhoDivisao * 2;

	}

	if (par)
		memcpy(vetor, aux, sizeof(int) * tamanho);

	free(aux);

}

int main (void) {

	int vetor[10] = {2, 3, 6, 8, 1, 4, 9, 5, 7, 0};
	int i;

	mergeSort(vetor, 10);

	for (i = 0; i < 10; i ++)
		printf("%d ", vetor[i]);

	putchar('\n');

	return 0;

}
