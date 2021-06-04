#include <ctype.h>
#include <libgameoflife/menu.h>
#include <stdio.h>
#include <stdlib.h>

int menu(Settings* settings)
{
    system("clear");
    int command;
    printf("1 - random\n");
    printf("2 - galaxy\n");
    printf("3 - fish\n");
    printf("4 - gun\n");
    printf("5 - x\n");
    printf("6 - exit\n");
    scanf("%d", &command);
    if (command == 6)
        return -1;
    else if (command == 1)
        return set_random(settings);
    else if (command == 2)
        return setup_galaxy(settings);
    else if (command == 3)
        return setup_fish(settings);
    else if (command == 4)
        return setup_gun(settings);
    else if (command == 5)
        return setup_x(settings);
    return 0;
}

int set_random(Settings* settings)
{
    int command;
    system("clear");
    printf("1 - start\n");
    printf("2 - field size\n");
    printf("3 - speed\n");
    scanf("%d", &command);
    if (check(3, command) == -1)
        return set_random(settings);
    if (command == 1)
        return 1;
    if (command == 2)
        return change_size_field(settings);
    if (command == 3)
        return change_speed(settings);

    return 0;
}

int setup_galaxy(Settings* settings)
{
    settings->width = 20;
    settings->height = 20;
    return 2;
}
int setup_fish(Settings* settings)
{
    settings->width = 100;
    settings->height = 18;
    return 3;
}
int setup_gun(Settings* settings)
{
    settings->width = 50;
    settings->height = 50;
    return 4;
}
int setup_x(Settings* settings)
{
    settings->width = 30;
    settings->height = 30;
    return 5;
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
    return set_random(settings);
    return 0;
}

int change_speed(Settings* settings)
{
    system("clear");
    printf("Enter speed\n");
    scanf("%f", &settings->speed);
    return set_random(settings);
    return 0;
}

int check(int size, int command)
{
    if ((command < 1) || (command > size))
        return -1;
    return 0;
}