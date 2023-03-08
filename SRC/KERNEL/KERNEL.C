asm volatile(
    ".code16gcc\n"
    "jmp main\n"
);
#include "../../INCLUDES/VIDEO/VIDEO_F.H"
#include "../../INCLUDES/VIDEO/PRINT_F.H"
#include "../../INCLUDES/KEYBOARD/KEYBOARD_F.H"
#include "../../INCLUDES/CURSOR/CURSOR_F.H"
#include "../../INCLUDES/STRINGS/STRING_LEN.H"
#include "../../INCLUDES/STRINGS/STRING_CMP.H"
#include "INTERRUPTS/MAIN_90/MAIN_INTERRUPT_HANDLER.H"
#include "FUNCTIONS/ETC.H"

void main(){
    u_char8 num = 0x90;
    u_char8 mode = 0x03;
    static u_char8 helloStr[] = "Hello World! =)";
    static CURSOR_POS pos = {0, 0};
    setInterruptHandler(num, mainInterruptHandler);
    setVideoMode(mode);
    printChar(1 + 0x30);
    for(u_char8 i = 0; i < 1; i++){
        printString(helloStr, Green);
    }
    pos.y = 1;
    SetCursorPos(pos);
    static u_char8 myString[10];
    for(u_char8 i = 0; i < 10; i ++){
        myString[i] = getKey();
        printChar(myString[i]);
    }
    myString[10] = 0;
    pos.y = 2;
    SetCursorPos(pos);
    printString(myString, Red);
    asm volatile("jmp $\n");
}