#ifndef MENUNAVIGATION_H_INCLUDED
#define MENUNAVIGATION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//typedef struct hiddenChar
//{
//    char c;
//    struct hiddenChar * next;
//}HiddenChar;

///I'm missing classes soooo bad...
typedef struct menuNavigatorData
{
    int firstLineIndex;
    int sizeOfNavigationField;
    int currentPosition;
}MenuNavigatorData;

void Navigator_Draw(struct menuNavigatorData * navigator)
{
    XY(0, navigator->firstLineIndex + navigator->currentPosition);
    printf(">>"); ///draws
}

void Navigator_SetValues(struct menuNavigatorData * navigator, int firstLineIndex, int sizeOfNavigationField)
{
    navigator->firstLineIndex = firstLineIndex;
    navigator->sizeOfNavigationField = sizeOfNavigationField;
    navigator->currentPosition = 0;

    Navigator_Draw(navigator);
}

void Navigator_Cycle(struct menuNavigatorData * navigator ,int by)
{
    XY(0, navigator->firstLineIndex + navigator->currentPosition);
    printf("  "); ///erazes

    navigator->currentPosition += by;// (navigator->currentPosition + by) % navigator->sizeOfNavigationField; ///i have tried to be smart but... -2%3==-2

    if(navigator->currentPosition >= navigator->sizeOfNavigationField)
        navigator->currentPosition = 0;
    else if(navigator->currentPosition < 0)
        navigator->currentPosition = navigator->sizeOfNavigationField - 1;

    XY(0, navigator->firstLineIndex + navigator->currentPosition);
    printf(">>"); ///draws
    return;
}

#endif // MENUNAVIGATION_H_INCLUDED
