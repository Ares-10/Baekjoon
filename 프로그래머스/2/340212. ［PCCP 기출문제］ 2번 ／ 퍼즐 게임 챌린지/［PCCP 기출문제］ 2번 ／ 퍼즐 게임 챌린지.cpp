#include <string>
#include <vector>

using namespace std;

bool is_solvable(vector<int> diffs, vector<int> times, long long limit, int level)
{
    for (int i = 0; i < diffs.size(); i++)
    {
        if (diffs[i] > level)
            limit -= times[i] * (diffs[i] - level);
    }
    if (limit >= 0)
        return true;
    return false;
}

int binary_search(vector<int> diffs, vector<int> times, long long limit, int left, int right)
{
    int mid = (left + right) / 2;
    
    if (mid == left)
        return mid + 1;
    
    if (is_solvable(diffs, times, limit, mid))
        return binary_search(diffs, times, limit, left, mid);
    else
        return binary_search(diffs, times, limit, mid, right);    
}

int solution(vector<int> diffs, vector<int> times, long long limit)
{
    int level = 1;
    
    for (int i = 0; i < times.size(); i++)
    {
        limit -= times[i];
        if (diffs[i] > level)
            level = diffs[i];
    }
    for (int i = times.size() - 1; i > 0; i--)
    {
        times[i] += times[i - 1];
    }
    if (is_solvable(diffs, times, limit, 1))
        return 1;
    return binary_search(diffs, times, limit, 1, level);
}