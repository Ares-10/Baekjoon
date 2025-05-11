#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> q;
    for (int i = 0; i < priorities.size(); i++)
        q.push(priorities[i]);
    sort(priorities.rbegin(), priorities.rend());
    int n;
    int i = 0;
    while (!q.empty())
    {
        
        n = q.front();
        q.pop();
        if (n == priorities[i])
        {
            i++;
            if (location == 0)
                return i;
            location--;
        }
        else
        {
            q.push(n);
            if (location == 0)
                location += q.size();
            location--;
        }

    }
    return i;
}