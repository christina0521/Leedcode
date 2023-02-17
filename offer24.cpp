// 反转链表
//定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
// 输入: 1->2->3->4->5->NULL
// 输出: 5->4->3->2->1->NULL

#include <vector>

struct ListNode {
    int val;     
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;

    }
};


int main(){
    Solution solution ;
    ListNode* list = new ListNode(1);
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(3);
    list->next = l1 ;
    l1->next = l2 ;
    solution.reverseList(list);
}