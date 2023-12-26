#include <stdio.h>
#include "circulateLinkList.h"
#include <string.h>

#define BUFFER_SIZE 3

int printBasicData(void *arg)
{
    int data = *(int *)arg;
    printf("data:%d\n", data);

}

int mian()
{

    CirculateLinkList * list = NULL;
    /* 初始化链表 */
    CirculateLinkListInit(&list);

    int buffer[BUFFER_SIZE] = {1, 2, 3};
    /* 插入数据 */
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        CirculateLinkListHeadInsert(list, (void *)&buffer[idx]);
    }

    /* 获取链表的长度 */
    int size = 0;
    CirculateLinkListLenghth(list, &size);
    printf("size:%d\n", size);

    /* 链表的遍历 */
    CirculateLinkListForeah(list, printBasicData);
}