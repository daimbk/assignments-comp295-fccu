/*Assignment 1
Name: Daim Bin Khalid
Roll no: 251686775*/

#include <iostream>
#include <cstdlib>

using namespace std;

// global occupied tile counter
int tile_counter = 0;

// grid function creates and contains tiles
// make array a pointer to return it
int (*game_grid())[4]
{
    static int grid[4][4] = {0};
    return grid;
}

void generate_tile()
{
    // check to see if grid is full (no moves left)
    if (tile_counter == 16)
    {
        return;
    }

    // get the grid array pointer
    int(*grid)[4] = game_grid();

    // get grid coordinates for rand empty tile
    int i = rand() % 4;
    int j = rand() % 4;
    while (grid[i][j] != 0)
    {
        i = rand() % 4;
        j = rand() % 4;
    }

    // get tile score
    int tile_score = rand() % 2;
    if (tile_score == 0)
    {
        tile_score = 2;
        grid[i][j] = tile_score;
        tile_counter++;
    }
    else
    {
        tile_score = 4;
        grid[i][j] = tile_score;
        tile_counter++;
    }
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
    // set seed
    srand(time(0));
    // initialize first two tiles
    generate_tile();
    generate_tile();

    string user_input;
    while (user_input != "exit")
    {
        system("cls");
        display_grid();
        cout << "Press any key: ";
        cin >> user_input;

        if (user_input != "exit")
        {
            if (tile_counter == 16)
            {
                cout << "Game Over!" << endl;
                user_input = "exit";
            }
            else
            {
                generate_tile();
            }
        }
    }

    return 0;
}
