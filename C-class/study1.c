#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*1차원 배열
int main()
{
    int age[10]={11,12,13,14,15,16,17,18,19,20};//배열은 첫번째 요소의 주솟값만 담고있다.
    int height[10]={0};//배열을 0으로 초기화
    int *page=age; //포인터에 int형 age배열을 할당

    printf("%d\n",age[1]);//두번째 요소 인덱스1 출력
    printf("%d\n",height[5]);
    printf("*page:%d\n",*page); //배열의 포인터 역참조하면 배열의 첫번째 요소에 접근
    printf("age[5]:%d\n",page[5]);//포인터로 배열의 인덱스에 접근할때는 *연산자 안붙음

    int sum=0;
    for(int i=0; i<sizeof(age)/sizeof(int);i++)
    {
        sum+=age[i];//배열 덧셈
    }

    printf("age배열의 합:%d\n",sum);
    
    
return 0;
}
*/
/*2차원 배열
int main()
{
    int num[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    
    int (*pnum)[4]=num; //가로크기가 4인 배열을 가리키는 포인터.즉,2차원 배열에 포인터로 접근

    printf("%d\n",pnum[2][1]); 
    
    return 0;
}
*/
/*포인터를 배열처럼 사용하기
int main()
{
    int *pnum=malloc(sizeof(int)*10); //40바이트 동적메모리 할당
    int **m=malloc(sizeof(int *)*3); //이중포인터에 동적메모리 할당

    for(int i=0;i<3;i++) //세로크기만큼 반복(세로3가로4인 배열에 맞는 동적메모리 할당중)
    {
        m[i]=malloc(sizeof(int)*4); //int 크기*가로크기 만큼 동적메모리 할당
    }

    m[0][0]=1;
    m[2][0]=5;
    m[2][3]=2;

    printf("2차원배열m[0][0],m[2][0],m[2]3[3]:%d,%d,%d\n",m[0][0],m[2][0],m[2][3]);

    for(int i=0;i<3;i++)
    {
        free(m[i]); //2차원 배열의 가로 공간 메모리 해제
    }
    
    free(m); //2차원 배열의 세로공간 메모리 해제

    pnum[9]=10; //배열처럼 인덱스로 접근하여 값 할당

    printf("%d\n",pnum[9]);

    free(pnum);

    return 0;
}
*/
int main()
{
    char c1='a';
    char *pc1="hello"; //문자열은 char포인터에 저장

    
    printf("%c\n",c1); //변환명세 %c(문자)
    printf("%s\n",pc1); //변환명세 %s(문자열)

    return 0;
}