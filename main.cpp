#include <Windows.h>

DWORD ret_address = 0xCCAF90;

DWORD* player_base;
DWORD* game_base;
DWORD* gold;

__declspec(naked) void codecave() {
    __asm {
        pushad
    }

    player_base = (DWORD*)0x017EED18;
    game_base = (DWORD*)(*player_base + 0xA90);
    gold = (DWORD*)(*game_base + 4);
    *gold = 888;

    __asm {
        popad
        mov eax, dword ptr ds : [ecx]
        lea esi, dword ptr ds : [esi]
        jmp ret_address
    }
}