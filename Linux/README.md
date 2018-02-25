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
* **HelloWorld** - demonstrates an ability to store data as the part of the .text section (usually, shellcode doesn't contains .data/.bss sections to take variables from), basic work with Linux SYSCALLs and the simplest technique to avoid bad characters (\x00 in this example).


## Resources
* (Syscall Reference)[https://syscalls.kernelgrok.com/]
