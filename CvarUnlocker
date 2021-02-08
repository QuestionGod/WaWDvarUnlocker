// WaW Dvar Unlocker For Multiplayer mode and Zombies Mode. 
// Made this in what would have been 2 mins but i guess i never took note of the addresses for the two functions... so 5 mins for some random YouTube video showing how to get access to CG_Fov in ZM.
// Why? Because i have always wanted to make a GitHub post, however shitty it may be... but code is 100% mine; all 40 lines of it xd
// 2 seperate DLLs have been compiled and are ready for immediate use, inject with any injector of choice
// Maybe i post more WaWmp cheats here in future, idk. Game lacks any REAL shit other than chams and some shat distance targeting aimbots :P

// Hook Addresses
DWORD dwDvarUnlockerMP = 0x0;
DWORD dwDvarUnlockerZM = 0x0;

// Pointer Addresses
int* iDvarUnlockerMP = (int*)0x0;
int* iDvarUnlockerZM = (int*)0x0;

typedef void (*tCvarUnlocker)();
tCvarUnlocker o_CvarUnlocker;

// Main to be hooked function
void  h_CvarUnlocker()
{
    *iDvarUnlockerZM |= 0;
    *iDvarUnlockerMP |= 0;
}

// Detouring The Function
void DetourFunctions()
{
    DetourFunction((PBYTE)dwDvarUnlockerMP, (PBYTE)&h_CvarUnlocker);
    _asm mov[o_CvarUnlocker], eax;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DetourFunctions();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:

    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

