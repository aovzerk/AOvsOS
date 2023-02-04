asm volatile(
    ".code16gcc\n"
    "jmp main\n"
);
#include "../INCLUDES/VIDEO_SERV.H"
#include "INTERRUPTS/MAIN_90/MAIN_INTERRUPT_HANDLER.H"
#include "FUNCTIONS/ETC.H"
static void printChar(u_char8 c){
    asm volatile(
        "mov ah, 0x0e\n"
        "mov al, %0\n"
        "int 0x10\n"
    ::"a"(c));
}

void main(){
    u_char8 num = 0x90;
    u_char8 mode = 0x03;
    u_char8 helloStr[] = "Hello";
    setInterruptHandler(num, mainInterruptHandler);
    setVideoMode(mode);
    for(u_char8 i = 0; i < 5; i++){
        printChar(helloStr[i]);
    }
    asm volatile("jmp $\n");
}