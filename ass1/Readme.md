Implementation of the 2048 tile game.

Game Rules:
The player can move up, down, left or right. Each input would move all tiles to that direction if there is empty cells or adjacent cells of same value can be added.
The player must combine tiles containing the same numbers until they reach a tile number 2048.

Code logic:
The code uses a 2D array to make a 4x4 grid initially set to 0 in each cell.
generate_tile() function is used to insert random tile of value of either 2 or 4 in an empty spot in the grid. In the beginning 2 tiles will be generated for the user.
Move functions are declared individually for each direction. Each function uses nested loops to cycle through each grid cell and check if adjacent cells have same value and can be added together.

check_game_over function uses same adjacent cell checking logic to see if tiles are full and any further moves can be made. If not then a bool value of game_over is set to true which indicates in main loop logic that the game is over.
The game can also be finished if the player reaches any single tile to score of 2048 which is check in get_largest_tile function and accordingly used if main loop to end the game.

Current user score and high score are stored for the running cycle of the game and displayed beneath the grid constantly.
The user input move directions using arrow keys.
When prompted to play again the user can enter Y or y to play again. Likewise n or N to stop the game.
display_grid function uses printf for easier formatting to maintain grid size on screen.

Note: button mashing arrow key input produces irregular behavior when grid gets full. Play Respectfully #respectthegrid
