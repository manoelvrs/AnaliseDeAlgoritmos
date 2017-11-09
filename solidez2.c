#include <stdio.h>

int solidez2(int [], int, int);
int main(){
    int t = 5;
    int vet[] = {20, -30, 15, -10, 30};
    int x;
    for (x = 0; x < t; x++){
        printf("%d\n", vet[x]);
    }

    printf ("\n\nSolidez: %d\n\n", solidez2(vet, 0,t-1));

    return 0;
}

int solidez2(int v[], int p, int r){
    int a, b, c, i, j;
    int x1, x2, y1, y2;
    y1 = 0;
    y2 = 0;
    x1 = 0;
    x2 = 0;
    c = 0;
    b = 0;
    a = 0;
    if(p == r){
        return v[p];
     }
    else{
        a = (p+r)/2;
        x1 = solidez2(v, p, a);
        x2 = solidez2(v, a+1, r);

        b = v[a];
        y1 = b;

        for(i = a -1 ; i > p; i--){
            b += v[i];
            if( b > y1) y1 = b;
            b = v[a+1];
            y2 = b;
        }
        for(j = a+2; j <= r; j++){
            b += v[j];
            if(b > y2) y2 = b;
        }
        if(x1 > x2 && x1 > y1+y2){
            c = x1;
        }if(x2 > x1 && x2 > y1+y2){
            c = x2;
        }if(y1+y2 > x1 && y1+y2 > x2 )c = y1+y2;

        return c;
     }
}
