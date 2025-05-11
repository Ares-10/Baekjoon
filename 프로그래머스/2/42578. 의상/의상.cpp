#include <string>
#include <vector>
#include <map>

using namespace std;

int f(vector<int> &v, int pos, int sum);

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    vector<string> v;
    int answer = 0;
    for (int i = 0; i < clothes.size(); i++)
    {
        if (m.find(clothes[i][1]) == m.end())
        {
            m.insert({clothes[i][1], 0});
            v.push_back(clothes[i][1]);
        }
        m[clothes[i][1]]++;
    }
    
    vector<int> category_num;
    
    for (int i = 0; i < v.size(); i++)
        category_num.push_back(m[v[i]]);
    
    for (int i = 0; i < v.size(); i++)
    {
        answer += f(category_num, i, category_num[i]);
    }
    
    return answer;
}

int f(vector<int> &v, int pos, int n)
{
    int sum = n;
    for (int i = pos + 1; i < v.size(); i++)
        sum += f(v, i, n * v[i]);
    return sum;
}