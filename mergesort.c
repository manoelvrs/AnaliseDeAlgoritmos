#include <stdio.h>

void inter(int , int , int , int []);
void mergesort(int , int []);
int main(){
    int vet[] = {4, 1, 5, 2, 3};
    int a = 5;
    mergesort(a, vet);
    int b;
    for(b = 0; b < a; b++){
        printf("vet[%d] = %d\n", b, vet[b]);
    }
    return 0;
}

void mergesort(int c, int v[]){
   int m, n;
   int d = 1;
   while (d < c) {
      m = 0;
      while (m + d < c) {
         n = m + 2 * d;
         if (n > c) n = c;
         inter(m, m + d, n, v);
         m = m + 2 * d;
      }
      d = 2 * d;
   }
}


void inter(int p, int q, int o, int v[]){
   int i, j, k;
   int y[o - p];

   for (i = p; i < q; i++)  y[i-p] = v[i];

   for (j = q; j < o; j++)  y[(o-p)+q-1-j] = v[j];

   i = 0;
   j = o - p - 1;

   for (k = p; k < o; k++)
      if (y[i] <= y[j]) v[k] = y[i++];
      else v[k] = y[j--];
}

