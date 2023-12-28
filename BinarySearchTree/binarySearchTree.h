#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#define ELEMENTTYPE void*
typedef struct BSTreenode
{
    ELEMENTTYPE data;
    /* 左子树 */
    struct  BSTreenode *left;
    /* 右子树 */
    struct  BSTreenode *right;
    /* 父节点 */
    struct BSTreenode *parent;   
} BSTreenode;

typedef struct  binarySearchTree
{
    /* 根节点 */
    BSTreenode *root;
    /* 树的大小 */
    int size;
    /* 钩子函数 比较 */  
    int (* compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2);
    /* 钩子函数 输出 */
    int (* printFunc)(ELEMENTTYPE val);

} binarySearchTree;


/* 二叉搜索树的初始化 */
int binarySearchTreeInit(binarySearchTree **pBtree, int (* compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (* printFunc)(ELEMENTTYPE val));

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(binarySearchTree *pBtree, ELEMENTTYPE val);

/* 二叉搜索树是否包含指定的元素 */
int binarySearchTreeContainAppointVal(binarySearchTree *pBtree, ELEMENTTYPE val);

/* 前序遍历 */
int binarySearchTreePreOrderTravel(binarySearchTree *pBtree);

/* 中序遍历 */
int binarySearchTreeInOrderTravel(binarySearchTree *pBtree);

/* 后序遍历 */
int binarySearchTreePostOrderTravel(binarySearchTree *pBtree);

/* 层序遍历 */
int binarySearchTreeLeveOrderTravel(binarySearchTree *pBtree);

/* 树的高度 */
int binarySearchTreeGetHeight(binarySearchTree *pBtree, int *pHeight);

/* 获取树的结点数 */
int binarySearchTreeGetNodeSize(binarySearchTree *pBtree, int *pSize);





#endif