#include "TYPES.H"
static void setVideoMode(u_char8 mode){
    asm volatile("pusha");
    asm volatile(
        "xor ax,ax\n"
        "mov al, %0\n"
        "int 0x90\n"
    ::"m"(mode));
    asm volatile("popa");
    return;
};