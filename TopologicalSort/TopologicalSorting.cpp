#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int V, E;

bool solution(vector<vector<int> > &graph, vector<int> &result)
{
    vector<int> indegree(V);
    priority_queue<int> queue;
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
            queue.push(i * (-1));
        }
    }
    while (!queue.empty())
    {
        int u = queue.top()  * (-1);
        queue.pop();
        result.push_back(u);
        vector<int>::iterator it;
        for (it = graph[u].begin(); it != graph[u].end(); it++)
        {
            indegree[*it]--;
            if (indegree[*it] == 0)
            {
                queue.push(*it * (-1));
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
    vector<int> results;
    cin >> V >> E;
    vector<vector<int> > graph(V);
    for (int i = 0; i < E; i++)
    {
        int src, dst;
        cin >> src >> dst;
        graph[src - 1].push_back(dst - 1);
    }
    int res = solution(graph, results);
    if (!res)
    {
        cout << "Sandro fails.";
    }
    else
    {
        for (int result : results)
        {
            cout << result + 1 << " ";
        }
    }
    cout << endl;
    return 0;
}