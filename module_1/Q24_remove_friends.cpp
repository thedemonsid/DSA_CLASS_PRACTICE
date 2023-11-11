#include <bits/stdc++.h>
using namespace std;

/*The code takes the number of test cases t.
For each test case, it takes the number of friends n and the number of friends to delete k.
It then takes the popularity scores of each friend and uses a deque (dq) to store friends in a way that maximizes the popularity of the remaining friends.
It iterates through the popularity scores, removing less popular friends from the back of the deque until the desired number (k) is reached.
Finally, it prints the popularity scores of the remaining friends. The process is repeated for each test case*/

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