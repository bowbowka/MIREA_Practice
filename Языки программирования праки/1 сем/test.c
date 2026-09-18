#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int main ()
{
    int seed = time(0) + getpid();
    srand(seed);
    int one = 0;
    int two = 0;
    int three = 0;
    int number;
    for (int i = 0; i < 100000; i++)
    {
        number = rand() % 3 + 1;
        switch (number) {
            case 1:
                one++;
                break;
            case 2:
                two++;
                break;
            case 3:
                three++;
                break;
            default:
                break;
        }
    }
    printf("%d %d %d", one, two, three);
}
