#include <stdio.h>
#include <stdlib.h>
void gul_moedas(float);
int main(){

    gul_moedas(0.95);
    return 0;
}

void gul_moedas(float valor){
    int v[6];
    int gul_moedas[] = {100, 50, 25, 10, 5, 1};
    int c;

    for(c=0; c < 6; c++){
        vet[c] = 0;
    }

    valor *= 100.0;
    while(valor != 0){
        if(valor >= 100){
            valor -= 100;
            v[0]++;
            continue;
        }else if(valor >= 50){
            valor -= 50;
            v[1]++;
            continue;
        }else if(valor >= 25){
            valor -= 25;
            v[2]++;
            continue;
        }else if(valor >= 10){
            valor -= 10;
            v[3]++;
            continue;
        }else if(valor >= 5){
            valor -= 5;
            v[4]++;
            continue;
        }else{
            valor --;
            v[5]++;
            continue;
        }
    }

    for(c=0; c < 6; c++){
        printf("%d Moedas de %d centavos\n",v[c], gul_moedas[c]);
    }



}
