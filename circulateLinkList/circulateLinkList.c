#include <stdio.h>
#include "circulateLinkList.h"
#include <string.h>
#include <stdlib.h>

/* 状态码 */
enum STATUS_CODE
{
    ON_SUCCESS, 
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
    NOT_FIND,
};

/* 静态数组声明前置 */
static int CirculateLinkListAccordAppointValGetPos(CirculateLinkList * pList, ELEMENTTYPE val, int *pPos);

/* 链表的初始化 */
int CirculateLinkListInit(CirculateLinkList **pList)
{
    int ret = 0;
    /* 初始化链表  定义一个链表结构体 并且开辟一个空间给链表 */
    CirculateLinkList *list = (CirculateLinkList *)malloc(sizeof(CirculateLinkList) * 1);
    if (list == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(list, 0, sizeof(list) * 1);

    /* 给头节点分配空间 */
    list->head = (CirculateLinkNode *)malloc(sizeof(CirculateLinkNode) * 1);
    if (list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(list, 0, sizeof(list) * 1);

    list->head->data = 0;
    /* 初始化的时候  头指针指向自己 */
    list->head->next = list->head;

    /* 链表的长度为0 */
    list->len = 0;

    /* 二级指针 */
    *pList = list;

    return ret;

}

/* 链表的头插 */
int CirculateLinkListHeadInsert(CirculateLinkList * pList, ELEMENTTYPE val)
{
    return CirculateLinkListAppointPosInsert(pList, 0, val);
}

/* 链表的任意位置的插入 */  
int CirculateLinkListAppointPosInsert(CirculateLinkList * pList,int pos, ELEMENTTYPE val)
{
    int ret = 0;

    /* 判断是否为空 */
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    /* 判断位置是否合法 */
    if (pos < 0 || pos > pList->len)
    {
        return INVALID_ACCESS; 
    }
 
    /* 封装一个新的节点 */
    CirculateLinkNode * newNode = (CirculateLinkList *)malloc(sizeof(CirculateLinkList) * 1);
    /* 判断节点是否为空 */
    if (newNode == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(newNode, 0, sizeof(newNode) * 1);

    /* 给新结点赋值 */
    newNode->data = val;

    /* 从头开始遍历 */
    CirculateLinkNode * travelNode = pList->head;

    /* 如果要插入的位置是链表的长度 直接指向头指针 */
    if (pos = pList->len)
    {
        travelNode = pList->head;

        /* 将新的结点插入 */
        travelNode->prve->next = newNode;
        travelNode->prve = newNode;
        newNode->next = travelNode;
        newNode->prve = travelNode->prve;
    }
    else
    {
        /* 找到自己的要插入的位置 */
        while(pos)
        {
            travelNode = travelNode->next;
            pos--;
            /* 将新的节点插入 */
            newNode->next = travelNode->next;
            newNode->prve = travelNode;
            travelNode->next->prve = newNode;
            travelNode->next = newNode;
        }  
    }
 

    /* 加入新结点 更新链表的长度 */
    (pList->len)++;
    return ret;


}

/* 链表的头删 */
int CirculateLinkListHeadDel(CirculateLinkList * pList)
{
    return CirculateLinkListAppointPosDel(pList, 1);
}


/* 链表指定位置的删除 */
int CirculateLinkListAppointPosDel(CirculateLinkList * pList, int pos)
{
    int ret = 0;

    /* 判断链表是否为空 */
    if (pList == NULL)
    {
        return NULL_PTR;
    }
    /* 判断位置是否非法 同时排除当链表为空的情况 */
    if (pos <= 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

    /* 从头开始遍历 */
    CirculateLinkNode * travelNode = pList->head;

#if 0
    if (pos = pList->tail)
    {
        flag = 1;
    }
#endif
    CirculateLinkNode * needDelNode = NULL;
    if (pos == pList->len)
    {
        travelNode = pList->head;
        needDelNode = travelNode->prve;

        travelNode->prve = needDelNode->prve;
        needDelNode->prve->next = travelNode;
    }
    else
    {
        while (--pos)
        {
            /* 遍历到需要删除的节点上 */
            travelNode = travelNode->next;
        }
        /* 将目标节点删掉 */
        needDelNode = travelNode->next;
        travelNode->next = needDelNode->next;
        needDelNode->next->prve = travelNode;
    }
   


    /* 释放内存 */
    if (needDelNode != NULL)
    {
        free(needDelNode);
        needDelNode = NULL;
    }

    /* 删除之后更新长度 */
    (pList->len)--;

    return ret;

}

static int CirculateLinkListAccordAppointValGetPos(CirculateLinkList * pList, ELEMENTTYPE val, int *pPos)
{
    int ret = 0;
    int pos = 0;
    CirculateLinkNode * travelNode = pList->head->next;

    while (travelNode != NULL)
    {
        if (travelNode->data == val)
        {
            *pPos = pos;
            return pos;
        }
        travelNode = travelNode->next;
        pos++;
    }
    *pPos = NOT_FIND;
    return NOT_FIND;

}
/* 链表删除指定元素 */
int CirculateLinkListAppointDataDel(CirculateLinkList * pList, ELEMENTTYPE val)
{
    int ret = 0;

    int pos = 0;
    int size = 0;
    while (CirculateLinkListLenghth(pList, &size) && pos != NOT_FIND)
    {
        int pos = 0;
        CirculateLinkListAccordAppointValGetPos(pList, val, &pos);
        CirculateLinkListAppointPosDel(pList, pos);
    }

}

/* 获取链表的长度 */
int CirculateLinkListLenghth(CirculateLinkList * pList, int * pSize)
{

    if (pList == NULL)
    {
        return NULL_PTR;
    }
    if (pSize)
    {
        *pSize = pList->len;
    }

    return pList->len;

}

/* 链表的销毁 */
int CirculateLinkListDestory(CirculateLinkList * pList)
{
    int ret = 0;
    /* 运用头删 进行循环的删除 */
    int size = 0;
    while (CirculateLinkListLenghth(pList, &size))
    {
        CirculateLinkListHeadDel(pList);
    }

    if (pList->head != NULL)
    {
        free(pList->head);
        pList->head = NULL;
    }

    return ret;

}

/* 链表的遍历 */
int CirculateLinkListForeah(CirculateLinkList * pList, int (* printFunc)(ELEMENTTYPE))
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }
    CirculateLinkNode * travelNode = pList->head->next;
    while (travelNode != pList->head)
    {
        printFunc(travelNode->data);
        travelNode = travelNode->next;
    }

    return ret;

}