#include "INTERRUPT_90_FUNC.H"
#include "../../../../INCLUDES/TYPES.H"
static u_char8 functionNum = 11;
static CURSOR_POS pos = {0, 0};

static void mainInterruptHandler(){
    
    asm volatile("push ax\n");
    asm volatile(
        "mov %0, ah"
        :
        : "m"(functionNum)
        :
    );
    if(functionNum == 0) {// ah 0 setVideo
        asm volatile("pop ax\n");
        fSetVideoMode();
    } else if(functionNum == 1) {// ah = 1 getCursorPos dh,dl cursor pos
        asm volatile("pop ax\n");
        pos = fGetCursorPos();
        asm volatile(
            "mov dh, %0\n"
            "mov dl, %1\n"
            :
            : "m"(pos.y), "m"(pos.x)
            :
        );
    } else if(functionNum == 2) {// ah = 2 setCursorPos dh,dl cursor pos
        asm volatile("pop ax\n");
        fSetCursorPos();
    } else {
        asm volatile("pop ax\n");
    }
    asm volatile("add esp, 0x10\n");
    asm volatile("iret");
}