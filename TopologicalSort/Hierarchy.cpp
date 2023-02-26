#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int V, E;

bool solution(vector<vector<int> > &graph, vector<int> &result)
{
    vector<int> indegree(V);
    queue<int> queue;
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
        result.push_back(u);
        vector<int>::iterator it;
        for (it = graph[u].begin(); it != graph[u].end(); it++)
        {
            indegree[*it]--;
            if (indegree[*it] == 0)
            {
                queue.push(*it);
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
    int n, k;
    cin >> n >> k;
    vector<vector<int> > wishes(n);
    for (int i = 0; i < k; i++)
    {
        int w;
        cin >> w;
        for (int j = 0; j < w; j++)
        {
            int s;
            cin >> s;
            wishes[i].push_back(s - 1);
        }
    }
    V = n;
    E = k;
    vector<int> results;
    solution(wishes, results);
    vector<int> bosses(n);
    for (int i = 1; i < n; i++)
    {
        bosses[results[i]] = results[i - 1] + 1;
    }
    for (int boss : bosses)
    {
        cout << boss << endl;
    }
    return 0;
}