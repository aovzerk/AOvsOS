#include "INTERRUPT_90_FUNC.H"
#include "../../../../INCLUDES/TYPES.H"
static void mainInterruptHandler(){
    
    static u_char8 functionNum = 11;
    asm volatile(
        "mov %0, ah"
        :
        : "m"(functionNum)
        :
    );
    if(functionNum == 0){
        fSetVideoMode();
    }
    asm volatile("iret");
}