#include <stdio.h>

int main() {
    int time;
    int hours;
    int minutes;
    int seconds;

    printf("Enter the time using this format [hh:mm:ss]: ");
    scanf("%d:%d:%d", &hours, &minutes, &seconds);

    time = hours * 3600 + minutes * 60 + seconds;

    printf("Time stored in a single integer variable: %d seconds\n", time);

    hours = time / 3600;
    minutes = (time % 3600) / 60;
    seconds = time % 60;

    printf("Time : %02d:%02d:%02d\n", hours, minutes, seconds);

    return 0;
}