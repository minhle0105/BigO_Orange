#include <iostream>
#include <set>
#include <vector>

using namespace std;

int dR[] = {0, 0, 1, -1};
int dC[] = {1, -1, 0, 0};

set<vector<int>> res;

void solution(vector<vector<char>> &graph, int r, int c, int nOctave, int n, 
              int countDepth, set<int> &visited)
{
    if (countDepth == 8)
    {
        if (graph[r][c] == 'X')
        {
            ++nOctave;
        } 
        if (nOctave == 8)
        {
            vector<int> answer{visited.begin(), visited.end()};
            res.insert(answer);
        }
        return;
    }

    if (graph[r][c] == 'X')
    {
        ++nOctave;
    }
    for (int i = 0; i < 4; ++i)
    {
        int nextR = r + dR[i];
        int nextC = c + dC[i];
        bool inBoundary = nextR >= 0 && nextR < n && nextC >= 0 && nextC < n;
        if (inBoundary)
        {
            int majorRowIndex = nextR * n + nextC;
            if (visited.count(majorRowIndex) == 0)
            {
                visited.insert(majorRowIndex);
                ++countDepth;
                solution(graph, nextR, nextC, nOctave, n, countDepth, visited);
                visited.erase(majorRowIndex);
                --countDepth;
            }
        }
    }
}

int main()
{
    int nTests;
    cin >> nTests;
    for (int i = 0; i < nTests; ++i)
    {
        int n;
        cin >> n;
        vector<vector<char>> graph(n, vector<char>(n));

        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                cin >> graph[j][k];
            }
        }
        for (int r = 0; r < n; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                set<int> visited;
                visited.insert(r * n + c);
                solution(graph, r, c, 0, n, 1, visited);
            }
        }
        cout << res.size() << endl;
        res.clear();
    }
}