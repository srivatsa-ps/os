#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
float aveg = 0;
int max, min, size void *avg(int num[])

{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += num[i];
    }
    aveg = (float)sum / size;
    pthread_exit(0);
}

void *maxx(int num[])
{
    int temp = num[0];
    for (int i = 1; i <= size - 1; i++)
    {
        if (num[i] > temp)
            temp = num[i];
        }
    max = temp;
    pthread_exit(0);
}

void *minn(int num[])
{
    int temp = num[0];
    for (int i = 1; i <= size - 1; i++)
    {
        if (num[i] < temp)
            temp = num[i];
    }
    min = temp;
    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    int n = argc - 1;
    int num[n];
    size = n;

    for (int i = 0; i < n; i++)
    {
        num[i] = atoi(argv[i + 1]);
    }
    pthread_t av, ma, mi;
    pthread_create(&av, NULL, *avg, num);
    pthread_create(&ma, NULL, *maxx, num);
    pthread_create(&mi, NULL, *minn, num);
    pthread_join(av, NULL);
    pthread_join(ma, NULL);
    pthread_join(mi, NULL);
    printf("\nthe average value  is %f", aveg);
    printf("\nthe minimum value is %d ", min);
    printf("\nthe maximum value is %d ", max);
    return 0;
}