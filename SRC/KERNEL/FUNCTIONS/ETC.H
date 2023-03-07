#include "../../../INCLUDES/TYPES.H"
#ifndef ETC
#define ETC
__attribute__ ((cdecl))
static void setInterruptHandler(u_char8 num, void (*handler)(u_char8 *f)){
    asm volatile("pusha");
    asm volatile(
        "push 0000\n"
        "pop es\n"
        "mov al, %0\n"
        "mov bl, 4\n"
        "mul bl\n"
        "mov bx, ax\n"
        "mov esi, %1\n"
        "mov es:[bx], si\n"
        "add bx, 2\n"
        "push cs\n"
        "pop ax\n"
        "mov es:[bx], ax\n"
        :
        : "r"(num), "r"(handler)
        :
    );
    asm volatile("popa");
    return;
};
#endif