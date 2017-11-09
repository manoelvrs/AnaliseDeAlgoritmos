
#include <stdlib.h>
#include <stdio.h>
void print_optimal_parens(int **s,int i,int j,int l);
void matrix_chain_order(int *p,int n,int **m,int **s);

int main()
{
	int n = 6;
	int p[7];
	p[0]=25;
	p[1]=20;
	p[2]=10;
	p[3]=5;
	p[4]=15;
	p[5]=35;
	p[6]=30;

	int m[n+1][n+1];
	int s[n+1][n+1];

	matrix_chain_order(p,n,(int**)m,(int**)s);
	int i,j;
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			printf("%d  ",m[i][j]);
		}
		printf("\n");
	}
	print_optimal_parens((int**)s,1,6,7);
	return 0;
}

void matrix_chain_order(int *p,int n,int **m,int **s){
	int i;
	int row = n+1;

	for(i=1;i<=n;i++){
		*((int*)m+row*i+i) = 0;
	}

	int l;
	for(l=2;l<=n;l++){
		for(i=1;i<=(n-l+1);i++){
			int j = i+l-1;
			*((int*)m+row*i+j) = -1;
			int k;
			for(k=i;k<=(j-1);k++){
				int tmp1 = *((int*)m+row*i+k);
				int tmp2 = *((int*)m+row*(k+1)+j);
				int q = tmp1+tmp2+p[i-1]*p[k]*p[j];
				int old = *((int*)m+row*i+j);
				if(q<old || old == -1){
					*((int*)m+row*i+j) = q;
					*((int*)s+row*i+j) = k;
				}
			}
		}
	}

}

void print_optimal_parens(int **s,int i,int j,int l){
	if(i==j){
 printf("A%d",i);
	}else{
		printf("(");
		print_optimal_parens(s,i,*((int*)s+l*i+j),l);
		print_optimal_parens(s,*((int*)s+l*i+j)+1,j,l);
		printf(")");
	}
}
