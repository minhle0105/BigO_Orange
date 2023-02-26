#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int bfs(set<pair<int, int> > &segments, pair<int, int> &start, pair<int, int> &dst)
{
    int dR[] = {0, 1, -1, 0, 1, 1, -1, -1};
    int dC[] = {1, 0, 0, -1, 1, -1, 1, -1};
    queue<pair<int, int> > queue;
    set<pair<int, int> > visited;
    queue.push(start);
    visited.insert(start);
    map<pair<int, int>, int> levels;
    levels[start] = 0;
    while (!queue.empty())
    {
        pair<int, int> currentPair = queue.front();
        queue.pop();
        for (int i = 0; i < 8; i++)
        {
            pair<int, int> nextPair = {currentPair.first + dR[i], currentPair.second +dC[i]};
            if (segments.find(nextPair) != segments.end())
            {
                if (visited.find(nextPair) == visited.end())
                {
                    visited.insert(nextPair);
                    queue.push(nextPair);
                    levels[nextPair] = levels[currentPair] + 1;
                }

            }
        }
    }
    return levels.find(dst) == levels.end() ? -1 : levels[dst];
}

int main()
{
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    int n;
    cin >> n;
    set<pair<int, int> > segments;
    for (int i = 0; i < n; i++)
    {
        int r, a, b;
        cin >> r >> a >> b;
        for (int j = a; j <= b; j++)
        {
            segments.insert({r, j});
        }
    }
    pair<int, int> start{x0, y0};
    pair<int, int> end{x1, y1};
    cout << bfs(segments, start, end) << endl;
    return 0;
}
