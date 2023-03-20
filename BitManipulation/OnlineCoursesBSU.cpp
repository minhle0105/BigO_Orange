#include <iostream>
#include <vector>

using namespace std;

bool dfs(const vector<vector<int> > &data, const int src, vector<bool> &visited, vector<int> &orders, vector<bool> &has_dfs_ed)
{
    visited[src] = true;
    for (int neighbor : data[src])
    {
        if (has_dfs_ed[neighbor])
        {
            continue;
        }
        if (!visited[neighbor])
        {
            visited[neighbor] = true;
            bool dfs_neighbor = dfs(data, neighbor, visited, orders, has_dfs_ed);
            visited[neighbor] = false;
            if (!dfs_neighbor)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    has_dfs_ed[src] = true;
    orders.push_back(src);
    return true;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> required_courses;
    for (int i = 0; i < k; ++i)
    {
        int course;
        cin >> course;
        required_courses.push_back(course - 1);
    }
    vector<vector<int> > data;
    data.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int nDependency;
        cin >> nDependency;
        for (int j = 0; j < nDependency; ++j)
        {
            int course;
            cin >> course;
            data[i].push_back(course - 1);
        }
    }

    vector<int> orders;
    vector<bool> has_dfs_ed(n, false);

    for (int course : required_courses)
    {
        vector<bool> visited(n, false);
        if (!has_dfs_ed[course])
        {
            visited[course] = true;
            bool has_no_cycle = dfs(data, course, visited, orders, has_dfs_ed);
            if (!has_no_cycle)
            {
                cout << "-1" << endl;
                return 0;
            }
        }
    }
    cout << orders.size() << endl;
    for (int order : orders)
    {
        cout << (order + 1) << " ";
    }
}