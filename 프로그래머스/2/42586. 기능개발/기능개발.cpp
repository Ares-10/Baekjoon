#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int time;
    int count = 0;
    int imm = 0;
    for (int i = 0; i < progresses.size(); i++) {
        time = ceil((float)(100 - progresses[i]) / speeds[i]);
        
        if (imm == 0)
            imm = time;
        if (time <= imm)
            count++;
        else
        {
            answer.push_back(count);
            count = 1;
            imm = time;
        }
    }
    if (count != 0)
    {
        answer.push_back(count);
        count = 0;
        imm = 0;
    }
    
    return answer;
}