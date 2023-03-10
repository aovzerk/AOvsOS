#include "INTERRUPT_90_FUNC.H"
#include "../../../../INCLUDES/TYPES.H"
#ifndef MAIN_INTERRUPT_HANDLER
#define MAIN_INTERRUPT_HANDLER
__attribute__ ((interrupt))
static void mainInterruptHandler(interrupt_frame *frame){
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
    }
    if(functionNum == 1) {// ah = 1 getCursorPos dh,dl cursor pos
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
    } 
    if(functionNum == 2) {// ah = 2 setCursorPos dh,dl cursor pos
        asm volatile("pop ax\n");
        fSetCursorPos();
    } 
    if(functionNum == 3) {// al = char
        asm volatile("pop ax\n");
        fPrintChar();
    } 
    if(functionNum == 4) {// dx cursor, bl, color, ebp - string, cl - len
        asm volatile("pop ax\n");
        fPrintString();
    } 
    if(functionNum == 5) {// out dl - ascii code
        asm volatile("pop ax\n");
        static u_char8 key = 0;
        key = fGetKey();
        asm volatile(
            "mov dl, %0\n"
            : 
            : "m"(key)
            :
        );
    } else {
        // asm volatile("pop ax\n");
    }
}
#endif