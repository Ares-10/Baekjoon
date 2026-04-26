#include <string>
#include <vector>

using namespace std;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int high = temperature > t2;
    int answer;
    
    temperature += 10;
    t1 += 10;
    t2 += 10;
    
    while (!onboard[onboard.size() - 1])
        onboard.erase(onboard.end() - 1);
    
    vector<vector<int>> dp(onboard.size());
        
    for (int j = 0; j <= 50; j++)
    {
        if (j == temperature)
            dp[0].push_back(0);
        else
            dp[0].push_back(100000);
    }
    
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 0; j <= 50; j++)
        {
            if ((high && j > temperature) || (!high && j < temperature))
            {
                dp[i].push_back(100000);
                continue;
            }
            if (onboard[i] && (j > t2 || j < t1))
            {
                dp[i].push_back(100000);
                continue;
            }
            int n;
            if (j == 0)
            {
                if (high)
                {
                    if (j == temperature)
                        n = min(dp[i - 1][j], dp[i - 1][j + 1] + a);
                    else
                        n = min(dp[i - 1][j] + b, dp[i - 1][j + 1] + a);
                }
                else
                {
                    if (j == temperature)
                        n = min(dp[i - 1][j + 1], dp[i - 1][j]);
                    else
                        n = min(dp[i - 1][j + 1], dp[i - 1][j] + b);
                }
            }
            else if (j == 50)
            { 
                if (high)
                {
                    if (j == temperature)
                        n = min(dp[i - 1][j - 1], dp[i - 1][j]);
                    else
                        n = min(dp[i - 1][j - 1], dp[i - 1][j] + b);
                }
                else
                {
                    if (j == temperature)
                        n = min(dp[i - 1][j], dp[i - 1][j - 1] + a);
                    else
                        n = min(dp[i - 1][j] + b, dp[i - 1][j - 1] + a);
                }
            }
            else
            {
                if (high)
                {
                    if (j == temperature)
                        n = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1] + a));
                    else
                        n = min(dp[i - 1][j - 1], min(dp[i - 1][j] + b, dp[i - 1][j + 1] + a));
                
                }
                else
                {
                    if (j == temperature)
                        n = min(dp[i - 1][j + 1], min(dp[i - 1][j], dp[i - 1][j - 1] + a));
                    else
                        n = min(dp[i - 1][j + 1], min(dp[i - 1][j] + b, dp[i - 1][j - 1] + a));
                }
            }
            dp[i].push_back(n);
        }
    }
    
    answer = INT32_MAX;
    for (int i = t1; i <= t2; i++)
    {
        answer = min(dp[dp.size() - 1][i], answer);
    }
    return answer;
}