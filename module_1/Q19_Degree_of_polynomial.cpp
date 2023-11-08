/*Finding the highest degree of the polynomial with non - zero coeffecient
First line will contain T, number of test cases. Then the test cases follow
First line of each test case contains of a single integer N - the number of terms in the polynomial.
second line of each test case contains of N spaced integers */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t; // Taking input for no. of test cases//
    while (t--)
    {
        int n, l;
        cin >> n; // Taking input for highest degree of the polynomials//
        int arr[n];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i]; // Taking input for coeffecient of the ith element//
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