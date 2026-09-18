#include <stdio.h>
#include <stdlib.h>

int *sort(int *old_arr, int size) // сортирует массив, создавая новый. не изменяет старый массив
{
    int *new_arr = malloc(sizeof(int) * size); // выделяем память под новый массив
    for (int i = 0; i < size; i++)
    {
        new_arr[i] = old_arr[i];
    }
    for (int i = 0; i < size; i++) // сортировка пузырьком
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (new_arr[j] > new_arr[j + 1]) // swap()
            {
                int temp = new_arr[j];
                new_arr[j] = new_arr[j + 1];
                new_arr[j + 1] = temp;
            }
        }
    }

    return new_arr;
}

int main()
{
    const int N = 5;                    // длина массива
    int *arr = malloc(sizeof(int) * N); // старый массив, он принимает данные от пользователя

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int *new_arr = sort(arr, N); // новый массив, его сортируем
    for (int i = 0; i < N; i++)
    {
        printf("%d ", new_arr[i]);
    }
    printf("\n");

    free(arr);     // надо не забыть освободить память
    free(new_arr); // надо не забыть освободить память
    return 0;
}
