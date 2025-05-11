#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> st;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push('(');
        else
        {
            if (st.size() != 0)
                st.pop();
            else
                return false;
        }
    }
    if (st.size() != 0)
        return false;
    return true;
}