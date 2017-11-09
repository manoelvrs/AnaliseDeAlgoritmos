#include <stdio.h>
#include <stdlib.h>

float fibonacci(int a);

int main(){
    
	printf("%f\n", fibonacci(80));
   
    	return 0;
	}

float fibonacci(int a){
    float fib[a];
    int b;

    	fib[0] = 0.0;
    	fib[1] = 1.0;

    		for( b= 2; b < a; b++){
        	fib[b] = fib[b-1] + fib[b-2];
    		}

    return fib[b-1];
	}


