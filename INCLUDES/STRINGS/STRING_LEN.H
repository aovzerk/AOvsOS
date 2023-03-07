#include "../TYPES.H"
#ifndef STRING_LEN
#define STRING_LEN
static u_char8 stringLen(u_char8 *s){
    for(u_char8 i = 0; i < 255; i++){
        if(*s == 0){
            return i;
        }
        s++;
    }
    return 0;
}
#endif