%macro operate 4                
    mov rax, %1
    mov rdi, %2
    mov rsi, %3
    mov rdx, %4
    
    syscall
%endmacro

section .data
arr dd 50.0,40.0,30.0,20.0,10.0
point db "."
pointlen equ $-point
divisor dd 5.0
tent dd 10000.0
new db 10

section .bss
mean1 rest 1
count resb 1
count1 resb 1
mean resd 1
temp resb 1

section .text
global _start
_start:
        mov esi,arr
        mov cx,05
        fldz
        
up:
        fadd dword[esi]
        add esi,4
        dec cx
        jnz up
        fdiv dword[divisor]
        fst dword[mean]
        fmul dword[tent] 
        fbstp tword[mean1]
        
        mov ebp,mean1
        call display
        operate 1,1,new,1
        operate 60,0,0,0
        
display:
        add ebp,9
        mov byte[count],10
        
above:  cmp byte[ebp],00
        je skip
        cmp byte[count],02
        jne print
        operate 1,1,point,pointlen
       
print:  mov bl,byte[ebp]
        mov byte[count1],2
        

againx: rol bl,4
        mov byte[ebp],bl
        and bl,0FH
        cmp bl,09H
        jbe downx
        add bl,07H
downx:
        add bl,30H
        mov byte[temp],bl
        operate 1,1,temp,1
        mov bl,byte[ebp]
        dec byte[count1]
        jnz againx
        
        
skip:
        dec ebp
        dec byte[count]
        jnz above
        ret
        
        

