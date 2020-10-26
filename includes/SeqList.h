/*
 * @Description: 顺序表
 * @Author: 大熊人
 * @Date: 2020-10-26 19:42:26
 * @LastEditTime: 2020-10-26 22:44:37
 */
#define MaxSize 50
#define LIST_DATA_TYPE int

/* 顺序表结构体类型 */
typedef struct SeqList
{
    LIST_DATA_TYPE list[MaxSize]; //定义一个存储数据的数组
    int size;                     //元素个数
} SeqList;

void InitList(SeqList *L);
int ListInsert(SeqList *L, int i, LIST_DATA_TYPE X);
int ListDelete(SeqList *L, int i, LIST_DATA_TYPE *X);
int ListGet(SeqList *L, int i, LIST_DATA_TYPE *X);
void TestSeqList();