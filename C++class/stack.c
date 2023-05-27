#include<stdio.h>
int decimal(int c, int n, int first, int ten, int m, int two) {
	for (c; c <= 8; c++) {
		n = first / ten;
		n *= two;
		m += n;
		first %= ten;
		ten /= 10;
		two /= 2;
	}
	return m;
}
int binary(int m, int n, int r, int s) {
	while (r >= 1) {
		m = r % 2;
		n += m * s;
		s *= 10;
		r /= 2;
	}
	return n;
}
int main(void)
{
	int a, c = 1, ten = 10000000, n = 0, m = 0, two = 128, first, second;
	int su = 0, p, q, r, s = 1, gap;
	printf("1. 이진수 변환기  2. 이진수 덧셈기  3. 이진수 뺼셈기\n");
	printf("번호를 선택하세요 : ");
	scanf("%d", &a);
	if (a == 1) {
		printf("8비트 이진수를 입력하세요. :");
		scanf("%d", &first);
		if (first / 10000000 == 0)
			printf("십진수로 %d입니다.", decimal(c, n, first, ten, m, two));
		else if (first / 10000000 == 1)
			printf("십진수로 %d입니다.", decimal(c, n, first, ten, m, two) - 256);
	}
	else if (a == 2) {
		printf("첫 번째 8비트 이진수를 입력하세요 :");
		scanf("%d", &first);
		printf("두 번째 8비트 이진수를 입력하세요 :");
		scanf("%d", &second);
		p = decimal(c, n, first, ten, m, two);
		q = decimal(c, n, second, ten, m, two);
		r = p + q;
		su = binary(m, n, r, s);
		printf("두 이진수의 합은 %08d이고, 십진수로 %d입니다.", su, r);
	}
	else if (a == 3) {
		printf("첫 번째 8비트 이진수를 입력하세요 :");
		scanf("%d", &first);
		printf("두 번째 8비트 이진수를 입력하세요 :");
		scanf("%d", &second);
		p = decimal(c, n, first, ten, m, two);
		q = decimal(c, n, second, ten, m, two);
		r = p - q;
		gap = binary(m, n, r, s);
		printf("두 이진수의 차는 %08d이고, 십진수로 %d입니다.", gap, r);
	}
}
