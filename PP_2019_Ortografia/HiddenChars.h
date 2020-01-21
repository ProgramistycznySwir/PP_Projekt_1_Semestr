#ifndef HIDDENCHARS_H_INCLUDED
#define HIDDENCHARS_H_INCLUDED

typedef struct hiddenChar
{
    char c;
    struct hiddenChar * next;
}HiddenChar;

///Inicjalizuje listê
struct hiddenChar * HiddenCharList_Initialize()
{
    struct hiddenChar * list = (struct hiddenChar *)malloc(sizeof(struct hiddenChar *)); ///jedynie head listy, nic poza tym nie robi
    list->c = 0; ///listCount - tylko na headzie
    list->next = NULL;
    return list;
}

///Usuwa listê (from head to tail)
//void HiddenCharList_Erase(struct hiddenChar * head)

///0 - jeœli nie ma, 1 - jest
char HiddenCharList_Find() ///NOT IMPLEMENTED
{
    return 0;
}

///Dodaje element na koniec listy
void HiddenCharList_Append(struct hiddenChar * head, char c) ///NOT USED
{
    struct hiddenChar * ptr = head;
    while(ptr->next != NULL) ///przechodzi na koniec listy
        ptr = ptr->next;

    struct hiddenChar * newChar = (struct hiddenChar *)malloc(sizeof(struct hiddenChar *));
    newChar->c = c;
    ptr->next = newChar;
    newChar->next = NULL;

    head->c++;

    return;
}

///Jeœli na liœcie jest ten element to go z niej zabiera, a jak nie ma to dodaje
void HiddenCharList_XOR(struct hiddenChar * head, char c)
{
    struct hiddenChar * ptr1 = head;
    struct hiddenChar * ptr2 = ptr1->next;
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
    ptr1->next = (struct hiddenChar *)malloc(sizeof(struct hiddenChar *));
    ptr1->next->c = c;
    ptr1->next->next = NULL;
    return;
}

void HiddenCharList_Display(struct hiddenChar * head)
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

#endif // HIDDENCHARS_H_INCLUDED
