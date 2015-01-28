#include <stdio.h>
#include <stdlib.h>

double circleF(int i, int n, int k, double *p);
double circleL(int i, int n, int k, double *p);

int main(int argc, char const *argv[])
{
    int n,k;
    double *p;
    int i;
    
    printf("Please Input Must Information:\n");
    printf("N: ");
    scanf("%d", &n);
    printf("K: ");
    scanf("%d", &k);
    p = (double*)malloc(sizeof(double)*(n+k+1));
    printf("P of Each Node(Seperate by Space): ");

    for(i = 1; i <= n; i++){
        scanf("%lf", &p[i]);
    }
    for(;i <= n+k; i++){
        p[i] = 0.0;
    }

    printf("R = %lf\n", circleF(1, n, k, p));

    return 0;
}

double circleF(int s, int n, int k, double *p){
    double r = 0.0;
    double t;
    int i, j;
    if(n < k){
        return 1.0;
    }else{
        for(i = s;i <= k; i++){
            t = p[i];
            for(j = 1; j < i; j++){
                t *= 1-p[j];
            }
	    printf("CF(%d, %d, %d)\n", i+1, n+i-1, k);
            r += t*circleL(1 , n-1, k, p+i);
        }
        return r;
    }
}

double circleL(int s, int n, int k, double *p){
    double r = 0.0;
    double t;
    int i;
    int j;
    if(n < k){
        return 1.0;
    }else{
        for(i = n-k+1; i <= n; i++){
            t = p[i];
            for(j = i+1; j <= n; j++){
                t *= 1-p[j];
            }
            printf("\tRL(%d, %d, %d)\n", s, i-1, k);
            r += t*circleL(s, i-1, k, p);
        }
    }
    return r;
}