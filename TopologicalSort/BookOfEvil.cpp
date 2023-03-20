#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

map<int, int> bfs(const vector<vector<int> > &graph, vector<int> &nodeIsInRange, const int start, const int d)
{
    queue<int> queue;
    vector<bool> visited(graph.size(), false);
    queue.push(start);
    visited[start] = true;
    map<int, int> levels;
    levels[start] = 0;

    while (!queue.empty())
    {
        int thisPoint = queue.front();
        queue.pop();
        for (int neighbor : graph[thisPoint])
        {
            if (visited[neighbor] == false)
            {
                visited[neighbor] = true;
                queue.push(neighbor);
                levels[neighbor] = levels[thisPoint] + 1;
            }
        }
    }
    
    for (size_t i = 1; i < graph.size(); i++)
    {
        if (levels[i] <= d && i != start)
        {
            nodeIsInRange[i] += 1;
        }
    }
    return levels;
}

int bfs(const vector<vector<int> > &graph, vector<int> &affectedBooks, const int start, const int d, const int k)
{
    queue<int> queue;
    vector<bool> visited(graph.size(), false);
    queue.push(start);
    visited[start] = true;
    map<int, int> levels;
    levels[start] = 0;

    while (!queue.empty())
    {
        int thisPoint = queue.front();
        queue.pop();
        for (int neighbor : graph[thisPoint])
        {
            if (visited[neighbor] == false)
            {
                visited[neighbor] = true;
                queue.push(neighbor);
                levels[neighbor] = levels[thisPoint] + 1;
            }
        }
    }
    
    int res;
    int dist = 0;
    for (size_t i = 0; i < affectedBooks.size(); i++)
    {
        if (levels[affectedBooks[i]] > dist)
        {
            res = affectedBooks[i];
            dist = levels[affectedBooks[i]];
        }
    }
    return res;
}

int main()
{
    int n, m, d;
    cin >> n >> m >> d;
  	if (d == 0)
    {
        if (m > 1)
        {
            cout << 0 << endl;
            return 0;
        }
        if (m == 1)
        {
            cout << 1 << endl;
            return 0;
        }
    }
    vector<int> affectedBooks;
    for (int i = 0; i < m; i++)
    {
        int affectedBook;
        cin >> affectedBook;
        affectedBooks.push_back(affectedBook);
    }

    vector<vector<int> > graph(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int src, dst;
        cin >> src >> dst;
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }
    vector<int> nodeIsInRange(graph.size());
    
    if (m < 2)
    {
        for (int book : affectedBooks)
        {
            bfs(graph, nodeIsInRange, book, d);
        }
        int res = 1;
        for (int d : nodeIsInRange)
        {
            if (d == affectedBooks.size())
            {
                res++;
            }
        }
        cout << res << endl;
    }
    else
    {
        int v = bfs(graph, affectedBooks, affectedBooks[0], d, 0);
        int u = bfs(graph, affectedBooks, v, d, 0);
        map<int, int> distanceFromV = bfs(graph, nodeIsInRange, v, d);
        map<int, int> distanceFromU = bfs(graph, nodeIsInRange, u, d);
        int res = 0;
        for (size_t i = 1; i < graph.size(); i++)
        {
            if (distanceFromV[i] <= d && distanceFromU[i] <= d)
            {
              res++;
            }
        }
        cout << res << endl;
        return 0;
    }

}