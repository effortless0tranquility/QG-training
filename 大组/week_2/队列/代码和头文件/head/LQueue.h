#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;


#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

  /**************************************************************
   *    Struct Define Section
   **************************************************************/
   //链式队列结构
typedef struct node
{
    void* data;                   //数据域指针
    struct node* next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node* front;                   //队头
    Node* rear;                    //队尾
    size_t length;            //队列长度
} LQueue;

typedef enum
{
    FALSE = 0, TRUE = 1
} Status;
char type;
char datatype[30];
Status IsEmptyLQueue(const LQueue* Q);
/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


 /**
  *  @name        : void InitLQueue(LQueue *Q)
  *    @description : 初始化队列
  *    @param         Q 队列指针Q
  *  @notice      : None
  */
void InitLQueue(LQueue* Q) 
{
    
    Node* p=new Node;
    Q->rear = Q->front = p;
    p->next = NULL;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q)
{
    Node* p1,*p2;
    if (IsEmptyLQueue(Q))
    {
        cout << "SUCCESS!" << endl;
        return;
    }
    while ((p1=Q->front->next) != NULL)
    {
        p2 = p1;
        p1 = p1->next;
        free(p2);
        Q->length--;
    }
    free(p1);
    free(Q->front);
    free(Q->rear);
    cout << "SUCCESS！" << endl;

}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q)
{
    return (Q->front == Q->rear ? TRUE : FALSE);
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void* e)
{
    if (IsEmptyLQueue(Q))
    {
        return FALSE;
    }
    
    memcpy(e, Q->front->next->data, sizeof(Q->front->next->data));
     return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status LengthLQueue(LQueue* Q,size_t*len)
{
   
    Node* p=new Node;
    p = Q->front;
    for (*len = 0; p != Q->rear; (*len)++)
    {
        p = p->next;
    }

    return TRUE;

}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, void* data)
{

    Node* p;
    p = new Node;
    p->data = data;
    Q->rear->next = p;
    Q->rear = p;
    p->next = NULL;
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q)
{
    if (IsEmptyLQueue(Q))
    {
        return FALSE;
    }
    Node* p;
    p = Q->front->next;
    Q->front->next = p->next;
    free(p);

    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q)
{
    if (IsEmptyLQueue)
    {
        cout << "SUCCESS!" << endl;
        return;
    }
    Q->rear = Q->front;
    Node* p1, *p2;
    p1 = Q->front->next;
    while (p1 != NULL)
    {
        p2 = p1;
        p1 = p1->next;
        free(p2);
        Q->length--;
    }
     free(p1);
     cout << "SUCCESS！" << endl;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q))
{
    if (IsEmptyLQueue(Q))
    {
        return FALSE;
    }
    Node* p;
    p = Q->front->next;
    while (p != NULL)
    {
        foo(p->data);
        p = p->next;
    }

    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void* q)
{
    if (type == 'i')
    {
        cout << *(int*)q << endl;
    }
    else if (type == 'f')
    {
        cout << *(float*)q << endl;
    }
    else if (type)
    {
        cout << *(char*)q << endl;
    }

}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED
