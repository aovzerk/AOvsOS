#include "../../../../../../INCLUDES/TYPES.H"
#ifndef KEYBOARD_S
#define KEYBOARD_S

__attribute__ ((cdecl))
static u_char8 fGetKey(){
    static u_char8 key = 0;
    asm volatile("pusha\n");
    asm volatile(
        "xor ax, ax\n"
        "int 0x16\n"
        "mov %0, al\n"
        : "=m"(key)
        :
        :
    );
    asm volatile("popa\n");
    return key;
};
#endif