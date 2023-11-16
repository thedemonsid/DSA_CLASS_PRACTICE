#include<bits/stdc++.h>
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
            //cout << u << " ";
            for (int i = 0; i < arr[u].size(); i++)
            {
                if (visited[arr[u][i]] == false)
                {
                    que.push(arr[u][i]);
                    visited[arr[u][i]] = true;
                }
            }
        }
        //cout << endl;
        for (int i = 0; i <= n; i++)
        {
            if(visited[i]==false){
                cout<<"Disconnected\n";
                return;
            }
        }
        cout<<"connected\n";
    }        
};

int main(){
    graph_list g(5);
    g.addelement(0,1);
    g.addelement(0,5);
    g.addelement(1, 2);
    g.addelement(2, 3);
    g.addelement(4, 5);
    g.display();
    g.BFS(1);
    return 0;
}