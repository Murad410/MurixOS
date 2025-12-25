[ORG 0x7C00]
[BITS 16]
	
start:
	jmp main

print:
	push si
	push ax
	
print_loop:
	lodsb
	cmp al,0
	jz done
	mov ah,0x0E
	int 0x10
	jmp print_loop
done:
	pop si
	pop ax
	ret

main:
	xor ax,ax
	mov ds,ax
	mov es,ax
	mov ss,ax
	mov sp,0x7C00
	mov si,msg
	call print
	msg db "Hello From Bootloader!",0x0D,0x0A,0

load_kernel:
	mov ax,0x1000
	mov es,ax
	xor bx,bx
	mov al,2
	mov ch,0
	mov dh,0
	mov cl,2
	mov dl,0x0
	mov ah,0x02
	int 0x13
	jmp 1000:0000
	
halt:
	jmp halt

times 510-($-$$) db 0
dw 0xAA55	
