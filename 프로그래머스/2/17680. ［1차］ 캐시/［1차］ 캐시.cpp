#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int time;
    vector<string> cache;
    bool hit;
    int i;
    
    time = 0;
    for (string city : cities)
    {
        for (i = 0; i < city.length(); i++)
        {
            if (city[i] >= 'A' && city[i] <= 'Z')
                city[i] += 'a' - 'A';
        }
        hit = false;
        for (i = 0; i < min((int) cache.size(), cacheSize); i++)
        {
            if (cache[i] == city)
            {
                hit = true;
                break;
            }
        }
        
        if (hit)
        {
            cache.push_back(city);
            cache.erase(cache.begin() + i);
            time++;
        }
        else
        {
            cache.push_back(city);
            if (cache.size() > cacheSize)
                cache.erase(cache.begin());
            time += 5;
        }
    }
    return time;
}