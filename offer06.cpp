#include <vector>

struct ListNode {
    int val;     
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    std::vector<int> reversePrint(ListNode* head) {
        std::vector<int> result, tmp;
        while(head != nullptr){
            tmp.push_back(head->val);
            head = head->next ;
        }
        for(int i = tmp.size()-1; i >=0 ; --i){
            result.push_back(tmp[i]);
        }
        return result ;
    }
};


int main(){
    Solution solution ;
    ListNode* list = new ListNode(1);
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(3);
    list->next = l1 ;
    l1->next = l2 ;
    solution.reversePrint(list);
}