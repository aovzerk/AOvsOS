#include "../../../INCLUDES/TYPES.H"
#ifndef DISK
#define DISK
struct DAPS
{
    u_char8 paksize;
    u_char8 reserved;
    u_char8 numsectors;
    u_char8 reserved2;
    u_int16 offset;
    u_int16 segment;
    u_long_int64 first_sector;
};
__attribute__ ((cdecl))
static void load_daps(DAPS* daps, u_char8 *disk){
    asm volatile("pusha");
    asm volatile(
        "push cs\n"
        "pop ds\n"
        "mov dl, %1\n"
        "mov ah, 0x42\n"
        "int 0x13\n"
        :
        : "S"(daps), "r"(*disk)
        :
    );
    asm volatile("popa");
    return;
}
__attribute__ ((cdecl))
static void load_table_files(file *files, u_char8 *disk){
    static DAPS tableFilesDUPS = {
        .paksize = 16, // packet size
        .reserved = 0, // reserved
        .numsectors = 1, // number of sectors
        .reserved2 = 0, // reserved
        .offset = 0x0000, // offset
        .segment = 0x0000, // segment
        .first_sector = 1 // first sector
    };
    tableFilesDUPS.offset = (u_int16)files;
    asm volatile(
        "pusha\n"
        "push ds\n"
        "pop bx\n"
        "mov %0, bx\n"
        "popa\n"
        : "=m"(tableFilesDUPS.segment)
        :
        :
    );
    load_daps(&tableFilesDUPS, disk);
}
#endif
