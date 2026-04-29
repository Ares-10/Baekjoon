#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#include <iostream>

int ttoi(string s)
{
    return (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');
}

string itot(int n)
{
    string s = "00:00";
    s[0] += n / 600;
    s[1] += n % 600 / 60;
    s[3] += n % 60 / 10;
    s[4] += n % 10;
    return s;
}


string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "09:00";
    int last_crew;
    int time;
    int i;
    
    sort(timetable.begin(), timetable.end());
    
    for (time = 9 * 60; n--; time += t)
    {
        for (i = 0; i < m && timetable.size() > 0; i++)
        {
            if (ttoi(timetable[0]) > time)
                break;
            last_crew = ttoi(timetable[0]);
            timetable.erase(timetable.begin());
        }

        if (n == 0)
            break;
    }
    if (m - i >= 1)
        return itot(time);
    else
        return itot(last_crew - 1);
}