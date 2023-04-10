#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int res;

int get_final_position(const string &instructions)
{
    int pos = 0;
    for (char c : instructions)
    {
        pos += (c == '+' ? 1 : -1);
    }
    return pos;
}

void solution(string &s, int numberOfQuestionMarks, int i, const int originalPosition)
{
    if (i == s.size())
    {
        int pos = get_final_position(s);
        res += pos == originalPosition ? 1 : 0;
        return;
    }
    if (s[i] == '?')
    {
        s[i] = '+';
        --numberOfQuestionMarks;
        solution(s, numberOfQuestionMarks, i + 1, originalPosition);
        ++numberOfQuestionMarks;
        s[i] = '-';
        --numberOfQuestionMarks;
        solution(s, numberOfQuestionMarks, i + 1, originalPosition);
        ++numberOfQuestionMarks;
        s[i] = '?';
    }
    else
    {
        solution(s, numberOfQuestionMarks, i + 1, originalPosition);
    }
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int pos1 = get_final_position(s1);
    int numberOfQuestionMarks = 0;
    for (char c : s2)
    {
        if (c == '?')
        {
            ++numberOfQuestionMarks;
        }
    }
    int totalChoices = pow(2, numberOfQuestionMarks);
    solution(s2, numberOfQuestionMarks, 0, pos1);
    cout << setprecision(10) << fixed << (static_cast<float>(res) / totalChoices) << endl;
    return 0;
}