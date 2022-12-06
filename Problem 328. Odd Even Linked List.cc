/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
using namespace std;
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        bool odd = true;
        if (head == nullptr){
            return head;
        }
        if (head->next == nullptr){
            return head;
        }
        ListNode * current = head;
        ListNode * even = head->next;
        while (current->next != nullptr){
            ListNode * temp = current->next;
            if ((current->next->next == nullptr) && (odd)){current->next = even;}
            else {current->next = current->next->next;}
            current = temp;
            odd = !odd;
        }
        if (odd){current->next = even;}
        return head; 
    }
};