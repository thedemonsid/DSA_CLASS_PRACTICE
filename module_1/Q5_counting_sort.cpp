#include <bits/stdc++.h>
using namespace std;
// function for counting sort
vector <int> count_sort(vector<int> a)
{
    int n = a.size();
    int max = *max_element(a.begin(), a.end());
    vector<int> count(max + 1, 0);
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    vector<int> output;
    for (int i = 0; i < max + 1; i++)
    {
        while (count[i] > 0)
        {
            output.push_back(i);
            count[i]--;
        }
    }
    return output;
}
int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int>ans=count_sort(a);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}