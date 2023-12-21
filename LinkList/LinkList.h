#ifndef __LINKLIST_H_
#define __LINKLIST_H_

#define ELEMENTTYPE void *

typedef struct LinkNode
{
    /* 链表里的内容 */
    ELEMENTTYPE data;
    /* 定义一个指向下一个结点的指针 */
    struct LinkNode *next;   
} LinkNode;

/* 链表 */
typedef struct LinkList
{
    /* 链表的头节点 */
    LinkNode * head;
    LinkNode * tail;
    /* 链表的长度 */
    int len;
} LinkList;


/* 链表的初始化 */
int LinkListInit(LinkList **pList);

/* 链表的头插 */
int LinkListHeadInsert(LinkList * pList, ELEMENTTYPE val);

/* 链表的尾插 */
int LinkListTailInsert(LinkList * pList, ELEMENTTYPE val);

/* 链表的任意位置的插入 */
int LinkListAppointPosInsert(LinkList * pList,int pos, ELEMENTTYPE val);

/* 链表的头删 */
int LinkListHeadDel(LinkList * pList);

/* 链表的尾删 */
int LinkListTailDel(LinkList * pList);

/* 链表指定位置的删除 */
int LinkListAppointPosDel(LinkList * pList, int pos);

/* 链表删除指定元素 */
int LinkListAppointValDel(LinkList * pList, ELEMENTTYPE val);

/* 获取链表的长度 */
int LinkListLenghth(LinkList * pList, int * pSize);

/* 链表的销毁 */
int LinkListDestory(LinkList * pList);

/* 链表的遍历 */
int LinkListForeah(LinkList * pList, int (* printFunc)(ELEMENTTYPE));


#endif