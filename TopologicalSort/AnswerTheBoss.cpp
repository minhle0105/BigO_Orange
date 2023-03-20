#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

bool solution(vector<vector<int> > &graph, vector<pair<int, int> > &result, const int V, const int E)
{
    vector<int> indegree(V);
    queue<int> queue;
    map<int, int> levels;
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
            queue.push(i);
        }
    }
    while (!queue.empty())
    {
        int u = queue.front();
        queue.pop();
        result.push_back({levels[u], u});
        vector<int>::iterator it;
        for (it = graph[u].begin(); it != graph[u].end(); it++)
        {
            indegree[*it]--;
            if (indegree[*it] == 0)
            {
                queue.push(*it);
                levels[*it] = levels[u] + 1;
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
    int nTest;
    cin >> nTest;
    for (int i = 0; i < nTest; i++)
    {
        int nEmployees, nLines;
        cin >> nEmployees >> nLines;
        vector<vector<int> > graph(nEmployees);
        vector<pair<int, int>> results;
        for (int j = 0; j < nLines; j++)
        {
            int src, dst;
            cin >> src >> dst;
            graph[dst].push_back(src);
        }
        solution(graph, results, nEmployees, nLines);
      	sort(results.begin(), results.end());
        cout << "Scenario #" << (i + 1) << ":\n";
        for (size_t k = 0; k < results.size(); k++)
        {
            cout << (results[k].first + 1) << " " << results[k].second << endl;
        }
    }
    return 0;
}