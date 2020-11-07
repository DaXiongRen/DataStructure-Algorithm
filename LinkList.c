/*
 * @Description: 单链表
 * @Author: 大熊人
 * @Date: 2020-10-30 20:17:20
 * @LastEditTime: 2020-11-08 00:09:04
 */
#include <stdio.h>
#include <stdlib.h>
#include "includes/LinkList.h"

/**
 * @description: 初始化带头结点的单链表
 * @param {struct **}L  用二级指针间接修改掉头指针的指向 使其指向初始化的头结点
 */
void InitList(LinkList *L)
{
    LinkList temp = (LinkList)malloc(sizeof(LinkNode));
    temp->Data = -1;
    temp->Next = NULL;
    *L = temp;
}

/**
 * @description: 头插法
 * @param {struct *}L
 * @param {LIST_DATA_TYPE}X
 */
void HeadInsert(LinkList L, LIST_DATA_TYPE X)
{
    LinkList temp = (LinkList)malloc(sizeof(LinkNode));
    temp->Data = X;
    temp->Next = L->Next;
    L->Next = temp;
}

/**
 * @description: 尾插法
 * @param {struct *}L
 * @param {LIST_DATA_TYPE}X
 */
void TailInsert(LinkList L, LIST_DATA_TYPE X)
{
    LinkList temp = (LinkList)malloc(sizeof(LinkNode));

    /* 查找最后一个结点 */
    while (L->Next)
    {
        L = L->Next;
    }
    temp->Data = X;
    temp->Next = NULL;
    L->Next = temp;
}

/**
 * @description: 在第i个位置插入元素 1<=i<=ListLength(L)+1
 * @param {struct *}L
 * @param {int}i
 * @param {LIST_DATA_TYPE}X
 * @return {int}
 */
int ListInset(LinkList L, int i, LIST_DATA_TYPE X)
{
    LinkList temp;
    int j = 1;

    /* 查找第i个结点的前驱或最后一个结点 */
    while (L && j < i)
    {
        L = L->Next;
        j++;
    }
    /* 防止输入 i<1 或 i>ListLength(L)+1 的情况 */
    if (!L && j > i)
    {
        return FALSE;
    }

    temp = (LinkList)malloc(sizeof(LinkNode)); //申请一个内存空间作为新结点
    temp->Data = X;                            //把数据存入新结点
    temp->Next = L->Next;                      //使新结点的后继指针指向L的后继 （L是第i个结点的前驱，L的后继就是第i个结点）
    L->Next = temp;                            //再使L的后继指针指向新结点
    return TRUE;
}

/**
 * @description: 删除第i个位置的元素，并存储在X中 1<=i<=ListLength(L)
 * @param {struct *}L
 * @param {int}i
 * @param {LIST_DATA_TYPE *}X
 * @return {int}
 */
int ListDelete(LinkList L, int i, LIST_DATA_TYPE *X)
{
    LinkList temp;
    int j = 1;

    /* 查找第i个结点的前驱 */
    while (L->Next && j < i) //L->Next代表当前要删除的结点不能为空
    {
        L = L->Next;
        j++;
    }
    /* 防止输入 i<1 或 i>ListLength(L) 的情况 */
    if (!(L->Next) && j > i)
    {
        return FALSE;
    }

    temp = L->Next;
    *X = temp->Data;
    L->Next = temp->Next;
    free(temp); //释放内存空间
    return TRUE;
}

/**
 * @description: 获取第i个位置元素，并存储在X中 1 <= i <= ListLength(L)
 * @param {struct *}L
 * @param {int}i
 * @param {LIST_DATA_TYPE *}X
 * @return {int}
 */
int GetElem(LinkList L, int i, LIST_DATA_TYPE *X)
{
    int j = 1;

    /* 查找第i个结点的前驱 */
    while (L && j < i)
    {
        L = L->Next;
        j++;
    }
    /* 防止输入 i<1 或 i>ListLength(L) 的情况 */
    if (!L && j > i)
    {
        return FALSE;
    }

    *X = L->Next->Data;
    return TRUE;
}

/**
 * @description: 打印链表
 * @param {struct *}L
 */
void PrintLinkList(LinkList L)
{
    L = L->Next; //跳过头结点
    printf("%d", L->Data);
    while (L->Next)
    {
        L = L->Next;
        printf("->%d", L->Data);
    }
}

/**
 * @description: 返回元素个数
 * @param {struct *}L
 * @return {int}
 */
int ListLength(LinkList L)
{
    int count = 0;
    while (L->Next)
    {
        count++;
        L = L->Next;
    }
    return count;
}

/**
 * @description: 销毁单链表
 * @param {struct **}L
 */
void Destroy(LinkList *L)
{
    if (*L == NULL)
    {
        return;
    }
    Destroy(&(*L)->Next);
    free(*L);
    *L = NULL;
}

/**
 * @description: 测试单链表
 */
void TestLinkList()
{
    LinkList head = NULL;
    LIST_DATA_TYPE value;

    InitList(&head);
    HeadInsert(head, 1);
    HeadInsert(head, 2);
    HeadInsert(head, 3);
    TailInsert(head, 2);
    TailInsert(head, 3);
    PrintLinkList(head);

    printf("\n\nListInset(6)=4 %s\n", ListInset(head, 6, 4) ? "TRUE" : "FALSE");
    PrintLinkList(head);
    printf("\nListInset(1)=100 %s\n", ListInset(head, 1, 100) ? "TRUE" : "FALSE");
    PrintLinkList(head);
    printf("\n\nListDelete(7) %s\n", ListDelete(head, 7, &value) ? "TRUE" : "FALSE");
    PrintLinkList(head);
    printf("\n\nGetElem(4) %s\n", GetElem(head, 4, &value) ? "TRUE" : "FALSE");
    printf("GetElem(4)=%d\n\n", value);

    PrintLinkList(head);
    printf("\nListLength=%d\n", ListLength(head));
    Destroy(&head);
}

void main()
{
    TestLinkList();
}