#ifndef IDT_H
#define IDT_H
#include <stdint.h>

struct idt_entry{
    uint16_t offset_low;
    uint16_t selector;
    uint8_t zero;
    uint8_t type_attribute;
    uint16_t offset_high;
}__attribute__((packed));

struct idt_ptr{
    uint16_t limit;
    uint32_t base;
}__attribute__((packed));

void initIDT(void);     //bizim lidt registr ucun

#endif