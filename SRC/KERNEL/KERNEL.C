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
#include "./FUNCTIONS/DISK.H"
static u_char8 boot_disk = 0x00;
static u_char8 helloStr[] = "AOvsOS is loading...\n\r";
void main(){
    asm volatile(
        "mov %0, dl\n"
        :"=m"(boot_disk)
        :
        :
    );
    u_char8 num = 0x90;
    setInterruptHandler(num, mainInterruptHandler);
    u_char8 mode = 0x03;
    setVideoMode(mode);
    
    printString(helloStr, Green);
    static file tablefiles[64];
    load_table_files(tablefiles, &boot_disk);
    printString(tablefiles[0].name, Red);
    asm volatile("jmp $\n");
}