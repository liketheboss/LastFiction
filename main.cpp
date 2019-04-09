#include <iostream>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "buildarea.h"

int main(int argc, char **argv)
{
    std::vector<std::vector<char>> map;
    map = readFile(argv[1]);
    printArea(map);
}