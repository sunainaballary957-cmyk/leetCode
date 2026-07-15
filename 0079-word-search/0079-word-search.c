#include <stdbool.h>

bool dfs(char** board, int rows, int cols, int i, int j, char* word, int index)
{
    if(word[index] == '\0')
        return true;

    if(i < 0 || i >= rows || j < 0 || j >= cols)
        return false;

    if(board[i][j] != word[index])
        return false;

    char temp = board[i][j];
    board[i][j] = '#';      // Mark visited

    bool found =
        dfs(board, rows, cols, i + 1, j, word, index + 1) ||
        dfs(board, rows, cols, i - 1, j, word, index + 1) ||
        dfs(board, rows, cols, i, j + 1, word, index + 1) ||
        dfs(board, rows, cols, i, j - 1, word, index + 1);

    board[i][j] = temp;     // Backtrack

    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word)
{
    int rows = boardSize;
    int cols = boardColSize[0];

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(dfs(board, rows, cols, i, j, word, 0))
                return true;
        }
    }

    return false;
}