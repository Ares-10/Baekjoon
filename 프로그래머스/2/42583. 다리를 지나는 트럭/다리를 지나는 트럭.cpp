#include <string>
#include <vector>
#include <utility>

using namespace std;

int bridge_weight(vector<pair<int, int>> bridge)
{
    int sum = 0;
    
    for (pair<int, int> truck : bridge)
        sum += truck.first;
    return sum;
}

bool push_truck(vector<pair<int, int>> &bridge, int bridge_length, int possible_weight, int truck_weight)
{
    if (bridge_weight(bridge) + truck_weight <= possible_weight)
    {
        bridge.push_back(make_pair(truck_weight, bridge_length));
        return true;
    }
    return false;
}

#include<iostream>
void time_passed(vector<pair<int, int>> &bridge)
{
    for (pair<int, int> &truck : bridge)
    {
        truck.second--;
    }
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 1;
    vector<pair<int, int>> bridge;
    
    for (int i = 0; ; time++)
    {        
        time_passed(bridge);
        
        if (bridge.size() > 0 && bridge[0].second == 0)
            bridge.erase(bridge.begin());
        
        if (push_truck(bridge, bridge_length, weight, truck_weights[i]))
        {
            i++;
        }
        if (i == truck_weights.size())
            return time + bridge_length;
    }
    return time;
}