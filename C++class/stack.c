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
	printf("1. ������ ��ȯ��  2. ������ ������  3. ������ �E����\n");
	printf("��ȣ�� �����ϼ��� : ");
	scanf("%d", &a);
	if (a == 1) {
		printf("8��Ʈ �������� �Է��ϼ���. :");
		scanf("%d", &first);
		if (first / 10000000 == 0)
			printf("�������� %d�Դϴ�.", decimal(c, n, first, ten, m, two));
		else if (first / 10000000 == 1)
			printf("�������� %d�Դϴ�.", decimal(c, n, first, ten, m, two) - 256);
	}
	else if (a == 2) {
		printf("ù ��° 8��Ʈ �������� �Է��ϼ��� :");
		scanf("%d", &first);
		printf("�� ��° 8��Ʈ �������� �Է��ϼ��� :");
		scanf("%d", &second);
		p = decimal(c, n, first, ten, m, two);
		q = decimal(c, n, second, ten, m, two);
		r = p + q;
		su = binary(m, n, r, s);
		printf("�� �������� ���� %08d�̰�, �������� %d�Դϴ�.", su, r);
	}
	else if (a == 3) {
		printf("ù ��° 8��Ʈ �������� �Է��ϼ��� :");
		scanf("%d", &first);
		printf("�� ��° 8��Ʈ �������� �Է��ϼ��� :");
		scanf("%d", &second);
		p = decimal(c, n, first, ten, m, two);
		q = decimal(c, n, second, ten, m, two);
		r = p - q;
		gap = binary(m, n, r, s);
		printf("�� �������� ���� %08d�̰�, �������� %d�Դϴ�.", gap, r);
	}
}
