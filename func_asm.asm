section .bss
    
global _start
    
_start:
 
    call _func
    
    mov rax, 60  
    mov rdi, 0
    syscall
 
_func:
    mov ebx, 7
    mov ecx, 8
    mov eax, ebx
    add eax, ecx
    syscall
    ret
