#include <stdio.h>
#include <stdlib.h>

void up(int *v, int m) {
  int i, aux;
  i = (m - 1) / 2;
  aux = v[m];
  while (m > 0 && v[i] > aux) {
    v[m] = v[i];
    m = i;
    i = (i - 1) / 2;
  }
  v[m] = aux;
}

void down(int *v, int m, int size) {
  int i, aux;
  i = 2 * m + 1;
  aux = v[m];
  while(i < size) {
    if (i < size - 1 && v[i] > v[i + 1]) {
      i ++;
    }
    if (aux > v[i]) {
      v[m] = v[i];
      m = i;
      i = 2 * i + 1;
    } else
      break;
  }
  v[m] = aux;
}

void build(int *v, int size) {
  int i;
  for (i = (size - 2) / 2; i >= 0; i --) {
    down(v, i, size);
  }
}

int insertHeap(int *v, int size, int x) {
  v[size] = x;
  up(v, size);
  return size + 1;
}

int removeHeap(int *v, int size, int *x) {
  *x = v[0];
  v[0] = v[size - 1];
  down(v, 0, size - 1);
  return size - 1;
}

void heapSort(int *v, int size) {
  int i, n, aux, temp;
  n = size;
  temp = size;
  for (i = (n - 2) / 2; i >= 0; i --) {
    down(v, i, size);
  }
  for (i = n - 1; i > 0; i --) {
    aux = v[0];
    v[0] = v[i];
    v[i] = aux;
    temp --;
    down(v, 0, temp);
  }
}

int main() {
  int size, *v, i;
  scanf("%d", &size);
  v = (int *) malloc (sizeof(int) * size);
  for (i = 0; i < size; i ++) {
    scanf("%d", &v[i]);
  }
  heapSort(v, size);
  for (i = 0; i < size; i ++) {
    printf("%d\n", v[i]);
  }
  return 0;
}
