#include<iostream>

using namespace std;

#define NULL 0

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m==n) return head;
        ListNode *before = NULL;
        if(m>1){
            before = head;
            ListNode *cur = head;
            for(int i=2;i<m;i++){cur=cur->next;}
            before=cur;
        }
        ListNode *newTail;
        if(before)newTail = before->next;
        else newTail=head;
        ListNode *cur=newTail,*next=cur->next,*nextnext=next->next;
        for(int i=0;i<n-m;i++,cur=next,next=nextnext,nextnext=(nextnext?nextnext->next:NULL)) 
            next->next=cur;
        ListNode *newHead = cur;
        if(before)before->next=newHead;
        else head=newHead;
        newTail->next=next;
        return head;
    }
};

int main(){
    ListNode *n1=new ListNode(3),*n2=new ListNode(5);
    n1->next=n2;
    n2->next=NULL;
    cout<<"----------------\n";
    for(ListNode*i=n1;i;i=i->next)cout<<i->val<<endl;
    Solution s;
    n1=s.reverseBetween(n1,1,2);
    cout<<"----------------\n";
    for(ListNode*i=n1;i;i=i->next)cout<<i->val<<endl;
    return 0;
}