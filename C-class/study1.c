#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*1���� �迭
int main()
{
    int age[10]={11,12,13,14,15,16,17,18,19,20};//�迭�� ù��° ����� �ּڰ��� ����ִ�.
    int height[10]={0};//�迭�� 0���� �ʱ�ȭ
    int *page=age; //�����Ϳ� int�� age�迭�� �Ҵ�

    printf("%d\n",age[1]);//�ι�° ��� �ε���1 ���
    printf("%d\n",height[5]);
    printf("*page:%d\n",*page); //�迭�� ������ �������ϸ� �迭�� ù��° ��ҿ� ����
    printf("age[5]:%d\n",page[5]);//�����ͷ� �迭�� �ε����� �����Ҷ��� *������ �Ⱥ���

    int sum=0;
    for(int i=0; i<sizeof(age)/sizeof(int);i++)
    {
        sum+=age[i];//�迭 ����
    }

    printf("age�迭�� ��:%d\n",sum);
    
    
return 0;
}
*/
/*2���� �迭
int main()
{
    int num[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    
    int (*pnum)[4]=num; //����ũ�Ⱑ 4�� �迭�� ����Ű�� ������.��,2���� �迭�� �����ͷ� ����

    printf("%d\n",pnum[2][1]); 
    
    return 0;
}
*/
/*�����͸� �迭ó�� ����ϱ�
int main()
{
    int *pnum=malloc(sizeof(int)*10); //40����Ʈ �����޸� �Ҵ�
    int **m=malloc(sizeof(int *)*3); //���������Ϳ� �����޸� �Ҵ�

    for(int i=0;i<3;i++) //����ũ�⸸ŭ �ݺ�(����3����4�� �迭�� �´� �����޸� �Ҵ���)
    {
        m[i]=malloc(sizeof(int)*4); //int ũ��*����ũ�� ��ŭ �����޸� �Ҵ�
    }

    m[0][0]=1;
    m[2][0]=5;
    m[2][3]=2;

    printf("2�����迭m[0][0],m[2][0],m[2]3[3]:%d,%d,%d\n",m[0][0],m[2][0],m[2][3]);

    for(int i=0;i<3;i++)
    {
        free(m[i]); //2���� �迭�� ���� ���� �޸� ����
    }
    
    free(m); //2���� �迭�� ���ΰ��� �޸� ����

    pnum[9]=10; //�迭ó�� �ε����� �����Ͽ� �� �Ҵ�

    printf("%d\n",pnum[9]);

    free(pnum);

    return 0;
}
*/
int main()
{
    char c1='a';
    char *pc1="hello"; //���ڿ��� char�����Ϳ� ����

    
    printf("%c\n",c1); //��ȯ�� %c(����)
    printf("%s\n",pc1); //��ȯ�� %s(���ڿ�)

    return 0;
}