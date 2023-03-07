#include "../TYPES.H"
#ifndef PRINT_S
#define PRINT_S
static void printChar(u_char8 c){
    asm volatile("pusha\n");
    asm volatile(
        "mov ah, 0x0e\n"
        "mov al, %0\n"
        "int 0x10\n"
    ::"r"(c));
    asm volatile("popa\n");
}
#endif