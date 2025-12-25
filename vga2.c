#include <stddef.h>
#include <stdint.h>

void kvga(uint16_t backfore,const char* s){
	volatile unsigned char* vga = (unsigned char*)0xB8000;
	size_t i = 0;
	uint16_t low = backfore & 0x0F; //maskalanmali ve asagi bitde qalmalidir
	uint16_t high = backfore << 4; //background surusmelidir 4 bit sola

	uint8_t atr = (uint8_t)low | high;

	const char* p = s;

	while(*p != '\0'){
		vga[i] = *p;
		vga[i+1] = atr;
		i+=2;
		p++;
	}
}
