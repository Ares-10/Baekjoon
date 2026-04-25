#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int type_wait(int mentor, vector<vector<int>> reqs)
{
    int waiting_time = 0;
    int t;
    vector<int> mentoring;

    for (int time = 0; !reqs.empty();)
    {
        if (mentoring.size() >= mentor)
            t = mentoring[0];
        else
            t = reqs[0][0] - time;

        time += t;
        for (int &time_left : mentoring)
            time_left -= t;
        // 멘토링이 끝났다면 큐에서 해제 
        while (!mentoring.empty() && mentoring[0] <= 0)
            mentoring.erase(mentoring.begin());

        // 멘토링 시간이 되었고 멘토링 가능하다면
        // 멘토링 진행중(우선순위큐)에 포함
        while (!reqs.empty() && reqs[0][0] <= time && mentoring.size() < mentor)
        {
            if (reqs[0][0] < time)
                waiting_time += time - reqs[0][0];
            mentoring.push_back(reqs[0][1]);
            sort(mentoring.begin(), mentoring.end());
            reqs.erase(reqs.begin());
        }
    }
    return waiting_time;
}

int total_wait(vector<int> mentors, vector<vector<vector<int>>> type_reqs)
{
    int sum = 0;
    for (int i = 0; i < mentors.size(); i++)
        sum += type_wait(mentors[i], type_reqs[i]);
    return sum;
}

// 유형 별 가능한 멘토 인원 집합 중 최솟값 구하기
int fun(int n, int m, vector<int> mentors, vector<vector<vector<int>>> type_reqs)
{
    if (m != -1)
        mentors.push_back(m);

    if (mentors.size() == type_reqs.size())
        return total_wait(mentors, type_reqs);

    int minimum = fun(n, 1, mentors, type_reqs);
    for (int i = 0; i <= n; i++)
        minimum = min(minimum, fun(n - i, i + 1, mentors, type_reqs));
    return minimum;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    vector<int> mentors; // 유형 별 멘토 수
    vector<vector<vector<int>>> type_reqs(k); // 유형 별 상담 수
    
    // 유형 별 상담 요청 queue 생성
    for (vector<int> req : reqs)
        type_reqs[req[2] - 1].push_back(req);
        
    return fun(n - k, -1, mentors, type_reqs);
}