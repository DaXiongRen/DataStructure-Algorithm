/*
 * @Description: 顺序循环队列
 * @Author: 大熊人
 * @LastEditTime: 2020-11-08 18:28:38
 */
#define QUEUE_DATA_TYPE int
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0

/* 顺序循环队列结构体 */
typedef struct SeqQueue
{
    QUEUE_DATA_TYPE *base;
    int front; //头指针
    int rear;  //尾指针
} SeqQueue;

int InitQueue(SeqQueue *Q);
int IsEmpty(SeqQueue *Q);
int IsFull(SeqQueue *Q);
int EnQueue(SeqQueue *Q, QUEUE_DATA_TYPE X);
int DeQueue(SeqQueue *Q, QUEUE_DATA_TYPE *X);
int GetFront(SeqQueue *Q, QUEUE_DATA_TYPE *X);
int QueueLength(SeqQueue *Q);
void TestSeqQueue();