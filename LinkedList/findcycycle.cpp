#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int val ; 
    Node* next;

    Node(int x){
        val = x;
        next = nullptr;
    }
};



bool ifCycle ( Node * head ){
    Node * slow = head;
    Node * fast = head;

    while(fast and fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) return true;   // *** we are not writing this at top , because at the starting both will be same
    }

    return false;
}


Node * detectCycle (Node * head){           // to get the exact node where cycle is starting
    Node * slow = head;
    Node * fast = head;

    while(fast and fast-> next){
        slow = slow -> next;
        fast = fast ->next -> next;
        if(slow ==fast) break;
    }
    if(not fast or not fast->next) return NULL;

    fast = head;
    while(fast ->next != slow -> next){
        fast = fast -> next;
        slow = slow ->next;
    }
    return slow -> next;
}

void removeCycle(Node* head) {              // to remove cycle
    Node* start = detectCycle(head);
    if (!start) return;
    Node* temp = start;
    while (temp->next != start) temp = temp->next;
    temp->next = NULL;
}






int main(){

    

    return 0;
}