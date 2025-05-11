#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    size_t min_str_len;
    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        min_str_len = min(phone_book[i].length(), phone_book[i + 1].length());
        if (phone_book[i].substr(0, min_str_len) == phone_book[i + 1].substr(0, min_str_len))
            return false;
    }
    return true;
}