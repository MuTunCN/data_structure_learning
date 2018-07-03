/*
串
*/
#include <stdlib.h>
#include <stdio.h>

#define dataType char
#define MAXSIZE 1000

typedef struct {
    dataType ch[MAXSIZE+1];
    int length;
}StrS;

typedef struct  {
    char* ch;
    int length;
}StrL;

void strAssign(StrL &str, char* ch) {
    printf("assigning string...\n");
    //释放空间
    if(str.ch) {
        free(str.ch);  
    }
    //求ch长度
    int len = 0;
    char* ctemp = ch;
    while(*ctemp != NULL) {
        len++;
        ctemp++;
    }
    //ch为空串的处理
    if(len == 0) {
        str.ch = NULL;
        str.length = 0;
        return;
    }else {
        //串赋值
        ctemp = ch;
        str.ch = (char*) malloc (len*sizeof(char)); //生成了多个指针 所以下面可以当数组用
        for(int i = 0; i<len; i++,ctemp++) {
            str.ch[i] = *ctemp; 
        }
        str.length = len;
    }
    
}
int strLength(StrL str) {
    return str.length;
}
void strCompare(StrL str1,StrL str2) {
    
}
// concat(str,str1,str2);
// subString(str,str1,3,6);
// clearString(str1);

int main(int argc, char const *argv[])
{
    StrL str,str1,str2;
    strAssign(str1,"hello world!");
    strAssign(str2,"hello warld!");
    // strLength(str1);
    // strCompare(str1,str2);
    // concat(str,str1,str2);
    // subString(str,str1,3,6);
    // clearString(str1);
    return 0;
}
