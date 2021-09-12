
//////////////////////////////////////////////////////////////
// 25. Reverse Nodes in k-Group
//////////////////////////////////////////////////////////////
// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of
// nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may be changed.
// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Example 2:
// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]
//
// Example 3:
// Input: head = [1,2,3,4,5], k = 1
// Output: [1,2,3,4,5]
//
// Example 4:
// Input: head = [1], k = 1
// Output: [1]
//
// Constraints:
//     The number of nodes in the list is in the range sz.
//     1 <= sz <= 5000
//     0 <= Node.val <= 1000
//     1 <= k <= sz
//////////////////////////////////////////////////////////////

#include <vector>
#include <assert.h>
#include <initializer_list>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    
    void reverseList(ListNode* head, ListNode* tail) {
        if (head->next == tail) {
            auto tmp = tail->next;
            tail->next = head;
            head->next = tmp;
            return;
        }

        auto h = head;
        auto h_next = h->next;
        while (h_next->next != tail) {
            auto tmp = h_next->next;
            h_next->next = h;
            h = h_next;
            h_next = tmp;
        }
        auto tmp = tail->next;        
        head->next = tmp;
        tail->next = h_next;
        tail->next->next = h;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if (k == 1) return head;
        
        int i=1;
        auto h = head;
        ListNode* ret = nullptr;
        auto snapshot = head;
        ListNode* last = nullptr;
        while (h) {
            if (i % k == 0) {
                reverseList(snapshot, h);
                if(!ret) ret = h;
                if(last) last->next = h;
                last = snapshot;
                h = snapshot;
                snapshot = h->next;
            }
            h = h->next;
            i++;
        }
        return ret;
    }
};