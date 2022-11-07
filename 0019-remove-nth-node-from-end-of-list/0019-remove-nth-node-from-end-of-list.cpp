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
class Solution {
public:
     ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    if(head==NULL) return head;
    
    ListNode *s=head, *f=head;          //2 pointers, slow=head
    
    for(int i=1;i<=n+1;i++){            //fast is initialised 'n+1' positions ahead
        if(f==NULL) return head->next;  
        f=f->next;
    }
    
    while(f!=NULL){                     //when fast is NULL, exit
        s=s->next;
        f=f->next;
    }
    
    s->next=s->next->next;              //update connection
    return head;
}
};