#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int dR[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dC[] = {1, -1, 0, 0, 1, -1, -1, 1};

vector<string> qualified_words[2];

void solution(char data[4][4], string &current_word, int current_vowel_count, int r, int c, int board_id, bool visited[4][4])
{
    if (data[r][c] == 'U' || 
        data[r][c] == 'E' || 
        data[r][c] == 'I' ||
        data[r][c] == 'A' ||
        data[r][c] == 'O' ||
        data[r][c] == 'Y')
    {
        current_vowel_count ++;
    }
    current_word += data[r][c];

    if (current_word.size() == 4)
    {
        if (current_vowel_count == 2)
        {
            qualified_words[board_id - 1].push_back(current_word);
        }
        current_word.pop_back();
        return;
    }

    for (int i = 0; i < 8; ++i)
    {
        int nextR = r + dR[i];
        int nextC = c + dC[i];
        bool in_bound = nextR >= 0 && nextR < 4 && nextC >= 0 && nextC < 4;
        if (in_bound)
        {
            if (!visited[nextR][nextC])
            {
                visited[nextR][nextC] = true;
                solution(data, current_word, current_vowel_count, nextR, nextC, board_id, visited);
                visited[nextR][nextC] = false;
            }
        }
    }
    current_word.pop_back();
}

int main()
{
    while (true)
    {
        char data_one[4][4];
        char data_two[4][4];
        qualified_words[0].clear();
        qualified_words[1].clear();
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                char next_char;
                cin >> next_char;
                if (next_char == '#')
                {
                    return 0;
                }
                if (j < 4)
                {
                    data_one[i][j] = next_char;
                }
                else
                {
                    data_two[i][j - 4] = next_char;
                }
            } 
        }
        bool visited[4][4];
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                std::string current_word_one{""};
                visited[i][j] = true;
                solution(data_one, current_word_one, 0, i, j, 1, visited);
                std::string current_word_two{""};
                visited[i][j] = true;
                solution(data_two, current_word_two, 0, i, j, 2, visited);
                visited[i][j] = false;
            }
        }

        sort (qualified_words[0].begin(), qualified_words[0].end());
        sort (qualified_words[1].begin(), qualified_words[1].end());
        vector<string> results(max(qualified_words[0].size(), qualified_words[1].size()));
        auto it = set_intersection (qualified_words[0].begin(), qualified_words[0].end(), 
                            qualified_words[1].begin(), qualified_words[1].end(), 
                            results.begin());
                                                
        results.resize(it - results.begin());                  

        if (results.size() == 0)
        {
            cout << "There are no common words for this pair of boggle boards." << endl;
          	cout << endl;
            continue;
        }
        set<string> results_set(results.begin(), results.end());
        for (auto result : results_set)
        {
            cout << result << endl;
        }
      	cout << endl;
    }
    return 0;
}