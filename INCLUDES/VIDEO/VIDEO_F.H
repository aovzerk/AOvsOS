#include "../TYPES.H"
#ifndef VIDEO_F
#define VIDEO_F
__attribute__ ((cdecl))
void setVideoMode(u_char8 mode){
    asm volatile(
        "pusha\n"
        "mov ah, 0\n"
        "mov al, %0\n"
        "int 0x90\n"
        "popa\n"
    ::"r"(mode));
    return;
};
#endif