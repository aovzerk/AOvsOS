#include "../TYPES.H"
#include "../STRINGS/STRING_LEN.H"
#include "../CURSOR/CURSOR_F.H"
#ifndef PRINT_S
#define PRINT_S
__attribute__ ((cdecl))
void printChar(u_char8 c){
    asm volatile(
        "pusha\n"
        "mov ah, 0x03\n"
        "mov al, %0\n"
        "int 0x90\n"
        "popa\n"
    ::"r"(c));
}
__attribute__ ((cdecl))
static void printString(u_char8 *s, u_char8 color){
    u_char8 len = stringLen(s);
    static CURSOR_POS pos = {0, 0};
    pos = GetCursorPos();
    asm volatile(
        "pusha\n"
        "mov ah, 0x04\n"
        "mov dh, %1\n"
        "mov dl, %2\n"
        "mov bl, %3\n"
        "mov ebp, %0\n"
        "mov cl, %4\n"
        "int 0x90\n"
        "popa\n"
    ::"D"(s), "r"(pos.y), "r"(pos.x), "b"(color), "c"(len));
}
#endif