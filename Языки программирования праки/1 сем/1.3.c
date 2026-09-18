#include <stdio.h>

int main()
{
	int N; // количество элементов массива

	printf("Введите количество элементов массива: ");
	scanf("%d", &N);
	int arr[N]; // наш массив чисел

	// Ввод чисел
	for (int i = 0; i < N; i++)
	{
		int element;
		scanf("%d", &element);
		arr[i] = element;
	}

	// Сортировка пузырьком
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			int temp;
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("\n");
	// Вывод отсортированного массива
	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("Минимальный: %d, Максимальный: %d", arr[0], arr[N - 1]);

	return 0;
}