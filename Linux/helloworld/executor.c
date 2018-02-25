char shellcode[] = "\xeb\x17" 	// jmp MESSAGE
		  
                                // PAYLOAD:
	           "\x31\xc0"   // xor eax, eax
		   "\xb0\x04" 	// mov al, 0x4
		   "\x31\xdb"   // xor ebx, ebx
		   "\xb3\x01" 	// mov bl, 0x1
		   "\x59"     	// pop ecx
		   "\x31\xd2"   // xor edx, edx
		   "\xb2\x0f" 	// mov dl, 0xf
		   "\xcd\x80" 	// int 0x80

		   "\x31\xc0"   // xor eax, eax
		   "\xb0\x01" 	// mov al, 0x1
		   "\x31\xdb" 	// xor ebx, ebx
		   "\xcd\x80" 	// int 0x80

		   				  // MESSAGE:
		   "\xe8\xe4\xff\xff\xff" 	  // call PAYLOAD
		   "\x48\x65\x6c\x6c\x6f\x2c\x20" // Hello, 
		   "\x57\x6f\x72\x6c\x64\x21"     // World!
		   "\x0d\x0a";

int main()
{
	int* ret;
	ret = (int *)&ret + 2;
	(*ret) = (int)shellcode;
}
