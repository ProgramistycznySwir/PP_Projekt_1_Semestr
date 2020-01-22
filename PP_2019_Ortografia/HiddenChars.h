#ifndef HIDDENCHARS_H_INCLUDED
#define HIDDENCHARS_H_INCLUDED

///Nazwa zmiennej by³a HiddenChar w poprzednich wersjach, a z racji ¿e zmiana nazwy pliku .h nie jest wymagana to i tego nie zrobiê :P

typedef struct Char
{
    char c;
    struct Char* next;
}Char_type;

///Inicjalizuje listê
struct Char* CharList_Initialize()
{
    struct Char* list = (struct Char*)malloc(sizeof(struct Char*)); ///jedynie head listy, nic poza tym nie robi
    list->c = 0; ///listCount - tylko na headzie
    list->next = NULL;
    return list;
}

///Usuwa listê (from head to tail)
//void HiddenCharList_Erase(struct hiddenChar * head)

///0 - jeœli nie ma, 1 - jest
char CharList_Find() ///NOT IMPLEMENTED
{
    return 0;
}

///Dodaje element na koniec listy
void CharList_Append(struct Char* head, char c)
{
    struct Char * ptr = head;
    while(ptr->next != NULL) ///przechodzi na koniec listy
        ptr = ptr->next;

    struct Char * newListElement = (struct Char*)malloc(sizeof(struct Char*));
    newListElement->c = c;
    ptr->next = newListElement;
    newListElement->next = NULL;

    head->c++;

    return;
}

///Jeœli na liœcie jest ten element to go z niej zabiera, a jak nie ma to dodaje (stara funkcjonalnoœæ)
void CharList_XOR(struct Char* head, char c) ///NOTUSED - FUNCTIONALITY ABANDONED
{
    struct Char* ptr1 = head;
    struct Char* ptr2 = ptr1->next;
    while(ptr2 != NULL)
    {
        if(ptr2->c == c) ///jeœli wykryje znak w liœcie to go z niej usuwa
        {
            ptr1->next = ptr2->next;
            free(ptr2);
            head->c--;
            return;
        }
        ptr1 = ptr2;
        ptr2 = ptr2->next;
    }
    ///Mo¿na to zrobiæ jeszcze "metod¹" Append() ale skoro ju¿ mamy koñcowy element listy...
    ptr1->next = (struct Char*)malloc(sizeof(struct Char*));
    ptr1->next->c = c;
    ptr1->next->next = NULL;
    return;
}

void CharList_Display(struct Char* head)
{
    head = head->next;
//    if(head == NULL)
//        printf(">>>Lista pusta<<<\n");
    while(head != NULL)
    {
        printf("%c,", head->c);
        head = head->next;
    }
    return;
}

///Char(acter)P(osition)T(racker) - struktura Char rozszerzona o pozycjê (x,y)
typedef struct CharPT
{
    char c;
    short x;
    short y;
    struct CharPT* next;
}CharPT_type;

struct CharPT* CharPTList_Initialize()
{
    struct CharPT* list = (struct CharPT*)malloc(sizeof(struct CharPT*)); ///jedynie head listy, nic poza tym nie robi
    list->c = 0; ///listCount - tylko na headzie
    list->next = NULL;
    return list;
}

void CharPTList_Append(struct CharPT* head, char c, short posX, short posY)
{
    struct CharPT * ptr = head;
    while(ptr->next != NULL) ///przechodzi na koniec listy
        ptr = ptr->next;

    struct CharPT * newListElement = (struct CharPT*)malloc(sizeof(struct CharPT*));
    newListElement->c = c;
    newListElement->x = posX;
    newListElement->y = posY;
    ptr->next = newListElement;
    newListElement->next = NULL;

    head->c++;

    return;
}

///0 - different (or some sort of error), 1 - same
char CompareListElements(struct Char* a, struct CharPT* b)
{
    if(a->c == b->c)
        return 1;
    return 0;
}

#endif // HIDDENCHARS_H_INCLUDED
