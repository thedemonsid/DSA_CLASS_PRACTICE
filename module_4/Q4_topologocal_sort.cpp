#include<bits/stdc++.h>
using namespace std;
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
    
    void DFS(){
        stack<int>ans;
        vector<int>visited(n+1,false);
         for(int i=0;i<=n;i++){
            if(visited[i]==false) DFS2(visited,arr[i],i,ans); 
         }

        while(!empty(ans)){
            cout<<ans.top()<<" ";
            ans.pop();
        }   
    }
    void DFS2(vector<int>&visited,vector<int>a,int source,stack<int>&ans){
       // cout<<source<<" ";
        visited[source]=true;
        for(int i=0;i<a.size();i++){
            if(visited[a[i]]==false)DFS2(visited,arr[a[i]],a[i],ans);
        }
        ans.push(source);
        return;
    }       
}; 

int main(){
  graph_list*a=new graph_list(5);
  a->addelement(5,0);
  a->addelement(4,0);
  a->addelement(5,2);
  a->addelement(2,3);
  a->addelement(3,1);
  a->addelement(4,1);
  a->display();
  a->DFS();
}