#include <stdio.h>
#include <stdlib.h>
#include <libgameoflife/menu.h>

int menu (Settings *settings) 
{
	int command;
	system("clear");
	printf ("1 - start\n");
	printf ("2 - settings\n");
	printf ("3 - exit\n");
	scanf ("%d", &command);
	if (command == 1)
		return 1;
	if (command == 3)
		return -1;
	if (command == 2)
		set (settings);
	return 0;
}

void set (Settings *settings)
{
	int command;
	system("clear");
	printf ("1 - field size\n");
	printf ("2 - return\n");
	scanf ("%d", &command);
	if (command == 1)
		change_size_field (settings);
	if (command == 2)
		menu (settings);
}

void change_size_field (Settings * settings)
{
	system("clear");
	printf ("Enter width\n"); 
	scanf ("%d", &settings-> width);
	printf ("Enter height\n"); 
	scanf ("%d", &settings-> height);
	set (settings);
}