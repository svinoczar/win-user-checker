#include <Windows.h>
#include <string>

std::string checkPrivilege(const std::string& username) {
    HANDLE hToken = NULL;
    if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
        TOKEN_PRIVILEGES tp;
        tp.PrivilegeCount = 1;
        tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
        tp.Privileges[0].Luid = 0;
        tp.Privileges[0].pValue = (LPDWORD)username.c_str();
        LookupPrivilegeValue(NULL, "SeSecurityPrivilege", &tp.Privileges[0].pValue);
        SetPrivilege(hToken, &tp);
        CloseHandle(hToken);
        return "Admin";
    } else {
        return "No privilege";
    }
}