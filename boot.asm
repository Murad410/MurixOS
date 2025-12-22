[ORG 0x7C00]
[BITS 16]

boot:
	cli
	xor ax,ax
	mov ss,ax
	mov sp,0x7C00
	sti
	mov ah,0x0E
	mov al,'H'
	int 0x10

	mov ah,0x0E
	mov al,'I'
	int 0x10

	mov ah,0x0E
	mov al,'!'
	int 0x10

kload:
	mov dx,0x1000
	mov ch,0
	mov cl,2
	mov dh,0
	mov es,dx
	xor bx,bx
	mov dl,0
	mov ah,0x02
	int 0x13
	call kmain

times 510-($-$$) db 0
dw 0xAA55
