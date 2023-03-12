asm volatile(
    ".code16gcc\n"
    "jmp main\n"
);
#include "../KERNEL/FUNCTIONS/DISK.H"
static void recalibration(){
    asm volatile(
        "cli\n"
        "xor ax,ax\n"
        "mov ds, ax\n"
        "mov es, ax\n"
        "mov ss, ax\n"
        "mov sp, 0x07C00\n"
        "sti\n"
    );
}
static u_char8 disk_num = 0x00;
static DAPS kernel_DAPS = {
    .paksize = 16, // packet size
    .reserved = 0, // reserved
    .numsectors = 10, // number of sectors
    .reserved2 = 0, // reserved
    .offset = 0x0500, // offset
    .segment = 0x0000, // segment
    .first_sector = 3 // first sector
};
void main(void){
    asm volatile(
        "mov %0, dl\n"
        : "=m"(disk_num)
        :
        :
    );
    recalibration();
    
    load_daps(&kernel_DAPS, &disk_num);
    asm volatile("jmp 0x0:0x0500\n");
    asm volatile("jmp $\n");
}