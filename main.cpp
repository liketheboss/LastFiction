#include <iostream>
#include "buildarea.h"

using namespace std;

int main(int argc, char **argv)
{
    vector<vector<char>> map;
    map = readFile(argv[1]);
    printArea(map);
}