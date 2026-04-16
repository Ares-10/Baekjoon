#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    for (int i = 1000; i >= 0; i--)
    {
        for (int j = 0; j < citations.size(); j++)
        {
            if (citations[j] >= i && citations.size() - j >= i)
                return i;
        }
    }
    return -1;
}