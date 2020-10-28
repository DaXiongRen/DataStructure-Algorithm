/*
 * @Description: 链栈
 * @Author: 大熊人
 * @Date: 2020-10-26 18:26:52
 * @LastEditTime: 2020-10-26 20:13:17
 */

#include <stdio.h>
#include <stdlib.h>
#include "includes/LinkStack.h"

/**
 * @description: 初始化链栈
 * @param {struct *}S
 * @return 
 */
void InitStack(LinkStack *S)
{
    S->Top = NULL; //初始化栈为空
    S->Size = 0;   //链栈长度初始化为0
}

/**
 * @description: 入栈
 * @param {struct *}S
 * @param {STACK_DATA_TYPE}X
 * @return {int}
 */
int Push(LinkStack *S, STACK_DATA_TYPE X)
{
    LinkStackNode *temp;
    temp = (LinkStackNode *)malloc(sizeof(LinkStackNode)); //申请一个临时内存空间，用于存储入栈的数据
    if (!temp)
    {
        return FALSE; //申请内存空间失败
    }
    temp->Data = X;
    temp->Next = S->Top; //新申请内存空间的下一个结点指针指向旧的结点指针
    S->Top = temp;       //将插入的元素作为新的栈顶元素
    S->Size++;           //链栈长度+1
    return TRUE;
}

/**
 * @description: 判断链栈是否为空
 * @param {struct *}S
 * @return {int}
 */
int IsEmpty(LinkStack *S)
{
    if (S->Size == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 * @description: 出栈
 * @param {struct *}S
 * @param {STACK_DATA_TYPE *}X
 * @return {int}
 */
int Pop(LinkStack *S, STACK_DATA_TYPE *X)
{
    LinkStackNode *temp;
    if (IsEmpty(S))
    {
        return FALSE; //链栈为空，出栈失败
    }
    temp = S->Top;       //临时指针指向栈顶结点的指针
    S->Top = temp->Next; //移动原始的栈顶指针 使其指向下一个结点的指针
    *X = temp->Data;     //将元素返回
    free(temp);          //释放上一个结点的内存空间
    S->Size--;           //链栈长度-1
    return TRUE;
}

/**
 * @description: 获取栈顶元素
 * @param {struct *}S
 * @param {STACK_DATA_TYPE *}X
 * @return {int}
 */
int GetTop(LinkStack *S, STACK_DATA_TYPE *X)
{
    if (IsEmpty(S))
    {
        return FALSE; //链栈为空，获取栈顶元素失败
    }
    *X = S->Top->Data;
    return TRUE;
}

/**
 * @description: 测试链栈
 */
void TestLinkStack()
{
    LinkStack S;
    int i;
    STACK_DATA_TYPE value;
    InitStack(&S);
    for (i = 1; i <= 5; i++)
    {
        printf("Push:%d %s\n", i, Push(&S, i) ? "入栈成功" : "入栈失败");
    }
    GetTop(&S, &value);
    printf("StackTop:%d\n", value);
    while (Pop(&S, &value))
    {
        printf("Pop:%d ", value);
    }
}