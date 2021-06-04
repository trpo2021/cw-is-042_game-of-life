#include <ctype.h>
#include <libgameoflife/menu.h>
#include <stdio.h>
#include <stdlib.h>

int menu(Settings* settings)
{
    system("clear");
    printf("width - %d\n", settings->width);
    printf("height - %d\n", settings->height);
    printf("speed - %f\n", settings->speed);
    int command;
    printf("1 - start\n");
    printf("2 - settings\n");
    printf("3 - exit\n");
    scanf("%d", &command);
    printf("%d\n", command);
    if (check(3, command) == -1)
        return menu(settings);
    if (command == 1)
        return choose_gen();
    if (command == 3)
        return -1;
    if (command == 2)
        return set(settings);
    return 0;
}

int set(Settings* settings)
{
    int command;
    system("clear");
    printf("1 - field size\n");
    printf("2 - speed\n");
    printf("3 - return\n");
    scanf("%d", &command);
    if (check(3, command) == -1)
        return set(settings);
    if (command == 1)
        return change_size_field(settings);
    if (command == 2)
        return change_speed(settings);
    if (command == 3)
        return menu(settings);
    return 0;
}

int change_size_field(Settings* settings)
{
    system("clear");
    printf("Enter width\n");
    scanf("%d", &settings->width);
    if (check(100, settings->width) == -1)
        return change_size_field(settings);
    printf("Enter height\n");
    scanf("%d", &settings->height);
    if (check(100, settings->height) == -1)
        return change_size_field(settings);
    return set(settings);
    return 0;
}

int change_speed(Settings* settings)
{
    system("clear");
    printf("Enter speed\n");
    scanf("%f", &settings->speed);

    return set(settings);
    return 0;
}

int choose_gen()
{
    int command;
    system("clear");
    printf("1 - from file\n");
    printf("2 - random\n");
    scanf("%d", &command);
    if (check(2, command) == -1)
        return choose_gen();
    return command;
}

int check(int size, int command)
{
    if ((command < 1) || (command > size))
        return -1;
    return 0;
}