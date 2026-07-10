void gameOfLife(int** board, int boardSize, int* boardColSize)
{
    int rows = boardSize;
    int cols = boardColSize[0];

    int dir[8][2] = {
        {-1,-1}, {-1,0}, {-1,1},
        { 0,-1},         { 0,1},
        { 1,-1}, { 1,0}, { 1,1}
    };

    // First pass: Mark changes
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            int live = 0;

            for(int k = 0; k < 8; k++)
            {
                int r = i + dir[k][0];
                int c = j + dir[k][1];

                if(r >= 0 && r < rows && c >= 0 && c < cols)
                {
                    if(board[r][c] == 1 || board[r][c] == 2)
                        live++;
                }
            }

            // Live cell
            if(board[i][j] == 1)
            {
                if(live < 2 || live > 3)
                    board[i][j] = 2;   // Live -> Dead
            }
            // Dead cell
            else
            {
                if(live == 3)
                    board[i][j] = 3;   // Dead -> Live
            }
        }
    }

    // Second pass: Finalize changes
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(board[i][j] == 2)
                board[i][j] = 0;
            else if(board[i][j] == 3)
                board[i][j] = 1;
        }
    }
}