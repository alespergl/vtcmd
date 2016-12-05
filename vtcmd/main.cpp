#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

int main()
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    if(output == INVALID_HANDLE_VALUE)
    {
        return GetLastError();
    }

    DWORD mode = 0;
    if(!GetConsoleMode(output, &mode))
    {
        return GetLastError();
    }

    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if(!SetConsoleMode(output, mode))
    {
        return GetLastError();
    }

    TCHAR cmd[] = L"cmd.exe";
    STARTUPINFO si;
    si.cb = sizeof(si);
    PROCESS_INFORMATION pi;
    if(!CreateProcess(nullptr, cmd, nullptr, nullptr, FALSE, 0, nullptr, nullptr, &si, &pi))
    {
        return GetLastError();
    }

    return 0;
}
