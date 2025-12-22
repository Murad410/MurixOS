#include <stddef.h>
#include "vga.h"
	volatile unsigned char* vga = (unsigned char*)0xB8000;
	unsigned int i = 0;
	const char* p = s;


	uint16_t high = backgr << 4;
	uint16_t low = foregr & 0x0F;


	uint16_t atribute = high | low;

	while(*p != '\0'){
        vga[i] = *p;
        vga[i+1] = atribute;
        i+=2;
    }

}
