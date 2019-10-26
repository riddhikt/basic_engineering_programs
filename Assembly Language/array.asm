
section .data
welmsg db 'Welcome to MITL assignment 03',10
welmsg_len equ $-welmsg
msg2 db 'Array is::',10
msglen2 equ $-msg2
msg3 db 10,'Array Addition is:'
msglen3 equ $-msg3
cnt db 0
nwln db 10
arr db 01h,02h,03h,04h

section .bss

cnt1 resb 2
cnt2 resb 2
dispbuff resb 5
resultl resb 1
resulth resb 1
cnt3 resb 2


%macro rw 4 ; to read and write
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro


section .text

global _start
_start:
rw 1,1,welmsg,welmsg_len

mov byte[cnt],5 
mov dl,[cnt]
mov [cnt1],dl
mov [cnt2],dl

rw 1,1,msg2,msglen2
mov rsi,arr 
arr2:
mov bl,[rsi] 
mov bh,0
mov rcx,04
push rsi
call disp16_proc 
pop rsi
inc rsi
dec byte[cnt1]
cmp byte[cnt1],0
jnz arr2

rw 1,1,msg3,msglen3
mov rsi,arr 
mov byte[resultl],0
mov byte[resulth],0
arr3: mov bl,[rsi] 
add [resultl],bl 
adc byte [resulth],0 
inc rsi ;get next num
dec byte[cnt2] 
cmp byte[cnt2],0
jnz arr3

mov bl,[resultl] 
mov bh,[resulth]
mov rcx,04
call disp16_proc

mov rax,60 ;Exit
mov rdi,0
syscall



disp16_proc:
mov rdi,dispbuff 
dup11:
rol bx,4 
mov al,bl 
and al,0Fh 
cmp al,09h 
jbe dskip1
add al,07h 
dskip1: add al,30h 
mov [rdi],al 
inc rdi 
loop dup11 
rw 1,1,dispbuff,4
rw 1,1,nwln,1
ret
