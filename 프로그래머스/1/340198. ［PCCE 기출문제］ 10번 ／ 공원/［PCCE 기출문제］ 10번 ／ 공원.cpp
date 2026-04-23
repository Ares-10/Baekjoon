#include <string>
#include <vector>

using namespace std;

bool possible(vector<vector<string>> park, int x, int y, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (y + i >= park.size() || x + j >= park[0].size() || park[y + i][x + j] != "-1")
                return false;
        }
    }
    return true;
}

int size(vector<vector<string>> park, int x, int y)
{
    int size;

    if (park[y][x] != "-1")
        return -1;

    size = 0;
    while (possible(park, x, y, size + 1))
        size++;
    return size;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer;
    int tmp;
    int max;
    
    max = 0;
    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[0].size(); j++)
        {
            tmp = size(park, j, i);
            if (tmp > max)
                max = tmp;
        }
    }
    
    answer = -1;
    for (int n : mats)
    {
        if (n > answer && n <= max)
            answer = n;
    }
    return answer;
}