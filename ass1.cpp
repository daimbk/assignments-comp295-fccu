/*Assignment 1
Name: Daim Bin Khalid
Roll no: 251686775*/

#include <iostream>
#include <cstdlib>

using namespace std;

// grid function creates and contains tiles
// make array a pointer to return it
int (*game_grid())[4]
{
    static int grid[4][4] = {0};

    // generate 2 random tiles with 2 or 4
    // set seed
    srand(time(0));

    int tile_score = rand() % 2;
    int i = rand() % 4;
    int j = rand() % 4;
    if (tile_score == 0)
    {
        tile_score = 2;
        grid[i][j] = tile_score;
    }
    else
    {
        tile_score = 4;
        grid[i][j] = tile_score;
    }

    int second_tile_score = rand() % 2;
    i = rand() % 4;
    j = rand() % 4;
    if (second_tile_score == 0)
    {
        second_tile_score = 2;
        grid[i][j] = second_tile_score;
    }
    else
    {
        second_tile_score = 4;
        grid[i][j] = second_tile_score;
    }

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
    string user_input;
    while (user_input != "exit")
    {
        system("cls");
        display_grid();
        cout << "Press any key: ";
        cin >> user_input;
    }

    return 0;
}
