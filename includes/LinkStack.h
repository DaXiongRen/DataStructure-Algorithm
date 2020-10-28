/*
 * @Description: 链栈
 * @Author: 大熊人
 * @Date: 2020-10-24 20:04:08
 * @LastEditTime: 2020-10-26 22:43:53
 */
#define TRUE 1
#define FALSE 0
#define STACK_DATA_TYPE int

/* 链栈结点 */
typedef struct LinkStackNode
{
    STACK_DATA_TYPE Data;       //数据域
    struct LinkStackNode *Next; //指向下一个结点的指针（指针域）
} LinkStackNode;

/* 链栈结构 */
typedef struct LinkStack
{
    LinkStackNode *Top; //指向结构体LinkStackNode的Top指针
    int Size;           //链栈长度
} LinkStack;

void InitStack(LinkStack *S);
int Push(LinkStack *S, STACK_DATA_TYPE X);
int IsEmpty(LinkStack *S);
int Pop(LinkStack *S, STACK_DATA_TYPE *X);
int GetTop(LinkStack *S, STACK_DATA_TYPE *X);
void TestLinkStack();