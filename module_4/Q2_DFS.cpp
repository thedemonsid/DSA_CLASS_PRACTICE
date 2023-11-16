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
    void DFS(int source){
        vector<bool>visited(n+1,false);
        DFS2(visited,arr[source],source); 
        for(int i=0;i<=n;i++){
            if(visited[i]==false){
                cout<<"disconnected\n";
                return;
            }
        }
        cout<<"connected\n";
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
void test_DFS() {
    graph_list g(6);
    g.addelement(0,1);
    g.addelement(1, 2);
    g.addelement(2, 3);

    g.addelement(4, 5);
    g.addelement(5, 6);
    g.display();
    cout << "DFS traversal starting from node 1: ";
    g.DFS(1);
    cout << endl;
    cout << "DFS traversal starting from node 4: ";
    g.DFS(4);
    cout << endl;
}
int main(){
    test_DFS();
}
