
#include "../../../../../../INCLUDES/TYPES.H"
#include "../../../../../../INCLUDES/STRINGS/STRING_LEN.H"
#include "../../../../../../INCLUDES/CURSOR/CURSOR_F.H"
#ifndef VIDEO_S
#define VIDEO_S
__attribute__ ((cdecl))
static void fSetVideoMode(){
    asm volatile("pusha\n");
    asm volatile(
        "mov ah, 0\n"
        "int 0x10\n"
    );
    asm volatile("popa\n");
    return;
};
__attribute__ ((cdecl))
static void fPrintChar(){
    asm volatile("pusha\n");
    asm volatile(
        "mov ah, 0x0e\n"
        "int 0x10\n"
    );
    asm volatile("popa\n");
}
__attribute__ ((cdecl))
static void fPrintString(){
    asm volatile("push es\n");
    asm volatile("pusha\n");
    asm volatile(
        "mov ah, 0x13\n"
        "push ds\n"
        "pop es\n"
        "mov al, 0x01\n"
        "mov bh, 0x0\n"
        "int 0x10\n"
    );
    asm volatile("popa\n");
    asm volatile("pop es\n");
}
#endif