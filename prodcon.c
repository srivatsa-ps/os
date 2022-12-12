#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, x = 0, empty;
int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("item #%d produced", x);

    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);

    printf("item #%d consumed", x);
    x--;

    mutex = signal(mutex);
}

int main()
{
    int ch, n;
    printf("enter buffer size\n");
    scanf("%d", &n);
    empty = n;
    printf("\n1.Producer\n2.Consumer\n3.Exit");
    while (1)
    {
        printf("\nenter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
            {
                producer();
            }
            else
            {
                printf("Buffer is full.");
            }
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
            {
                consumer();
            }
            else
            {
                printf("Buffer is empty.");
            }
            break;
        case 3:
            exit(0);
            break;
        }
    }
}