%macro rw 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .data
msg db "Enter two three digit number", 10
msglen equ $-msg
msg1 db "Number converted to packed format sucessfully", 10
msglen1 equ $-msg1

section .bss
num resb 4

section .text
    global _start
    _start:
        rw 1,1,msg,msglen
        rw 0,0,num,4
        
        mov rsi,num
        mov rcx,2
        mov rax,0
        up: rol al,4
            mov bl,[rsi]
            cmp bl,39h
            jbe down
            sub bl,07h
        down:sub bl,30h
            add al,bl
            inc rsi
            dec rcx
            jnz up 
            rw 1,1,msg1,msglen1
            mov rax,60
            mov rdi,0
            syscall          
          


;for Executing in debugger
;ibm@IBM:~$ nasm -f elf64 -F stabs hexa.asm
;ibm@IBM:~$ ld -o hexa hexa.o
;ibm@IBM:~$ ddd hexa&


