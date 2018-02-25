global _start

section .text

_start:
    jmp DATA      

PAYLOAD: 
    pop ebx		; Place address of "/bin/sh" to EBX
    xor ecx, ecx 	; All other params for SYS_EXECVE 
    xor eax, eax        ; equal 0
    xor edx, edx        ;
    xor esi, esi        ;

    mov al, 0x0b 	; SYS_EXECVE CODE
    int 0x80       
DATA:
    call PAYLOAD       
    db "/bin/sh", 0h	

section .data
