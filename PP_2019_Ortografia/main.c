//#include <sys/ioctl.h>
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>

//#include <conio.h>
//#include "BasicFunctions.h"
//#include "MenuNavigation.h"

#include "Menus.h"

//char * errorLogFilePath = "eeeeTESTYYYYYY";

//typedef struct hiddenChar
//{
//    char c;
//    struct hiddenChar * next;
//}HiddenChar;

int main()
{
    //MainMenu();

    MenuTest();



//    XY(0,10);
//    printf("Program ended exucution without problems...\n\n");

    ///w ostatecznej wersji usun¹æ te 2 linijki, s³u¿¹ one jedynie po to by po w³¹czeniu .exe konsola od razu siê nie zamyka³a
    printf("\n\n\n^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^\nProgram zakonczony poprawnie.\nNacisnij dodolny przycisk by zakonczyc jego dzialanie.");
    getch();
    return 0;
}
/*
    KeyCodes:
27 - esc
72 - UP
-32 - [i don't fricking know, ok?]
48-57 - numbers from 0 to 9
*/


//    FILE * file = fopen("file.txt","r");
//
////    char * string;
////    fscanf(file, "%s", string);
////    printf("%s\n", string);
////
////    fscanf(file, "%s", string);
////    printf("%s\n", string);
////
////    fscanf(file, "%s", string);
////    printf("%s\n", string);
//
////    int i = 0;
//    char c;
//
//    c = getc(file);
//    while(c != EOF)// && c != '\n')
//    {
//        putc(c, stdout);
//        c = getc(file);
//    }
//
//    fclose(file);

    //DisplayFile("file.txt");

//    char stopeer;
//    printf("\n\n\n Powinno byæ cacy");
//    scanf("%d", &stopeer);
