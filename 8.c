#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// дһ���жϵ������Ƿ�ƥ��ĺ���
int MatchCheck(char a[],int len){
    int flag = 0;
    char s[10000];
    int top,i;
    char temp;
    // ��ʼ��һ��ջ
    top = 0;
    for(i=0;i<len;i++){
        if(a[i]=='['){ // �����������ֱ����ջ
            s[++top]=a[i];
            continue;
        }
        if(a[i]==']'){ // ����������ţ�����ƥ��
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

        if(a[i]=='('){ // �����������ֱ����ջ
            s[++top]=a[i];
            continue;
        }
        if(a[i]==')'){ // ����������ţ�����ƥ��
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
    // ��ʾ����һ����
    int N,i;
    scanf("%d",&N);
    int len;
     // ��N������ѭ���ж�
     int count = 1;
     int result[5];
     while(count<=N){
         char a[10000]={'\0'};
        // ����һ���ַ���
        scanf("%s",&a);
         // ���ַ����ĳ���
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
