#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

void func1(){
    printf("1\n");
    return;
}

void func2(){
    printf("2\n");
    return;
}     

int func_hack(){
    mprotect(&func1 - ((int)&func1)%0x1000, 0x1000, PROT_READ | PROT_WRITE | PROT_EXEC);
    return 0;

}

int main(){
    func1();
    func2();
    func_hack();
    return 0;

}
