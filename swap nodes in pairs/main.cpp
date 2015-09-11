#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
           return head;
        struct ListNode* left,*mid,*right,*tmp;
        tmp=head->next;
        head->next=tmp->next;
        tmp->next=head;
        head=tmp;
        left=head->next;
        while(left->next&&left->next->next)
        {
            mid=left->next;
            right=mid->next;
            tmp=right->next;
            right->next=mid;
            mid->next=tmp;
            left->next=right;
            left=mid;
        }

        return head;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
