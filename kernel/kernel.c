__attribute__((section(".multiboot")))
unsigned int multiboot_header[] = {
    0x1BADB002,
    0x0,
    -(0x1BADB002)
};

#include <stdint.h>
#include <stddef.h>
#include "idt.h"

void kernel_main(){
    initIDT();
    TimeHandler();
    pic_setup();
    while(1){ }
}

