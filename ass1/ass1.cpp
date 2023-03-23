/*Assignment 1
Name: Daim Bin Khalid
Roll no: 251686775*/

#include <iostream>
#include <cstdlib>
#include <conio.h>

// define arrow keys for user input
#define up 72
#define down 80
#define left 75
#define right 77

using namespace std;

// global occupied tile counter
int tile_counter = 0;

// grid function initializes tiles
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

// movement functions
void move_right()
{
    // get the grid array pointer
    int(*grid)[4] = game_grid();

    // move tiles to the right and merge adjacent tiles of the same value
    for (int i = 0; i < 4; i++)
    {
        for (int j = 2; j >= 0; j--)
        {
            if (grid[i][j] != 0)
            {
                int k = j;
                while (k < 3 && grid[i][k + 1] == 0)
                {
                    grid[i][k + 1] = grid[i][k];
                    grid[i][k] = 0;
                    k++;
                }

                if (k < 3 && grid[i][k + 1] == grid[i][k])
                {
                    grid[i][k + 1] *= 2;
                    grid[i][k] = 0;
                    tile_counter--;
                }
            }
        }
    }
}

void move_up()
{
    // get the grid array pointer
    int(*grid)[4] = game_grid();

    // move tiles up and merge adjacent tiles of the same value
    for (int j = 0; j < 4; j++)
    {
        for (int i = 1; i < 4; i++)
        {
            if (grid[i][j] != 0)
            {
                int k = i;
                while (k > 0 && grid[k - 1][j] == 0)
                {
                    grid[k - 1][j] = grid[k][j];
                    grid[k][j] = 0;
                    k--;
                }

                if (k > 0 && grid[k - 1][j] == grid[k][j])
                {
                    grid[k - 1][j] *= 2;
                    grid[k][j] = 0;
                    tile_counter--;
                }
            }
        }
    }
}

void move_down()
{
    int(*grid)[4] = game_grid();

    for (int j = 0; j < 4; j++)
    {
        for (int i = 3; i >= 0; i--)
        {
            if (grid[i][j] != 0)
            {
                int k = i + 1;
                while (k < 4 && grid[k][j] == 0)
                {
                    k++;
                }

                if (k - 1 != i)
                {
                    grid[k - 1][j] = grid[i][j];
                    grid[i][j] = 0;
                }

                if (k < 4 && grid[k][j] == grid[k - 1][j])
                {
                    grid[k][j] *= 2;
                    grid[k - 1][j] = 0;
                    tile_counter--;
                }
            }
        }
    }
}

void move_left()
{
    int(*grid)[4] = game_grid();

    for (int j = 0; j < 4; j++)
    {
        for (int i = 1; i < 4; i++) // start from i = 1 instead of i = 0
        {
            if (grid[j][i] != 0) // swap i and j to update the correct element
            {
                int k = i - 1;
                while (k >= 0 && grid[j][k] == 0)
                {
                    k--;
                }

                if (k + 1 != i)
                {
                    grid[j][k + 1] = grid[j][i];
                    grid[j][i] = 0;
                }

                if (k >= 0 && grid[j][k] == grid[j][k + 1])
                {
                    grid[j][k] *= 2;
                    grid[j][k + 1] = 0;
                    tile_counter--;
                }
            }
        }
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

    int user_input = 0;
    bool exit_game = false;
    while (!exit_game)
    {
        system("cls");
        display_grid();
        cout << "Press any arrow key: ";

        switch ((user_input = getch()))
        {
        case up:
            move_up();
            generate_tile();
            break;
        case down:
            move_down();
            generate_tile();
            break;
        case left:
            move_left();
            generate_tile();
            break;
        case right:
            move_right();
            generate_tile();
            break;
        }

        if (tile_counter == 16)
        {
            cout << "Game Over!" << endl;
            exit_game = true;
        }
    }

    return 0;
}