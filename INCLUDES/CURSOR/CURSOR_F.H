#include "CURSOR_T.H"
#ifndef CURSOR_F
#define CURSOR_F
__attribute__ ((cdecl))
void printChar1(u_char8 c){
    asm volatile(
        "pusha\n"
        "mov ah, 0x03\n"
        "mov al, %0\n"
        "int 0x90\n"
        "popa\n"
    ::"r"(c));
}
__attribute__ ((cdecl))
CURSOR_POS GetCursorPos(){
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
__attribute__ ((cdecl))
void SetCursorPos(CURSOR_POS pos){
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