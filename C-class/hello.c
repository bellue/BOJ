#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    int *pnum1; //�����Ϳ��� ���� ���� �����ϸ� �ȵ�
    int **ppnum1; //����������
    int num1=10;

    pnum1=&num1;
    ppnum1=&pnum1;

    int *pnum2;

    pnum2=malloc(sizeof(int)); // pnum2�� int�� ũ�� 4����Ʈ��ŭ �����޸� �Ҵ�
    printf("%p\n",pnum2); //�޸��� �ּ� ���,��ǻ�͸���,�����Ҷ����� �޶���

    *pnum2=10;
    printf("%d\n",*pnum2);

    memset(pnum2,0,sizeof(int)); //pnum2�� ����Ű�� �޸𸮸� int�� ũ�⸸ŭ 0���� ����
    printf("%d\n",*pnum2);

    free(pnum2); //�������� �Ҵ��� �޸� ���� (malloc�Լ� ���� ���� ����ǹǷ� �ʼ�)

    *pnum1=20;
    printf("%d\n",num1);
    printf("%d\n",*pnum1);
    printf("%d",**ppnum1);

    return 0;
}

/*struct person
{
    char name[20];
    int age;
    char address[100];
};

int main()
{
    struct person *p1=malloc(sizeof(struct person));
    strcpy(p1->name,"������");
    p1->age=22;
    strcpy(p1->address,"��⵵ �ϳ���");

    printf("�̸�:%s\n",p1->name);
    printf("����:%d\n",p1->age);
    printf("�ּ�:%s\n",p1->address);

    free(p1);

    return 0;
}
*/
