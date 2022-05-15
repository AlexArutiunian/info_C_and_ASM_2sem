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
    size_t page_size = sysconf(_SC_PAGE_SIZE);
    if(page_size == -1){
        printf("sysconf");
        return -1;
    }
    void *base = &func1 - (unsigned long long)&func1%page_size;
    if(mprotect(base, page_size, PROT_READ | PROT_WRITE | PROT_EXEC) != 0){
        printf("ERROR in mpotect() syscall\n");
        return -1;
    }
    return 0;

}

int main(){
    func1();
    func2();
    func_hack();
    return 0;

}
