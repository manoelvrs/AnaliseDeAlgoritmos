#include <stdio.h>

int solidez1(int [], int, int);
int main(){
    int t = 5;
    int vet[] = {20, -30, 15, -10, 30};
    int x;
    for (x = 0; x < t; x++){
        printf("%d\n", vet[x]);
    }

    printf ("\nSolidez: %d\n",solidez1(vet, 0,t-1));

    return 0;
}

int solidez1(int A[], int m, int n){
    int y = A[n];
    int i;
    int j;
    for(i = n-1; i >= m ; i--){
        int s = 0;
        for(j = i; j <= n; j++){
            s = s + A[j];
            if(s > y){
                y = s;
            }
        }
    }
    return y;
}

