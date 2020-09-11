#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
int delay(float sec)
{
    int millis = 1000 * sec;
    clock_t start_time = clock();
    while (clock() < start_time + millis)
        ;
    return 0;
}

int main()
{
    int i = 0;
    float delayTime;
    printf("\nEnter the delay (in s) - ");
    scanf("%f", &delayTime);
    while (!kbhit())
    {
        printf("\nTime Passed - %f", delayTime);
        printf("\nRandom Number - %d", rand());
        delay(delayTime);
        i++;
    }
    main();
    return 0;
}
