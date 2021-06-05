#include <ctype.h>
#include <libgameoflife/menu.h>
#include <libgameoflife/setup.h>
#include <stdio.h>
#include <stdlib.h>

int menu(Settings* settings)
{
    system("clear");
    int command;
    printf("1 - random\n");
    printf("2 - shapes\n");
    printf("3 - exit\n");

    while ((command = com_input(3)) == -1)
        ;

    if (command == 3)
        return -1;
    else if (command == 1)
        return set_random(settings);
    else if (command == 2)
        return shoose_shape(settings);
    return 0;
}

int shoose_shape(Settings* settings)
{
    system("clear");
    int command;
    printf("1 - galaxy\n");
    printf("2 - fish\n");
    printf("3 - gun\n");
    printf("4 - x\n");
    while ((command = com_input(4)) == -1)
        ;
    if (command == 1)
        return setup_galaxy(settings);
    else if (command == 2)
        return setup_fish(settings);
    else if (command == 3)
        return setup_gun(settings);
    else if (command == 4)
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

    while ((command = com_input(3)) == -1)
        ;

    if (command == 1)
        return 1;
    if (command == 2)
        return change_size_field(settings);
    if (command == 3)
        return change_speed(settings);

    return 0;
}

int change_size_field(Settings* settings)
{
    system("clear");
    printf("Enter width(no more than %d)\n", MAXSIZE);
    while ((settings->width = com_input(MAXSIZE)) == -1)
        ;
    printf("Enter height(no more than %d)\n", MAXSIZE);
    while ((settings->height = com_input(MAXSIZE)) == -1)
        ;
    return set_random(settings);
}

int change_speed(Settings* settings)
{
    system("clear");
    printf("Enter speed (no more than %d)\n", MAXSPEED);
    while ((settings->speed = com_input(MAXSPEED)) == -1)
        ;
    return set_random(settings);
}

int com_input(int size)
{
    char command[10];
    scanf("%s", &command[0]);
    if ((isdigit(command[0]) == 0) || (check(atoi(&command[0]), size)) == -1) {
        printf("Enter correct command\n");
        return -1;
    } else
        return atoi(&command[0]);
}

int check(int data, int size)
{
    if ((data <= 0) || (data > size))
        return -1;
    else
        return 0;
}