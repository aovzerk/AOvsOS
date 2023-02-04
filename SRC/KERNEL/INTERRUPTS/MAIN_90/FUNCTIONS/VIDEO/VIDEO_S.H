static void fSetVideoMode(){
    asm volatile(
        "mov ah, 0\n"
        "int 0x10\n"
    );
    return;
};