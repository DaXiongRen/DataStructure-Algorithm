/*
 * @Description: 顺序循环队列
 * @Author: 大熊人
 * @LastEditTime: 2020-11-08 18:27:54
 */
#include <stdio.h>
#include <stdlib.h>
#include "includes/SeqQueue.h"

/**
 * @description: 初始化顺序循环队列
 * @param {struct *}Q
 * @return {int}
 */
int InitQueue(SeqQueue *Q)
{
    Q->base = (QUEUE_DATA_TYPE *)malloc(sizeof(QUEUE_DATA_TYPE) * MAXSIZE);
    if (Q->base == NULL)
    {
        return FALSE; //申请内存空失败
    }
    Q->front = 0;
    Q->rear = 0;
    return TRUE;
}

/**
 * @description: 判断队列是否为空
 * @param {struct *}Q
 * @return {int}
 */
int IsEmpty(SeqQueue *Q)
{
    if (QueueLength(Q) == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 * @description: 判断队列是否满
 * @param {struct *}Q
 * @return {int}
 */
int IsFull(SeqQueue *Q)
{
    if (QueueLength(Q) > 0 && Q->front == Q->rear)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 * @description: 入列
 * @param {struct *}Q
 * @param {QUEUE_DATA_TYPE *}X
 * @return {int}
 */
int EnQueue(SeqQueue *Q, QUEUE_DATA_TYPE X)
{
    if (IsFull(Q) == TRUE)
    {
        return FALSE; //队列满
    }
    Q->base[Q->rear] = X;
    Q->rear = (Q->rear + 1) % MAXSIZE; //在MAXSIZE范围内指针后移
    return TRUE;
}

/**
 * @description: 出列
 * @param {struct *}Q
 * @param {QUEUE_DATA_TYPE *}X
 * @return {int}
 */
int DeQueue(SeqQueue *Q, QUEUE_DATA_TYPE *X)
{
    if (IsEmpty(Q) == TRUE)
    {
        return FALSE; //队列空
    }
    *X = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE; //在MAXSIZE范围内指针后移
    return TRUE;
}

/**
 * @description: 获取队头元素
 * @param {struct *}Q
 * @return {int}
 */
int GetFront(SeqQueue *Q, QUEUE_DATA_TYPE *X)
{
    if (IsEmpty(Q) == TRUE)
    {
        return FALSE;
    }
    *X = Q->base[Q->front];
    return TRUE;
}

/**
 * @description: 获取队列长度
 * @param {struct}Q
 * @return {int}
 */
int QueueLength(SeqQueue *Q)
{
    return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

/**
 * @description: 测试顺序循环队列
 */
void TestSeqQueue()
{
    SeqQueue Q;
    QUEUE_DATA_TYPE value;

    if (InitQueue(&Q))
    {
        printf("初始化成功！\n");
    }
    else
    {
        printf("初始化失败！\n");
    }
    printf("EnQueue:1 %s\n", EnQueue(&Q, 1) ? "TURE" : "FALSE");
    printf("EnQueue:2 %s\n", EnQueue(&Q, 2) ? "TURE" : "FALSE");
    printf("EnQueue:3 %s\n", EnQueue(&Q, 3) ? "TURE" : "FALSE");

    printf("GetFront:%d %s\n", value, GetFront(&Q, &value) ? "TURE" : "FALSE");

    while (DeQueue(&Q, &value))
    {
        printf("DeQueue:%d\n", value);
    }

    printf("GetFront: %s\n", GetFront(&Q, &value) ? "TURE" : "FALSE");

    free(Q.base); //释放申请的内存空间
}