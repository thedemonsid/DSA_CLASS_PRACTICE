#include <bits/stdc++.h>
using namespace std;
class graph_matrix
{
public:
    int **arr;
    int n;

    graph_matrix(int size) : n(size)
    {
        arr = new int *[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            arr[i] = new int[n + 1];
            for (int j = 0; j < n + 1; j++)
            {
                arr[i][j] = 0;
            }
        }
    }

    ~graph_matrix()
    {
        for (int i = 0; i < n + 1; i++)
            delete[] arr[i];
        delete[] arr;
    }

    void display()
    {
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};

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
    void BFS(int source)
    {
        bool visited[n + 1];
        for (int i = 0; i <= n; i++)
            visited[i] = false;

        queue<int> que;
        que.push(source);
        visited[source] = true;
        while (!que.empty())
        {
            int u = que.front();
            que.pop();
            cout << u << " ";
            for (int i = 0; i < arr[u].size(); i++)
            {
                if (visited[arr[u][i]] == false)
                {
                    que.push(arr[u][i]);
                    visited[arr[u][i]] = true;
                }
            }
        }
        cout << endl;
    }
    void BFS()
    {
        bool visited[n + 1];
        for (int i = 0; i <= n; i++)
            visited[i] = false;

        queue<int> que;
        for (int i = 0; i <= n; i++)
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                que.push(i);
                while (!que.empty())
                {
                    int u = que.front();
                    que.pop();
                    cout << u << " ";
                    for (int i = 0; i < arr[u].size(); i++)
                    {
                        if (visited[arr[u][i]] == false)
                        {
                            que.push(arr[u][i]);
                            visited[arr[u][i]] = true;
                        }
                    }
                }
                cout << endl;
            }
        }
    }
    void DFS(int source){
        vector<bool>visited(n+1,false);
        DFS2(visited,arr[source],source); 
    }
    void DFS2(vector<bool>&visited,vector<int>a,int source){
        cout<<source<<" ";
        visited[source]=true;
        for(int i=0;i<a.size();i++){
            if(visited[a[i]]==false)DFS2(visited,arr[a[i]],a[i]);
        }
        return;
    }
       
};

void testGraphMatrix()
{
    int n;
    cout << "Enter the Number of vertices: ";
    cin >> n;
    cout << "Enter coneection from to where and cin -1 -1 for terminating the program:\n ";
    graph_matrix *a = new graph_matrix(n);
    int i = 0, j = 0;
    while (i != -1 || j != -1)
    {
        cin >> i >> j;
        if (i != (-1) && j != (-1))
        {
            a->arr[i][j] = 1;
        }
    }
    a->display();
}
void testGraphList()
{
    // Create a graph with 4 vertices and 2 disconnected components
    graph_list g(5);
    g.addelement(0, 1);
    g.addelement(0, 2);
    g.addelement(1, 3);
    g.addelement(1, 4);
    g.addelement(2, 4);
    g.addelement(3, 5);
    g.addelement(4, 5);

    // Perform BFS on the disconnected graph
    cout << "BFS traversal of disconnected graph: ";
    g.BFS();

    // Expected output: 1 2 3 4
}
void testDFS()
{
    graph_list g(5);
    g.addelement(0, 1);
    g.addelement(0, 2);
    g.addelement(1, 3);
    g.addelement(1, 4);
    g.addelement(2, 4);
    g.addelement(3, 5);
    g.addelement(4, 5);

    cout << "DFS traversal starting from vertex 0: ";
    g.DFS(0);
    // Expected output: 0 1 3 5 4 2

    cout << "DFS traversal starting from vertex 1: ";
    g.DFS(1);
    // Expected output: 1 0 2 4 5 3
}
int main()
{
    testDFS();
}