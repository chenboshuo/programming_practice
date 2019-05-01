#include <stdio.h>
#include <stdlib.h>

/**
 * Generating the next permulation in lwxicographic order
 * @param a array
 * @param n the length of array
 * @return if it have next permulation, return 1;else return 0;
 */
int next_permulation(int *a, int n){
  if (n == 1) {
    return 0;
  }

  // let j be the largest subscript(下标) of with a[j] < a[j+1]
  int j = n - 2;
  while (a[j] > a[j+1]) {
    --j;
  }
  if (j < 0) {
    return 0;
  }

  // let a[k] be the smallest integer greater than a[j] to the right of a[i]
  int k = n-1;
  while (a[j] > a[k]) {
    --k;
  }

  // interchange a[j] and a[k]
  a[j] ^= a[k]; a[k] ^= a[j]; a[j] ^= a[k];

  int r = n - 1;
  int s = j + 1;
  while (r > s && r < n && s >= 0) {
    // interchange a[r] and a[s]
    a[r] ^= a[s]; a[s] ^= a[r]; a[r] ^= a[s];
    --s;++r;
  }
  return 1;

}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  int *a = (int*)malloc (sizeof(int) * n);
  for(int i = 1; i <= n; ++i){
    a[i-1] = i;
  }
  do {
    for(int i = 0; i < n; ++i){
      printf("%d ", a[i]);
    }
    printf("\n");
  } while(next_permulation(a,n));
  return 0;
}
/*
  input
  3

  output
  1 2 3
  1 3 2
  2 1 3
  2 3 1
  3 1 2
  3 2 1

  input
  4

  output
  1 2 3 4
  1 2 4 3
  1 3 2 4
  1 3 4 2
  1 4 2 3
  1 4 3 2
  2 1 3 4
  2 1 4 3
  2 3 1 4
  2 3 4 1
  2 4 1 3
  2 4 3 1
  3 1 2 4
  3 1 4 2
  3 2 1 4
  3 2 4 1
  3 4 1 2
  3 4 2 1
  4 1 2 3
  4 1 3 2
  4 2 1 3
  4 2 3 1
  4 3 1 2
  4 3 2 1
 */
