/*
 * @Description: 顺序表
 * @Author: 大熊人
 * @Date: 2020-09-30 11:38:10
 * @LastEditTime: 2020-10-26 20:40:09
 */
#include <stdio.h>
#include <stdlib.h>
#include "includes/SeqList.h"

/**
 * @description: 初始化顺序表
 * @param {struct *}L
 */
void InitList(SeqList *L)
{
    L->size = 0; /*定义初始数据元素个数*/
}

/**
 * @description: 在顺序表L的位置i（0 ≤ i ≤ size）前插入数据元素值X
 * @param {struct *}L
 * @param {LIST_DATA_TYPE}X
 * @return {int}
 */
int ListInsert(SeqList *L, int i, LIST_DATA_TYPE X)
{
    int j;
    if (L->size >= MaxSize)
    {
        return 0; //顺序表已满 无法插入
    }
    else if (i < 0 || i > L->size)
    {
        return 0; //传入的参数i不合法
    }
    else
    {
        for (j = L->size - 1; j >= i; j--)
        {
            L->list[j + 1] = L->list[j]; /* 插入元素的位置及之后的元素向后移  5 4 3 2 1 0 --> 6 5 4 3 2 1 */
        }
        L->list[i] = X;        /*插入*/
        L->size = L->size + 1; /*元素个数加1*/
        return 1;
    }
}

/**
 * @description: 删除顺序表L中位置i（0 ≤ i ≤ size - 1）的数据元素值并存放到参数X中
 * @param {struct *}L
 * @param {LIST_DATA_TYPE *}
 * @return {int}
 */
int ListDelete(SeqList *L, int i, LIST_DATA_TYPE *X)
{
    int j;
    if (L->size <= 0)
    {
        return 0; //顺序表为空 无法删除
    }
    else if (i < 0 || i > L->size - 1)
    {
        return 0; //传入的参数i不合法
    }
    else
    {
        *X = L->list[i]; /*保存删除的元素到参数X中*/
        for (j = i + 1; j <= L->size - 1; j++)
            L->list[j - 1] = L->list[j]; /* 删除元素的位置之后的元素向前移  0 1 2 3 4 5 --> 0 2 3 4 5 */
        L->size = L->size - 1;           /*数据元素个数减1*/
        return 1;
    }
}

/**
 * @description: 取顺序表L中第i个数据元素的值存于X中
 * @param {struct *}L
 * @param {LIST_DATA_TYPE *}X
 * @return {int}
 */
int ListGet(SeqList *L, int i, LIST_DATA_TYPE *X)
{
    if (i < 0 || i > L->size - 1)
    {
        return 0; //传入的参数i不合法
    }
    else
    {
        *X = L->list[i];
        return 1;
    }
}

/**
 * @description: 测试顺序表
 */
void TestSeqList()
{
    SeqList L;
    int i;
    LIST_DATA_TYPE value;
    InitList(&L);
    for (i = 0; i < 3; i++)
    {
        ListInsert(&L, i, i + 1);
    }
    ListGet(&L, 0, &value);
    printf("value%d=%d\n", 0, value);
    ListGet(&L, 1, &value);
    printf("value%d=%d\n", 1, value);
    ListGet(&L, 2, &value);
    printf("%value%d=%d\n", 2, value);
    ListDelete(&L, 0, &value);
    ListDelete(&L, 1, &value);
    ListDelete(&L, 2, &value);
}