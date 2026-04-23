#include <string>
#include <vector>

using namespace std;

struct robot
{
    int r;
    int c;
    bool complete;
    vector<int> route;
};

#include <iostream>

int crush_count(vector<robot> robots)
{
    vector<vector<int>> points;
    bool crush;
    int count;
    
    count = 0;
    for (robot r: robots)
    {
        if (r.complete)
            continue;

        crush = false;
        for (vector<int> &p : points)
        {
            if (p[0] == r.r && p[1] == r.c)
            {
                crush = true;
                p[2]++;
                if (p[2] == 2)
                    count++;
                break;
            }
        }
        if (!crush)
            points.push_back({r.r, r.c, 1});
    }
    return count;
}

bool is_on_point(robot r, vector<int> p)
{
    if (r.r == p[0] && r.c == p[1])
        return true;
    return false;
}

void move(robot &r, vector<int> p)
{
    if (r.r > p[0])
        r.r--;
    else if (r.r < p[0])
        r.r++;
    else if (r.c > p[1])
        r.c--;
    else
        r.c++;
}

void move_robots(vector<robot> &robots, vector<vector<int>> points)
{
    for (robot &r : robots)
    {
        if (r.complete)
            continue;
        if (is_on_point(r, points[r.route[0] - 1]))
        {
            r.route.erase(r.route.begin());
            if (r.route.size() == 0)
            {
                r.complete = true;
                continue;
            }
        }
        move(r, points[r.route[0] - 1]);
    }
}

bool complete(vector<robot> robots)
{
    for (robot r : robots)
    {
        if (!r.complete)
            return false;
    }
    return true;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    vector<robot> robots;
    
    for (vector<int> route : routes)
    {
        robot r = {
            points[route[0] - 1][0],
            points[route[0] - 1][1],
            false,
            route,
        };
        r.route.erase(r.route.begin());
        robots.push_back(r);
    }

    while (!complete(robots))
    {
        answer += crush_count(robots);
        move_robots(robots, points);
    }
    
    return answer;
}