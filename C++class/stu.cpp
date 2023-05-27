#include <stdio.h>
int z;
void f(int x, int y)
{
	z = y;
	x += y + z;
	y = z * 2;
    printf("%d %d %d\n",x,y,z);		
}
int main()
{
	int y = 3;
	f(z, y);
    printf("%d %d \n",z,y);
	printf("%d\n", z + y);
	return 0;
}