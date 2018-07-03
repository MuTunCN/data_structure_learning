/*
队列
*/
#include <stdlib.h>
#include <stdio.h>

#define dataType int
#define MAXSIZE 1000

typedef struct SqQueue {    //顺序队列
    dataType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

typedef struct QNode {  //链队
    dataType data;
    struct QNode* next;
}QNode;
typedef struct {
    QNode* front;
    QNode* rear;
}LinQueue;
//顺序队
void initQueue(SqQueue &sqQ){
    printf("initing queue...\n");
    sqQ.front = sqQ.rear = 0;
}
int isSqQueueEmpty(SqQueue sqQ) {
    printf("is sequeue empty?...\n");
    return sqQ.front == sqQ.rear ? 1 : 0;
}
void enSqQueue(SqQueue &sqQ, dataType value) {
    printf("enter value in sequence queue...\n");
    if(sqQ.rear+1 % MAXSIZE == sqQ.front) {
        printf("max size...\n");
        return;
    }
    sqQ.rear = sqQ.rear+1 % MAXSIZE;
    sqQ.data[sqQ.rear] = value;
}
void deSqQueue(SqQueue &sqQ,dataType &r) {
    printf("delete value in sequence queue...\n");
    if(sqQ.rear == sqQ.front) {
        printf("empty queue...\n");
    }
    sqQ.front = sqQ.front+1 % MAXSIZE;
    r = sqQ.data[sqQ.front];
}

//链队
void initLinQueue(LinQueue* &linQ) {
    printf("initing queue...\n");
    linQ = (LinQueue*) malloc (sizeof(LinQueue));
    linQ->front = linQ->rear = NULL;
}
int isLinQueueEmpty(LinQueue* linQ) {
    printf("is queue empty?...\n");
    return linQ->front == NULL || linQ->rear == NULL ? 1 : 0;
}
void enLinQueue(LinQueue* &linQ, dataType value) {
    printf("enter value in  queue...\n");
    QNode* q = (QNode*) malloc (sizeof(QNode));
    q->data = value;
    q->next = NULL;
    if (linQ->front == NULL || linQ->rear == NULL) {
        linQ->front = linQ->rear = q;
    } else {
        linQ->rear->next = q;
        linQ->rear = q;
    }
}
void deLinQueue(LinQueue* &linQ,dataType &r) {
    printf("delete value in sequence queue...\n");
    if(linQ->rear == NULL || linQ->front == NULL) {
        printf("empry queue...\n");
        return;
    }
    QNode* p = linQ->front;
    r = p->data;
    if(linQ->rear == linQ->front) {
        linQ->front = linQ->rear = NULL;
    }else {
        linQ->front = p->next;
    }
    free(p);
}
int main() {
    dataType r;
    // SqQueue sqQ;
    // initQueue(sqQ);
    // int flag = isSqQueueEmpty(sqQ);
    // printf("%d\n",flag);
    // enSqQueue(sqQ,38);
    // deSqQueue(sqQ,r);
    // printf("delete %d...\n",r);

    LinQueue* linQ;
    initLinQueue(linQ);
    int flag = isLinQueueEmpty(linQ);
    printf("%d\n",flag);
    enLinQueue(linQ,38);
    deLinQueue(linQ,r);
    printf("delete %d...\n",r);
}