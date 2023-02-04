asm volatile(
    ".code16gcc\n"
    "jmp main\n"
);
#include "../../INCLUDES/VIDEO/VIDEO_SERV.H"
#include "../../INCLUDES/CURSOR/CURSOR_F.H"
#include "INTERRUPTS/MAIN_90/MAIN_INTERRUPT_HANDLER.H"
#include "FUNCTIONS/ETC.H"
static void printChar(u_char8 c){
    asm volatile("pusha\n");
    asm volatile(
        "mov ah, 0x0e\n"
        "mov al, %0\n"
        "int 0x10\n"
    ::"r"(c));
    asm volatile("popa\n");
}

void main(){
    static u_char8 num = 0x90;
    static u_char8 mode = 0x03;
    static u_char8 helloStr[] = "Hello";
    setInterruptHandler(num, mainInterruptHandler);
    setVideoMode(mode);
    CURSOR_POS pos = {0, 0};
    pos.x = 5;
    SetCursorPos(pos);
    pos = GetCursorPos();
    pos.x += (u_char8) 50;
    SetCursorPos(pos);
    for(u_char8 i = 0; i < 5; i++){
        printChar(helloStr[i]);
    }
    asm volatile("jmp $\n");
}