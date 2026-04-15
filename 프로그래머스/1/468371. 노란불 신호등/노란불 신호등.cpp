#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> signals) {
    int sig_count;
    
    for (int time = 1; time < 20 * 20 * 20 * 20 * 20; time++)
    {
        sig_count = 0;
        for (vector<int> signal : signals)
        {
            if (time % (signal[0] + signal[1] + signal[2]) > signal[0] 
               && time % (signal[0] + signal[1] + signal[2]) <= signal[0] + signal[1] )
                sig_count++;
            else
                continue;
        }
        
        if (sig_count == signals.size())
            return time;
    }
    return -1;
}
