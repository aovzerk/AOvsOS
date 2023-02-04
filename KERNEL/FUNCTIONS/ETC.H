#include "../../INCLUDES/TYPES.H"
static void setInterruptHandler(u_char8 num, void (*handler)(void)){
    asm volatile("pusha");
    asm volatile(
        "xor ax,ax\n"
        "push ax\n"
        "pop es\n"
        "mov al, %0\n"
        "mov bl, 4\n"
        "mul bl\n"
        "mov bx, ax\n"
        "mov es:[bx], si\n"
        "add bx, 2\n"
        "push cs\n"
        "pop ax\n"
        "mov es:[bx], ax\n"
        :
        : "m"(num), "S"(handler)
        :
    );
    asm volatile("popa");
    return;
};