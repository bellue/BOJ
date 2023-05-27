#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    int *pnum1; //포인터에는 값을 직접 저장하면 안됨
    int **ppnum1; //이중포인터
    int num1=10;

    pnum1=&num1;
    ppnum1=&pnum1;

    int *pnum2;

    pnum2=malloc(sizeof(int)); // pnum2에 int의 크기 4바이트만큼 동적메모리 할당
    printf("%p\n",pnum2); //메모리의 주소 출력,컴퓨터마다,실행할때마다 달라짐

    *pnum2=10;
    printf("%d\n",*pnum2);

    memset(pnum2,0,sizeof(int)); //pnum2이 가리키는 메모리를 int의 크기만큼 0으로 설정
    printf("%d\n",*pnum2);

    free(pnum2); //동적으로 할당한 메모리 해제 (malloc함수 쓰면 힙에 저장되므로 필수)

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
    strcpy(p1->name,"정종우");
    p1->age=22;
    strcpy(p1->address,"경기도 하남시");

    printf("이름:%s\n",p1->name);
    printf("나이:%d\n",p1->age);
    printf("주소:%s\n",p1->address);

    free(p1);

    return 0;
}
*/
