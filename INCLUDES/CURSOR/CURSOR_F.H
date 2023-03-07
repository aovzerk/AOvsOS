#include "CURSOR_T.H"
#ifndef CURSOR_F
#define CURSOR_F
static CURSOR_POS GetCursorPos(){
    static CURSOR_POS pos = {0, 0};
    asm volatile("pusha\n");
    asm volatile(
        "mov ah, 1\n"
        "int 0x90\n"
        "mov %0, dh\n"
        "mov %1, dl\n"
        : "=m"(pos.y), "=m"(pos.x)
        :
        :
    );
    asm volatile("popa\n");
    return pos;
}
static void SetCursorPos(CURSOR_POS pos){
    asm volatile("pusha\n");
    asm volatile(
        "mov ah, 2\n"
        "mov dh, %0\n"
        "mov dl, %1\n"
        "int 0x90\n"
        : 
        :"r"(pos.y), "r"(pos.x)
        :
    );
    asm volatile("popa\n");
}
#endif