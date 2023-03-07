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
    static u_char8 num = 0x90;
    static u_char8 mode = 0x03;
    static u_char8 helloStr[] = "123456789";
    static u_char8 helloStr2[] = "123456789";
    setInterruptHandler(num, mainInterruptHandler);
    setVideoMode(mode);
    CURSOR_POS pos = {0, 0};
    pos.x = 5;
    SetCursorPos(pos);
    pos = GetCursorPos();
    pos.x += (u_char8) 50;
    SetCursorPos(pos);
    u_char8 len = stringLen(helloStr);
    for(u_char8 i = 0; i < len; i++){
        printChar(helloStr[i]);
    }
    printChar((u_char8)0x00);
    printChar(len + 0x30);
    u_char8 eqStrings = stringCmp(helloStr, helloStr2);
    printChar((u_char8)0x00);
    printChar(eqStrings + 0x30);
    asm volatile("jmp $\n");
}