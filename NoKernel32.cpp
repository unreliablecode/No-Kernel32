#include <windows.h>
#include <detours.h>
#include <string>

// Original function pointers
static HMODULE (WINAPI *trueGetModuleHandleA)(LPCSTR lpModuleName) = GetModuleHandleA;
static HMODULE (WINAPI *trueLoadLibraryA)(LPCSTR lpLibFileName) = LoadLibraryA;

// Hooked functions
HMODULE WINAPI hookedGetModuleHandleA(LPCSTR lpModuleName) {
    if (lpModuleName != NULL && strstr(lpModuleName, "RAT") != NULL) {
        return NULL;
    }
    return trueGetModuleHandleA(lpModuleName);
}

HMODULE WINAPI hookedLoadLibraryA(LPCSTR lpLibFileName) {
    if (lpLibFileName != NULL && strstr(lpLibFileName, "RAT") != NULL) {
        return NULL;
    }
    return trueLoadLibraryA(lpLibFileName);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        DetourRestoreAfterWith();
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourAttach(&(PVOID&)trueGetModuleHandleA, hookedGetModuleHandleA);
        DetourAttach(&(PVOID&)trueLoadLibraryA, hookedLoadLibraryA);
        DetourTransactionCommit();
        break;
    case DLL_PROCESS_DETACH:
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourDetach(&(PVOID&)trueGetModuleHandleA, hookedGetModuleHandleA);
        DetourDetach(&(PVOID&)trueLoadLibraryA, hookedLoadLibraryA);
        DetourTransactionCommit();
        break;
    }
    return TRUE;
}
