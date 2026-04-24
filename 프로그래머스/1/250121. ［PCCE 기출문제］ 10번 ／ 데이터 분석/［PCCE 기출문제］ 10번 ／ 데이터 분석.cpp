#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int i;

bool compare(vector<int> data1, vector<int> data2)
{
    if (data1[i] < data2[i])
        return true;
    return false;
}

int get_idx(string s)
{
    if (s == "code")
        return 0;
    else if (s == "date")
        return 1;
    else if (s == "maximum")
        return 2;
    else
        return 3;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    i = get_idx(ext);

    for (vector<int> d : data)
        if (d[i] < val_ext)
            answer.push_back(d);
    
    i = get_idx(sort_by);
    
    sort(answer.begin(), answer.end(), compare);
    return answer;
}