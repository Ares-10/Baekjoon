#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    char s[n + 1];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr1[i] / (int) pow(2, j) % 2 == 1
               || arr2[i] / (int) pow(2, j) % 2 == 1)
            {
                s[n - 1 - j] = '#';
            }
            else
                s[n - 1 - j] = ' ';
        }
        s[n] = '\0';
        answer.push_back(s);
    }
    return answer;
}