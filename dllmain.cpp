// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
DWORD dwDvarUnlockerMP = 0xF3F3F80;
DWORD dwDvarUnlockerZM = 0x21B1358;
int* iDvarUnlockerMP = (int*)0xF3F3F80;
int* iDvarUnlockerZM = (int*)0x21B1358;

typedef void (*tCvarUnlocker)();
tCvarUnlocker o_CvarUnlocker;

void  h_CvarUnlocker()
{
    *iDvarUnlockerMP |= 1;
}

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
        DetourFunctions();

    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

