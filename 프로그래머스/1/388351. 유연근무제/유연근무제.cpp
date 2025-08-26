#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for (int i = 0; i < schedules.size(); i++)
    {
        bool n = true;
        if (schedules[i] % 100 >= 50)
            schedules[i] += 50;
        else
            schedules[i] += 10;
        for (int j = 0; j < 7; j++)
        {
            if ((startday + j - 1) % 7 == 5 || (startday + j - 1) % 7 == 6)
                continue;
            if (timelogs[i][j] > schedules[i])
                n = false;
        }
        if (n)
            answer++;
    }
    return answer;
}