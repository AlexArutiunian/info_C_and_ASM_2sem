#include <stdio.h>
#define N 4
int main()
{
    int i;
    int arr[N] = {'A', 'B', 'C', 'D'};
    printf("Array:\n");
    for(i = 0; i < N; i++) printf("%c ", arr[i]);
    printf("\n");
    
    long long N_count = N;
    int * p_arr = arr;
    
    long long res = 0;
    long long razn = 'A' - 'a';
    printf("razn = %lld\n", razn);
    
    asm volatile(
        ".intel_syntax noprefix\n"
       
        "L1:;\n"
        "mov bl, [rax + (rcx-1)*4];\n"
        "sub bl, dl;\n"
        "mov [rax + (rcx-1)*4], bl;\n"
        "loop L1;\n"
        
        ".att_syntax noprefix"
        : "=d" (res)
        : "a" (p_arr), "c" (N_count), "d" (razn)
        
    );
    
    printf("After asm\n");
    printf("Array:\n");
    for(i = 0; i < N; i++) printf("%c ", arr[i]);
    printf("\n");
    return 0;
}

