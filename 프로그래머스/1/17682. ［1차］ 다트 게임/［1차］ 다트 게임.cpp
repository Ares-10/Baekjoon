#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int n;
    char c;
    vector<int> score;
    
    for (int i = 0; i < dartResult.size(); i++)
    {
        c = dartResult[i];
        if (c >= '0' && c <= '9')
        {
            if (c == '1' && i + 1 < dartResult.size() && dartResult[i + 1] == '0')
            {
                i++;
                score.push_back(10);
            }
            else
                score.push_back(c - '0');
        }
        else if (c == 'S')
            ;
        else if (c == 'D')
            score[score.size() - 1] *= score[score.size() - 1];
        else if (c == 'T')
            score[score.size() - 1] *= score[score.size() - 1] * score[score.size() - 1];
        else if (c == '#')
            score[score.size() - 1] *= -1;
        else if (c == '*')
        {
            score[score.size() - 1] *= 2;
            if (score.size() >= 2)
                score[score.size() - 2] *= 2;
        }
    }
    for (int n : score)
        answer += n;
    return answer;
}