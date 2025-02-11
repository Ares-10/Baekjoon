#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = { 50, 50, 0, 0 };
    
    for (int i = 0; i < wallpaper.size(); i++)
    {
        string s = wallpaper[i];
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == '#')
            {
                if (i < answer[0])
                    answer[0] = i;
                if (j < answer[1])
                    answer[1] = j;
                if (i + 1 > answer[2])
                    answer[2] = i + 1;
                if (j + 1 > answer[3])
                    answer[3] = j + 1;
            }
        }
    }
    return answer;
}