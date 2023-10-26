//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* recursiveListConvert (ListNode* l1, ListNode* l2, int carry){
        if (l1 == nullptr && l2 == nullptr && carry == 0) return nullptr; 
        ListNode* nextL1 = nullptr;
        ListNode* nextL2 = nullptr;
        int total = carry; 
        int nextCarry = 0; 
        if (l1 != nullptr) {
            total += l1->val;
            nextL1 = l1->next;
        }
        if (l2 != nullptr) {
            total += l2->val;
            nextL2 = l2->next;
        }
        if (total >= 10) {
            total = (total%10);
            nextCarry = 1; 
        }
        ListNode* current = new ListNode(total, (recursiveListConvert(nextL1, nextL2, nextCarry)));
        return current;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return recursiveListConvert(l1, l2, 0);
    }
};