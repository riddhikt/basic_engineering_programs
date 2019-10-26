section .data
msg db "Sorted array is: ",10
msglen equ $-msg
arr db 05h,0Ah,75h,0D3h,12h           

%macro operate 4                       
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .bss                           
result resb 15

section .text                         
global _start
_start:

mov bl,5                              
l1: 	mov cl,4
	mov esi,arr
	
l2: 	mov al,byte[esi]
	cmp al,byte[esi+1]
	jae l3               ;for ascending jbe
	xchg al,byte[esi+1]
	mov byte[esi],al
	
l3: 	inc esi
	dec cl
	jnz l2
	dec bl
	jnz l1
	
operate 1,1,msg,msglen
mov edi,arr
mov esi,result
mov dl,10

disp:	mov cl,2
	mov al,[edi]

againx:	rol al,4
	mov bl,al
	and al,0fh
	cmp al,09h
	jbe downx
	add al,07h

downx:	add al,30h
	mov byte[esi],al
	mov al,bl
	inc esi
	dec cl
	jnz againx
	mov byte[esi],0ah
	inc esi
	inc edi
	dec dl
	jnz disp
	operate 1,1,result,15

operate 60,0,0,0



	

	
	
	 

