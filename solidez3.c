#include <stdio.h>

int solidez3(int [], int, int);
int main(){
    int t = 5;
    int vet[] = {20, -30, 15, -10, 30};
    int x;
    for (x = 0; x < t; x++){
        printf("%d\n", vet[x]);
    }

    printf ("\nSolidez: %d\n", solidez3(vet, 0,t-1));

return 0;
}

int solidez3(int v[], int p, int r){
    int a, b;
    int s[r];

    s[p] = v[p];
    for(a = p+1; a <= r; a++){
        if(s[a-1] > 0){
            s[a] = s[a-1] + v[a];

        }else{
            s[a] = v[a];
        }
    }
    b = s[p];
    for(a = p+1; a <= r; a++){
        if(s[a] > b){
            b = s[a];
        }
    }
    return b;
}
