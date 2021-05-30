#include <stdio.h>
#include <libgameoflife/menu.h>

int main()
{
	Settings settings;
	settings.width = 30;
	settings.height = 30;
    menu (&settings);
    return 0; 
}
