#include<bits/stdc++.h>
using namespace std;

class ListNode{
    int val ;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = NULL;
    }
};


    int getlength(ListNode * head){
        if(head == nullptr) return 0;

        int ans = 0;
        ListNode*temp =  head;
        while(temp){
            ans++;
            temp=temp->next;
        }
        return ans;
    }

    ListNode* moveAhead(ListNode * head, int k){
        while(k--){
            head = head -> next;
        }
        return head;
    }

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int a = getlength(headA);
    int b = getlength(headB);

    // move the larger linkedlist by k step

    ListNode* ptr1;
    ListNode* ptr2;

    if(a>=b){
        int k = a-b;
        ptr1 = moveAhead(headA, k);
        ptr2 = headB;
            
    } else {
        int k = b-a;
            
        ptr1 = headA;
        ptr2 = moveAhead(headB,k);
            
    }

    while(ptr1 and ptr2){
        if(ptr1 == ptr2) return ptr2;
        ptr1= ptr1->next;
        ptr2= ptr2->next;
    }

    return nullptr;

}





int main(){

    

    return 0;
}



