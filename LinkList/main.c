#include <stdio.h>
#include "LinkList.h"
#include <string.h>

#define BUFFER_SIZE 3

typedef struct stuInfo
{
    int age;
    char sex;
} stuInfo;

int printStruct(void *arg)
{
    stuInfo * info = (stuInfo *)arg;
}

int mian()
{
    LinkList * list = NULL;
    LinkListInit(&list);

    LinkListForeah(list, printStruct);

    return 0;
}