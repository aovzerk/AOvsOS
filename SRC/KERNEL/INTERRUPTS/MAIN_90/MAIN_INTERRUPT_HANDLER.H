#include "INTERRUPT_90_FUNC.H"
#include "../../../../INCLUDES/TYPES.H"
#ifndef MAIN_INTERRUPT_HANDLER
#define MAIN_INTERRUPT_HANDLER
__attribute__ ((interrupt))
static void mainInterruptHandler(u_char8 *f){
    u_char8 functionNum = 101; // non-existent function
    asm volatile("push ax\n");
    asm volatile(
        "mov %0, ah"
        :"=m"(functionNum)
        : 
        :
    );
    if(functionNum == 0) {// ah 0 setVideo
        asm volatile("pop ax\n");
        fSetVideoMode();
    } else if(functionNum == 1) {// ah = 1 getCursorPos dh,dl cursor pos
        static CURSOR_POS pos = {0, 0};
        pos = fGetCursorPos();
        asm volatile(
            "mov dh, %0\n"
            "mov dl, %1\n"
            : 
            : "m"(pos.y), "m"(pos.x)
            :
        );
        asm volatile("pop ax\n");
    } else if(functionNum == 2) {// ah = 2 setCursorPos dh,dl cursor pos
        asm volatile("pop ax\n");
        fSetCursorPos();
    } else if(functionNum == 3) {// al = char
        asm volatile("pop ax\n");
        fPrintChar();
    } else if(functionNum == 4) {// ebp = string
        asm volatile("pop ax\n");
        fPrintString();
    } else {
        asm volatile("pop ax\n");
    }
}
#endif