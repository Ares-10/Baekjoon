#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int sum = 0;
    for (int i = 0; i < players.size(); i++)
        players[i] -= m - 1;
    
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i] <= 0)
            continue;
        int n = players[i] / m;
        if (players[i] % m != 0)
            n++;
        for (int j = i; j < i + k && j < 24; j++)
            players[j] -= n * m;
        sum += n;
    }
    return sum;
}