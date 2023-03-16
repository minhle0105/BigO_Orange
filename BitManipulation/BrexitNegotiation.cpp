#include <iterator>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int V;

bool solution(vector<vector<int>> &graph, vector<int> &result, vector<int> minutes)
{
    vector<int> indegree(V);
    priority_queue<pair<int, int>> queue;
    for (int i = 0; i < V; i++)
    {
        vector<int>::iterator it;
        for (it = graph[i].begin(); it != graph[i].end(); it++)
        {
            indegree[*it]++;
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            queue.push({minutes[i], i});
        }
    }
    while (!queue.empty())
    {
        int u = queue.top().second;
        queue.pop();
        result.push_back(u);
        vector<int>::iterator it;
        for (it = graph[u].begin(); it != graph[u].end(); it++)
        {
            indegree[*it]--;
            if (indegree[*it] == 0)
            {
                queue.push({minutes[*it], *it});
            }
        }
    }
    for (int d : indegree)
    {
        if (d != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    V = static_cast<int>(n);
    vector<vector<int>> topics(n);
    vector<int> minutes;
    for (int i = 1; i <= n; ++i)
    {
        int e, d;
        cin >> e >> d;
        minutes.push_back(e);
        for (int j = 0; j < d; j++)
        {
            int topic;
            cin >> topic;
            topics[topic - 1].push_back(i - 1);
        }
    }
    
    vector<int> results;
    solution(topics, results, minutes);
    int res = results[0];
    for (size_t i = 0; i < results.size(); ++i)
    {
        res = max(res, static_cast<int>(i + minutes[results[i]]));
    }
    cout << res << endl;
}