#include <windows.h>
#include <tchar.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    // Set up the STARTUPINFO structure
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    // Create the child process
    if (CreateProcess(
        _T("C:\\Windows\\System32\\calc.exe"),   // Path to the executable
        NULL,                                   // Command line (optional)
        NULL,                                   // Process security attributes
        NULL,                                   // Thread security attributes
        FALSE,                                  // Inherit handles from the parent process
        0,                                      // Creation flags
        NULL,                                   // Environment block (optional)
        NULL,                                   // Current directory (optional)
        &si,                                    // STARTUPINFO structure
        &pi                                     // PROCESS_INFORMATION structure
    )) {
        // Wait for the child process to complete
        WaitForSingleObject(pi.hProcess, INFINITE);

        // Close process and thread handles
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

        return 0;
    } else {
        // Print an error message if the process creation fails
        _tprintf(_T("CreateProcess failed (%d)\n"), GetLastError());
        return 1;
    }
}
