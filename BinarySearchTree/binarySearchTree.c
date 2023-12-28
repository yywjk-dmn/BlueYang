#include <stdio.h>
#include "binarySearchTree.h"
#include <stdlib.h>
#include "doubleLinkListQueue.h"

/* 状态码 */
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
    NOT_FIND,
};
/* 静态函数的前置声明 */
static BSTreenode *createBSTreeNewNode(ELEMENTTYPE val, BSTreenode *newNode);
/* 根据指定的值获取二叉搜索树的结点 */
static int baseAppointValGetBSTressNode(binarySearchTree *pBtree, ELEMENTTYPE val);
/* 前序遍历 */
static int preOrderTravel(binarySearchTree *pBtree, BSTreenode *node);
/* 中序遍历 */
static int inOrderTravel(binarySearchTree *pBtree, BSTreenode *node);
/* 后序遍历 */
static int postOrderTravel(binarySearchTree *pBtree, BSTreenode *node);






static BSTreenode *createBSTreeNewNode(ELEMENTTYPE val, BSTreenode *parent)
{
    BSTreenode *newNode = (BSTreenode *)malloc(sizeof(BSTreenode) * 1);
    if (newNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newNode, 0, sizeof(newNode) * 1);
    /* 初始化结点 */
    {
        newNode->data = 0;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;
    }
    /* 赋值 */
    newNode->data = val;

    /* 更新父结点 */
    newNode->parent = parent;
    return newNode;
}

/* 二叉搜索树的初始化 */
int binarySearchTreeInit(binarySearchTree **pBtree, int (* compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (* printFunc)(ELEMENTTYPE val))
{
    int ret = 0;
    binarySearchTree *bstree = (binarySearchTree *)malloc(sizeof(binarySearchTree) * 1);
    if (bstree == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(bstree, 0, sizeof(binarySearchTree) * 1);

    /* 初始化树 */
    {
        bstree->root = NULL;
        bstree->size = 0;
        bstree->compareFunc = compareFunc;
        bstree->printFunc = printFunc;
    }

    /* 创建新结点 */
    bstree->root = createBSTreeNewNode(0, NULL);
    if (bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }

    *pBtree = bstree;
    return ret;

}

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(binarySearchTree *pBtree, ELEMENTTYPE val)
{
    int ret = 0;
    if (pBtree->size == 0)
    {
        (pBtree->size)++;
        pBtree->root->data = val;
        return ret;
    }

    /* 指针指向根结点 */
    BSTreenode *travelNode = pBtree->root;
    BSTreenode *parentNode = pBtree->root;

    /* 进行遍历，判断插入的数据是要放在左边还是右边 */
    int cmp = 0;
    while (travelNode != NULL)
    {
        /* 标记父结点 */
        parentNode = travelNode;
        cmp = pBtree->compareFunc(val, travelNode->data);

        if (val < travelNode->data)
        {
            travelNode = travelNode->left;
        }
        else if (val > travelNode->data)
        {
            travelNode = travelNode->right;
        }
        else
        {
            return ret;
        }
    }

    /* 新增一个结点 */
    BSTreenode *newNode = createBSTreeNewNode(pBtree, parentNode);

    /* 将数据插入 */
    if (cmp < 0)
    {
        parentNode->left = newNode;
    }
    else if (cmp > 0)
    {
        parentNode->right = newNode;
    }
    else
    {
        parentNode = newNode;
    }

    /* 树的大小更新 */
    (pBtree->size)++;

    return ret;


}


/* 根据指定的值获取二叉搜索树的结点 */
static int baseAppointValGetBSTressNode(binarySearchTree *pBtree, ELEMENTTYPE val)
{
    BSTreenode *travelNode = pBtree->root;
    int cmp = 0;
    while (travelNode != NULL)
    {
        cmp = pBtree->compareFunc(val, travelNode->data);
        if (cmp < 0)
        {
            travelNode = travelNode->left;
        }
        else if (cmp > 0)
        {
            travelNode = travelNode->right;
        }
        else
        {
            return travelNode;
        }

    }
    return NULL;

}

/* 二叉搜索树是否包含指定的元素 */
int binarySearchTreeContainAppointVal(binarySearchTree *pBtree, ELEMENTTYPE val)
{
    return baseAppointValGetBSTressNode(pBtree, val) == NULL ? 0 : 1;
}

/* 前序遍历 */
static int preOrderTravel(binarySearchTree *pBtree, BSTreenode *node)
{
    int ret = 0;
    if (node == NULL)
    {
        return ret;
    }
    /* 根结点 */
    pBtree->printFunc(node->data);
    /* 左结点 */
    preOrderTravel(pBtree, node->left);
    /* 右结点 */
    preOrderTravel(pBtree, node->right);

}

/* 前序遍历 */
int binarySearchTreePreOrderTravel(binarySearchTree *pBtree)
{
    int ret = 0;
    preOrderTravel(pBtree, pBtree->root);
    return ret;

}

/* 中序遍历 */
static int inOrderTravel(binarySearchTree *pBtree, BSTreenode *node)
{
    int ret = 0;
    if (node == NULL)
    {
        return ret;
    }
    /* 左结点 */
    inOrderTravel(pBtree, node->left);
    /* 根结点 */
    pBtree->printFunc(node->data);
    /* 右结点 */
    inOrderTravel(pBtree, node->right);

}

/* 中序遍历 */
int binarySearchTreeInOrderTravel(binarySearchTree *pBtree)
{
    int ret = 0;
    inOrderTravel(pBtree, pBtree->root);           
    return ret;


}

/* 后序遍历 */
static int postOrderTravel(binarySearchTree *pBtree, BSTreenode *node)
{
    int ret = 0;
    if (node == NULL)
    {
        return ret;
    }
    /* 左结点 */
    postOrderTravel(pBtree, node->left);
    /* 右结点 */
    postOrderTravel(pBtree, node->right);
    /* 根节点 */
    pBtree->printFunc(node->data);

}

/* 后序遍历 */
int binarySearchTreePostOrderTravel(binarySearchTree *pBtree)
{
    int ret = 0;
    postOrderTravel(pBtree, pBtree->root);
    return ret;


}

/* 层序遍历 */
int binarySearchTreeLeveOrderTravel(binarySearchTree *pBtree)
{
    int ret = 0;

    /* 初始化队列 */
    DoubleLinkList *queue = NULL;
    doubleLinkListQueueInit(&queue);

    /* 将根结点入队 */
    doubleLinkListQueuePush(queue, pBtree->root);

    /* 避免野指针 */
    BSTreenode *nodeVal = NULL;
    /* 判断队列是否为空 */
    while (!doubleLinkListQueueIsEmpty(queue))
    {
        /* 将根结点写入队列中 然后用一个指针指向它，方便后面找到它的左指针和右指针 */
        doubleLinkListQueueTop(queue, (void**)&nodeVal);
        /* 将这个节点的值输出 */
        pBtree->printFunc(nodeVal->data);
        doubleLinkListQueuePop(queue);

        if (nodeVal->left != NULL)
        {
            doubleLinkListQueuePush(queue, nodeVal->left);
        }
        if (nodeVal->right != NULL)
        {
            doubleLinkListQueuePush(queue, nodeVal->right);
        }

    }

    /* 释放队列 */
    doubleLinkListQueueDestory(queue);

    return ret;
}

/* 树的高度 */
int binarySearchTreeGetHeight(binarySearchTree *pBtree, int *pHeight)
{
    /* 判断树是否为空 */
    if (pBtree == NULL)
    {
        return NULL_PTR;
    }
    /* 判断结点个数是否为空 */
    if (pBtree->size == NULL)
    {
        return 0;
    }
    /* 初始化队列 */
    doubleLinkListQueue *pQueue;
    doubleLinkListQueueInit(&pQueue); 
    
    /* 将头结点入队 */
    doubleLinkListQueuePush(pQueue, pBtree->root);
    int ret = 0;

    /* 定义一个指针 */
    BSTreenode * travelNode = NULL;

    /* 定义树的高度 */
    int height = 0;
    /* 定义每一层的结点树 */
    int levelSize = 0;
    /* 判断 当队列不为空 */
    while (!doubleLinkListQueueIsEmpty(pQueue))
    {
        /* 将结点入队 */
        doubleLinkListQueuePush(pQueue, (void **)&travelNode);
        /* 将结点pop */
        doubleLinkListQueuePop(pQueue);
        levelSize--;

        /* 判断左子树是否为空 */
        if (travelNode->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, travelNode->left);

        }
        /* 判断右子树是否为空 */
        if (travelNode->right != NULL)
        {
            doubleLinkListQueuePush(pQueue, travelNode->right);

        }

        /* 判断高度 */
        if (levelSize == 0)
        {
            height++;
            doubleLinkListQueueGetSize(pQueue, &levelSize);
        }

        *pHeight = height;
        /* 队列的释放 */
        doubleLinkListQueueDestory(pQueue);

        return ret;

    }



}

int binarySearchTreeGetNodeSize(binarySearchTree *pBtree, int *pSize)
{
    /* 判断树是否为空 */
    if (pBtree == NULL)
    {
        return NULL_PTR;
    }
    if (pSize)
    {
        *pSize = pBtree->size;
    }

    return pBtree->size;
}
