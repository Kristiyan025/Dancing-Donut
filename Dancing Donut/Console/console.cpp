#include "console.h"

#define _WIN32_WINNT 0x0500

#include <windows.h>
#include<cmath>

HANDLE Console::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
HWND Console::console = GetConsoleWindow();

int Console::bufferWidth = 80,
    Console::bufferHeight = 36;
int Console::halfWidth = Console::bufferWidth / 2, 
    Console::halfHeight = Console::bufferHeight / 2;
int Console::consoleCharWidth = 8, 
    Console::consoleCharHeight = 16;
int Console::screenX = GetSystemMetrics(SM_CXSCREEN),
    Console::screenY = GetSystemMetrics(SM_CYSCREEN);
int Console::width = (Console::bufferWidth + 5) * Console::consoleCharWidth - 7,
    Console::height = (Console::bufferHeight + 3) * Console::consoleCharHeight - 9;

void Console::hidecursor() 
{ 
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);   
    CONSOLE_CURSOR_INFO info;   
    info.dwSize = 8;   
    info.bVisible = FALSE;   
    SetConsoleCursorInfo(consoleHandle, &info); 
}

void Console::setConsole()
{
    int posX = (screenX - Console::width) / 2,
        posY = (screenY - Console::height) / 2;

    MoveWindow(console, posX, posY, Console::width, Console::height, TRUE);

    Console::hidecursor();

    //Change the internal buffer size: to hide the scrollbar
    _COORD c = { Console::bufferWidth, Console::bufferHeight };
    SetConsoleScreenBufferSize(hConsole, c); 
    
    //Stop user from resizing the console
    SetWindowLong(Console::console, GWL_STYLE, GetWindowLong(Console::console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

void Console::writeAt(short x, short y, std::string line)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(hConsole, pos);
    WriteConsole(hConsole, line.c_str(), line.size(), NULL, NULL);
}