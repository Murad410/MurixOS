#include "idt.h"
#include <stdint.h>
#include <stddef.h>

extern TimeHandler;

struct idt_entry IDT[256];
struct idt_ptr idtr;

void idt_gate(uint8_t n,uint32_t handler){
    IDT[n].offset_low = handler & 0xFFFF;
    IDT[n].selector = 0x08;
    IDT[n].zero = 0;
    IDT[n].type_attribute = 0x8E;
    IDT[n].offset_high = (handler >> 16) & 0xFFFF;
}

static inline void outb(uint16_t port,uint8_t val){     //outb funksiyasi
    asm volatile("outb %0,%1"
                    :
                    :
                "a"(val),"Nd"(port)        );
}

void TimeHandler(void){
    volatile unsigned char* vidmem = (unsigned char*)0xb8000;
    size_t sayac = 0;
    sayac++;                                    //ISR
    if(sayac % 100 == 0){
        vidmem[2] = 'm';
    }
    outb(0x20,0x20);        //iretd
}

void initIDT(void){
    idtr.limit = sizeof(IDT) - 1;
    idtr.base = (uint32_t)&IDT;    //registr ucun quruldu (pointer)
    asm volatile("lidt %0" : :"m"(idtr));
    asm volatile("sti");
}

void pic_setup(void){
    
}