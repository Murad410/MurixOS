#include "include/string/kstring.h"
#include "include/mem/mem.h"
#include "vga.h"
#include <stdint.h>
#include <stddef.h>

void kmain(void){
	char buff[100];

	char src[10] = "Salam";
	kstrcpy(buff,src);

	char dest[10];
	kmemset(dest,'s',5);
	
	writk(0xF,0xA,"Salam");
}

