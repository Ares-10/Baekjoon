#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    string s1, s2;
    
    s1 = to_string(a);
    s2 = to_string(b);

    return stoi(s1 + s2) > stoi(s2 + s1);
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    for (int n : numbers)
    {
        answer += to_string(n);
    }
    if (answer[0] == '0')
        return "0";
    return answer;
}