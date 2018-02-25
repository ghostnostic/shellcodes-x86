global _start

section .text

_start:
    jmp MESSAGE      

PAYLOAD:
    xor eax, eax
    mov al, 0x4		; SYS_WRITE CODE

    xor ebx, ebx	; FILE_DESCRIPTOR = STDOUT
    mov bl, 0x1  	

    pop ecx             ; Message Address
                      
    xor edx, edx
    mov dl, 0xf		; Message Length
    int 0x80		; SYS_WRITE CALL
    
    xor eax, eax
    mov al, 0x1		; SYS_EXIT CODE
    
    xor ebx, ebx	; EXIT_CODE = 0
    int 0x80		; SYS_EXIT CALL

MESSAGE:
    call PAYLOAD       	; String Address will be pushed in the Stack
			; As Saved-EIP value
    db "Hello, World!", 0dh, 0ah

section .data

