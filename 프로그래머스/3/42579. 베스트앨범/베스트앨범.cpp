#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class category {
public:
    string name;
    int count;
    int play;
    int max_play_index;
    int sec_max_play_index;

    bool operator<(category c) {
        return this->play < c.play; 
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<category> c;
    bool new_category;
    
    for (int i = 0; i < genres.size(); i++)
    {
        new_category = true;
        for (int j = 0; j < c.size(); j++)
        {
            if (c[j].name == genres[i])
            {
                new_category = false;
                c[j].count++;
                c[j].play += plays[i];
                if (plays[i] > plays[c[j].max_play_index])
                {
                    c[j].sec_max_play_index = c[j].max_play_index;
                    c[j].max_play_index = i;
                }
                else if (c[j].count != 1 && plays[i] > plays[c[j].sec_max_play_index])
                {
                    c[j].sec_max_play_index = i;
                }
            }
        }
        
        sort(c.begin(), c.end());
        
        if (new_category)
            c.push_back({ genres[i], 1, plays[i], i, -1 });
    }
    
    for (int i = c.size() - 1; i >= 0; i--)
    {
        answer.push_back(c[i].max_play_index);
        if (c[i].count > 1)
            answer.push_back(c[i].sec_max_play_index);
    }
    return answer;
}