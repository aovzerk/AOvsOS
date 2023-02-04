#include "../../INCLUDES/TYPES.H"
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
static void load_daps(DAPS* daps){
    asm volatile("pusha");
    asm volatile(
        "push cs\n"
        "pop ds\n"
        "mov ah, 0x42\n"
        "int 0x13\n"
        :
        : "S"(daps)
        :
    );
    asm volatile("popa");
    return;
}
