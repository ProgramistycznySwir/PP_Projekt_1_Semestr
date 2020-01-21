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

void Draw_Dyktando()
{
    //printf();
}


void Draw_DyktandoMenu(struct Char * hiddenCharsList)
{
    printf("Dostowowane Dyktanda:\n");
    printf("To menu umozliwia definiowanie wlasnych liter ktore pozniej maja byc uzupelnione w odroznieniu od Gotowych Dyktand\n\n"); ///it's early access soo we are not supposed to polish project, this works this way i guess...
    printf("  1. Uzupelnij\n");
    printf("  2. Wybierz dyktando\n");
    printf("  3. Wroc do Menu Glownego\n");
    printf(" Ukryj: ");
    CharList_Display(hiddenCharsList);

    printf("\n\n [Ukryte Znaki wprowadzasz przyciskajac klawisze je reprezentujace, a powinny sie wyswietlic u gory]");
    printf("\n\n [Niepoprawne znaki sa pokazwyane jako puste miejsca, oraz dziwne znaki\n");
    printf(" Dla prawidlowego dzialania programu zaleca sie usuwac je (w taki sam sposob jak je wprowadzono)]");
//    printf("  1. c i ch\n");
//    printf("  2. rz i z(z kropka)\n");
//    printf("  3. o(kreskowane) i u\n");
//    printf("  4. Interpunkcja\n");
//    printf("  5. Wlasne\n");
//    printf("  6. Wroc do Menu Glownego\n");
}
///Logika wyboru i kofigurowania dyktand
char DyktandoMenu()
{
    struct Char* hiddenCharsList = CharList_Initialize();

    MenuNavigatorData navigator;
    Navigator_SetValues(&navigator, 3, 3);

    ///Clearing last menu and drawing this one
    system("cls");
    Draw_DyktandoMenu(hiddenCharsList);


    char input;

    char breakOffFlag = 0; ///i hate lack of bools in this language...
    char overrideInputFlag = 0; ///B letter at end will indicate that it acts as bool
    char reDrawFlag = 0;
    char exitProgramFlag = 0;
    while(breakOffFlag == 0 && exitProgramFlag == 0)
    {
        ///Te menu musi siê zawsze przeryssowywaæ by odpowiednio wyœwietlaæ Ukryte Znaki
        system("cls");
        Draw_DyktandoMenu(hiddenCharsList);
        Navigator_Draw(&navigator);

        if(overrideInputFlag == 1)
            overrideInputFlag = 0;
        else
            input = getch(); ///arrow key codes are from {72, 80, 77, 75} for {up, down, right, left}

        if(input == -32) continue; ///ah, the finest of troubleshooting, i don't know why but this works :D
        switch(input)
        {
            case 49: ///1
            {
                XY(0, 10);
                printf("BEEP BOOP ACCESSING MENU #1");
                break;
            }
            case 50: ///2
            {
                XY(0, 10);
                printf("BEEP BOOP ACCESSING MENU #2");
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
            case 51: ///4
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
                CharList_XOR(hiddenCharsList, input);
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
    ///Clearing last menu and drawing this one
    system("cls");
    Draw_SettingsMenu();

    MenuNavigatorData navigator;
    Navigator_SetValues(&navigator, 2, 1);

    char input;

    char breakOffFlag = 0; ///i hate lack of bools in this language...
    char overrideInputFlag = 0; ///B letter at end will indicate that it acts as bool eventually
    char reDrawFlag = 0;
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
            case 49:
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
    printf("  1. Gotowe Dyktanda\n");
    printf("  2. Dyktando z wlasnymi zasadami\n");
    printf("  3. Wprowadz nowe dyktando\n");
    printf("  4. Ustawienia\n");
    printf("  5. Wyjdz z programu\n");
}
///Main Menu logic, this one is displayed on startup and is used to navigate to other menus
char MainMenu()
{
    ///Clearing last menu and drawing this one
    system("cls");
    Draw_MainMenu();

    ///Displayed only once at startup
    printf("\n\n[Jesli jeszcze tego nie zrobiles, dostosuj rozmiar i typ czcionki konsoli dla lepszego uzytkowania programu!]");

    MenuNavigatorData navigator;
    Navigator_SetValues(&navigator, 2, 5);

    char input;

    char breakOffFlag = 0; ///i hate lack of bools in this language...
    char overrideInputFlag = 0; ///B letter at end will indicate that it acts as bool
    char reDrawFlag = 0;
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
                XY(0, 10);
                printf("BEEP BOOP ACCESSING MENU #1");
                break;
            }
            case 50: ///2
            {
                exitProgramFlag = DyktandoMenu();
                reDrawFlag = 1;
                break;
            }
            case 51: ///3
            {
                XY(0, 10);
                printf("BEEP BOOP ACCESSING MENU #3");
                break;
            }
            case 52: ///4
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
            case 53: ///5
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


void MenuTest()
{
    //DisplayDirectoryFiles("C:\\PP_Proyekt\\PP_Projekt_1_Semestr\\PP_2019_Ortografia");
    DisplayDirectoryFiles("Dyktanda");
    printf("\n\n");
    DisplayFileByPath("Dyktanda\\Pangramy.txt");
    printf("\n\n");
    DisplayFile(GetDirectoryFileByIndex("Dyktanda", 2));

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
