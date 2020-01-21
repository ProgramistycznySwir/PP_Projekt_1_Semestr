#ifndef BASICFUNCTIONS_H_INCLUDED
#define BASICFUNCTIONS_H_INCLUDED


void XY(int, int);

void DisplayFileByPath(char *);
void DisplayFile(FILE *);

short GetConsoleSize(char);

void DisplayDirectoryFiles(char);

FILE* GetDirectoryFileByIndex(char * directoryPath, int index)


#endif // BASICFUNCTIONS_H_INCLUDED
