/**
 * DFS to mark boundary-connected 'O's as safe ('S')
 */
void dfs(char** board, int boardSize, int* boardColSize, int row, int col)
{
    if(row < 0 || row >= boardSize ||
       col < 0 || col >= boardColSize[0] ||
       board[row][col] != 'O')
        return;

    board[row][col] = 'S';

    dfs(board, boardSize, boardColSize, row - 1, col);
    dfs(board, boardSize, boardColSize, row + 1, col);
    dfs(board, boardSize, boardColSize, row, col - 1);
    dfs(board, boardSize, boardColSize, row, col + 1);
}

void solve(char** board, int boardSize, int* boardColSize)
{
    if(boardSize == 0)
        return;

    int rows = boardSize;
    int cols = boardColSize[0];

    // First and Last Column
    for(int i = 0; i < rows; i++)
    {
        if(board[i][0] == 'O')
            dfs(board, rows, boardColSize, i, 0);

        if(board[i][cols - 1] == 'O')
            dfs(board, rows, boardColSize, i, cols - 1);
    }

    // First and Last Row
    for(int j = 0; j < cols; j++)
    {
        if(board[0][j] == 'O')
            dfs(board, rows, boardColSize, 0, j);

        if(board[rows - 1][j] == 'O')
            dfs(board, rows, boardColSize, rows - 1, j);
    }

    // Convert surrounded 'O' to 'X' and restore safe cells
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            else if(board[i][j] == 'S')
                board[i][j] = 'O';
        }
    }
}