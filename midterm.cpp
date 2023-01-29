// Thanakit Thinkum 65543206059-9 SEC 3
// URL : https://youtu.be/LCDQzyknHH8

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Menulist
{
    char Name[50];
    int Price;
    struct Menulist *next;
};

void ShowAll(struct Menulist *walk);
struct Menulist *AddNode(struct Menulist **walk, const char name[], int price);
void UpdateNode(struct Menulist **start, const char Old_name[], const char New_name[], int New_price);
struct Menulist *ShowBack(struct Menulist *start);
void SwapNode(struct Menulist **start, const char name1[], const char name2[]);

int main()
{
    struct Menulist *start = NULL;
    AddNode(&start, "KaoManKai", 40);
    AddNode(&start, "KaijeawMoosap", 45);
    AddNode(&start, "KaosoiKai", 50);
    AddNode(&start, "KaoKhaMoo", 55);
    ShowAll(start);
    UpdateNode(&start, "KaijeawMoosap", "KaoPad", 35);
    ShowAll(start);
    start = ShowBack(start);
    ShowAll(start);
    SwapNode(&start, "KaoManKai", "KaoKhaMoo");
    ShowAll(start);
    return 0;
}

void ShowAll(struct Menulist *walk)
{
    while (walk != NULL)
    {
        printf("[%s | %d Baht], ", walk->Name, walk->Price);
        walk = walk->next;
    }
    printf("\n");
}

struct Menulist *AddNode(struct Menulist **walk, const char name[], int price)
{
    while (*walk != NULL)
    {
        walk = &(*walk)->next;
    }
    *walk = (struct Menulist *)malloc(sizeof(struct Menulist));
    strcpy((*walk)->Name, name);
    (*walk)->Price = price;
    (*walk)->next = NULL;
    return *walk;
}

void UpdateNode(struct Menulist **walk, const char Old_name[], const char New_name[], int price)
{
    struct Menulist *change = *walk;
    while (change != NULL)
    {
        if (!strcmp(change->Name, Old_name))
        {
            strcpy(change->Name, New_name);
            change->Price = price;
        }
        change = change->next;
    }
}

struct Menulist *ShowBack(struct Menulist *start)
{
    struct Menulist *early = NULL;
    struct Menulist *next = NULL;
    while (start != NULL)
    {
        next = start->next;
        start->next = early;
        early = start;
        start = next;
    }
    start = early;
    return start;
}

void SwapNode(struct Menulist **start, const char Name1[], const char Name2[])
{
    struct Menulist *list1 = *start;
    struct Menulist *list2 = *start;
    struct Menulist *menu1 = NULL;
    while (list1 && strcmp(list1->Name, Name1) != 0)
    {
        menu1 = list1;
        list1 = list1->next;
    }
    struct Menulist *menu2 = NULL;
    while (list2 && strcmp(list2->Name, Name2) != 0)
    {
        menu2 = list2;
        list2 = list2->next;
    }
    if (list1 == NULL || list2 == NULL)
    {
        return;
    }
    if (menu1 != NULL)
    {
        menu1->next = list2;
    }
    else
    {
        *start = list2;
    }
    if (menu2 != NULL)
    {
        menu2->next = list1;
    }
    else
    {
        *start = list1;
    }
    struct Menulist *temp = list2->next;
    list2->next = list1->next;
    list1->next = temp;
}
