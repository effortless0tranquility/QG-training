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
   //��ʽ���нṹ
typedef struct node
{
    void* data;                   //������ָ��
    struct node* next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node* front;                   //��ͷ
    Node* rear;                    //��β
    size_t length;            //���г���
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
  *    @description : ��ʼ������
  *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
    cout << "SUCCESS��" << endl;

}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q)
{
    return (Q->front == Q->rear ? TRUE : FALSE);
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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
     cout << "SUCCESS��" << endl;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q

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
