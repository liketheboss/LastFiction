#include "buildarea.h"

using namespace std;

vector<vector<char>> readFile(string inFile)
{
    ifstream inString;
    inString.open(inFile);

    string line;

    vector<vector<char>> map;

    while (std::getline(inString, line))
    {
        vector<char> newRow(line.begin(), line.end());
        map.push_back(newRow);
    }
    return map;
}

void printArea(vector<vector<char>> area)
{
    for (int i = 0; i < area.size(); i++)
    {
        for (int j = 0; j < area[i].size(); j++)
        {
            cout << area[i][j];
        }
        cout << endl;
    }
}