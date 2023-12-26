#ifndef __CirculateLinkList_H_
#define __CirculateLinkList_H_

#define ELEMENTTYPE void *

typedef struct CirculateLinkNode
{
    /* 链表里的内容 */
    ELEMENTTYPE data;
    /* 定义一个指向前一个结点的指针 */
    struct  CirculateLinkNode *prve;
    /* 定义一个指向下一个结点的指针 */
    struct CirculateLinkNode *next;   
} CirculateLinkNode;

/* 链表 */
typedef struct CirculateLinkList
{
    /* 链表的头节点 */
    CirculateLinkNode * head;
    /* 循环链表没有尾指针 */
    /* 链表的长度 */
    int len;
} CirculateLinkList;


/* 链表的初始化 */
int CirculateLinkListInit(CirculateLinkList **pList);

/* 链表的头插 */
int CirculateLinkListHeadInsert(CirculateLinkList * pList, ELEMENTTYPE val);

/* 链表的尾插 */
int CirculateLinkListTailInsert(CirculateLinkList * pList, ELEMENTTYPE val);

/* 链表的任意位置的插入 */
int CirculateLinkListAppointPosInsert(CirculateLinkList * pList,int pos, ELEMENTTYPE val);

/* 链表的头删 */
int CirculateLinkListHeadDel(CirculateLinkList * pList);

/* 链表的尾删 */
int CirculateLinkListTailDel(CirculateLinkList * pList);

/* 链表指定位置的删除 */
int CirculateLinkListAppointPosDel(CirculateLinkList * pList, int pos);

/* 链表删除指定元素 */
int CirculateLinkListAppointValDel(CirculateLinkList * pList, ELEMENTTYPE val);

/* 获取链表的长度 */
int CirculateLinkListLenghth(CirculateLinkList * pList, int * pSize);

/* 链表的销毁 */
int CirculateLinkListDestory(CirculateLinkList * pList);

/* 链表的遍历 */
int CirculateLinkListForeah(CirculateLinkList * pList, int (* printFunc)(ELEMENTTYPE));


#endif