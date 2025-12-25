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
	call print_loop

msg:
	hello db "Hello From Bootloader!",0

halt:
	jmp halt

times 510-($-$$) db 0
dw 0xAA55	
