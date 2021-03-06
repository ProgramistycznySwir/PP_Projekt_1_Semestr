#include <stdio.h>
#include <stdlib.h>

//#include "BasicFunctions.h"
#include "MenuNavigation.h"
#include "HiddenChars.h"

///Every menu returns flag 0 - if just ended it's execution, 1 - if inside of it was requested to quit program
///It is meant to leave program by using

///Handles exiting program;
///Don't need Draw_ "method"
char ExitProgramMenu()
{
    system("cls");

    printf("Czy jestes pewien ze chcesz wyjsc?\n");
    printf("Nacisnij Y jesli tak, albo dowolny inny znak jesli nie\n");

    char input = getch();

    if(input == 'y')
        return 1; ///Program exit flag
    else
        return 0;
}


char DyktandoSolvingLogic(FILE* file)
{
    ///najpierw s�u�y przygotowaniom, a p�niej inputowi
    char input = getc(file);

    struct CharPT* whitespaces = CharPTList_Initialize();

    ///Przygotowuje dyktando
    while(input != EOF) ///je�li znak jest 1 a s� 2 miejsca to si� wprowadza tylko w pierwsze miejsce, a drugie zostawia si� puste przyciskaj�c SPACE
    {
        if(input == '_')
        {
            putc("_", stdout);
            if(input == '_')
            {
                putc("_", stdout);
                CharPTList_Append(whitespaces, input, GetConsoleCPX(), GetConsoleCPY());
                CharPTList_Append(whitespaces, ' ', GetConsoleCPX(), GetConsoleCPY());

//                if(input == '_')
//                {
//                    putc("_", stdout);
//                    CharPTList_Append(whitespaces, )
//                }
            }
            else
                CharPTList_Append(whitespaces, input, GetConsoleCPX(), GetConsoleCPY());
        }
    }




    char breakOffFlag = 0; ///i hate lack of bools in this language...
    char overrideInputFlag = 0; ///B letter at end will indicate that it acts as bool
    char reDrawFlag = 1; ///1 for drawing this menu 1st time
    char exitProgramFlag = 0;
    while(breakOffFlag == 0 && exitProgramFlag == 0)
    {
        if(reDrawFlag == 1)
        {
            system("cls");
            DisplayFile(file);
            reDrawFlag = 0;
        }

        if(overrideInputFlag == 1)
            overrideInputFlag = 0;
        else
            input = getch(); ///arrow key codes are from {72, 80, 77, 75} for {up, down, right, left}

        if(input == -32) continue; ///ah, the finest of troubleshooting, i don't know why but this works :D
        switch(input)
        {
            case 72: ///UP - Cycles cursor up
            {
                break;
            }
            case 80: ///DOWN - Cycles cursor down
            {
                break;
            }
            case 77: ///Right - Accesses menu
            {

                break;
            }
            case 75: ///LEFT - Exits menu
            case 49: ///1
            {
                breakOffFlag = 1;
                break;
            }
            case 27: ///ESC
            {
                ///INSERT HERE LOGIC OF CLOSING PROGRAM
                exitProgramFlag = ExitProgramMenu();
                reDrawFlag = 1; ///put this after every menu access
                input = ' ';
                break;
            }
            default:
            {
                break;
            }
        }
    }

    ///After while structure should be placed "destructors" if needed

    return exitProgramFlag; ///delete this later, this is only needed to not forget about this feature


}

///Specyfikowanie literek do szybkiego tworzenia dyktand FUNCTIONALITY ABANDONED


void Draw_SolvingMenu()
{
    printf("Wybierz dyktando do rozwi�zania:\n\n");

    printf("  1.Wroc do poprzedniego menu\n");
    DisplayDirectoryFiles("Dyktanda");
}

char SolvingMenu() ///mode{0 - solving(read), 1 - editting} FUNCIONALITY ABANDONED
{
    MenuNavigatorData navigator;
    Navigator_SetValues(&navigator, 2, DisplayDirectoryFiles("Dyktanda")-1); ///displays directory files and return it's number in it

    char input;

    char breakOffFlag = 0; ///i hate lack of bools in this language...
    char overrideInputFlag = 0; ///B letter at end will indicate that it acts as bool
    char reDrawFlag = 1; ///1 for drawing this menu 1st time
    char exitProgramFlag = 0;
    while(breakOffFlag == 0 && exitProgramFlag == 0)
    {
        if(reDrawFlag == 1)
        {
            system("cls");
            Draw_SolvingMenu();
            Navigator_Draw(&navigator);
            reDrawFlag = 0;
        }

        if(overrideInputFlag == 1)
            overrideInputFlag = 0;
        else
            input = getch(); ///arrow key codes are from {72, 80, 77, 75} for {up, down, right, left}

        if(input == -32) continue; ///ah, the finest of troubleshooting, i don't know why but this works :D
        switch(input)
        {
            case 72: ///UP - Cycles cursor up
            {
                Navigator_Cycle(&navigator, -1);
                break;
            }
            case 80: ///DOWN - Cycles cursor down
            {
                Navigator_Cycle(&navigator, 1);
                break;
            }
            case 77: ///Right - Accesses menu
            {
                if(navigator.currentPosition > 0)///nie jest to 1 co by oznacza�o wyj�cie do poprzedniego menu
                {
                    ///Logika rozwi�zywania dyktand
                    DyktandoSolvingLogic(GetDirectoryFileByIndex("Dyktanda", navigator.currentPosition+1));
                }
                else
                {
                    overrideInputFlag = 1;
                    input = 49 + navigator.currentPosition;
                }
                break;
            }
            case 75: ///LEFT - Exits menu
            case 49: ///1
            {
                breakOffFlag = 1;
                break;
            }
            case 27: ///ESC
            {
                ///INSERT HERE LOGIC OF CLOSING PROGRAM
                exitProgramFlag = ExitProgramMenu();
                reDrawFlag = 1; ///put this after every menu access
                input = ' ';
                break;
            }
            default:
            {
                break;
            }
        }
    }

    ///After while structure should be placed "destructors" if needed

    return exitProgramFlag; ///delete this later, this is only needed to not forget about this feature
}



void Draw_SettingsMenu()
{
    printf("Ustawienia: <Work in Progress>\n\n");
    printf("  1. Wroc do Menu Glownego");
}
///Settings logic
char SettingsMenu()
{
    MenuNavigatorData navigator;
    Navigator_SetValues(&navigator, 2, 1);

    char input;

    char breakOffFlag = 0; ///i hate lack of bools in this language...
    char overrideInputFlag = 0; ///B letter at end will indicate that it acts as bool eventually
    char reDrawFlag = 1; ///1 for drawing this menu 1st time
    char exitProgramFlag = 0;
    while(breakOffFlag == 0 && exitProgramFlag == 0)
    {
        if(reDrawFlag == 1)
        {
            system("cls");
            Draw_SettingsMenu();
            Navigator_Draw(&navigator);
            reDrawFlag = 0;
        }

        if(overrideInputFlag == 1)
            overrideInputFlag = 0;
        else
            input = getch(); ///arrow key codes are from {72, 80, 77, 75} for {up, down, right, left}

        if(input == -32) continue; ///ah, the finest of troubleshooting, i don't know why but this works :D
        switch(input)
        {
//            case 49: ///1
//            {
//                XY(0, 10);
//                printf("BEEP BOOP ACCESSING MENU #1");
//                break;
//            }
            case 72: ///UP - Cycles cursor up
            {
                Navigator_Cycle(&navigator, -1);
                break;
            }
            case 80: ///DOWN - Cycles cursor down
            {
                Navigator_Cycle(&navigator, 1);
                break;
            }
            case 77: ///Right - Accesses menu
            {
                overrideInputFlag = 1;
                input = 49 + navigator.currentPosition;
                break;
            }
            case 75: ///LEFT - Exits menu
            case 49: ///1
            {
                breakOffFlag = 1;
                break;
            }
            case 27: ///ESC
            {
                ///INSERT HERE LOGIC OF CLOSING PROGRAM
                exitProgramFlag = ExitProgramMenu();
                reDrawFlag = 1; ///put this after every menu access
                input = ' ';
                //breakOffFlag = 1;
                break;
            }
            default:
            {
                break;
            }
        }
    }

    ///After while structure should be placed "destructors" if needed

    return exitProgramFlag; ///delete this later, this is only needed to not forget about this feature
}


void Draw_MainMenu()
{
    printf("Menu Glowne:\n\n"); ///it's early access soo we are not supposed to polish project, this works this way i guess...
    printf("  1. Wybor Dyktand\n");
    printf("  2. Wprowadz nowe dyktando\n");
    printf("  3. Ustawienia\n");
    printf("  4. Wyjdz z programu\n");
}
///Main Menu logic, this one is displayed on startup and is used to navigate to other menus
char MainMenu()
{
    ///Displayed only once at startup
    printf("\n\n[Jesli jeszcze tego nie zrobiles, dostosuj rozmiar i typ czcionki konsoli dla lepszego uzytkowania programu!]");

    MenuNavigatorData navigator;
    Navigator_SetValues(&navigator, 2, 4);

    char input;

    char breakOffFlag = 0; ///i hate lack of bools in this language...
    char overrideInputFlag = 0; ///B letter at end will indicate that it acts as bool
    char reDrawFlag = 1; ///1 for drawing this menu 1st time
    char exitProgramFlag = 0;
    while(breakOffFlag == 0 && exitProgramFlag == 0)
    {
        if(reDrawFlag == 1)
        {
            system("cls");
            Draw_MainMenu();
            Navigator_Draw(&navigator);
            reDrawFlag = 0;
        }

        if(overrideInputFlag == 1)
            overrideInputFlag = 0;
        else
            input = getch(); ///arrow key codes are from {72, 80, 77, 75} for {up, down, right, left}

        if(input == -32) continue; ///ah, the finest of troubleshooting, i don't know why but this works :D
        switch(input)
        {
            case 49: ///1
            {
                exitProgramFlag = SolvingMenu();
                reDrawFlag = 1;
                break;
            }
            case 50: ///2
            {
                XY(0, 10);
                printf("BEEP BOOP ACCESSING MENU #2");
                break;
            }
            case 51: ///3
            {
                exitProgramFlag = SettingsMenu();
                reDrawFlag = 1;
                break;
            }
            case 72: ///UP - Cycles cursor up
            {
                Navigator_Cycle(&navigator, -1);
                break;
            }
            case 80: ///DOWN - Cycles cursor down
            {
                Navigator_Cycle(&navigator, 1);
                break;
            }
            case 77: ///Right - Accesses menu
            {
                overrideInputFlag = 1;
                input = 49 + navigator.currentPosition;
                break;
            }
            case 75: ///LEFT - Exits menu (in other menus LEFT only exits this menu, so it only set's breakOFF flag)
            case 52: ///4
            case 27: ///ESC
            {
                ///INSERT HERE LOGIC OF CLOSING PROGRAM
                exitProgramFlag = ExitProgramMenu();
                reDrawFlag = 1; ///put this after every menu access
                input = ' ';
                break;
            }
            default:
            {
                break;
            }
        }
    }

    ///After while structure should be placed "destructors" if needed

    return exitProgramFlag; ///delete this later, this is only needed to not forget about this feature
}

//#include "console.ddt"
//#include <iostream>
#include <conio.h>
void MenuTest()
{
    //DisplayDirectoryFiles("C:\\PP_Proyekt\\PP_Projekt_1_Semestr\\PP_2019_Ortografia");
//    DisplayDirectoryFiles("Dyktanda");
//    printf("\n\n");
//    DisplayFileByPath("Dyktanda\\Pangramy.txt");
//    printf("\n\n");
//    DisplayFile(GetDirectoryFileByIndex("Dyktanda", 4));

    int x = wherex();

    int a = 0;
    while(1==1)
    {
        int i;
//        for(i = 0; i < a; i++)
//            printf(" ");
        int x = GetConsoleCPX();
        int y = GetConsoleCPY();
        printf("<%d;%d>\n", x, y);
        getch();
        a++;
    }

    XY(40, 5);
    printf("<%d;%d>", GetConsoleCPX(), GetConsoleCPY());
    getch();

//    struct hiddenChar * list = HiddenCharList_Initialize();
//
//    char input;
//    while(0==0)
//    {
//        input = getch();
//        HiddenCharList_XOR(list, input);
//        //printf("\n(%c)\n", list->next->c);
//        //system("cls");
//        printf("%c\nElementy Listy: ", input);
//        HiddenCharList_Display(list);
//    }


//    HiddenCharList_Append(list, 'a');
//    HiddenCharList_Append(list, 'b');
//    //printf("\n%c\n", list->c);
//    HiddenCharList_Display(list);
//
//    HiddenCharList_Append(list, 'c');
//    HiddenCharList_Display(list);

//    printf("\n\n%d", list->c);
}
