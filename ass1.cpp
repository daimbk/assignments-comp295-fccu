/*Assignment 1
Name: Daim Bin Khalid
Roll no: 251686775*/

#include <iostream>

using namespace std;

// grid function creates and contains tiles
// make array a pointer to return it
int (*game_grid())[4]
{
    static int grid[4][4] = {0};
    return grid;
}

void display_grid()
{
    // get the grid array pointer
    int(*grid)[4] = game_grid();

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << grid[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    display_grid();
}
