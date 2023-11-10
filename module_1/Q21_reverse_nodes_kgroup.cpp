#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp1 = head;
    ListNode* temp2 = head;
    while (temp2 != NULL) {
        int count = 1;
        vector<int> ans;
        while (count <= k && temp2 != NULL) {
            ans.push_back(temp2->val);
            temp2 = temp2->next;
            count++;
        }
        if (count == k+1) { 
            for (int i = k-1; i >= 0; i--) {
                temp1->val = ans[i];
                temp1 = temp1->next;
            }
        }
    }
    return head;
}
};