section .data
na db "Enter Your name " ,10			;Declarations and intialisation
msglen equ $-na
rolln db "Enter your roll number: " ,10
msglen1 equ $-rolln
divv db "Enter your class: " ,10
msglen2 equ $-divv
stud db "Student details are:" ,10
msglen3 equ $-stud


section .bss

name resb 20
roll resb 10
divi resb 10


section .text
global _start

_start:

mov rax,1			;printing msg
mov rdi,1
mov rsi,na
mov rdx,msglen
syscall

mov rax,0			;Reading Value
mov rdi,0
mov rsi,name
mov rdx,20
syscall

mov rax,1			;printing msg1
mov rdi,1
mov rsi,rolln
mov rdx,msglen1
syscall

mov rax,0			;Reading Value
mov rdi,0
mov rsi,roll
mov rdx,10
syscall

mov rax,1			;printing msg
mov rdi,1
mov rsi,divv
mov rdx,msglen2
syscall

mov rax,0			;Reading Value
mov rdi,0
mov rsi,divi
mov rdx,10
syscall

mov rax,1			;printing msg
mov rdi,1
mov rsi,stud
mov rdx,msglen3
syscall

mov rax,1			;printing msg
mov rdi,1
mov rsi,name
mov rdx,20
syscall

mov rax,1			;printing msg
mov rdi,1
mov rsi,roll
mov rdx,10
syscall

mov rax,1			;printing msg
mov rdi,1
mov rsi,divi
mov rdx,10
syscall


mov rax,60			;terminating program
mov rdi,0
syscall
