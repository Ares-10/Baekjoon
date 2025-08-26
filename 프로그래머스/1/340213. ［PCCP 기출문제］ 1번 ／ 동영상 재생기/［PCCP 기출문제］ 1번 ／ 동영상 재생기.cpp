#include <string>
#include <vector>

using namespace std;

int fun_1(string s)
{
    return (s[0] - '0') * 10 * 60
        + (s[1] - '0') * 60
        + (s[3] - '0') * 10
        + (s[4] - '0');
}

string fun_2(int i)
{
    string s = "00:00";
    s[0] = s[0] + (i / 60 / 10);
    s[1] = s[1] + ((i % (60 * 10)) / 60);
    s[3] = s[3] + ((i % 60) / 10);
    s[4] = s[4] + (i % 10);
    return s;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int video_l = fun_1(video_len);
    int op_s = fun_1(op_start);
    int op_e = fun_1(op_end);
    int pos_i = fun_1(pos);
    
    for (int i = 0; i < commands.size(); i++)
    {
        
        if (pos_i >= op_s && pos_i <= op_e)
            pos_i = op_e;
        if (commands[i] == "next")
        {
            if (pos_i + 10 > video_l)
                pos_i = video_l;
            else
                pos_i += 10;
        }
        else
        {
            if (pos_i - 10 < 0)
                pos_i = 0;
            else
                pos_i -= 10;
        }
        if (pos_i >= op_s && pos_i <= op_e)
            pos_i = op_e;
    }
    return fun_2(pos_i);
}