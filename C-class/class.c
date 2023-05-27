
#include <stdio.h>
#pragma warning (disable : 4996)

void getString(char* p);
void getString(char* p)
{
    char ch;
    int i=0;

    while ((ch=getchar()) != '\n')
    {
        p[i++]=ch;
    }
    p[i]='\0'; //문자열의 끝에는 널문자 추가
}

int strlength(char* p)
{
    int i,len=0;
    for (i=0;p[i]!='\0';i++)
    {
        len++;
    }
    return len;
}

int main()
{
    char str[255];
    int len;
    
    printf("문자열 입력:");
    getString(str);
    printf("입력 문자열: %s\n",str);
    
    //len=strlength(str);
    //pirntf("문자열의 길이: %d\n",len);
    
    return 0;
}
