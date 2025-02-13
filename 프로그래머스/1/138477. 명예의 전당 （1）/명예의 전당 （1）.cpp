#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> board;
    vector<int> answer;
    for (int i = 0; i < score.size(); i++)
    {
        board.push_back(score[i]);
        sort(board.begin(), board.end());
        if (i >= k)
        {
            board.erase(board.begin());
        }
        answer.push_back(board[0]);
    }
    return answer;
}