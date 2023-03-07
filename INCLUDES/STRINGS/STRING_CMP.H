#include "../TYPES.H"
#include "./STRING_LEN.H"
#ifndef STRING_CMP
#define STRING_CMP
__attribute__ ((cdecl))
u_char8 stringCmp(u_char8 *s1, u_char8 *s2){// 0 = eq, 1 = !eq
    u_char8 len_s1 = stringLen(s1);
    u_char8 len_s2 = stringLen(s2);
    if(len_s1 != len_s2){
        return 1;
    }
    for(u_char8 i = 0; i < len_s1; i++){
        if(s1[i] != s2[i]) return 1;
    }
    return 0;
}
#endif