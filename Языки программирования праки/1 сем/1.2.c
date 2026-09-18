#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#define ROCK 0
#define PAPER 1
#define SCISSORS 2

int main()
{
	srand(time(0) ^ getpid()); // генерация seed, разная каждую секунду
	int user_win_count = 0;
	int program_win_count = 0;
	int action = 0;

	while (action >= 0 && action <= 2)
	{
		printf("Для начала игры введите число. 0 - камень, 1 - бумага, 2 - ножницы. \n");
		printf("Чтобы завершить игру напишите любое другое число.\n");
		printf("Ваш счётчик побед: %d\n", user_win_count);
		printf("Счётчик побед программы: %d\n", program_win_count); // исправлено: было user_win_count

		scanf("%d", &action);

		// если ввели число не 0/1/2 - выходим из игры, не обрабатывая раунд
		if (action < 0 || action > 2)
			break;

		int rand_action = rand() % 3;

		// выводим, что показала программа, через обычные if
		if (rand_action == ROCK)
			printf("Программа показала: камень\n");
		if (rand_action == PAPER)
			printf("Программа показала: бумага\n");
		if (rand_action == SCISSORS)
			printf("Программа показала: ножницы\n");

		int round_result = 0; // 0 - ничья, 1 - победа игрока, 2 - победа программы

		if (rand_action == ROCK && action == PAPER)
		{
			user_win_count++;
			round_result = 1;
		}
		if (rand_action == PAPER && action == SCISSORS)
		{
			user_win_count++;
			round_result = 1;
		}
		if (rand_action == SCISSORS && action == ROCK)
		{
			user_win_count++;
			round_result = 1;
		}

		if (rand_action == ROCK && action == SCISSORS)
		{
			program_win_count++;
			round_result = 2;
		}
		if (rand_action == PAPER && action == ROCK)
		{
			program_win_count++;
			round_result = 2;
		}
		if (rand_action == SCISSORS && action == PAPER)
		{
			program_win_count++;
			round_result = 2;
		}

		// выводим, кто выиграл в этом раунде
		if (round_result == 1)
			printf("Раунд выиграл пользователь!\n\n");
		if (round_result == 2)
			printf("Раунд выиграла программа!\n\n");
		if (round_result == 0)
			printf("Ничья!\n\n");
	}

	printf("Игра окончена. Итоговый счёт - вы: %d, программа: %d\n", user_win_count, program_win_count);

	return 0;
}
