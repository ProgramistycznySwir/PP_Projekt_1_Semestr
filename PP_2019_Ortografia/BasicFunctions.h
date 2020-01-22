#ifndef BASICFUNCTIONS_H_INCLUDED
#define BASICFUNCTIONS_H_INCLUDED


void XY(int, int);

int GetConsoleCPX();
int GetConsoleCPY();

void DisplayFileByPath(char *);
void DisplayFile(FILE *);

short GetConsoleSize(char);

int DisplayDirectoryFiles(char);

FILE* GetDirectoryFileByIndex(char * directoryPath, int index)


#endif // BASICFUNCTIONS_H_INCLUDED
