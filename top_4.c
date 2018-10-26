#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// 写一个判断的括号是否匹配的函数
int MatchCheck(char a[],int len){
    int flag = 0;
    char s[10000];
    int top,i;
    char temp;
    // 初始化一个栈
    top = 0;
    for(i=0;i<len;i++){
        if(a[i]=='['){ // 如果是左括号直接入栈
            s[++top]=a[i];
            continue;
        }
        if(a[i]==']'){ // 如果是右括号，则尝试匹配
            temp = s[top];
            if(temp=='['){
                flag = 1;
                top--;
                continue;
            }else{
                flag = 0;
                break;
            }
        }

        if(a[i]=='('){ // 如果是左括号直接入栈
            s[++top]=a[i];
            continue;
        }
        if(a[i]==')'){ // 如果是右括号，则尝试匹配
            temp = s[top];
            if(temp=='('){
                flag = 1;
                top--;
                continue;
            }else{
                flag = 0;
                break;
            }
        }
    }
    if(flag&&(top==0)){
        return 1;
    }else{
        return 0;
    }

}
int main(){
    // 提示输入一个数
    int N,i;
    scanf("%d",&N);
    int len;
     // 对N组数据循环判断
     int count = 1;
     int result[5];
     while(count<=N){
         char a[10000]={'\0'};
        // 读入一行字符串
        scanf("%s",&a);
         // 求字符串的长度
        len = strlen(a);
        result[count]=MatchCheck(a,len);
        count++;
     }
     for(i=1;i<count;i++){
         if(result[i]){
             printf("Yes\n");
         }else{
             printf("No\n");
         }
     }
     return 0;
}//{[({()()()({}{}{})})]}
