#include <Windows.h>

DWORD ret_address = 0xCCAF90;

DWORD* player_base;
DWORD* game_base;
DWORD* gold;

__declspec(naked) void codecave() {

    
    __asm {
        // this command is for making sure we save the registery value so we dont crash the game when jumping back to orignal part of the stack
        pushad
    }

    player_base = (DWORD*)0x017EED18;
    game_base = (DWORD*)(*player_base + 0xA90);
    gold = (DWORD*)(*game_base + 4);
    *gold = 888;

    __asm {
        // popad is the is restoring the registy from pushad
        popad

        // these commands were the snippid we had to remove to get enough space for the jmp command we replaced it with
        mov eax, dword ptr ds : [ecx]
        lea esi, dword ptr ds : [esi]
        jmp ret_address
    }
}