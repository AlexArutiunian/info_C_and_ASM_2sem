section .bss
    
section .text
    global _start
    
text:
        db      "# # # # # # # #", 10, 0
_start:
 
    xor rbx, rbx
    
    L1:
    add rbx, 1
    call _printText
    cmp rbx, 7
    jle L1
    
    mov rax, 60  
    mov rdi, 0
    syscall
 
_printText:
    mov rax, 1
    mov rdi, 1
    mov rsi, text
    mov rdx, 16
    syscall
    ret
