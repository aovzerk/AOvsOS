asm volatile(
    ".code16gcc\n"
    "jmp main\n"
);
#include "../../INCLUDES/VIDEO/VIDEO_SERV.H"
#include "../../INCLUDES/VIDEO/PRINT_S.H"
#include "../../INCLUDES/CURSOR/CURSOR_F.H"
#include "../../INCLUDES/STRINGS/STRING_LEN.H"
#include "../../INCLUDES/STRINGS/STRING_CMP.H"
#include "INTERRUPTS/MAIN_90/MAIN_INTERRUPT_HANDLER.H"
#include "FUNCTIONS/ETC.H"

void main(){
    u_char8 num = 0x90;
    u_char8 mode = 0x03;
    static u_char8 helloStr[] = "Hello World! =)";
    static CURSOR_POS pos = {10, 0};
    setInterruptHandler(num, mainInterruptHandler);
    setVideoMode(mode);
    for(u_char8 i = 0; i < 100; i++){
        printString(helloStr, Green);
    }
    asm volatile("jmp $\n");
}