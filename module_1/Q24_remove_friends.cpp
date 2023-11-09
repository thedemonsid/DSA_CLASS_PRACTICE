#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cout<<"Number of test cases: ";
    cin >> t;
    while (t--) {
        int n, k;
        cout<<"Enter number of friends and number of friends to delete: ";
        cin >> n >> k;
        vector<int> friends(n);
        cout<<"Friends popularity: ";
        for (int i = 0; i < n; i++) {
            cin >> friends[i];
        }
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && dq.back() < friends[i] && k > 0) {
                dq.pop_back();
                k--;
            }
            dq.push_back(friends[i]);
        }
        while (k--) {
            dq.pop_back();
        }
        for (auto it = dq.begin(); it != dq.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}