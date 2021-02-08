
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

