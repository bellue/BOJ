#include <stdio.h>
int main()
{
  int num1,num2,a,b;
  
  scanf("%d %d",&num1,&num2);

  a=(num1/100)+(num1/10%10)*10+(num1%10)*100;
  b=(num2/100)+(num2/10%10)*10+(num2%10)*100;

  if(a>=b){
      printf("%d",a);
  }
  if(a<b){
      printf("%d",b);
  }
  

    return 0;
}