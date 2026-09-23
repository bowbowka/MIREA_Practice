#include <stdint.h>
#include <stdio.h>

int getMinor(int N, int arr[N][N], int minor[N-1][N-1], int row, int col) // функция, находящая минор
{
    int sub_row = 0;
    for (int i = 0; i < N; i++)
    {
        if (i == row) // если ряд в котором элемент == скип
        {
            continue;
        }

        int sub_col = 0;
        for (int j = 0; j < N; j++)
        {
            if (j == col) // // если столбик в котором элемент == скип
            {
                continue;
            }
            minor[sub_row][sub_col] = arr[i][j];
            sub_col++;
        }
        sub_row++;
    }
}

int findDeterminant(int N, int arr[N][N]) // ищем определитель, раскладываем по первой строке
{
    if (N == 1) return arr[0][0]; // для матрицы 1х1 просто вощвращаем элемент
    else if (N == 2)
    {
        return arr[0][0]*arr[1][1] - arr[1][0]*arr[0][1]; // для матрицы 2х2, ищем определитель по формуле ad-bc
    }
    // Создаем минор
    int minor[N-1][N-1];
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        int a = (i%2==0 ? arr[0][i] : -arr[0][i]);
        getMinor(N, arr, minor, 0, i);
        result = result + a*findDeterminant(N-1, minor);
    }
    return result;
}

int main()
{
    int M, N; // Строки и столбики
    scanf("%d %d", &M, &N);

    int matrix[M][N]; // наша матрица
    printf("\nЗаполните матрицу %d x %d:\n", M, N);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++) { // вводим матрицу
            int element;
            scanf("%d", &element);
            matrix[i][j] = element;
        }
    }

    // поиск определителя
    if (N != M) {
        printf("невозможно найти определитель (M != N)\n");
        return 0;
    }
    int determinant = findDeterminant(N, matrix);
    printf("\ndeterminator: %d", determinant);



    return 0;
}
