/*
 * @Description: 顺序栈
 * @Author: 大熊人
 * @LastEditTime: 2020-11-02 23:10:46
 */
#include <stdio.h>
#include <stdlib.h>
#include "includes/SeqStack.h"

/**
 * @description: 初始化顺序栈
 * @param {struct *}S
 * @return {int}
 */
int InitStack(SeqStack *S)
{
    /*
        当时的错误，顺便记下笔记：
        S必须是一个结构体指针才能完成栈的初始化  因为如果只是结构体变量的话 那么它就是一个形参（局部变量）
        局部变量的改变是不会影响到函数间同名变量的改变的 因此我们需要传结构体变量S的地址
        简单理解就是通过S的地址  修改结构体成员变量   入栈 出栈 都一样   
    */

    //申请内存空间后 S->base指向一段可用内存起始地址 大小为SEQSTACK_MAX*4字节 以4字节为一个单位连续的空间 一段一段的
    S->base = (STACK_DATA_TYPE *)malloc(SEQSTACK_MAX * sizeof(STACK_DATA_TYPE));
    if (!S->base)
    {
        return FALSE; //申请内存空间失败
    }
    S->top = S->base;
    S->stacksize = SEQSTACK_MAX;
    return TRUE;
}

/**
 * @description: 入栈
 * @param {struct *}S
 * @param {STACK_DATA_TYPE}X
 * @return {int}
 */
int Push(SeqStack *S, STACK_DATA_TYPE X)
{
    STACK_DATA_TYPE *temp;
    temp = S->base; //用于保护原来的数据

    //当栈满时 则增加内存空间 初始化时申请的内存是以4字节为一个单位的内存空间
    //例如S->base指向1  S->top指向101   那么S->top - S->base = 100 即栈满
    if (S->top - S->base >= S->stacksize)
    {
        //按照S->stacksize + ADD_SIZE大小申请新的内存空间，将原有数据拷贝到新的内存空间后并释放原有的内存空间（内存是自动释放的）
        //最后返回新申请内存空间的首地址         realloc函数的详细解释->百度
        temp = (STACK_DATA_TYPE *)realloc(S->base, (S->stacksize + ADD_SIZE) * sizeof(STACK_DATA_TYPE));

        if (!temp)
        {
            return FALSE; //内存追加失败
        }
        S->base = temp;
        S->top = S->base + S->stacksize; //重置栈顶指针指向新的地址
        S->stacksize += ADD_SIZE;        //更新顺序栈的长度
    }
    *S->top++ = X; //元素入栈  可拆分成：*S->top = X; S->top++;
    return TRUE;
}

/**
 * @description: 获取栈顶元素
 * @param {struct *}S
 * @param {STACK_DATA_TYPE *}X
 * @return {int}
 */
int GetTop(SeqStack *S, STACK_DATA_TYPE *X)
{
    if (S->stacksize == 0)
    {
        return FALSE;
    }
    *X = *(S->top - 1);
    return TRUE;
}

/**
 * @description: 出栈
 * @param {struct *}S
 * @param {STACK_DATA_TYPE *}X
 * @return {int}
 */
int Pop(SeqStack *S, STACK_DATA_TYPE *X)
{
    if (S->top == S->base)
        return FALSE; //空
    *X = *--S->top;   //*(--(S->top))
    return TRUE;
}

/**
 * @description: 返回元素个数
 * @param {struct}S
 * @return {int}
 */
int SeqStackLength(SeqStack S)
{
    return S.top - S.base;
}

/**
 * @description: 测试顺序栈
 */
void TestSeqStack()
{
    SeqStack S;
    STACK_DATA_TYPE value;
    int i;
    if (InitStack(&S))
        printf("初始化成功！\n");
    else
        printf("初始化失败！\n");
    for (i = 1; i <= 5; i++)
    {
        printf("Push:%d %s\n", i, Push(&S, i) ? "TRUE" : "FALSE");
    }
    printf("\nSeqStackLength=%d\n", SeqStackLength(S));

    GetTop(&S, &value);
    printf("Top:%d\n", value);
    while (Pop(&S, &value))
    {
        printf("Pop:%d ", value);
    }
    printf("\nSeqStackLength=%d\n", SeqStackLength(S));
    free(S.base);
}