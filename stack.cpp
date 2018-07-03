/*
栈
*/
#include <stdlib.h>
#include <stdio.h>

#define dataType int
#define MAXSIZE 1000

typedef struct sqStack {
    dataType data[MAXSIZE];
    int top;
}sqStack;

typedef struct SNode {
    dataType data;
    struct SNode* next;
}SNode;

//顺序栈
void initSqStack(sqStack &sqS) {
    printf("initing sequence stack...\n");
    sqS.top = -1;  
}
int sqSIsEmpty(sqStack sqS) {
    printf("is sequence stack is empty?...\n");
    return sqS.top == -1 ? 1 : 0;
}
void sqSPush(sqStack &sqS, int value) {
    printf("pushing...\n");
    if (sqS.top == MAXSIZE - 1) {
        printf("max size...\n");
        return;
    }
    sqS.top++;
    sqS.data[sqS.top] = value;
}
void sqSPop(sqStack &sqS,dataType &r) {
    printf("poping...\n");
    if(sqS.top == -1) {
        printf("empty stack");
        return;
    }
    r = sqS.data[sqS.top];
    sqS.top--;
}
//链栈
void initLinStack(SNode* &linS) {
    printf("initing link stack...\n");
    linS = (SNode*) malloc (sizeof(SNode));
    linS->next = NULL;
}
int LinSIsEmpty(SNode* linS) {
    printf("is link stack empty?...\n");
    return linS->next == NULL ? 1:0;
}
void linSPush(SNode* &linS, dataType value) {
    printf("pushing...\n");
    SNode* p = (SNode*) malloc (sizeof(SNode));
    p->data = value;
    p->next = linS->next;
    linS->next = p;
}
void linSPop(SNode* &linS, dataType &r) {
    if (linS->next == NULL) {
        printf("empty stack...\n");
        return;
    }
    SNode* p = linS->next;
    r = p->data;
    linS->next = p->next;
    free(p);
}

int main() {
    dataType r;
    // sqStack sqS;
    // initSqStack(sqS);
    // int flag = sqSIsEmpty(sqS);
    // printf("%d\n",flag);
    // sqSPush(sqS,5);
    // sqSPop(sqS,r);
    // printf("pop %d",r);

    SNode* linS;
    initLinStack(linS);
    int flag2 = LinSIsEmpty(linS);
    printf("%d\n",flag2);
    linSPush(linS,5);
    linSPop(linS,r);
    printf("pop %d",r);
}
