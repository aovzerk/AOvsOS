#include "../TYPES.H"
#ifndef VIDEO_SERV
#define VIDEO_SERV
static void setVideoMode(u_char8 mode){
    asm volatile("pusha");
    asm volatile(
        "mov ah, 0\n"
        "mov al, %0\n"
        "int 0x90\n"
    ::"r"(mode));
    asm volatile("popa");
    return;
};
#endif