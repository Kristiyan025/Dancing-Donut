#pragma once

#include <windows.h>
#include <string>

static class Console
{
private:
    static HANDLE hConsole;
    static HWND console;

public:
    static int screenX, screenY;
    static int width, height;
    static int consoleCharWidth, consoleCharHeight;
    static int bufferWidth, bufferHeight;
    static int halfWidth, halfHeight;
    static void hidecursor();
    static void setConsole();
    static void writeAt(short x, short y, std::string line);
};
