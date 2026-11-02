#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
int main()
{
    char win_string[100];
    char cmd[300];
    scanf("%s",&win_string);
    HWND web_win = FindWindow(NULL,win_string);
    
    DWORD process_id = 0;
    GetWindowThreadProcessId(web_win, &process_id);
    
    HANDLE win_web = OpenProcess(SYNCHRONIZE, TRUE, process_id);

    if(win_web != NULL)
    {
        WaitForSingleObject(win_web, INFINITE);
        CloseHandle(win_web);
        Sleep(500);
        strcpy(cmd, "for /d %i in (\"%APPDATA%\\Mozilla\\Firefox\\Profiles\\*\") do del /f /q \"%i\\cookies.sqlite\"");
        system(cmd);

    }
    else{
        return 1;
    }
return 0;
}