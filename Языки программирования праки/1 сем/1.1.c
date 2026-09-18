#include <stdio.h>

int main()
{
	int x1, x2, x3, x4, x5; // делаем пять переменных
	scanf("%d\n %d\n %d\n %d\n %d\n", &x1, &x2, &x3, &x4, &x5);

	int summa = x1 + x2 + x3 + x4 + x5;
	printf("%d\n", summa);

	int raznost = -x1 - x2 - x3 - x4 - x5;
	printf("%d\n", raznost);

	int proizf = x1 * x2 * x3 * x4 * x5;
	printf("%d\n", proizf);

	int ost1 = x1 % 10;
	printf("%d\n", ost1);
	int ost2 = x2 % 10;
	printf("%d\n", ost2);
	int ost3 = x3 % 10;
	printf("%d\n", ost3);
	int ost4 = x4 % 10;
	printf("%d\n", ost4);
	int ost5 = x5 % 10;
	printf("%d\n", ost5);

	int size1 = sizeof(x1);
	printf("%d\n", size1);
	int size2 = sizeof(x2);
	printf("%d\n", size2);
	int size3 = sizeof(x3);
	printf("%d\n", size3);
	int size4 = sizeof(x4);
	printf("%d\n", size4);
	int size5 = sizeof(x5);
	printf("%d\n", size5);
}
