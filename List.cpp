/*
线性表
*/
#include <stdio.h>
#include <stdlib.h>
#define dataType int
#define MaxSize 1000

typedef struct LLNode { //单链表
    dataType data;
    struct LLNode* next;
}LLNode;

typedef struct SLNode { //顺序表
    dataType data[MaxSize];
    int size;
}SLNode;

typedef struct DLLNode { //双链表
    dataType data;
    struct DLLNode* prior;
    struct DLLNode* next;
}DLLNode;

//单链表系列
void initLL(LLNode *&LL) {  //引用指针 需要改变参数就用引用
    LL = (LLNode*) malloc (sizeof(LLNode));
    LL->next = NULL;
    LL->data = -1;
    printf("head node created success...\n");
    // for (int i = 0; i < 10; i++) {  //头插法
    //     LLNode* node =  (LLNode*) malloc (sizeof(LLNode));
    //     node->data = i;
    //     node->next = LL->next;
    //     LL->next = node;
    //     // printf("node %d create success data is %d...\n",i,node->data);
    // }
    LLNode* p = LL;
    for (int i = 0; i < 10; i++) {  //尾插法
        LLNode* node =  (LLNode*) malloc (sizeof(LLNode));
        node->data = i;
        node->next = p->next;
        p->next = node;
        p = p->next;
        // printf("node %d create success data is %d...\n",i,node->data);
    }
    printf("List created success...\n");
}

void showLL(LLNode* LL) {   //遍历
    printf("traversed List:");
    LLNode* p = LL->next;
    while(p != NULL) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void findLL(LLNode* LL, int pos) {
    printf("start finding list...\n");
    LLNode* p = LL->next;
    while(p != NULL) {
        if (pos == 0) {
            printf("pos found value is %d\n", p->data);
            return;
        }
        p = p->next;
        pos--;
    }
    printf("not found\n");
}

void insertLL(LLNode *&LL, dataType value, int pos) {
    printf("start inserting list...\n");
    LLNode* p = LL->next;
    while(pos != 0) {
        p = p->next;
        pos--;
    }
    printf("found pos");
    LLNode* node = (LLNode*) malloc (sizeof(LLNode));
    node->data = value;
    node->next = p->next;
    p->next = node;
    printf("inserted success...\n");
}

void deleteLL(LLNode *&LL, int pos) {
    printf("deleteing list node...\n");
    LLNode* p = LL->next;
    while(pos != 1) {
        p = p->next;
        pos--;
    }
    LLNode* node = p->next;
    p->next = node->next;
    free(node);
}
//顺序表系列
void initSL(SLNode &SL) {
    printf("initing sq list...");
    SL.size = 0;
    for (int i = 0; i < 10; i++) {
        SL.data[i] = i;
        SL.size++;
    }
}

void showSL(SLNode SL) {
    printf("traversed sq list:\n");
    for(int i = 0; i < SL.size; i++) {
        printf("%d ",SL.data[i]);
    }
    printf("\n");
}

void findSL(SLNode SL, int pos) {
    printf("found vlaue is %d\n", SL.data[pos]);
}

void insertSL(SLNode &SL,dataType value,int pos) {
    for(int i = SL.size; i >= pos  ; i --) {
        SL.data[i+1] = SL.data[i];
    }
    SL.data[pos] = value;
    SL.size++;
}

void deleteSL(SLNode &SL, int pos) {
    for (int i = pos; i < SL.size ; i++) {
        SL.data[i] = SL.data[i+1];
    }
    SL.size--;
}

//双链表
void initDLL(DLLNode* &DLL) {
    printf("initing double link list...");
    DLL = (DLLNode*) malloc (sizeof(DLLNode));
    DLL->next = NULL;
    DLL->data = -1;
    printf("head node created success...\n");
    // for (int i = 0; i < 10; i++) {  //头插法
    //     DLLNode* node =  (DLLNode*) malloc (sizeof(DLLNode));
    //     node->data = i;
    //     node->next = DLL->next;
    //     DLL->next = node;
    //     // printf("node %d create success data is %d...\n",i,node->data);
    // }
    DLLNode* p = DLL;
    for (int i = 0; i < 10; i++) {  //尾插法
        DLLNode* node =  (DLLNode*) malloc (sizeof(DLLNode));
        node->data = i;
        node->next = p->next;
        p->next = node;
        p = p->next;
        // printf("node %d create success data is %d...\n",i,node->data);
    }
    printf("List created success...\n");    
}

void showDLL(DLLNode* DLL) {   //遍历
    printf("traversed List:");
    DLLNode* p = DLL->next;
    while(p != NULL) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void findDLL(DLLNode* DLL, int pos) {
    printf("start finding list...\n");
    DLLNode* p = DLL->next;
    while(p != NULL) {
        if (pos == 0) {
            printf("pos found value is %d\n", p->data);
            return;
        }
        p = p->next;
        pos--;
    }
    printf("not found\n");
}

void insertDLL(DLLNode *&DLL, dataType value, int pos) {
    printf("start inserting list...\n");
    DLLNode* p = DLL->next;
    while(pos != 0) {
        p = p->next;
        pos--;
    }
    printf("found pos");
    DLLNode* node = (DLLNode*) malloc (sizeof(DLLNode));
    node->data = value;
    node->next = p->next;
    p->next = node;
    printf("inserted success...\n");
}

void deleteDLL(DLLNode *&DLL, int pos) {
    printf("deleteing list node...\n");
    DLLNode* p = DLL->next;
    while(pos != 1) {
        p = p->next;
        pos--;
    }
    DLLNode* node = p->next;
    p->next = node->next;
    free(node);
}
int main() {
    // LLNode* LL;
    // initLL(LL);
    // showLL(LL);
    // findLL(LL,5);
    // insertLL(LL,38,5);
    // showLL(LL);
    // deleteLL(LL,6);
    // showLL(LL);

    // SLNode SL;
    // initSL(SL);
    // showSL(SL);
    // findSL(SL,5);
    // insertSL(SL,38,5);
    // showSL(SL);
    // deleteSL(SL,6);
    // showSL(SL);

    DLLNode* DLL;
    initDLL(DLL);
    showDLL(DLL);
    findDLL(DLL,5);
    insertDLL(DLL,38,5);
    showDLL(DLL);
    deleteDLL(DLL,6);
    showDLL(DLL);
}