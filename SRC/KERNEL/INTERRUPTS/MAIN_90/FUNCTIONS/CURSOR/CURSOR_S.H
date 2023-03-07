#include "../../../../../../INCLUDES/CURSOR/CURSOR_T.H"
#ifndef CURSOR_S
#define CURSOR_S
__attribute__ ((cdecl))
static CURSOR_POS fGetCursorPos(){
    static CURSOR_POS pos = {0, 0};
    asm volatile("pusha\n");
    asm volatile(
        "mov ah, 3\n"
        "mov bh, 0\n"
        "int 0x10\n"
        "mov %0, dh\n"
        "mov %1, dl\n"
        : "=m"(pos.y), "=m"(pos.x)
        :
        :
    );
    asm volatile("popa\n");
    return pos;
}
static void fSetCursorPos(){
    asm volatile("pusha\n");
    asm volatile(
        "mov ah, 2\n"
        "mov bh, 0\n"
        "int 0x10\n"
    );
    asm volatile("popa\n");
}
#endif