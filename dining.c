
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int chopstick[5] = {1};
int comp[5] = {0};
int state[5];
// State
// 0 is think
// 1 is hungry
// 2 is eating
void wait(int *s)
{
    while (s == 0)
        ;
    s--;
}
void signal(int *s)
{
    s++;
}

int main()
{
    int c = 0;
    int j;
    srand(time(0));
    do
    {
        // To check if all phil are done eating then end
        if (comp[0] = 1 && comp[1] == 1 && comp[2] == 1 && comp[3] == 1 && comp[4] == 1)
            break;
        // To gen random phil no
        int i = rand() % 5;
        // To check if the rand phil no hasn't already eaten

        if (comp[i] != 1)
        {
            printf("\n----------------------------\n");
            printf("\nPhilosopher %d Hungry\n", i);

            state[i] = 1;
            // Check if phil is hungry and left and right phil arent eating
            if (state[i] == 1 && state[(i + 4) % 5] != 2 && state[(i + 1) % 5] != 2)
            {
                wait(&chopstick[i]);
                wait(&chopstick[(i + 1) % 5]);
                state[i] = 2;
                comp[i] = 1;
                int k;
                for (k = 0; k < 5; k++)
                {
                    if (state[k] == 0)
                    {
                        printf("\nPhilosopher %d is thinking", k);
                    }
                    else if (state[k] == 1)
                    {
                        printf("\nPhilosopher %d is Hungry", k);
                    }
                    else

                        printf("\nPhilosopher %d is Eating", k);
                }
                signal(&chopstick[i]);
                signal(&chopstick[(i + 1) % 5]);
                state[i] = 0;
            }
        }
    } while (1);
    return 0;
}