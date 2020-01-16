#ifndef BASICFUNCTIONS_H_INCLUDED
#define BASICFUNCTIONS_H_INCLUDED

///this stuff should be in .c file but i don't know how all of this works, YET!

#include <windows.h>

///Shamelessly stollen from internet
void SetPosition(int X, int Y)
{
    HANDLE Screen;
    Screen = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position={X, Y};

    SetConsoleCursorPosition(Screen, Position);
}

#endif // BASICFUNCTIONS_H_INCLUDED
