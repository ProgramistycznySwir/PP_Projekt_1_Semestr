#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <windows.h> ///Needed for SetPosition()

int currentMenuID = 0;
char * errorLogFilePath = "eeeeTESTYYYYYY";

///Later we will manage this mess into neat .h and .c but not now

///I'm missing classes soooo bad...
typedef struct menuNavigatorData
{
    char firstLineIndex;
    char sizeOfNavigationField;
    char currentPosition;
} MenuNavigatorData;

///Shamelessly stollen from internet
void SetPosition(int X, int Y)
{
    HANDLE Screen;
    Screen = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position={X, Y};

    SetConsoleCursorPosition(Screen, Position);
}

//void CycleNavigator(* MenuNavigatorData navigator ,char a)
//{
//    return;
//}

///Main Menu logic, this one is displayed on startup and is used to navigate to other menus
void MainMenu()
{
    printf("pre-pre-alpha version 0.0.1\n\n"); ///it's early access soo we are not supposed to polish project, this works this way i guess...
    printf("  1. Rozpocznij dyktando\n");
    printf("  2. Ustawienia\n");
    printf("  3. Wyjdz\n");

    MenuNavigatorData navigator;
    navigator.firstLineIndex = 1;
    navigator.sizeOfNavigationField = 3;
    navigator.currentPosition = 0;

    char input;

    //input = getch();

    //printf("%c", input);

    char hasChosen = 0; ///i hate lack of bools in this language...
    while(hasChosen == 0)
    {
        input = getch(); ///arrow key codes are from {72, , ,} for {up, down, right, left} //Maksim, could you map them?

        //printf("%c", input);
        if(input == -32) continue; ///ah, the finest of troubleshooting, i don't know why but this works :D
        switch(input)
        {
            case 72:
            {
                printf("UP we go! %d\n", input); ///it will navigate someday using UP-DOWN to choose options, RIGHT to accept option, LEFT to navigate one menu out
                break;
            }
            case 51:
            {
                currentMenuID = -1;
                hasChosen = 1;
                break;
            }
            default:
            {
                printf("NOTHING, BOOOORING! %d\n", input);
                break;
            }
        }
    }

    return;
}

///This function picks menus soo the program don't end up in sick recurency where there are multiple layers of menus
void MenuPicker(int menuID)
{
    switch(menuID)
    {
        case 0:
            MainMenu();
            break;
        default:
            printf("--ERROR<MenuPicker>: menuID (%d) out of scope!", menuID);
            break;
    }
}

int main()
{
    //MainMenu();
//    while(currentMenuID >= 0) ///after this while program terminating takes place
//    {
//        MenuPicker(currentMenuID);
//    }

    SetPosition(5, 5);
    printf("Program terminated...");

    return 0;
}
/*
    KeyCodes:
27 - esc
72 - UP
-32 - [i don't fricking know, ok?]
48-57 - numbers from 0 to 9
*/
