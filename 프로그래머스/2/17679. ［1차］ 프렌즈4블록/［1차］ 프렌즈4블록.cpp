#include <string>
#include <vector>

using namespace std;

bool check(vector<string> const &board, int x, int y)
{
    char c;

    c = board[y][x];
    if (c != ' '
       && board[y + 1][x] == c
       && board[y][x + 1] == c
       && board[y + 1][x + 1] == c)
        return true;
    return false;
}

bool erase_block(vector<string> &board)
{
    vector<vector<bool>> v(board.size() - 1);
    bool b;
    
    for (int i = 0; i + 1 < board.size(); i++)
        for (int j = 0; j + 1 < board[0].length(); j++)
            v[i].push_back(check(board, j, i));
    
    b = false;
    for (int i = 0; i + 1 < board.size(); i++)
    {
        for (int j = 0; j + 1 < board[0].length(); j++)
        {
            if (v[i][j])
            {
                board[i][j] = ' ';
                board[i + 1][j] = ' ';
                board[i][j + 1] = ' ';
                board[i + 1][j + 1] = ' ';
                b = true;
            }
        }
    }
    return b;
}

void move_block(vector<string> &board)
{
    for (int x = 0; x < board[0].length(); x++)
    {
        for (int y = 1; y < board.size(); y++)
        {
            bool b;
            
            b = false;
            if (board[y][x] == ' ')
            {
                for (int i = y - 1; i >= 0; i--)
                {
                    if (board[i][x] != ' ')
                    {
                        b = true;
                        break;
                    }
                }
            }
            
            if (b)
            {
                for (int i = y; i >= 1; i--)
                    board[i][x] = board[i - 1][x];
                board[0][x] = ' ';
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int count;
    
    while (erase_block(board))
        move_block(board);

    count = 0;
    for (string s : board)
        for (char c : s)
            if (c == ' ')
                count++;
    return count;
}