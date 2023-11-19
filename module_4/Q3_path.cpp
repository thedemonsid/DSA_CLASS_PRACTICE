#include <bits/stdc++.h>
using namespace std;
class graph_list
{
public:
    int n;
    vector<vector<int>> arr;
    graph_list(int x)
    {
        n = x;
        arr.resize(x + 1);
    }
    void addelement(int u, int v)
    {
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    void display()
    {
        for (int i = 0; i <= n; i++)
        {
            cout << i << " -> ";
            for (auto v : arr[i])
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void findAllPaths(int start, int end, vector<bool> &visited, vector<int> &path)
    {
        visited[start] = true;
        path.push_back(start);

        if (start == end)
        {
            for (int i = 0; i < path.size(); i++)
            {
                cout << path[i] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int i = 0; i < arr[start].size(); i++)
            {
                if (!visited[arr[start][i]])
                {
                    findAllPaths(arr[start][i], end, visited, path);
                }
            }
        }

        path.pop_back();
        visited[start] = false;
    }

    void findAllPathsInGraph(int start, int end)
    {
        int n = arr.size();
        vector<bool> visited(n, false);
        vector<int> path;
        findAllPaths(start, end, visited, path);
    }
};

int main()
{
    graph_list *a = new graph_list(5);
    a->addelement(0, 1);
    a->addelement(0, 2);
    a->addelement(1, 5);
    a->addelement(4, 5);
    a->addelement(2, 4);
    a->addelement(2, 3);
    a->addelement(3, 5);
    a->findAllPathsInGraph(0, 5);
}