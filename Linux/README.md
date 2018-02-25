# Linux Shellcodes

Most of shellcodes contain two files - \*.c and \*.asm, where first file is just a code that executes shellcode and second is the shellcode itself.

## Make things work
Execute these commands to build an ELF from \*.asm file:
```
nasm -f elf prog.asm
ld -m elf_i386 prog.o -o prog
```

Examine ELF with ObjDump:
```
objdump -D helloworld -M intel

```

Compile the executor:
```
gcc executor.c -o execute
```

## Description
* **HelloWorld** - demonstrates an ability (eip-based way) to store data as the part of the .text section (usually, shellcode doesn't contains .data/.bss sections to take variables from), basic work with Linux SYSCALLs and the simplest technique to avoid bad characters (\x00 in this example).

* **sh_shell** - implements both eip-based and stack-based approaches of passing data into shellcode. Both \*.asm files are working, but only second way is working when we try to run shellcode from C program, because of 0x00 byte in the first shellcode (necessary for proper SYS_EXECVE call). 

## Resources
* (Syscall Reference)[https://syscalls.kernelgrok.com/]
