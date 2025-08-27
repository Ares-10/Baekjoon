#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    n--;
    num--;
    
    int floor = num / w;
    int pos = num % w;
    if (floor % 2 != 0)
        pos = w - 1 - pos;
    cout << floor << " " << pos << endl;
    
    int top_floor = n / w;
    int top_pos = n % w;
    if (top_floor % 2 != 0)
        top_pos = w - 1 - top_pos;
    cout << top_floor << " " << top_pos << endl;
    if (top_floor % 2 == 0)
    {
        if (top_pos >= pos)
            return top_floor + 1 - floor;
        else
            return top_floor - floor;
    }
    else
    {
        if (top_pos <= pos)
            return top_floor + 1 - floor;
        else
            return top_floor - floor;
    }
}