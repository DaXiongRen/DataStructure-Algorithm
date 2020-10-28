/*
 * @Description: 顺序栈
 * @Author: 大熊人
 * @Date: 2020-10-25 19:19:02
 * @LastEditTime: 2020-10-26 22:45:32
 */
#define SEQSTACK_MAX 100 //栈的最大值
#define ADD_SIZE 10      //每次追加的值
#define TRUE 1
#define FALSE 0
#define STACK_DATA_TYPE int

/* 顺序栈结构类型 */
typedef struct SeqSrack
{
    STACK_DATA_TYPE *base; //栈底指针
    STACK_DATA_TYPE *top;  //栈顶指针
    int stacksize;         //顺序栈的长度
} SeqStack;

int InitStack(SeqStack *S);
int Push(SeqStack *S, STACK_DATA_TYPE X);
int Pop(SeqStack *S, STACK_DATA_TYPE *X);
int Pop(SeqStack *S, STACK_DATA_TYPE *X);
void TestSeqStack();