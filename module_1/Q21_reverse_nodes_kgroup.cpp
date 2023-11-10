#include<bits/stdc++.h>
using namespace std;
/*The reverseKGroup function attempts to reverse nodes in groups of size k in a linked list by modifying the values of the nodes.
It uses two pointers (temp1 and temp2) to traverse the list and a vector (ans) to temporarily store the values of the nodes in a group.
The code has some issues: it modifies values instead of reversing nodes, does not handle cases where the number of nodes is not a multiple of k, and uses an unnecessary vector for reversal*/
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