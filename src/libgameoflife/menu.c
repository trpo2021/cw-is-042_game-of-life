#include <libgameoflife/menu.h>
#include <stdio.h>
#include <stdlib.h>

int menu(Settings* settings)
{
    int command;
    system("clear");
    printf("1 - start\n");
    printf("2 - settings\n");
    printf("3 - exit\n");
    scanf("%d", &command);
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
    printf("Enter height\n");
    scanf("%d", &settings->height);
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
    return command;
}