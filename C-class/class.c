
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
    p[i]='\0'; //���ڿ��� ������ �ι��� �߰�
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
    
    printf("���ڿ� �Է�:");
    getString(str);
    printf("�Է� ���ڿ�: %s\n",str);
    
    //len=strlength(str);
    //pirntf("���ڿ��� ����: %d\n",len);
    
    return 0;
}
