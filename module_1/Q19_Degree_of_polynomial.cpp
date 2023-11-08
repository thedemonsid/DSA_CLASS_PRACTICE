#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l;
        cin >> n;
        int arr[n];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] != 0)
            {
                l = i;
            }
        }
        cout << l - 1 << endl;
    }
}