#include "../TYPES.H"
#ifndef KEYBOARD_F
#define KEYBOARD_F
__attribute__ ((cdecl))
u_char8 getKey(){ // not print char
    static u_char8 key = 0;
    asm volatile(
        "pusha\n"
        "mov ah, 0x05\n"
        "int 0x90\n"
        "mov %0, dl\n"
        "popa\n"
        :"=m"(key)
        :
        :
    );
    return key;
}
#endif