#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_LENGTH 1000

typedef struct _Fibonacci{
    char n[NUMBER_LENGTH];
}Fibonacci;

static char tmp[NUMBER_LENGTH];

int FnLen(Fibonacci *fn){return strlen(fn->n);}

Fibonacci *FnInit(int n){
    Fibonacci *fn = (Fibonacci*)malloc(sizeof(Fibonacci)*n);
    memset(fn[0].n, 0, NUMBER_LENGTH);
    memset(fn[1].n, 0, NUMBER_LENGTH);
    fn[0].n[0] = '1';
    fn[1].n[0] = '1';
    return fn;
}

void FnAdd(Fibonacci *fn, int res_no, int added1_no, int added2_no){
    int len_a1 = FnLen(&fn[added1_no]);
    int len_a2 = FnLen(&fn[added2_no]);
    int len_res = (len_a1 > len_a2)?len_a1:len_a2;
    int c = 0;
    int a1 = len_a1-1;
    int a2 = len_a2-1;
    int res = len_res-1;
    memset(fn[res_no].n, 0, NUMBER_LENGTH);
    while(res >= 0){

        fn[res_no].n[res] =
            ((a1 >= 0)? fn[added1_no].n[a1]-'0' : 0)
            + ((a2 >= 0)? fn[added2_no].n[a2]-'0' : 0)
            + c +'0';

        if(fn[res_no].n[res] > '9'){
            c = 1;
            fn[res_no].n[res] -= 10;
        }else{
            c = 0;
        }
        res--;
        a1--;
        a2--;
    }
    if(c == 1){
        memcpy(tmp, fn[res_no].n, len_res);
        memcpy(fn[res_no].n+1, tmp, len_res);
        fn[res_no].n[0] = '1';
    }
}

Fibonacci *FnGen(int n){
    Fibonacci *fn = FnInit(n);
    int i;
    for(i = 2; i < n; i++){
        FnAdd(fn, i, i-1, i-2);
    }
    return fn;
}
int main(int argc, char const *argv[])
{
    int seq_no;
    int i;
    Fibonacci *fn;
    printf("Please Enter Nth you want to get: ");
    scanf("%d", &seq_no);
    fn = FnGen(seq_no);
    if(argc == 2 && strncmp(argv[1], "-l", 2) == 0) i = 0;
    else i = seq_no - 1;
    for(; i < seq_no; i++){
        printf("[%d] %s\n", i+1, fn[i].n);
    }
    return 0;
}