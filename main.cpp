/***************************************************
 *  Project: Maze Solver                           *
 *  Authors: Man N. Darius,                        *
 *           Pacuraru L. Fabian Virgil,            *
 *           Zah D. Elena                          *
 *  Description: The project is a maze generation  *
 *               and solver.                       *
 ***************************************************/

#include <stdio.h>
#include <graphics.h>
#include "headers/menu.h"
#include "headers/printing.h"

int main()
{
    init_window();
    main_menu();
    closegraph();
    return 0;
}
