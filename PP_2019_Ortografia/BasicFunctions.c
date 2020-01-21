#include <stdio.h>
#include <windows.h>

///Shamelessly stollen from internet
void XY(int X, int Y)
{
    HANDLE Screen;
    Screen = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position={X, Y};

    SetConsoleCursorPosition(Screen, Position);
}

void DisplayFileByPath(char * path) ///NOT USED
{
    FILE * file = fopen(path,"r");

    char string[0];
    fscanf(file, "%s", string);

    int i = 0;
    while(string[i] != EOF && string[i] != '\n')
    {
        putc(string[i], stdout);
        i++;
    }

    //printf("%s", string);


    fclose(file);

    return;
}

void DisplayFile(FILE * file) ///NOT USED
{
    char string[0];
    fscanf(file, "%s", string);

    int i = 0;
    while(string[i] != EOF && string[i] != '\n')
    {
        putc(string[i], stdout);
        i++;
    }
    return;
}

short GetConsoleSize(char dimmension) ///NOT USED
{
    HANDLE console;
	CONSOLE_SCREEN_BUFFER_INFO info;
	short rows;
	short columns;
	/* Create a handle to the console screen. */
	console = CreateFileW(L"CONOUT$", GENERIC_READ | GENERIC_WRITE,
	    FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING,
	    0, NULL);
	if (console == INVALID_HANDLE_VALUE)
		return 1;

	/* Calculate the size of the console window. */
	if (GetConsoleScreenBufferInfo(console, &info) == 0)
		return 1;
	CloseHandle(console);
	columns = info.srWindow.Right - info.srWindow.Left + 1;
	rows = info.srWindow.Bottom - info.srWindow.Top + 1;

	//wprintf(L"%d columns by %d rows\n", columns, rows);

	if(dimmension == 0)
        return columns;
    else if(dimmension == 1)
        return rows;
    else
        return -1;
}


#include <dirent.h>

///tak¿e zwraca iloœæ plików w folderze
int DisplayDirectoryFiles(char * directoryPath)
{
    DIR *dir;
    struct dirent *ent;
    int count = 0;
    if ((dir = opendir (directoryPath)) != NULL)
    {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL)
        {
            printf ("%s\n", ent->d_name);
            count++;
        }
        closedir (dir);
    }
    else
    {
    /* could not open directory */
    perror ("Nie znaleziono folderu o danej sciezce.");
    return EXIT_FAILURE;
    }
    return count;
}

FILE* GetDirectoryFileByIndex(char * directoryPath, int index)
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (directoryPath)) != NULL)
    {
        /* print all the files and directories within directory */
        int i = 0;
        while ((ent = readdir (dir)) != NULL)
        {
            if(i == index)
            {
                closedir (dir);
                return fopen(ent->d_name, "r+");
            }
            i++;
        }
        closedir (dir);
    }
    else
    {
    /* could not open directory */
    perror ("Nie znaleziono folderu o danej sciezce.");
    return EXIT_FAILURE;
    }
    return NULL;
}
