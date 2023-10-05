#include <Windows.h>

DWORD ret_address = 0xCCAF90;

__declspec(naked) void codecave() {
    __asm {
        pushad
    }

    // code to modify gold

    __asm {
        popad
        mov eax, dword ptr ds : [ecx]
        lea esi, dword ptr ds : [esi]
        jmp ret_address
    }
}