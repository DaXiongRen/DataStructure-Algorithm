/*
 * @Description: 单链表
 * @Author: 大熊人
 * @Date: 2020-10-30 20:18:09
 * @LastEditTime: 2020-11-01 22:31:14
 */
#define TRUE 1
#define FALSE 0
#define LIST_DATA_TYPE int

/* 单链表结点 */
typedef struct LinkNode
{
    LIST_DATA_TYPE Data;   //数据域
    struct LinkNode *Next; //指向下一个结点的指针指针域
} LinkNode, *LinkList;

void InitList(LinkList *L);
void HeadInsert(LinkList L, LIST_DATA_TYPE X);
void TailInsert(LinkList L, LIST_DATA_TYPE X);
int ListInset(LinkList L, int i, LIST_DATA_TYPE X);
int ListDelete(LinkList L, int i, LIST_DATA_TYPE *X);
int GetElem(LinkList L, int i, LIST_DATA_TYPE *X);
void PrintLinkList(LinkList L);
int ListLength(LinkList L);