#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

bool solution(vector<vector<int> > &graph, vector<int> &result, int V, int E)
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
    int nDrinks;
    int nCase = 1;
    while (cin >> nDrinks)
    {
        vector<string> drinks;
        map<string, int> drinkMap;
        map<int, string> indexDrinkMap;

        for (int i = 0; i < nDrinks; i++)
        {
            string drink;
            cin >> drink;
            drinks.push_back(drink);
            drinkMap[drink] = i;
            indexDrinkMap[i] = drink;
        }
        int nLines;
        cin >> nLines;
        vector<int> results(nDrinks);
        vector<vector<int> > graph(nDrinks);
        for (int i = 0; i < nLines; i++)
        {
            string src, dst;
            cin >> src >> dst;
            int srcIndex = drinkMap[src];
            int dstIndex = drinkMap[dst];
            graph[srcIndex].push_back(dstIndex);
        }
        solution(graph, results, nDrinks, nLines);
        cout << "Case #" << nCase << ": ";
        cout << "Dilbert should drink beverages in this order: ";
        for (size_t i = results.size() - nDrinks; i < results.size() - 1; i++)
        {
            cout << indexDrinkMap[results[i]] << " ";
        }
        cout << indexDrinkMap[results[results.size() - 1]] << ".\n";
        cout << "\n";
        nCase++;
    }
    return 0;
}
